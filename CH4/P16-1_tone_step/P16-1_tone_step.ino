/*
*P16-1
*設計Arduino 程式，依序播放低音階C、B、A、G、F、E、D 及中音階C等8個音符。
*/

const int tones[] = {262, 294, 330, 349, 392, 440, 494, 523};
                   //c    d    e    f    g    a    b    C

const int speaker_pin = 6;
const int freq = 500; //Hz

void setup()
{
	pinMode(speaker_pin, OUTPUT);
}

void loop()
{
	for(int i=0;i<sizeof(tones)/sizeof(int);i++)
	{
		tone(speaker_pin, tones[i]);
		delay(500);
	}
	noTone(speaker_pin);
	delay(2000);
}
