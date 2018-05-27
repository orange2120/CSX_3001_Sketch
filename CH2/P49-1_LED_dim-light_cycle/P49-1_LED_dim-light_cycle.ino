/*
*P49-1
*設計Arduino 程式，控制一個LED 由最暗變化至最亮，再由最亮變化至最暗。
*/

const uint8_t led = 11; //LED位於Pin 11

void setup()
{

}

void loop()
{
	for(int i=0;i<=255;i++)
	{
		analogWrite(led, i); //使用PWM功能
		delay(20);
	}
	for(int i=255;i>=;i--)
	{
		analogWrite(led, i); //使用PWM功能
		delay(20);
	}
}