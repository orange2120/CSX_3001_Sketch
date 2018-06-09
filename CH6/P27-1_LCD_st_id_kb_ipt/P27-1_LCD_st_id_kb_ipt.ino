/*
*P27-1
*設計Arduino程式，控制LCD在第0列顯示學號"0123456789"，
*在第1列閃爍顯示電腦鍵盤輸入字元，按減號""鍵可以清除輸入字元。
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

#define BLINK_SPEED 250 //ms,blink speed of input character 

#define LCD_ROW 16
#define LCD_COL 2

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

char buf[20]; //Character buffer array
int num = 0;

uint32_t last_blink = 0;
bool blink_state = 0;

void setup()
{
	Serial.begin(9600);

	lcd.begin(LCD_ROW,LCD_COL);
	lcd.setCursor(0,0);
	lcd.print("0123456789");
	
	for(int i=0;i<sizeof(buf);i++) buf[i] = ' ';
}

void loop()
{
	uint32_t now = millis(); 

	if(Serial.available())
	{
		buf[num] = Serial.read();
		if(buf[num] == '-')
		{
			lcd.setCursor(0,1);
			for(int i=0;i<LCD_ROW;i++)
			{
				lcd.write(' ');
				buf[i] = ' ';
			}
			lcd.setCursor(0,1);
			num = 0;
		}
		else
		{	
			lcd.write(buf[num]);
			num++;
			if(num > 15)
			{	
				lcd.setCursor(0,1);
				num = 0;
			}
		}
	}
	if(now-last_blink >= BLINK_SPEED) //字串閃爍
	{
		lcd.setCursor(0,1);
		if(blink_state)
		{
			for(int i=0;i<LCD_ROW;i++)
			{
				lcd.write(buf[i]);
			}
		}
		else
		{	for(int i=0;i<LCD_ROW;i++)
			{
				lcd.write(' ');
			}
		}
		blink_state = !blink_state;
		last_blink = now;
	}
}
