#include <LiquidCrystal.h>;
//#include <IRremote.h>;

#define mode 2

LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

int HallEffectValue = 0;
const int HallEffectPin = A3;

const int thereLED = 8;

//const int switchPin = 6;
//int switchState = 0;
//int prevswitchState = 0;
//int reply;

void setup() {
  Serial.begin (9600);
  pinMode(thereLED, OUTPUT);
  
  lcd.begin (16, 2);
  //pinMode(switchPin, OUTPUT);
  lcd.print("Play the");
  lcd.setCursor(0, 1);
  lcd.print("Nerfgame");
  randomSeed(analogRead(0));
}

void loop() {
  //switchState = digitalRead(switchPin);

  switch (mode){
    case 1:
      standardTest();
      break; 
    case 2:
      sprint();
      break; 
  }
}

