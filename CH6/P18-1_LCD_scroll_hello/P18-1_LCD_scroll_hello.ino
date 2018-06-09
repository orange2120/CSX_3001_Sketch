/*
*P18-1
*使用Arduino 板控制LCD 顯示"hello!"，並且左右來回移動。
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

void setup()
{
	lcd.begin(16,2);
	lcd.SetCursor(0,0);
	lcd.print("Hello!");
}

void loop()
{
	for(int i=0;i<8;i++)
	{
		lcd.scrollDisplayRight();
		delay(200);
	}
	for(int i=0;i<8;i++)
	{
		lcd.scrollDisplayLeft();
		delay(200);
	}
}
