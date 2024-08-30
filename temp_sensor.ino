/*
#include "max6675.h"
#include "AK09918.h"
#include <Wire.h>

AK09918_err_type_t err;
int32_t x, y, z;
AK09918 ak09918;
int thermoDO = 4;
int thermoCS = 5;
int thermoCLK = 6;
int i = 0;
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

void setup() {
  Serial.begin(9600);
   
  Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  delay(500);
 Wire.begin();

   
    }



void loop() {
  // basic readout test, just print the current temp
  
  Serial.print("C = "); 
  Serial.println(thermocouple.readCelsius());
  Serial.print("F = ");
  Serial.println(thermocouple.readFahrenheit());
  delay(1000); 
}

*/ 


