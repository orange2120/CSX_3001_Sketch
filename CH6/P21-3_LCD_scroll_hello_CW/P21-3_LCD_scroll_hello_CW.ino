/*
*P21-3
*控制LCD顯示”hello!”，讓其可以呈口字型移動
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

#define SHIFT_INTERVAL 400 //ms，字串shift的間隔

void setup()
{
	lcd.begin(16,2);
	lcd.setCursor(0,0);
	lcd.print("Hello!");
}

void loop()
{
	for(int i=0;i<=10;i++)
	{
		lcd.setCursor(i,0);
		lcd.print("Hello!");
		delay(SHIFT_INTERVAL);
		lcd.clear();
	}
	for(int i=10;i>=0;i--)
	{
		lcd.setCursor(i,1);
		lcd.print("Hello!");
		delay(SHIFT_INTERVAL);
		lcd.clear();
	}
}