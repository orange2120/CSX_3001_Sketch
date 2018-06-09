/*
*P46-1
*設計Arduino 程式，在第0 行、第0 列顯示"2013 年08 月05 日"，
*在第0 行第1 列顯示"I♥LCD"，愛心符號如圖10-16 所示。
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

byte yearChar[8] = {0x10,0x1F,0x02,0x0F,0x0A,0x1F,0x02,0x00};
byte moonChar[8] = {0x0F,0x09,0x0F,0x09,0x0F,0x09,0x1D,0x00};
byte dayChar[8] =  {0x0F,0x09,0x09,0x0F,0x09,0x09,0x0F,0x00};
byte loveChar[8] = {0x00,0x0A,0x1F,0x1F,0x0E,0x04,0x00,0x00};

int years = 2013;
byte moons = 8;
byte days = 5;

void setup()
{
	lcd.begin(16,2);

	lcd.createChar(0, yearChar);
	lcd.createChar(1, moonChar);
	lcd.createChar(2, dayChar);
	lcd.createChar(3, loveChar);
	
	lcd.setCursor(0,0);
	lcd.print(years);
	lcd.write(byte(0));
	lcd.print(moons);
	lcd.write(byte(1));
	lcd.print(days);
	lcd.write(byte(2));
	
	lcd.setCursor(0,1);
	lcd.print('I');
	lcd.write(byte(3));
	lcd.print("LCD");
}

void loop()
{
}
