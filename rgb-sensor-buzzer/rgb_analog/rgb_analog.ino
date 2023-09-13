int echoPin= 4;
int trigPin= 3;

int buzzerPin=12;
long duration,distance;
int redPin = A0;
int greenPin = A1;
int bluePin = A2;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin,OUTPUT);
}


void redcolor(){
    setColor(255, 0, 0); // red
  }
  void bluecolor(){
   setColor(0, 0, 255);
  }
    void yellowcolor(){   //yellow
  setColor(255, 255, 0);

  }
  void greencolor(){  //green
 setColor(0, 255, 0); 

  }
  void sondurcolor(){
     setColor(0, 0, 0); 
    }


void loop() {

digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin,LOW);

  duration=pulseIn(echoPin,HIGH);
  distance=(duration/2)/29.1;

  if(distance<=15)
  {
   redcolor();
    tone(buzzerPin,450);
    Serial.println("kırmızı");
  }

 

  else if(distance<=20)
  {
   yellowcolor();
    tone(buzzerPin,350);
    delay(150);

  sondurcolor();
    noTone(buzzerPin);
    delay(150);
         Serial.println("sarı");
  }
  else if(distance<=25)
  {
  greencolor();
    tone(buzzerPin,300);
    delay(200);
     sondurcolor();
    noTone(buzzerPin);
    delay(200);
         Serial.println("yesil");
  }
  else
  {
bluecolor();
    noTone(buzzerPin);
         Serial.println("mavi");
  }
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
