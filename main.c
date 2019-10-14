/*******************************************************
* Name:                Emily Battey and Rebecca Goslow
* Course:            EGR 226 - Microcontroller Programming and Applications
* Project:            Lab 07 - Interfacing a 4x16 LCD to a MSP432
* Description:        print users names to the LCD and the EGR 266 centered
*******************************************************/
#include "msp.h"
#include "LCD.h"
#include <string.h>
//#include "LCD.c"


/**
 * main.c
 */
void main(void)
{
    Systick_ms_delay(100);
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    innit_pins();
    Systick_ms_delay(100);
    write_command(0b00000011);
    LCD_innit();
    Systick_ms_delay(100);
    write_command(0b00100100);//2 lines
    Systick_ms_delay(100);
    write_command(0b00000011);
    Systick_ms_delay(100);
    //write_command(0b00000001);
    Systick_ms_delay(100);
    //write_command(0b00001100);
    Systick_ms_delay(100);
    //space(5);
    char word[] = "LABORATORY OVER";
    int i = 0;
    for(i = 0;i<15;i++){
        dataWrite((int)word[i]);//print to LCD
    }
    space(1);

    while(1){

//space(16);
        for(i = 0; i < (17); i++){
                    write_command(0b00010000);//
                }
    i = 0;
    while(i < 17){
            write_command(0b00011000);//shift disp
            dataWrite(0x20);

            Systick_ms_delay(1000);
            i++;
        }
    //write_command(0b00011000);//shift disp
               //dataWrite(0x20);
    space(17);
    for(i = 0;i<15;i++){
            dataWrite((int)word[i]);//print to LCD
            write_command(0b00011000);//shift disp
            Systick_ms_delay(1000);

        }
    }
}
