
#include "mbed.h"

BusOut north(PB_13, PB_14, PB_15); 
BusOut south(PC_13, PC_14, PC_15); 
BusOut west(PA_13, PA_14, PA_15); 
BusOut east(PA_12, PA_11, PB_12);

Digitalin switch1(PC_4);

int main() {

while(1) {

if(switch1==0){
    north=2; 
    south=2; 
    west=2; 
    east=2; 
    wait(2); }

else{
    north=4;
    south=4;
    east=1;
    west=1;
    wait(15);
    east=2;
    west=2;
    wait(2);
    east=4;
    west=4;
    north=1;
    south=1;
    wait(15);
    north=2;
    south=2;
    wait(2);
    }
}
}