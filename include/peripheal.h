#include <Arduino.h>
#include <ArduinoJson.h>

class Peripheal {
    private:
        String name;
        uint16_t id;
    public:
        Peripheal();
        Peripheal(String name, uint16_t id);
        String getName();
        String setName(String name);
        uint16_t getId();
        uint16_t setId(uint16_t id);
        void report(Stream &uart);
};

Peripheal::Peripheal(){};

Peripheal::Peripheal(String name, uint16_t id=random(0, 0xFFFF)) {
    this->name = name;
    this->id = id;
}

String Peripheal::getName() {
    return name;
}

uint16_t Peripheal::getId() {
    return id;
}

String Peripheal::setName(String name) {
    return this->name = name;
}

uint16_t Peripheal::setId(uint16_t id) {
    return this->id = id;
}

void Peripheal::report(Stream &uart){
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& res = jsonBuffer.createObject();
    res["name"] = this->getName();
    res["id"] = this->getId();
    String out;
    res.prettyPrintTo(out);
    uart.println(out);
};