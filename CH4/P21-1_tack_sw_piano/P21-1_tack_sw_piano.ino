/*
*P21-1
*設計Arduino 程式，模擬8 鍵電子琴功能。使用8個TACK按鍵開關
*來模擬琴鍵低音階C、D、E、F、G、A、B 及中音階C等8個音符。
*/

#define PLAY_INTERVAL 100 //ms，持續播放音符的時間

const int sw_pin[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int tones[] = {262, 294, 330, 349, 392, 440, 494, 523};
                   //c    d    e    f    g    a    b    C

const int speaker_pin = 11;

void setup()
{
	pinMode(speaker_pin, OUTPUT);
	
	for(int i=0;i<sizeof(sw_pin)/sizeof(int);i++)
	{
		pinMode(sw_pin[i], INPUT_PULLUP);
	}
}

void loop()
{
	for(int i=0;i<8;i++)
	{
		bool val = digitalRead(sw_pin[i]);
		if(!val)
		{
			tone(speaker_pin, tones[i], PLAY_INTERVAL);
		}
	}
}