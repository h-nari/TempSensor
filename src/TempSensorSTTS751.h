#ifndef _temp_sensor_stts751_h_
#define _temp_sensor_stts751_h_

#include "TempSensor.h"

class TempSensorSTTS751 : public TempSensor {
 public:
  TempSensorSTTS751();
  TempSensorSTTS751(uint8_t addr);
  ~TempSensorSTTS751();
  bool begin(void);
  bool getTemperature(float *pTemp);
};

#endif /* _temp_sensor_stts751_h */


