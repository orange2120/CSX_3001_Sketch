/*
*P10-2
*設計Arduino程式，輸出嗶!嗶!嗶!警報聲音。
*/

const int speaker_pin = 6;
const int freq = 500; //Hz

void setup()
{
	pinMode(speaker_pin, OUTPUT);
}

void loop()
{
	tone(speaker_pin, freq);
	delay(200);
	noTone(speaker_pin);
	delay(200);
}