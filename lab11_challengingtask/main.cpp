//21BLC1660
#include "mbed.h"
#include "TextLCD.h"
#include "keypad.h"
#include "string.h"


Serial pc(USBTX, USBRX);
TextLCD lcd(PC_0, PC_1, PB_0, PA_4, PA_1, PA_0);
Keypad keypad(PA_10, PB_3, PB_5, PB_4, PB_10, PA_8, PA_9, PC_7); // column pins, row pins

PwmOut buzz(PC_6);
PwmOut lock(PC_8);
AnalogIn ldr(PC_5);

char input[4] ;

int main() {
    keypad.enablePullUp();
    buzz.period(1.0/200.0);
    lock.period_ms(20);
    lock.pulsewidth_us(0);

    while(1) {
        if(keypad.getKeyPressed()) {
            lcd.cls();
            lcd.printf("Enter password:");
            lcd.locate(0,1);

            for(int i = 0; i < 4; i++) {
                while(keypad.getKey() == '\0');
                input[i] = keypad.getKey();
                lcd.printf("*");
                wait(0.5);
            }

            wait(1);
            lcd.cls();

            if(input[0] =='1' && input[1] =='2' && input[2] == '3' && input[3] == '4') {
                lcd.printf("Password Correct");
                lcd.locate(0, 1);
                lcd.printf("Opening door");
                lock.pulsewidth_us(1000);
                wait(3);
            } else {
                lcd.printf("Password Wrong");
                buzz = 0.5;
                wait(3);
                buzz = 0;
            }

            lock.pulsewidth_us(0);
        } else {
            if(ldr > 0.5f) {
                lcd.cls();
                lcd.printf("Intruder!!!");
                buzz = 0.5;
                wait(3);
                buzz = 0;
                lcd.cls();
            }
        }
    }
}
