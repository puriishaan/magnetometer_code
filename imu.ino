#include "max6675.h"
#include "AK09918.h"
#include <Wire.h>

AK09918_err_type_t err;
int32_t x, y, z;
AK09918 ak09918;
int i = 0;
int n = 3; // Define how many serial prints you want before exporting

void setup() {
  Serial.begin(9600);
  delay(500);
  Wire.begin();

  err = ak09918.initialize();
  ak09918.switchMode(AK09918_POWER_DOWN);
  ak09918.switchMode(AK09918_CONTINUOUS_100HZ);
  Serial.begin(9600);

  err = ak09918.isDataReady();
  while (err != AK09918_ERR_OK) {
    Serial.println("Waiting Sensor");
    delay(1000);
    err = ak09918.isDataReady();
  }
}

void loop() {
  err = ak09918.isDataReady();
  if (err == AK09918_ERR_OK) {
    err = ak09918.isDataSkip();
    err = ak09918.getData(&x, &y, &z);
    if (err == AK09918_ERR_OK) {
      Serial.print("{\"i\": ");
      Serial.print(i);
      Serial.print(", \"X\": ");
      Serial.print(x);
      Serial.print(", \"Y\": ");
      Serial.print(y);
      Serial.print(", \"Z\": ");
      Serial.print(z);
      Serial.println("}");

      i++;
    }
  }

  // Check if the desired number of readings is reached
  if (i >= n) {
    // Stop the loop to finalize data capture
    while (true) {
      delay(1000);
    }
  }

  delay(1000); // Wait before the next reading
}

