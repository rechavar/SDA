
class Actuator: public Peripheal,public Trigger, public Task<bool, uint16_t> { //La clase actuator va a heredar las propiedades de Peripheal y task
private:
  String type; //Inicializando la variable type como un String
public:
  Actuator(String name, String type, uint16_t id = random(0, 0xFFFF)): Peripheal(name, id) {
      this->type = type; // Asignando el valor the type en el espacio del objeto type con el this pointer.
  }
  String getType(); //inicializacion de la funcion de get type
  void report(Stream &uart);
};

String Actuator::getType(){
  return this->type;
};

void Actuator::report(Stream &uart){ //Se crea el objeto y se llenan los valores de nombre, id, type. Proximamente se agrega el trigger
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& res = jsonBuffer.createObject();
    res["name"] = this->getName();
    res["id"] = this->getId();
    res["type"] = "Actuator";
    res["act_type"] = this->getType();
    res["Trigger"] = this->getTrigger();
    String out;
    res.prettyPrintTo(out);
    uart.println(out);
}