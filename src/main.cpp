#include <Arduino.h>
#include <peripheal.h>
#include <task.h>
#include <sensor.h>
#include <actuator.h>
#include "functions.h"


Sensor sensor = Sensor(String("lm35"), String("°C"));
Actuator actuator = Actuator(String("AX500"), String("Speed Controller"));

void setup() {
  Serial.begin(115200);
  sensor.attach(readTemp);
  actuator.attach(setSpeed);
}

void loop() {
  Serial.println(sensor.run(0));
  actuator.report(Serial);
  while(1){

  }
}

