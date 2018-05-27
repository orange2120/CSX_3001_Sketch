/*
*P59-1
*設計Arduino 程式，利用Arduino 板PWM 信號輸出接腳3、9、10、11 控制四個LED產生左移雨滴變化。
*/

const uint8_t  led[4] = {6,9,10,11};
//                                                    最左      最右
const uint8_t brightness[7][4] =
{
	{250,0,0,0},    //第一組亮度
	{100,250,0,0},  //第二組亮度，以此類推
	{50,100,250,0},
	{5,50,100,250},
	{0,5,50,100},
	{0,0,5,50},
	{0,0,0,5},
}; //定義亮度


void setup()
{
	
}

void loop()
{
	for(int i=0;i<7;i++) //brightness index
	{
		for(int j=0;j<4;j++) //LED index
		{
			analogWrite(led[j], brightness[i][j]);
			delay(50);
		}
	}
}
