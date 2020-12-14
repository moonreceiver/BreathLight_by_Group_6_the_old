#ifndef Breath_h
#define Breath_h

#include <Arduino.h>
#include "DHT.h"
#include <math.h>

#define ON true
#define OFF false
#define DHTPIN 2
#define DHTTYPE DHT11

class Breath
{
	public:
	Breath(int pin);//通过pin指定pinMode的第一个参数，使用时可令其为3。
	void breath(bool value);//使用此方法对应的模式，当前亮度的维持时间为8毫秒。
	void breath(bool value, int breathLength);//使用此方法对应的模式，用户可通过breathLength参数指定当前亮度的维持时间。
	void breathBYtemperature(bool value);//呼吸频率随外部温度变化，温度越高，频率越高，使用时需在引脚2接入DHT11温湿度传感器。
	void temperatureSetup(int Beg);//Beg为波特率。
	private:
	uint8_t pinNumber;
};

#endif