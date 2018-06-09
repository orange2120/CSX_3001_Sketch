/*
*P37-2
*設計Arduino 程式，配合移動偵測器設計自動小夜燈，
*當晚上有人靠近時，點亮LED 20秒後關閉，當無人靠近時，關閉LED。
*/

const uint8_t led = 13;
const uint8_t PIRout = 2;

bool val = 0; //PIR sensor state

void setup()
{
	pinMode(led, OUTPUT);
	pinMode(PIRout, INPUT);
}

void loop()
{
	val = digitalRead(PIRout);
	
	if(val)
	{
		digitalWrite(led, HIGH);
		delay(20000); //延遲20秒，不接受其他指令
		digitalWrite(led, LOW);
	}
	else digitalWrite(led, LOW);
}
