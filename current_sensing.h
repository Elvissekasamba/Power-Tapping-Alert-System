#ifndef CURRENT_SENSING_H
#define CURRENT_SENSING_H
#include "gsm.h"
#include "lcd_display.h"
#include "ACS712.h"
ACS712 sensor(ACS712_30A, A0);

/*
This value must be calibrated
float calibrationFactor = 5.70 / 210.0;  
Example only: realCurrent / adcRms
float calibrationFactor = 0.0209; 
*/
int sensorPin = A1;
int sensorPin2 = A2;
float Current, calibrationFactor = 0.0211;

float currentSensor_1, currentSensor_2, currentSensor_3;
float positionA, positionB; 

float ZMCT103C_AC_reading(int analogPin){
      const int samples = 1000;
      long offsetSum = 0;
      
      for(int i = 0; i < samples; i++){
          offsetSum += analogRead(analogPin);
      }
      float offset = offsetSum / (float)samples;
      float sumSquares = 0;
      int minVal = 1023;
      int maxVal = 0;
      
      for(int i = 0; i < samples; i++){
          int adc = analogRead(analogPin);
          if(adc < minVal) minVal = adc;
          if(adc > maxVal) maxVal = adc;
          float centered = adc - offset;
          sumSquares += centered * centered;
      }
      float adcRms = sqrt(sumSquares / samples);
      Current = adcRms * calibrationFactor;
      
      if (Current < 1.00){
         Current = 0.00;
      }
      return Current;
}

int buzzer = 7;
// Pulsing or Strobe-style Buzzer Alarm Tone
void intruderAlarm() {
  for (int i = 0; i < 8; i++) {  // 8 fast pulses
    tone(buzzer, 2800, 120);     // High sharp tone
    delay(150);
    noTone(buzzer);
    delay(50);
  }
  delay(400);   // Pause before next burst
}

void powerTappingDetection(){
      // check whether current is the same at end user
      if (positionA != currentSensor_3 and positionB == currentSensor_3){ 
          lcd.clear();
          lcd.setCursor(2,0);
          lcd.print("Illegal Load"); 
          
          lcd.setCursor(1,1);
          lcd.print("On Position A");
          intruderAlarm();   
          clearPreviousDisplay = true; 

          // send an alert SMS notification for the above
          if (sendSMS_A){
              sendSMS(phoneNumber, "Illegal Load connected\nalong position A");
              sendSMS_A = false;
              delay(200);
          }
      }
      if (positionB != currentSensor_3 and positionA == currentSensor_3){ 
          lcd.clear();
          lcd.setCursor(2,0);
          lcd.print("Illegal Load"); 
          
          lcd.setCursor(1,1);
          lcd.print("On Position B");
          intruderAlarm();   
          clearPreviousDisplay = true;  
          
          // send an alert SMS notification for the above
          if (sendSMS_B){
              sendSMS(phoneNumber, "Illegal Load connected\nalong position B");
              sendSMS_B = false;
              delay(200);
          }
      }
      if (positionA and positionB != currentSensor_3){ 
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("Illegal Loads"); 
          
          lcd.setCursor(2,1);
          lcd.print("At A and B");
          
          intruderAlarm();   
          clearPreviousDisplay = true;  
          
          // send an alert SMS notification for the above
          if (sendSMS_A_and_B){
              sendSMS(phoneNumber, "Illegal Loads connected\nat both position A and B");
              sendSMS_A_and_B = false;
              delay(200);
          }
      }     
      // ensures the previous displayed LCD output is first cleared to avoid over writes
      if (clearPreviousDisplay){ 
          lcd.clear();
          clearPreviousDisplay = false;
          delay(200);
      } 
}

#endif
