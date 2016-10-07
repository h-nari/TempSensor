#include "TempSensor.h"

bool TempSensor::reg_write( uint8_t reg_addr, uint8_t value )
{
  reg_write(reg_addr, &value, 1);
}

bool TempSensor::reg_write( uint8_t reg_addr, uint8_t *buf, uint8_t buf_len)
{
  Wire.beginTransmission(m_addr);
  Wire.write(reg_addr);
  for(int i=0; i<buf_len; i++)
    Wire.write(buf[i]);
  return Wire.endTransmission() == 0;
}


bool TempSensor::reg_read( uint8_t reg_addr, uint8_t *buf, uint8_t buf_len)
{
  int i = 0;
  Wire.beginTransmission(m_addr);
  Wire.write(reg_addr);
  if(Wire.endTransmission(false) != 0) {
    if(m_verbose) Serial.print(" - tx error - ");
    return false;
  }

  Wire.requestFrom(m_addr, buf_len);
  for(i=0; i<buf_len; i++){
    if(!Wire.available()) {
      if(m_verbose){
	Serial.print(" - rx error i:");
	Serial.print(i);
	Serial.print(" ");
      }
      return false;
    }
    buf[i] = Wire.read();
  }
  return true;
}
