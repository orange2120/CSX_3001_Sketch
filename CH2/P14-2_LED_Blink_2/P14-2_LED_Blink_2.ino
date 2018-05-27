/*
*P14-2
*設計Arduino 程式，控制一個LED 閃爍，0.5 秒亮、0.5 秒暗。
*/

const int led_1 = 13;
const int led_2 = 12;

void setup()
{
	pinMode(led_1, OUTPUT);
	pinMode(led_2, OUTPUT);
	
	digitalWrite(led_1, LOW);
	digitalWrite(led_2, LOW);
}

void loop()
{
	digitalWrite(led_2, LOW);
	digitalWrite(led_1, HIGH);
	delay(500);
	digitalWrite(led_1, LOW);
	digitalWrite(led_2, HIGH);
	delay(500);
}