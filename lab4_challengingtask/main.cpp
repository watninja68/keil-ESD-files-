#include "mbed.h"
AnalogIn potentiometer(PC_3); // Analog input from potentiometer
DigitalOut led1(PC_4);
DigitalOut led2(PB_13);
DigitalOut led3(PB_14);
DigitalOut led4(PB_15);
DigitalOut led5(PB_1);
Serial pc(USBTX, USBRX); // Serial communication to monitor output

int main(){
    while(1) {
        float voltage = potentiometer.read() * 5.0; // Assuming potentiometer is connected to a 5V reference
        if (voltage >= 0 && voltage < 1){
            led1 = 0;
            led2 = 0;
            led3 = 0;
            led4 = 0;
            led5 = 1;
            pc.printf("0 to 1V\n");
        } 
        else if (voltage >= 1 && voltage < 2){
            led1 = 0;
            led2 = 0;
            led3 = 0;
            led4 = 1;
            led5 = 1;
            pc.printf("1 to 2V\n");
        }
        else if (voltage >= 2 && voltage < 3){
            led1 = 0;
            led2 = 0;
            led3 = 1;
            led4 = 1;
            led5 = 1;
            pc.printf("2 to 3V\n");
            } else if (voltage >= 3 && voltage < 4){
                led1 = 0;
                led2 = 1;
                led3 = 1;
                led4 = 1;
                led5 = 1;
                pc.printf("3 to 4V\n");
            } else if (voltage >= 4 && voltage <= 5){
                led1 = 1;
                led2 = 1;
                led3 = 1;
                led4 = 1;
                led5 = 1;
                pc.printf("4 to 5V\n");
            } else {
                // Turn off all ĮEDs if voltage is out of range
                led1 = 0;
                led2 = 0;
                led3 = 0;
                led4 = 0;
                led5 = 0;
                }
                wait(1); // Delay for better readability
    }
}