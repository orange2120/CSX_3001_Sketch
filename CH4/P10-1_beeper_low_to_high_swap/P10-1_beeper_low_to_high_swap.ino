/*
*P10-1
*設計Arduino程式，輸出由低至高的警車聲音
*/

const int speaker_pin = 6;

void setup()
{
	pinMode(speaker_pin, OUTPUT);
}

void loop()
{
	for(int i=500;i<=1000;i+=10)
	{
		tone(speaker_pin, i);
		delay(20);
	}
	
	noTone(speaker_pin);
	delay(2000); //2秒之後重新開始
}