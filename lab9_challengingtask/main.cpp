#include "mbed.h"

Serial bt(PC_10, PC_11);

AnalogIn temp(PC_5);
DigitalOut buz(PB_8);
Serial pc(USBTX, USBRX);

int main() {
    bt.baud(9600);
    bt.printf("Temprature sensing");  
    while(1) {
        float read = temp * 5;
        pc.printf("%.4f\n\r", read);

        bt.printf("Voltage is %.4f\n\r", read);

        if(read > 3.0) {
            buz = 1;
            bt.printf("High Voltage");
        }
        else {
            buz = 0;
        bt.printf("Low Voltage");
        }
      
        wait(1);
    }
}