#include "TempSensorADT7410.h"


TempSensorADT7410::TempSensorADT7410() : TempSensor(){};
TempSensorADT7410::~TempSensorADT7410() {};

TempSensorADT7410::TempSensorADT7410(uint8_t addr) : TempSensor(addr) {};

bool TempSensorADT7410::begin(void)
{
  // return reg_write(3, 0xc0);		// 16bit resolution, 1 SPS
  return reg_write(3, 0x80);		// 16bit resolution, continuous
}

bool TempSensorADT7410::getTemperature(float *pTemp)
{
  uint8_t d[2],high, low;
  float t;
  
  if(!reg_read(0, d, 2)) return false;
  high = d[0];
  low  = d[1];
  
  t = ((high << 8) | low) / 128.0;
  if(pTemp) *pTemp = t;
  return true;
}

bool TempSensorADT7410::led(bool on)
{
  uint8_t buf[2];
  
  if(on) {
    buf[0] = 0xff;
    buf[1] = 0xff;
  } else {
    buf[0] = 0x80;
    buf[1] = 0x00;
  }

  return reg_write(0x08, buf, sizeof buf);
}

uint32_t TempSensorADT7410::getCapability(void)
{
  return C_Temp | C_LED;
}


