
class Actuator: public Peripheal, public Task<bool, uint16_t> {
private:
  String type;
public:
  Actuator(String name, String type, uint16_t id = random(0, 0xFFFF)): Peripheal(name, id) {
      this->type = type;
  }
  String getType();
  void report(Stream &uart);
};

String Actuator::getType(){
  return this->type;
};

void Actuator::report(Stream &uart){
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& res = jsonBuffer.createObject();
    res["name"] = this->getName();
    res["id"] = this->getId();
    res["type"] = "Actuator";
    res["act_type"] = this->getType();
    String out;
    res.prettyPrintTo(out);
    uart.println(out);
}