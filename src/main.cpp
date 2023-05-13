#include <Arduino.h>

unsigned long time_now = 0;

void setup() {
  /* Define DAC output pins*/
  #define DAC_CH1 25
  #define DAC_CH2 26

  /* Initialize the Serial com*/
  Serial.begin(115200);
}


void dacBenchmark() {

  if(millis() == time_now + 1000) {
    dacWrite(DAC_CH1, 0);
    Serial.println("DAC Value 0");
  }

  if(millis() == time_now + 2000){
    dacWrite(DAC_CH1, 64);
    Serial.println("DAC Value 64");
  }

  if(millis() == time_now + 3000){
    dacWrite(DAC_CH1, 128);
    Serial.println("DAC Value 128");
  }

  if(millis() == time_now + 4000){
    dacWrite(DAC_CH1, 192);
    Serial.println("DAC Value 192");
  }
 
  if(millis() == time_now + 5000){
    time_now += 5000;
    dacWrite(DAC_CH1, 255);
    Serial.println("DAC Value 255");
  }

}

void loop() {
  dacBenchmark();
}

