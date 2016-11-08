void sprint (){

  long randomTime = 0;
  long delayTime = 0;
  long startTime = 0;
  long endTime = 0;
  long nextDisplay = 0;
  int elapseTime = 0;
  
  HallEffectValue = analogRead(HallEffectPin);
  Serial.print("Hall effect value " );
  Serial.println(HallEffectValue);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Please replace");
  lcd.setCursor(0, 1);
  lcd.print("target can");
  
  while (HallEffectValue > 500){
    Serial.print("Waiting " );
    Serial.println(HallEffectValue);
    HallEffectValue = analogRead(HallEffectPin);
  }
  
  Serial.print("Go " );
  Serial.println(HallEffectValue);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Wait ...");
  lcd.setCursor(0, 1);
  lcd.print("");

  randomTime = random(0, 60);
  delayTime = randomTime * 1000;
  Serial.print("Delay time ");
  Serial.println(delayTime);
  delay(delayTime);

  digitalWrite(thereLED, HIGH);
 
  startTime = millis();
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("elapsed");
  HallEffectValue = analogRead(HallEffectPin);
   while (HallEffectValue <= 500){
    endTime = millis();
    elapseTime = (endTime - startTime) / 1000; 
    lcd.setCursor(0, 0);
    lcd.print(elapseTime);
    lcd.print(" seconds");
    HallEffectValue = analogRead(HallEffectPin);
  }

  endTime = millis();
  elapseTime = (endTime - startTime) / 1000; 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Final time");
  lcd.setCursor(0, 1);
  lcd.print(elapseTime);
  lcd.print(" seconds");

  Serial.print("Stop " );
  Serial.println(HallEffectValue);

  delay(30000);
  delayTime = 0;
  digitalWrite(thereLED, LOW);
}
