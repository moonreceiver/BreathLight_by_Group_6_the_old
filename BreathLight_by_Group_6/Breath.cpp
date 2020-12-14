#include <Arduino.h>
#include "DHT.h"
#include <math.h>
#include "Breath.h"

Breath::Breath(int pin){
	pinMode(pin, OUTPUT);
	pinNumber=pin;
}

void Breath::breath(bool value){
	if(value==true){
		for(int a=0;a<=255;a++){
			analogWrite(pinNumber,a);
			delay(8);
		}
		for(int a=255;a>=0;a--){
			analogWrite(pinNumber,a);
			delay(8);
		}
	}
	else{
		analogWrite(pinNumber,0);
	}
}

void Breath::breath(bool value, int breathLength){
	if(value==true){
		for(int a=0;a<=255;a++){
			analogWrite(pinNumber,a);
			delay(breathLength);
		}
		for(int a=255;a>=0;a--){
			analogWrite(pinNumber,a);
			delay(breathLength);
		}
	}
	else{
		analogWrite(pinNumber,0);
	}
}

void Breath::breathBYtemperature(bool value){
	DHT dht(DHTPIN,DHT11);
	if(value==true){
		for(int a=0;a<=255;a++){
			float temperature=dht.readTemperature();
			int b=temperature;
			int c=pow(1.1,50-b);
			analogWrite(pinNumber,a);
			delay(c);
		}
		for(int a=255;a>=0;a--){
			float temperature=dht.readTemperature();
			int b=temperature;
			int c=pow(1.1,50-b);
			analogWrite(pinNumber,a);
			delay(c);
		}
	}
	else{
		analogWrite(pinNumber,0);
	}
}

void Breath::temperatureSetup(int Beg){
	Serial.begin(Beg);
	delay(1000);
}