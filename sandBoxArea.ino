// the following sketch below is version 1 of the code and can be deleted because its no longer needed
//#include "current_sensing.h"
//#include "ac_voltage_sensor.h"
//
//#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x27,16,2);
//int buzzer = 7;
//
//void setup() {
//      pinMode(buzzer, OUTPUT);
//      Serial.begin(9600);
//
//      execute();
//      voltageSensor.setSensitivity(SENSITIVITY); 
//      
//      Serial.println("\n__Sensor calibration complete__:)");
//      delay(500);
//
//      lcd.init();      // initiate the LCD
//      lcd.backlight(); // Turn On the LED backlight on the LCD display
//      lcd.setCursor(1,0);
//      lcd.print("Power Tapping"); 
//     
//      lcd.setCursor(2,1);
//      lcd.print("Alert System");
//     
//      delay(4000);
//      lcd.clear();
//}   
//
//void loop() {
//       if (llm){
//          float voltageValue = readVoltage();       
//          float currentSensor_1 = getCurrentReading(SENSOR_PIN_1); // current at transmission  
//          float currentSensor_2 = getCurrentReading(SENSOR_PIN_2); // current at consumer end  
//             
//          if (currentSensor_1 - currentSensor_2 > 0){
//              Serial.print("\n\n*** illegal load connected ***");
//              lcd.clear();  // clears previous display
//              lcd.setCursor(1,0);
//              lcd.print("illegal load");
//              digitalWrite(buzzer, HIGH);
//             
//              lcd.setCursor(2,1);
//              lcd.print("Tapping Power");
//             
//              delay(2000);
//              digitalWrite(buzzer, LOW);
//              lcd.clear();  
//          }
//          else{
//                String ac_voltage = "\n\nA.C. voltage: " + (String)voltageValue + " V"; 
//                Serial.print(ac_voltage);
//          
//                String lcd_V = (String)voltageValue + "V";  
//                lcd.setCursor(9,1);
//                lcd.print(lcd_V);
//                
//                String at_transmission = "c1:" + (String)currentSensor_1 + "A";  
//                lcd.setCursor(0,0);
//                lcd.print(at_transmission);  
//                
//                String at_consumer = "c2:" + (String)currentSensor_2 + "A,";  
//                lcd.setCursor(0,1);
//                lcd.print(at_consumer);
//    
//                String transmissionCurrent = "\n\nAt transmission end: " + (String)currentSensor_1 + " A";
//                Serial.print(transmissionCurrent);
//          
//                String consumerCurrent = "  |  At consumer end: " + (String)currentSensor_2 + " A";
//                Serial.print(consumerCurrent);
//                delay(500);
//          }
//    }
//}
