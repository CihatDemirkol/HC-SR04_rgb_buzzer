int echoPin= 4;
int trigPin= 3;
int ledK=8;
int ledM=9;
int ledY=10;
int buzzerPin=12;
long duration,distance;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(ledK,OUTPUT);
  pinMode(ledM,OUTPUT);
  pinMode(ledY,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin,LOW);

  duration=pulseIn(echoPin,HIGH);
  distance=(duration/2)/29.1;

  if(distance<=15)
  {
    digitalWrite(ledK,HIGH);
    digitalWrite(ledM,LOW);
    digitalWrite(ledY,LOW);
    tone(buzzerPin,450);
    Serial.println("kırmızı");
  }

 

  else if(distance<=20)
  {
    digitalWrite(ledK,HIGH);
    digitalWrite(ledM,LOW);
    digitalWrite(ledY,HIGH);
    tone(buzzerPin,350);
    delay(150);
    digitalWrite(ledK,LOW);
    digitalWrite(ledY,LOW);
    noTone(buzzerPin);
    delay(150);
         Serial.println("sarı");
  }
  else if(distance<=25)
  {
    digitalWrite(ledY,HIGH);
    digitalWrite(ledK,LOW);
    digitalWrite(ledM,LOW);
    tone(buzzerPin,300);
    delay(200);
    digitalWrite(ledY,LOW);
    noTone(buzzerPin);
    delay(200);
         Serial.println("yesil");
  }
  else
  {
    digitalWrite(ledM,HIGH);
    digitalWrite(ledK,LOW);
    digitalWrite(ledY,LOW);
    noTone(buzzerPin);
         Serial.println("mavi");
  }
}
