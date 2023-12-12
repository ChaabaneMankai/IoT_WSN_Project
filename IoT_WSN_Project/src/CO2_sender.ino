#include "LoRaRadio.h"
#include <SPI.h>
#include <STM32L0.h>
#include <MQUnifiedsensor.h>
#define TEMPO 1800 // 30 minutes = 1800 seconds.

unsigned long DUREE_ECOULEE, TOP_CHRONO;
const int AOUTpin = 0;
int value;
int seuil = 0; 
String trame = "";
int g = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial) { }
  LoRaRadio.begin( v;
  LoRaRadio.setFrequency(868100000);
  LoRaRadio.setTxPower(14);
  LoRaRadio.setBandwidth(LoRaRadio.BW_125);
  LoRaRadio.setSpreadingFactor(LoRaRadio.SF_7);
  LoRaRadio.setCodingRate(LoRaRadio.CR_4_5);
  LoRaRadio.setLnaBoost(true);
  pinMode(AOUTpin, INPUT);
  TOP_CHRONO = millis() / 1000;
}

void loop()
{
  //Read analog value of gaz sensor:
  value = analogRead(AOUTpin);
  Serial.println(value);
  //Check the behavior of the MQ5 sensor:
  if ( value >= seuil ) {
    g = 1;
  }
  else {
    g = 0;
  }
  DUREE_ECOULEE = (millis() / 1000) - TOP_CHRONO;
  //Send gaz value when it surpasses the threshold:
  if (g == 1) {
    Serial.print("CO value: ");
    Serial.println(value);//prints the CO value*/
    LoRaRadio.beginPacket();
    trame = ("2:" + String(value));
    LoRaRadio.print(trame);
    LoRaRadio.endPacket();
    delay(2000);
  }
  delay(1000);
}