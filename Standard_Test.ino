void standardTest () {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("The target is");
  lcd.setCursor(0, 1);
  lcd.print(HallEffectValue);
        
  // Check the light and turn on the sensor if required
  HallEffectValue = analogRead(HallEffectPin);

  Serial.print ("The Hall Effect value is ");
  Serial.println (HallEffectValue);

  if (HallEffectValue > 450) {
    lcd.print(" - Missing");
    digitalWrite(thereLED, LOW);
    //Serial.println ("Missing");
  }  
  else {
    lcd.print(" - Here");
    Serial.println ("Here");
    digitalWrite(thereLED, HIGH);
  }
  delay (1000);
}

