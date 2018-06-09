/*
*P37-2
*設計Arduino 程式，在第0 行、第0 列顯示字元"up counter"，
*在第0 行、第1 列顯示0000~9999 計數值，每秒上數加1。
*/

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

int n = 0; //Current counter value

void setup()
{
	lcd.begin(16,2);
	lcd.setCursor(0,0);
	lcd.print("up counter");
	lcd.setCursor(0,1);
}

void loop()
{
	if(n > 9999) n = 0;
	int tmp = n;
	for(int i=3;i>=0;i--)
	{	
		lcd.setCursor(i,1);
		lcd.print(tmp%10);
		tmp /= 10;
	}
	n++;
	delay(1000);
}