#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);   // top display
//LiquidCrystal_I2C lcd_2(0x26,16,2); // bottom display

bool clearPreviousDisplay;

void project_title_displayed(){
      // top display......
      lcd.init();      // initiate the LCD
      lcd.backlight(); // Turn On the LED backlight on the LCD display
      lcd.setCursor(1,0);
      lcd.print("Power Tapping"); 
     
      lcd.setCursor(2,1);
      lcd.print("Alert System");

//      // bottom display......
//      lcd_2.init();      // initiate the LCD
//      lcd_2.backlight(); // Turn On the LED backlight on the LCD display
//      lcd_2.setCursor(1,0);
//      lcd_2.print("Final Year"); 
//     
//      lcd_2.setCursor(3,1);
//      lcd_2.print("Project");
     
      delay(4000);
      lcd.clear();
//      lcd_2.clear();
}

#endif
