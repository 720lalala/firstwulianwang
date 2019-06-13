
#define M3 658

//列出全部D调的频率
#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.25
#define SIXTEENTH 0.625

int tune[]=        //根据简谱列出各频率
{
   M3,M3,M3,
};
float durt[]=       //根据简谱列出各节拍
{
  1,1,1,
};
int length;
int tonepin=8;   //得用8号接口


//int buzzer = 8;
int LED = 7; //LED灯接口
int flame_sensor = 4; //火焰传感器数据输入接口
int flame_detected;

void setup()
{
  Serial.begin(9600);
  pinMode(tonepin, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(flame_sensor, INPUT);
  length=sizeof(tune)/sizeof(tune[0]);   //计算长度

}

void loop()
{
  flame_detected = digitalRead(flame_sensor);
  if (flame_detected == 0)
  {
    Serial.println("Flame detected...! take action immediately.");
//    digitalWrite(buzzer, LOW);
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(100);
      for(int x=0;x<length;x++)
  {
    tone(tonepin,tune[x]);
    delay(500*durt[x]);   //这里用来根据节拍调节延时，500这个指数可以自己调整，在该音乐中，我发现用500比较合适。
    noTone(tonepin);
  }
  delay(100);

  }
  else
  {
    Serial.println("No flame detected. stay cool");
    digitalWrite(tonepin, HIGH);
    digitalWrite(LED, LOW);
  }
  delay(1000);
}
