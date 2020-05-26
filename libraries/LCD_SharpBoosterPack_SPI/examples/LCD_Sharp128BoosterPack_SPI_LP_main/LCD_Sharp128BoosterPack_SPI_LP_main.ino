//
//  Sharp128 BoosterPackLCD SPI with Low Power Feature - esp. for CC13xx
//  Example for library for Sharp BoosterPack LCD with hardware SPI
//
//
//  Author :  Stefan Sch
//  Date   :  May. 05, 2020
//  Version:  1.00
//  File   :  LCD_Sharp128BoosterPack_SPI_LP_main.ino
//
//  Version:  1.00 : Demo with init all pins and no UART to show low power demo
//
//  Based on the LCD5110 Library
//  Created by Rei VILO on 28/05/12
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
//  Licence CC = BY SA NC
//


// Include application, user and local libraries
#include "SPI.h"
#include "OneMsTaskTimer.h"
#include "LCD_SharpBoosterPack_SPI.h"

// Variables
LCD_SharpBoosterPack_SPI myScreen(SHARP_128);
uint8_t myOrientation = 0;
uint16_t myCount = 0;

#define LCD_VERTICAL_MAX    myScreen.getSize()
#define LCD_HORIZONTAL_MAX  myScreen.getSize()


// Add setup code
void setup()
{
    int i;

    for (i=1;i<=40; i++)
    {
        //DIO20 - 38  -- Flash_CS   -- PULLUP on Board
        //DIO5  - 10  -- SDA        -- PULLUP on Board
        //DIO22 -  5  -- SDL        -- PULLUP on Board
        //DIO12 -  3  -- RX         -- PULLUP on Board
        //DIO13 -  4  -- TX         -- PULLDOWN on Board
        //DIO13 -  7  -- SCLK       -- LCD
        //DIO13 - 14  -- MISO       -- LCD
        //DIO13 - 15  -- MOSI       -- LCD


        if (i != 2 && i != 3 && i != 5 && i != 7 && i != 10 && i != 14  && i != 15 && i != 38){
            pinMode(i, INPUT_PULLDOWN);
        }
    }


    myScreen.begin();
    myScreen.clearBuffer();

    myScreen.setFont(1);
    myScreen.text(10, 10, "Hello!");
    myScreen.flush();

    for (uint8_t i = 0; i < 20; i++)
    {
        delay(100);
    }
    myScreen.reverseFlush();
    for (uint8_t i = 0; i < 20; i++)
    {
        delay(100);
    }

    myScreen.clear();

    for (uint8_t i = 0; i < 4; i++)
    {
        myScreen.setOrientation(i);
        myScreen.text(10, 10, String(i));
        myScreen.flush();
    }
    for (uint8_t i = 0; i < 20; i++)
    {
        delay(100);
    }
}

// Add loop code
void loop()
{
    myCount++;
    if (myCount > 16)
    {
        myOrientation++;
        myOrientation %= 4;
        myScreen.setOrientation(myOrientation);
        myCount = 0;
    }
    myScreen.clearBuffer();
    myScreen.setFont(0);

    myScreen.text(myCount, 10, "ABCDE", LCDWrapNone);
    for (uint8_t i = 10; i < LCD_HORIZONTAL_MAX - 10; i++)
    {
        myScreen.setXY(i, 20, 1);
    }

    myScreen.text(10, 30, String(myCount, 10));

    for (uint8_t i = 0; i <= 20; i++)
    {
        myScreen.setXY(50 + i, 30, 1);
        myScreen.setXY(50, 30 + i, 1);
        myScreen.setXY(50 + i, 50, 1);
        myScreen.setXY(70, 30 + i, 1);
    }

    myScreen.setFont(1);
    myScreen.setCharXY(10, 40);
    myScreen.print("ABC");
    myScreen.setFont(0);
    myScreen.setCharXY(60, 60);
    myScreen.print(0x7F, HEX);
    myScreen.print(0x81, HEX);
    myScreen.setCharXY(10, 60);
    myScreen.println("Break!");
    myScreen.print("ABC\nabc");
    myScreen.flush();

    myScreen.setManualPowerMode(LOW);
    delay(30000);  // power down for 30 seconds
    myScreen.setManualPowerMode(HIGH);

}
