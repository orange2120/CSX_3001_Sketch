/*
*P41-2
*設計Arduino 程式，控制四個LED 變化如圖4-9 所示。
*/

#define SHIFT_INTERVAL 200 //ms

const int led[4] = {10,11,12,13};



void setup()
{
	pinMode(led[0], OUTPUT);
	pinMode(led[1], OUTPUT);
	pinMode(led[2], OUTPUT);
	pinMode(led[3], OUTPUT);
	
	digitalWrite(led[0], LOW);
	digitalWrite(led[1], LOW);
	digitalWrite(led[2], LOW);
	digitalWrite(led[3], LOW);
}

void loop()
{
	for(int i=0;i<=3;i++)
	{
		digitalWrite(led[i], HIGH);
		delay(SHIFT_INTERVAL);
	}
	for(int i=0;i<=3;i++)
	{
		digitalWrite(led[i], LOW);
		delay(SHIFT_INTERVAL);
	}
}
