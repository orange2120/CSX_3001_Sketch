/*
*P49-2
*設計Arduino 程式，控制兩個LED 輪流由最暗變化至最亮，再由最亮變化至最暗。
*/

const uint8_t led1 = 10;
const uint8_t led2 = 11;

void setup()
{
}

void loop()
{
	for(int i=0;i<=255;i++)
	{
		analogWrite(led1, i);
		delay(10);
	}
	for(int i=255;i>=0;i--)
	{
		analogWrite(led1, i);
		delay(10);
	}
	
	for(int i=0;i<=255;i++)
	{
		analogWrite(led2, i);
		delay(10);
	}
	for(int i=255;i>=0;i--)
	{
		analogWrite(led2, i);
		delay(10);
	}
}
