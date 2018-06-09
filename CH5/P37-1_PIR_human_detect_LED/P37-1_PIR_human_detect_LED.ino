/*
*P37-1
*設計Arduino 程式，使用Arduino 板配合移動偵測器偵測人或動物的移動，
*當有人靠近時，點亮LED，當無人靠近時，關閉LED。
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
	
	if(val) digitalWrite(led, HIGH);
	else digitalWrite(led, LOW);
}
