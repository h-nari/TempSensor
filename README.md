# TempSensor

I2c温度センサーインターフェース共通化のための抽象クラス

## 概要

TempSensorは、I2C温度センサーのための抽象クラスです。
多く存在するI2C温度センサーを共通のインターフェースで
使用するため作成しました。実際のI2C温度センサーを使用するには、
このクラスを継承したサブクラスを作成する必要があります。

現在、以下のサブクラスを提供しています。

- TempSensorADT7410 : AnalogDevices社 ADT7410用
- TempSensorSTTS751 : STmicro社 STTS751用

## API

~~~
コンストラクタ
 TempSensor();
 TempSensor(uint8_t addr);   //  i2c アドレス指定付き
~~~
~~~
アドレス指定
setAddr(uint8_t addr);
~~~
~~~
初期化
bool begin(void);                   // 失敗したら false
~~~
~~~
温度取得
bool getTemperature(float *pTemp);  // 取得に失敗したら false
~~~
~~~
湿度取得
bool getHumidity(float *pHumidity); // 取得に失敗したら false
~~~
~~~
LED点灯
bool led(bool on);                  // 失敗したらfalse
~~~
~~~
機能取得
uint32_t getCapability(void);       // enum値 C_Temp, C_Humidity, C_LEDのor値
~~~

## Author

- [h-nari](https://github.com/h-nari "h-nari (Hiroshi Narimatsu)")
