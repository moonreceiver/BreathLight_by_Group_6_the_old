/*
基础的呼吸灯，当前亮度的维持时间为8毫秒,可以在breath方法的括号中添加第二个参数以改变当前亮度的维持时间。
*/
#include <Breath.h>

Breath pin(3);

void setup() {

}

// the loop function runs over and over again forever
void loop() {
	pin.breath(ON);
}