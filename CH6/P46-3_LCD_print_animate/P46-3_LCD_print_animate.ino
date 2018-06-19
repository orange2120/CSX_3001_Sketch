/*
*P46-3
*試著輸出前二頁的字元動畫。
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

byte sp[][8] = {
{B00100, B01110, B11111, B10101, B11111, B01110, B01010, B10001},
{B00100, B01110, B11111, B11010, B11111, B00100, B01010, B01010},
{B00100, B01110, B11111, B11110, B11111, B01110, B00100, B00100},
{B00100, B01110, B11111, B11111, B11111, B00100, B01010, B01010},
{B00100, B01110, B11111, B01111, B11111, B01110, B00100, B00100},
{B00100, B01110, B11111, B01101, B11111, B00100, B01010, B01010}
};
void setup()

{
	lcd.begin(16,2);
	
	for(int i=0;i<6;i++) lcd.createChar(i, sp[i]);
	lcd.setCursor(0,0);
}

void loop()
{
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<16;j++)
		{
			lcd.setCursor(j,0);
			lcd.write(byte(i));
		}	
		delay(500);
	}
}
