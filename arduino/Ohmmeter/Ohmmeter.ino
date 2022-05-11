/*
   This program is used to mesure the resistance for Kiroulpa
   see https://github.com/ENSIMelec/Kiroulpa


  Schematic :
  
             |----------|              |----------|
   Vcc ------|  R1      |------|-------|   R2     |----- GND
             |----------|      |       |----------|
                            ResPin


   * Vcc is set to 5V
   * GND is set to 0V
   * R1 is set to 2290 Ohms
   * R2 is the resistance we want to calculate
   * ResPin is the pin linked to the Arduino

   Author : Tom Pouderoux

   Updated : March 03 2022 by Tom de Pasquale
   Added some documentation
*/

//#define DEBUG

#include <Wire.h>
#define SLAVE_ADDRESS 9

#define RES_Pin A1
#define R1 2290
#define Vcc 5.0
#define NB_MES 10

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

long readResistance(){
  unsigned long resistor = 0;
  double Vres = 0;
  for(int i=0;i<NB_MES;i++){
    Vres = analogRead(RES_Pin)* Vcc / 1023;
    resistor += Vres * R1 / (Vcc - Vres);
  }
  return resistor / NB_MES;
}

void sendData()
{
  long mes = readResistance();
  if (mes > 400 && mes < 600) { // 470 Ohms
    Serial.println("Violette");
    Wire.write(0x01);
  } else if (mes > 800 && mes < 1200) { // 1k Ohms
    Serial.println("Orange");
    Wire.write(0x02);
  } else {
    Serial.println("Personne");
    Wire.write(0x03);
  }
}
