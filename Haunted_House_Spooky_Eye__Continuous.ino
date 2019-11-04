

#include <Adafruit_NeoPixel.h>

#define PIN6      6
#define NUMPIXELS     200
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN6, NEO_GRB + NEO_KHZ800);
int pos = 0;
int i=0;
int eyes[5][8]={{0,1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18,19},{20,21,22,23,24,25,26},{27,28,29,30,31,32,33}};


//const int TrigPin = 8;//uncomment this to add motion sensor.

//const int EchoPin = 7;//uncomment this to add motion sensor.

//float cm;//uncomment this to add motion sensor.
//int delayTime = 200;//uncomment this to add motion sensor.

void setup()
{
  Serial.begin(9600);
//  pinMode(TrigPin, OUTPUT);//uncomment this to add motion sensor.
//  pinMode(EchoPin, INPUT);//uncomment this to add motion sensor.
  pixels.begin();
}
void loop()
{
//  digitalWrite(TrigPin, LOW);//uncomment this to add motion sensor.
//  delayMicroseconds(20000);//uncomment this to add motion sensor.
 // digitalWrite(TrigPin, HIGH);//uncomment this to add motion sensor.
  //delayMicroseconds(20000);//uncomment this to add motion sensor.
  //digitalWrite(TrigPin, LOW);//uncomment this to add motion sensor.
  //cm = pulseIn(EchoPin, HIGH) / 30.0; //The echo time is converted into cm
  //cm = (int(cm * 100.0)) / 30.0;     //Keep two decimal places
  //Serial.print("Distance\t=\t");//uncomment this to add motion sensor.
  //Serial.print(cm);//uncomment this to add motion sensor.
  //Serial.print("cm");//uncomment this to add motion sensor.
  //Serial.println();//uncomment this to add motion sensor.
  //if (cm < 100 & cm > 10) 
  {for(int j=0; j<5; j++){
    int randeyes=random()%5;                                  //uncomment me for 5 sets of eyes
    for(int i=0; i<255; i = i + 5){
      for(int k=0;k<7; k++){
        pixels.setPixelColor(eyes[randeyes][k],pixels.Color(i,0,0));  //replace 0 with randeyes
        pixels.show();
        
      }
    }
    for(int i=255; i>0; i = i - 3){
      for(int k=0;k<7; k++){
        pixels.setPixelColor(eyes[randeyes][k],pixels.Color(i,0,0));   //replace 0 with randeyes
        pixels.show();
        
      }
    }    
    for(int k=0;k<7; k++){
        pixels.setPixelColor(eyes[randeyes][k],pixels.Color(0,0,0));   //replace 0 with randeyes
        pixels.show();
        
    }
    delay(2000);
  }
  }
}
