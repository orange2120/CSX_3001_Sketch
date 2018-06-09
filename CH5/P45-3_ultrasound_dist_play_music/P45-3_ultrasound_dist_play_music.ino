/*
*P45-3
*測距離音樂盒 - 請用超音波距離感測器，測量物體的距離
*1~5cm 播放小蜜蜂
*5~10cm 播放小星星
*超過10cm 播放其它任何你喜歡的曲目
*/

#define TRIG_PIN 2
#define ECHO_PIN 3

const int speaker_pin = 11;
const char toneName[] = "CDEFGA";
const int tones[] = {262, 294, 330, 349, 392, 440};
                   //c    d    e    f    g    a
char starTone[] = "CCGGAAGFFEEDDCGGFFEEDGGFFEEDCCGGAAGFFEEDDC";
uint8_t starBeat[] = {1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2};

char beeTone[] = "GEEFDDCDEFGGGGEEFDDCEGGEDDDDDEFEEEEEFGGEEFDDCEGGC";
uint8_t beeBeat[] = {1,1,2,1,1,2,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1,1,2};

int music_index = 0; //0=mute(default), 1=Little Bee,2=Little Star,3=?
int last_music_index = 0; //Record last played music index

int remain_beats = 0;
int beats_num = 0;
unsigned long tempo = 180; //beats per minute

void setup()
{
	pinMode(speaker_pin, OUTPUT);
	pinMode(TRIG_PIN, OUTPUT);
	pinMode(ECHO_PIN, INPUT);
}

void loop()
{
	unsigned long now = millis();
	long dist = ping();
	
	if(dist >= 1 && dist <= 5)
	{
		music_index = 1;
		remain_beats = sizeof(beeTone);
	}
	else if(dist >5 && dist <= 10)
	{
		music_index = 2;
		remain_beats = sizeof(starTone);
	}
	else if(dist > 10)
	{
		music_index = 3;
	}
	else
	{
		remain_beats = 0;
	}
	
	if(music_index != last_music_index)
	{
		beats_num = 0;
		last_music_index = music_index;
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
	else noTone(speaker_pin);
}

long ping(void)
{
	digitalWrite(TRIG_PIN, LOW);
	delayMicroseconds(2);
	digitalWrite(TRIG_PIN ,HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG_PIN, LOW);
	return pulseIn(ECHO_PIN, HIGH)/58;
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