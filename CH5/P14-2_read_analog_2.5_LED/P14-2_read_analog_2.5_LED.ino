/*
*P14-2
*設計Arduino 程式，使用Arduino 板讀取類比電壓值，並顯示於Serial Monitor 視窗。
*當類比電壓大於2.5V 則LED 亮，否則LED 不亮。
*/

const byte input = A0;
const int led = 13;

int val = 0;

void setup()
{
	Serial.begin(9600);
	
	pinMode(led, OUTPUT);
}

void loop()
{
	val = analogRead(input);
	if(val >=512)
	{
		digitalWrite(led, HIGH);
	}
	else
	{
		digitalWrite(led, LOW);
	}
	Serial.println(val*5.0/1023.0, 2);
}	
