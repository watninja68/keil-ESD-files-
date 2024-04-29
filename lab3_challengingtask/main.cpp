#include "mbed.h"

DigitalIn switch1(PB_13);
DigitalIn switch2(PB_14);
DigitalIn switch3(PB_15);
DigitalIn switch4(PB_1);
PwmOut speaker(PC_6);

int main(){
    speaker=0.0;
    while(1){
    if(switch1==1){
        speaker.period(1.0/2.0);
        speaker=0.5;
        wait(0.5);
    }
    else if(switch2==1){
        speaker.period(1.0/400.0);
        speaker=0.5;
        wait(0.5);
    }
    else if(switch3==1){
        speaker.period(1.0/612.0);
        speaker=0.5;
        wait(0.5);
    }
    else if(switch4==1){
        speaker.period(1.0/1000.0);
        speaker=0.5;
        wait(0.5);
    }
    else{
        speaker=0;
        wait(0.5);
    }
    }
    
}
