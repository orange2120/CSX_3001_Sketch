/*
*P52-2
*設計Arduino 程式，控制LCD 顯示兩位15×16 數字字形計數00~99，每秒上數加1。
/*

*LiquidCrystal(rs, rw, enable, d4, d5, d6, d7)
	 1              16 
	|________________|
	|      LCD       |
	|________________|
*1 -> Vss(GND)
*2 -> Vdd(5V)
*3 -> Vo(Contrast)
*4 -> RS(Register sel)
*5 -> R/W(LCM)
*6 -> E(LCM enable)
*7~14 -> Data bus(DB0(LSB)~DB7(MSB))
*/
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

byte shape[8][8]={
{B11111,B11111,B11111,B11111,B11111,B11111,B11111,B11111}, //編號0。
{B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000}, //編號1。
{B11111,B11111,B00000,B00000,B00000,B00000,B00000,B00000}, //編號2。
{B00000,B00000,B00000,B00000,B00000,B00000,B11111,B11111}, //編號3。
{B11111,B11111,B00000,B00000,B00000,B00000,B00000,B11111}, //編號4。
{B11111,B00000,B00000,B00000,B00000,B00000,B11111,B11111}, //編號5。
{B11111,B00000,B00000,B00000,B00000,B00000,B00000,B00000}, //編號6。
{B00000,B00000,B00000,B00000,B00000,B00000,B00000,B11111}  //編號7。
};

const char number[10][6]={
{0,2,0,0,3,0},{1,0,1,1,0,1},//15×16數字0、1。
{4,4,0,0,5,5},{2,4,0,3,5,0},//15×16數字2、3。
{0,7,0,6,6,0},{0,4,4,5,5,0},//15×16數字4、5。
{0,4,4,0,5,0},{2,2,0,1,1,0},//15×16數字6、7。
{0,4,0,0,5,0},{0,4,0,5,5,0} //15×16數字8、9。
};

int n = 0; //Current number

void setup()
{
	lcd.begin(16,2);

	for(int i=0;i<8;i++) lcd.createChar(i, shape[i]);
}

void loop()
{
	if(n>99) n = 0;
	int tmp = n;
	
	print_num(tmp%10, 8); //字元處理
	tmp /= 10;
	print_num(tmp%10, 4);
	
	delay(1000);
	n++;
}

void print_num(int val,int pos)
{
	lcd.setCursor(pos, 0);
	for(int i=0;i<=2;i++)
	{
		lcd.write(byte(number[val][i]));
	}
	lcd.setCursor(pos, 1);
	for(int i=3;i<=5;i++)
	{
		lcd.write(byte(number[val][i]));
	}
}