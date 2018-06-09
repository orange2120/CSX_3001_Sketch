/*
*P58-2
*設計Arduino 程式，使用Arduino 板配合LM35 溫度感測器測量環境溫度，
*以Serial Monitor 視窗顯示環境溫度，當環境溫度大於30°C時，點亮紅色LED；
*當環境溫度介於20°C~30°C時，點亮黃色LED；
*當環境溫度小於20°C時，點亮綠色LED。
*/

#define SEND_INTERVAL 500 //ms，interval between sending serial data

const byte lm35_pin = A0;

const uint8_t led_R = 13; //Red LED
const uint8_t led_Y = 12; //Yellow LED
const uint8_t led_G = 11; //Green LED

uint32_t last_send = 0;

long temperature = 0;

void setup()
{
	Serial.begin(9600);
	
	pinMode(led_R, OUTPUT);
	pinMode(led_Y, OUTPUT);
	pinMode(led_G, OUTPUT);
	
	digitalWrite(led_R, LOW);
	digitalWrite(led_G, LOW);
	digitalWrite(led_Y, LOW);
}

void loop()
{
	uint32_t now = millis();
	
	temperature = get_temp(lm35_pin);
	
	if(now-last_send >= SEND_INTERVAL)
	{
		Serial.print(temperature);
		Serial.println(" degC");
		last_send = now;
	}
	
	if(temperature > 30)
	{
		digitalWrite(led_R, HIGH);
		digitalWrite(led_G, LOW);
		digitalWrite(led_Y, LOW);
	}
	else if(temperature > 20 && temperature <= 30)
	{
		digitalWrite(led_R, LOW);
		digitalWrite(led_G, LOW);
		digitalWrite(led_Y, HIGH);
	}
	else
	{
		digitalWrite(led_R, LOW);
		digitalWrite(led_G, HIGH);
		digitalWrite(led_Y, LOW);
	}
}

long get_temp(byte pin)
{
	int val;
	val = analogRead(pin);
	return (long)val*500/1024;
}