#ifndef _temp_sensor_h
#define _temp_sensor_h

#include "arduino.h"
#include <Wire.h>

class TempSensor {
 protected:
  uint8_t m_addr;
  uint8_t m_verbose;
  
  TempSensor() { m_addr = 0; m_verbose = 0;};
  TempSensor(uint8_t addr) { m_addr = addr;};
  bool reg_write( uint8_t reg_addr, uint8_t value );
  bool reg_write( uint8_t reg_addr, uint8_t *buf, uint8_t buf_len);
  bool reg_read( uint8_t reg_addr, uint8_t *buf, uint8_t buf_len);
  
 public:

  enum Capability {
    C_Temp 	= (1 << 0),
    C_Humidity 	= (1 << 1),
    C_LED 	= (1 << 2),
  };

  virtual bool begin(void)  {return false;}
  virtual bool getTemperature(float *pTemp) {return false;}
  virtual bool getHumidity(float *pHumidity) {return false;}
  virtual bool led(bool on) {return false;}
  virtual uint32_t getCapability(void) {return 0;}
  void setAddr(uint8_t addr) {m_addr = addr;}
  void setVerbose(uint8_t v) {m_verbose = v;}
};


#endif /* _temp_sensor_h */


