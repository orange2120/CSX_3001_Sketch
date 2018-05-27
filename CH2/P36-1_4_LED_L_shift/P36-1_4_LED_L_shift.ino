/*
*P36-1
*設計Arduino 程式，控制四個LED 單燈左移。
*/

const int led_1 = 10; //最左
const int led_2 = 11;
const int led_3 = 12;
const int led_4 = 13; //最右

void setup()
{
	pinMode(led_1, OUTPUT);
	pinMode(led_2, OUTPUT);
	pinMode(led_3, OUTPUT);
	pinMode(led_4, OUTPUT);
	
	digitalWrite(led_1, LOW);
	digitalWrite(led_2, LOW);
	digitalWrite(led_3, LOW);
	digitalWrite(led_4, LOW);
}

void loop() //每隔500ms左移一個LED，至最左邊則重新開始
{
	digitalWrite(led_1, LOW);
	digitalWrite(led_4, HIGH);
	delay(500);
	digitalWrite(led_4, LOW);
	digitalWrite(led_3, HIGH);
	delay(500);
	digitalWrite(led_3, LOW);
	digitalWrite(led_2, HIGH);
	delay(500);
	digitalWrite(led_2, LOW);
	digitalWrite(led_1, HIGH);
	delay(500);
}