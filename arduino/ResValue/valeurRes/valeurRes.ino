/*
   This program is used to mesure the resistance for Kiroulpa
   see https://github.com/ENSIMelec/Kiroulpa
  Schematic :

             |----------|              |----------|
   Vcc ------|  R1      |------|-------|   R2     |----- GND
             |----------|      |       |----------|
                            ResPin
     Vcc is set to 5V
     GND is set to 0V
     R1 is set to 2176 Ohms
     R2 is the resistance we want to calculate
     ResPin is the pin linked to the Arduino
   Author : Tom Pouderoux
   Updated : March 03 2022 by Tom de Pasquale
*/

#define DEBUG

#include <Wire.h>
#define SLAVE_ADDRESS 9

#define RES_Pin A7
#define R1 2176
#define Vcc 5

void setup() {
  pinMode(RES_Pin, INPUT);

  Wire.begin(SLAVE_ADDRESS);
  Wire.onRequest(sendData);

  Serial.begin(9600);


}

void loop() {
#ifdef DEBUG
  Serial.print("Value resistance : ");
  Serial.println(readResistance());

  delay(50);
#endif
}

long readResistance() {
  double V = 5;

  double Vres = analogRead(RES_Pin) * V / 1023;
  unsigned long resistor = Vres * R1 / (V - Vres);
  return resistor;
}

void sendData()
{
  long mes = readResistance();
  if (mes > 4000 && mes < 5000) { // 470 Ohms
    Serial.println("Violette");
    Wire.write(0x01);
  } else if (mes > 8000 && mes < 11000) { // 1k Ohms
    Serial.println("Orange");
    Wire.write(0x02);
  } else { // 4.7k Ohms
    Serial.println("Personne");
    Wire.write(0x03);
  }
}
