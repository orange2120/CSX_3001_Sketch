/*
*P32-1
*設計Arduino 程式，使用1 個TACK 按鍵開關SW，控制播放兩首鋼琴入門音樂—小
*蜜蜂（Little Bee及小星星（Little Star，同時使用LED 顯示播放的音符。
*/

const int led[] = {5, 6, 7, 8, 9, 10}; //define LED pins

const int sw_pin = 12; //switch pin
const int speaker_pin = 11;
const char toneName[] = "CDEFGA";
const int tones[] = {262, 294, 330, 349, 392, 440};
                   //c    d    e    f    g    a

char starTone[] = "CCGGAAGFFEEDDCGGFFEEDGGFFEEDCCGGAAGFFEEDDC";
//                                                     |       |        |       |         |      |         |      |         |       |        |
uint8_t starBeat[] = {1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2};
char beeTone[] = "GEEFDDCDEFGGGGEEFDDCEGGEDDDDDEFEEEEEFGGEEFDDCEGGC";
//                                                                         |                           |                |                 |
uint8_t beeBeat[] = {1,1,2,1,1,2,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1,1,2};

int music_index = 0; //0=mute(default), 1=Little Bee,2=Little Star

int remain_beats = 0;
int beats_num = 0;

unsigned long tempo = 180; //beats per minute

void setup()
{
	pinMode(sw_pin, INPUT_PULLUP);
	pinMode(speaker_pin, OUTPUT);
	for(int i=0;i<6;i++) pinMode(led[i], OUTPUT);
}

void loop()
{
	if(digitalRead(sw_pin)==0)
	{
		delay(20); //debounce
		while(digitalRead(sw_pin)==0);
		music_index++;
		if(music_index > 2) music_index = 0;

		set_music(music_index);
	}
	
	if(remain_beats > 0)
	{
		switch(music_index)
		{
			case 1:
				
				playTone(beeTone[beats_num], beeBeat[beats_num]);
				beats_num++;
				remain_beats--;
			break;
			case 2:
				playTone(starTone[beats_num], starBeat[beats_num]);
				beats_num++;
				remain_beats--;
			break;
		}
	}
	else
	{
		set_music(music_index);
	}
}

void set_music(int index)
{
	beats_num = -1;
	switch(index)
		{
			default:
				remain_beats = 0;
			break;
			case 0:
				remain_beats = 0;
			break;
			case 1:
				remain_beats = sizeof(beeTone);
			break;
			case 2:
				remain_beats = sizeof(starTone);
			break;
		}
}

void playTone(char toneNo, uint8_t beatNo)
{
	unsigned long duration=beatNo*60000/tempo;
	for(int j=0;j<=6;j++)
	{
		if(toneNo == toneName[j])
		{
			tone(speaker_pin, tones[j]);
			digitalWrite(led[j], HIGH);
			delay(duration);
		}
		noTone(speaker_pin);
		digitalWrite(led[j], LOW);
	}
}