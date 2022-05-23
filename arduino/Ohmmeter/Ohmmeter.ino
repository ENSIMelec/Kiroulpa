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
     R1 is set to 2290 Ohms
     R2 is the resistance we want to calculate
     ResPin is the pin linked to the Arduino

   Author : Tom Pouderoux

   Updated : March 03 2022 by Tom de Pasquale
   Added some documentation
*/

#define DEBUG

#include <Wire.h>
#define SLAVE_ADDRESS 9
#define START_BYTE  0xA5
#define END_BYTE    0x5A

// Colors
#define RED         0x00
#define YELLOW      0x01
#define PURPLE      0x02
#define NONE        0x03

#define RES_PIN_0 A0
#define RES_PIN_1 A1

double resistors[] = {0, 0};

#define R1 2290
#define Vcc 5.0
#define NB_MES 1

void setup() {
  pinMode(RES_PIN_0, INPUT);
  pinMode(RES_PIN_1, INPUT);

  Wire.begin(SLAVE_ADDRESS);
  Wire.onRequest(sendData);

  Serial.begin(9600);
}

void loop() {
#ifdef DEBUG
  double r0 = readResistance(RES_PIN_0);
  double r1 = readResistance(RES_PIN_1);

  Serial.print("R0 : ");
  Serial.print(r0);
  Serial.print(getColor(r0) == RED ? " (RED)" : getColor(r0) == PURPLE ? " (PURPLE)" : getColor(r0) == YELLOW ? " (YELLOW)" : " (NONE)");
  Serial.print("\tR1 : ");
  Serial.print(r1); 
  Serial.println(getColor(r1) == RED ? " (RED)" : getColor(r1) == PURPLE ? " (PURPLE)" : getColor(r1) == YELLOW ? " (YELLOW)" : " (NONE)");

  
#endif
}

long readResistance(int pin) {
  unsigned long resistor = 0;

  double Vres = 0;
  for (int i = 0; i < NB_MES; i++) {
    Vres = analogRead(pin) * Vcc / 1023;
    resistor += Vres * R1 / (Vcc - Vres);
  }
  return resistor / NB_MES;
}

void sendData()
{
  double r0 = readResistance(RES_PIN_0);
  double r1 = readResistance(RES_PIN_1);

  uint8_t color1 = getColor(r0);
  uint8_t color2 = getColor(r1);

  Wire.write(START_BYTE);
  Wire.write(color1);
  Wire.write(color2);
  Wire.write(END_BYTE);
}

uint8_t getColor(double res) {
  if (res > 400 && res < 600) { // 470 Ohms
    return PURPLE;
  } else if (res > 800 && res < 1200) { // 1k Ohms
    return YELLOW;
  } else if(res > 4000 && res < 6000) {
    return RED;
  } else{
    return NONE;
  }
}
