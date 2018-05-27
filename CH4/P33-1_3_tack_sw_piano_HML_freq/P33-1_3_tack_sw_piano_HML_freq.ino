/*
*P33-1
*使用七個按鍵開關實作一電子琴
*有C、D、E、F、G、A、B七個音階
*並利用另外三個按鍵開關，切換成 低/中/高音模式
*/

#define PLAY_INTERVAL 100 //ms，持續播放音符的時間

const int speaker_pin = 11;
const int freq_sw_pin[] = {9, 10, 12}; //Frequency change switch
const int sw_pin[] = {2, 3, 4, 5, 6, 7, 8};
const int tones[3][7] = {
{262, 294, 330, 349, 392, 440, 494}, //Low freq
{523, 587, 659, 698, 784, 880, 988}, //Medium freq
{1046, 1175, 1318, 1397, 1568, 1760, 1976} //High freq
};
                   
int freq_index = 0; //0=Low freq,1=Medium freq,2=High freq

void setup()
{
	pinMode(speaker_pin, OUTPUT);
	
	for(int i=0;i<sizeof(sw_pin)/sizeof(int);i++)
	{
		pinMode(sw_pin[i], INPUT_PULLUP);
	}
	for(int i=0;i<sizeof(freq_sw_pin)/sizeof(int);i++)
	{
		pinMode(freq_sw_pin[i], INPUT_PULLUP);
	}
}

void loop()
{
	if(digitalRead(freq_sw_pin[0])==0)
	{
		delay(20); //debounce
		while(digitalRead(freq_sw_pin[0])==0);
		freq_index = 0;
	}
	else if(digitalRead(freq_sw_pin[1])==0)
	{
		delay(20); //debounce
		while(digitalRead(freq_sw_pin[1])==0);
		freq_index = 1;
	}
	else if(digitalRead(freq_sw_pin[2])==0)
	{
		delay(20); //debounce
		while(digitalRead(freq_sw_pin[2])==0);
		freq_index = 2;
	}
	
	for(int i=0;i<7;i++)
	{
		bool val = digitalRead(sw_pin[i]);
		if(!val)
		{
			tone(speaker_pin, tones[freq_index][i], PLAY_INTERVAL);
		}
	}
}