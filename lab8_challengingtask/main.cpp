#include "mbed.h"
#include "SPI.h"

SPISlave spi(PB_15, PB_14, PB_13, PB_12); // mosi, miso, sclk, cs
DigitalOut led1(PC_6);
DigitalOut led2(PC_8);

int main() {
    spi.format(8, 0); // 8 bits per frame, SPI mode 0
    spi.frequency(1000000); // 1MHz clock rate
    
    while(1) {
        if (spi.receive()) {
            int switch_word_rx = spi.read(); // Receive data from master
            int switch1 = switch_word_rx & 0x01;
            int switch2 = (switch_word_rx >> 1) & 0x01;
            
            // Implement half adder logic
            int sum = switch1 ^ switch2;
            int carry = switch1 & switch2;
            
            // Output result to LEDs
            led1 = sum;
            led2 = carry;
        }
    }
}
