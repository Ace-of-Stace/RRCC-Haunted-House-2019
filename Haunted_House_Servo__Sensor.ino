
#include <Servo.h>
const int servoPin = 6;  // Servo pin
 
Servo myservo;
int pos = 0;
const int TrigPin = 8;

const int EchoPin = 7;

float cm;
int delayTime = 200;

void setup()
{
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
   myservo.attach(6);
}
void loop()
{
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(20000);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(20000);
  digitalWrite(TrigPin, LOW);
  cm = pulseIn(EchoPin, HIGH) / 30.0; //The echo time is converted into cm
//  cm = (int(cm * 100.0)) / 30.0;     //Keep two decimal places
  Serial.print("Distance\t=\t");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  if (cm < 100 & cm > 10) {

       for(pos = 0; pos <= 80; pos += 1)
       {
         myservo.write(pos); 
         delay(15);  // waits 15ms to reach the position
       }
       delay(2000);
       for (pos = 80; pos >= 0; pos -=1)
       {
         myservo.write(pos);
         delay(15);
       }      
     }
 
   } 

