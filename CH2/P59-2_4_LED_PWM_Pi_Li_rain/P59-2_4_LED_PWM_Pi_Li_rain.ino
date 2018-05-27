/*
*P59-2
*設計Arduino 程式，控制四個LED 模擬拖尾霹靂燈變化。
*/

const uint8_t led[4] = {6,9,10,11};
//                                                    最左      最右
const uint8_t brightness[7][4] =
{
	{250,0,0,0},
	{100,250,0,0},
	{50,100,250,0},
	{5,50,100,250},
	{0,5,50,100},
	{0,0,5,50},
	{0,0,0,5},
}; //定義亮度，共7種LED的state

int i = 0;   //Current LED state index
int dir = 1; //1右，-1向左

void setup()
{

}

void loop()
{
	
	for(int k=0;k<7;k++) //向右
	{
		for(int j=0;j<4;j++) //LED index
		{
			analogWrite(led[j], brightness[k][j]);
			delay(50);
		}
		
	}
	for(int j=0;j<4;j++) //LED index
	{
		analogWrite(led[j], 0);
	}
	delay(200);
	
	for(int k=0;k<7;k++) //向左
	{
		for(int j=0;j<=3;j++) //LED index
		{
			analogWrite(led[j], brightness[k][3-j]);
			delay(50);
		}
		
	}
	for(int j=0;j<4;j++) //LED index
	{
		analogWrite(led[j], 0);
	}
	delay(200);
}