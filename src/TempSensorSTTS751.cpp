#include "TempSensorSTTS751.h"


TempSensorSTTS751::TempSensorSTTS751() : TempSensor(){};
TempSensorSTTS751::~TempSensorSTTS751() {};

TempSensorSTTS751::TempSensorSTTS751(uint8_t addr) : TempSensor(addr) {};

bool TempSensorSTTS751::begin(void)
{
  return reg_write(3, 0x0c);		// 12bit resolution
}

bool TempSensorSTTS751::getTemperature(float *pTemp)
{
  uint8_t high, low;
  float t;
  
  if(!reg_read(0, &high, 1)) return false;
  if(!reg_read(2, &low,  1))  return false;

  t = high + low / 256.0;
  if(pTemp) *pTemp = t;
  return true;
}
