#include "mbed.h"
#include "TextLCD.h"

TextLCD lcd(PC_0,PC_1,PB_0,PA_4,PA_1,PA_0);
Serial pc(USBTX,USBRX);
int main()
{
	pc.printf("\n enter the temperature: ");
	int y;
    pc.scanf("%d",&y);
    if(y<32)
    {
        lcd.printf("OFF");
    }
    else 
    {
        lcd.printf("ON");
    }
}