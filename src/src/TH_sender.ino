#include <LoRaRadio.h>
#include <STM32L0.h>
#include <SPI.h>
#include <DHT.h>
#define TEMPO 1800 // 30 minutes = 1800 secondes 
#define DHTPIN 8
#define DHTTYPE DHT22   // DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino
float hum;  //Stores humidity value
float temp; //Stores temperature value
String trame="";
float max_temp= 0;
float max_hum=0; //define max for hum & temp 
int buzzer=9;      
unsigned long DUREE_ECOULEE, TOP_CHRONO; // Start

void setup() {
   Serial.begin(9600);
    dht.begin();  
    Serial.println("Hello");
    LoRaRadio.begin(868100000);
    LoRaRadio.setFrequency(868100000);
    LoRaRadio.setTxPower(14);
    LoRaRadio.setBandwidth(LoRaRadio.BW_125);
    LoRaRadio.setSpreadingFactor(LoRaRadio.SF_7);
    LoRaRadio.setCodingRate(LoRaRadio.CR_4_5);
    LoRaRadio.setLnaBoost(true);
    TOP_CHRONO = millis()/1000; // calculating time
    pinMode(buzzer, OUTPUT); 
}
 
void loop() {
  DUREE_ECOULEE = (millis()/1000) - TOP_CHRONO; // Calculating passed time
  hum = dht.readHumidity();
  temp= dht.readTemperature();
  Serial.println(hum);
  Serial.println(temp);
  if (temp>max_temp||hum>max_hum){
    trame = ("1:" + String(temp)+ ","+ String(hum));
     LoRaRadio.beginPacket();
     LoRaRadio.print(trame);
     LoRaRadio.endPacket(); 
     delay(2000);
  }  
  if (DUREE_ECOULEE >= TEMPO) 
  { 
   trame = ("1:15,15");//or 105:5:15 depending on the PIR-STM32 receiver
   LoRaRadio.beginPacket();
   LoRaRadio.print(trame);
   LoRaRadio.endPacket();    
   TOP_CHRONO = millis()/1000; 
  }
 delay(2000);
}