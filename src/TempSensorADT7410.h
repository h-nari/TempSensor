#ifndef _temp_sensor_adt7410_h_
#define _temp_sensor_adt7410_h_

#include "TempSensor.h"

class TempSensorADT7410 : public TempSensor {
 public:
  TempSensorADT7410();
  TempSensorADT7410(uint8_t addr);
  ~TempSensorADT7410();
  bool begin(void) override;
  bool getTemperature(float *pTemp) override;
  bool led(bool on) override;
  uint32_t getCapability(void) override;
};

#endif /* _temp_sensor_adt7410_h_ */


