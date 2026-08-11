/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 3.1.0
*/

/*
© [2026] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#include "../pins.h"


void PIN_MANAGER_Initialize(void)
{
   /**
    LATx registers
    */
    LATA = 0x08; /* RA3 (oledC_nCS) idle high */
    LATB = 0x0;
    LATC = 0x0;
    LATD = 0x03; /* RD0 (oledC_RST) and RD1 (SIO) high */
    LATE = 0x0;

    /**
    TRISx registers
    */
    TRISA = 0xB5; /* RA1 (RW), RA3 (nCS), RA6 (D4) outputs */
    TRISB = 0xD5; /* RB1/RB3 (SPI), RB5 (EN) outputs */
    TRISC = 0xBB; /* RC2 (DC), RC6 (TX) outputs */
    TRISD = 0xFC; /* RD0 (RST), RD1 (SIO) outputs */
    TRISE = 0x7;

    /**
    ANSELx registers
    */
    ANSELA = 0xB5; /* digital: RA1, RA3, RA6 */
    ANSELB = 0xC1; /* digital: RB1-RB5 */
    ANSELC = 0x1B; /* digital: RC2, RC5-RC7 */
    ANSELD = 0xFC; /* digital: RD0, RD1 */
    ANSELE = 0x7;

    /**
    WPUx registers
    */
    WPUA = 0x0;
    WPUB = 0x0;
    WPUC = 0x0;
    WPUD = 0x0;
    WPUE = 0x0;

    /**
    ODx registers
    */
    ODCONA = 0x0;
    ODCONB = 0x0;
    ODCONC = 0x0;
    ODCOND = 0x0;
    ODCONE = 0x0;

    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    SLRCOND = 0xFF;
    SLRCONE = 0x7;

    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLD = 0xFF;
    INLVLE = 0xF;

   /**
    RxyI2C | RxyFEAT registers   
    */
    /**
    PPS registers
    */
    RX1PPS = 0x17; //RC7->EUSART1:RX1;
    SSP1DATPPS = 0xA; //RB2->MSSP1:SDI1;
    RC6PPS = 0x09;  //RC6->EUSART1:TX1;
    RB3PPS = 0x10;  //RB3->MSSP1:SDO1;
    SSP1CLKPPS = 0x9;  //RB1->MSSP1:SCK1;
    RB1PPS = 0x0F;  //RB1->MSSP1:SCK1;

   /**
    IOCx registers 
    */
    IOCAP = 0x0;
    IOCAN = 0x0;
    IOCAF = 0x0;
    IOCBP = 0x0;
    IOCBN = 0x0;
    IOCBF = 0x0;
    IOCCP = 0x0;
    IOCCN = 0x0;
    IOCCF = 0x0;
    IOCEP = 0x0;
    IOCEN = 0x0;
    IOCEF = 0x0;


}
  
void PIN_MANAGER_IOC(void)
{
}
/**
 End of File
*/