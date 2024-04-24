#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int Sonic_Time_out = 3000;

long Sonic_Timing(){
  digitalWrite(8, LOW);
  delayMicroseconds(2);
  digitalWrite(8, HIGH);
  delayMicroseconds(10);
  digitalWrite(8, LOW);
  long duration = pulseIn(9,HIGH);
  if ( duration == 0 ){
    duration = Sonic_Time_out;
    digitalWrite(0, HIGH);
    delay(25);
    digitalWrite(0 ,LOW);
    delay(225);
  }
  return duration;
}
unsigned long previousMillis;
int previousDistance;
int buttonDenied;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
pinMode(8, OUTPUT);
pinMode(9, INPUT);
pinMode(0, OUTPUT);
pinMode(10, OUTPUT);
pinMode(6, OUTPUT);
pinMode(13, INPUT);
previousMillis = millis();
previousDistance = Sonic_Timing()/29/2;
lcd.begin(16, 2);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
unsigned long currentMillis = millis();
if(currentMillis - previousMillis >= 1000){
  if(abs(Sonic_Timing()/29/2 - previousDistance) > 6){
    Serial.print(Sonic_Timing()/29/2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(abs(Sonic_Timing()/29/2 - previousDistance));
    lcd.print("cm/s");
    lcd.setCursor(0, 1);
    lcd.print("Failure.");
    analogWrite(10, 175);
    analogWrite(6, 0);
    tone(7, 1500, 600);
    delay(500);
  }
    else if(abs(Sonic_Timing()/29/2 - previousDistance) <= 6 && abs(Sonic_Timing()/29/2 - previousDistance) >= 3){
      Serial.print(Sonic_Timing()/29/2);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(abs(Sonic_Timing()/29/2 - previousDistance));
      lcd.print("cm/s");
      analogWrite(10, 175);
      analogWrite(6, 200);
      delay(500);
    }
    else if((abs(Sonic_Timing()/29/2 - previousDistance) < 3)){
      Serial.print(Sonic_Timing()/29/2);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(abs(Sonic_Timing()/29/2 - previousDistance));
      lcd.print("cm/s");
      analogWrite(6,175);
      analogWrite(10, 0);
      delay(500);
    }
 previousMillis = currentMillis;
  previousDistance = Sonic_Timing()/29/2;
    
  }
  if(digitalRead(13) == HIGH){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Victory!");
    delay(3000);
    lcd.clear();
    delay(2000);
  }
 
}
