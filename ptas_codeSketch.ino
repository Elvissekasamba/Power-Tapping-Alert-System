#include "current_sensing.h"
#include "lcd_display.h"
#include "gsm.h"

void setup(){
      gsmSetUp();
      delay(400);
      pinMode(buzzer, OUTPUT);
      
      project_title_displayed(); 
        
      sensor.calibrate();  
         
      Serial.begin(9600);     
      Serial.println("ZMCT103C AC Current Measurement");
}

void loop(){
      gsmFunction();
      if (positionA == currentSensor_3 or positionB == currentSensor_3){ // to ensure the SMS alerts are sent only once
          sendSMS_A = true; 
          sendSMS_B = true;
          sendSMS_A_and_B = true;
      }
      
      currentSensor_1 = sensor.getCurrentAC(); 
      if (currentSensor_1 < 1.00){
          currentSensor_1 = 0.00;
      }     
      currentSensor_2 = ZMCT103C_AC_reading(sensorPin);     
      currentSensor_3 = ZMCT103C_AC_reading(sensorPin2);     
      
      Serial.print("\ncurrentSensor_1 = " + String(currentSensor_1) + " A | ");
      Serial.print("currentSensor_2 = " + String(currentSensor_2) + " A | ");
      Serial.print("currentSensor_3 = " + String(currentSensor_3) + " A");
      delay(500);
      
      // current measurement at Position A on top display...................................
      positionA = currentSensor_3 - currentSensor_1;
      lcd.setCursor(0,0);
      lcd.print("A: "); 
      
      lcd.setCursor(3,0);
      lcd.print(positionA);
     
      // current measurement at Position B on bottom display...................................
      positionB = currentSensor_3 - currentSensor_2;
      lcd.setCursor(9,0); 
      lcd.print("B: "); 
      
      lcd.setCursor(12,0); 
      lcd.print(positionB);

      // current measurement at the end user (the actual customer)
      lcd.setCursor(1,1);   
      lcd.print("End User: "); 
      
      lcd.setCursor(11,1);  
      lcd.print(currentSensor_3);

      powerTappingDetection(); // In current_sensing.h file , start from here
}
