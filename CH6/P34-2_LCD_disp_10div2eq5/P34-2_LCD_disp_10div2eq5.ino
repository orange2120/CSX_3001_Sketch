/*
*P34-2
*設計Arduino 程式，控制LCD 顯示"10÷2=5"。
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

#define DIV_SYM B11111101 //Divide symbol

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

void setup()
{
	lcd.begin(16,2);
	lcd.setCursor(0,0);
	lcd.print("10");
	lcd.write(DIV_SYM);
	lcd.print("2=5");
}

void loop()
{
}