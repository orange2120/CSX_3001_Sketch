/*
*P54-1
*設計 Arduino 程式,控制四個 LED 亮度變化並依序左移。每一個 LED 亮度由暗逐漸
變亮,再由亮逐漸變暗。
*/


const uint8_t  led[4] = {6,9,10,11};
//                                                        最左      最右

void setup()
{
	
}

void loop()
{
	for(int i=3;i>=0;i--) //向左移
	{
		for(int j=0;j<=255;j++) //漸亮
		{
			analogWrite(led[i], j);
			delay(5); //ms
		}
		for(int j=255;j>=0;j--) //漸暗
		{
			analogWrite(led[i], j);
			delay(5); //ms
		}
	}
}
