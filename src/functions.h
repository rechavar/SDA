#ifndef function_h
#define function_h

#include <Arduino.h>

float readTemp(int var){
  return (float(analogRead(0)/1023.0)*5.0);
}

bool setSpeed(uint16_t duty){
  char buff[50];
  sprintf(buff, "PWM set to %2d");
  Serial.print(buff);
}

#endif