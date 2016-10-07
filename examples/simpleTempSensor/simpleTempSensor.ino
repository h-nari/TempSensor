#include <Wire.h>
#include <TempSensor.h>
#include <TempSensorADT7410.h>

TempSensorADT7410 s1(0x48);

void setup()
{
  Serial.begin(19200);
  delay(100);
  Serial.println("\n\nReset:");
  Wire.begin();
  s1.begin();
}

void loop()
{
  float t;
  static int led = 0;
  
  if(s1.getTemperature(&t))
    Serial.println(t);
  else
    Serial.println("-");

  s1.led(led);
  led = !led;
  
  delay(1000);
}
  
