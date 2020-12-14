/*
呼吸频率随温度变化的呼吸灯，温度越高，频率越高，测温范围为0~50摄氏度，使用时需在引脚2接入DHT11传感器。
*/
#include <Breath.h>

Breath pin(3);

void setup() {
	pin.temperatureSetup(9600);//参数为波特率。
}

// the loop function runs over and over again forever
void loop() {
	pin.breathBYtemperature(ON);
}