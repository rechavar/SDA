
class Sensor: public Peripheal, public Task<float, int> {
private:
  String units;
public:
  Sensor(String name, String units, uint16_t id = random(0, 0xFFFF)): Peripheal(name, id) {
    this->units = units;
  }
};