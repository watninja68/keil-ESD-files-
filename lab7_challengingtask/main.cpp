#include "mbed.h"
#include "TextLCD.h"
Serial pc(USBTX,USBRX);
AnalogIn ldr1(PC_2);
AnalogIn ldr2(PC_3);
PwmOut servo(PC_8);
TextLCD lcd(PC_0,PC_1,PB_0,PA_4,PA_1,PA_0);

int main() {
    lcd.cls();
    int i = 15000;
    servo.period_us(20000);
    servo.pulsewidth_us(i);
    while(i){
        float LDRdiff = ldr1-ldr2;
        if(LDRdiff>0.1){
            i=i+100;
            servo.pulsewidth_us(i);
            }
        else {
            i=i-100;
            servo.pulsewidth_us(i);
            }
    float servoangle=(i-500)*0.09;
    lcd.locate(0,0);
    lcd.printf("LDRE = %0.1f",ldr1*100);
    lcd.locate(8,0);
    lcd.printf("LDRW = %0.1f",ldr2*100);
    lcd.locate(0,1);
    lcd.printf("Servo Angle=%0.1f",servoangle);
    wait(2);
    lcd.cls();
    wait(1);
    }
} 
