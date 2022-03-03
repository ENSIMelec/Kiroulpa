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
   * R1 is set to 2176 Ohms
   * R2 is the resistance we want to calculate
   * ResPin is the pin linked to the Arduino

   Author : Tom Pouderoux

   Updated : March 03 2022 by Tom de Pasquale
   Added some documentation
*/

#define RES_Pin = A0;
#define R1 2176;
#define Vcc 5

void setup() {
  pinMode(RES_Pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(readResistance());
  delay(100);
}


//
long readResistance(){
  
  double Vres = analogRead(RES_Pin)* Vcc / 1023;
  unsigned long resistor = Vres * R1 / (Vcc - Vres);
  return resistor;
}
