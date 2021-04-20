/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78
        Device            :  PIC16F18875
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
*/

/*******************************************************************************
    (c) 2019 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software
    and any derivatives exclusively with Microchip products. It is your  
    responsibility to comply with third party license terms applicable to your
    use of third party software (including open source software) that may
    accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*******************************************************************************/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set oledC_RW aliases
#define oledC_RW_TRIS                 TRISAbits.TRISA1
#define oledC_RW_LAT                  LATAbits.LATA1
#define oledC_RW_PORT                 PORTAbits.RA1
#define oledC_RW_WPU                  WPUAbits.WPUA1
#define oledC_RW_OD                   ODCONAbits.ODCA1
#define oledC_RW_ANS                  ANSELAbits.ANSA1
#define oledC_RW_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define oledC_RW_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define oledC_RW_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define oledC_RW_GetValue()           PORTAbits.RA1
#define oledC_RW_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define oledC_RW_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define oledC_RW_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define oledC_RW_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define oledC_RW_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define oledC_RW_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define oledC_RW_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define oledC_RW_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set oledC_nCS aliases
#define oledC_nCS_TRIS                 TRISAbits.TRISA3
#define oledC_nCS_LAT                  LATAbits.LATA3
#define oledC_nCS_PORT                 PORTAbits.RA3
#define oledC_nCS_WPU                  WPUAbits.WPUA3
#define oledC_nCS_OD                   ODCONAbits.ODCA3
#define oledC_nCS_ANS                  ANSELAbits.ANSA3
#define oledC_nCS_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define oledC_nCS_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define oledC_nCS_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define oledC_nCS_GetValue()           PORTAbits.RA3
#define oledC_nCS_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define oledC_nCS_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define oledC_nCS_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define oledC_nCS_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define oledC_nCS_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define oledC_nCS_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define oledC_nCS_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define oledC_nCS_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set D4 aliases
#define D4_TRIS                 TRISAbits.TRISA6
#define D4_LAT                  LATAbits.LATA6
#define D4_PORT                 PORTAbits.RA6
#define D4_WPU                  WPUAbits.WPUA6
#define D4_OD                   ODCONAbits.ODCA6
#define D4_ANS                  ANSELAbits.ANSA6
#define D4_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define D4_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define D4_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define D4_GetValue()           PORTAbits.RA6
#define D4_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define D4_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define D4_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define D4_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define D4_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define D4_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define D4_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define D4_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set SCK2 aliases
#define SCK2_TRIS                 TRISBbits.TRISB1
#define SCK2_LAT                  LATBbits.LATB1
#define SCK2_PORT                 PORTBbits.RB1
#define SCK2_WPU                  WPUBbits.WPUB1
#define SCK2_OD                   ODCONBbits.ODCB1
#define SCK2_ANS                  ANSELBbits.ANSB1
#define SCK2_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define SCK2_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define SCK2_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define SCK2_GetValue()           PORTBbits.RB1
#define SCK2_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define SCK2_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define SCK2_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define SCK2_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define SCK2_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define SCK2_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define SCK2_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define SCK2_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set SDI2 aliases
#define SDI2_TRIS                 TRISBbits.TRISB2
#define SDI2_LAT                  LATBbits.LATB2
#define SDI2_PORT                 PORTBbits.RB2
#define SDI2_WPU                  WPUBbits.WPUB2
#define SDI2_OD                   ODCONBbits.ODCB2
#define SDI2_ANS                  ANSELBbits.ANSB2
#define SDI2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define SDI2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define SDI2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define SDI2_GetValue()           PORTBbits.RB2
#define SDI2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define SDI2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define SDI2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define SDI2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define SDI2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define SDI2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define SDI2_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define SDI2_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set SDO2 aliases
#define SDO2_TRIS                 TRISBbits.TRISB3
#define SDO2_LAT                  LATBbits.LATB3
#define SDO2_PORT                 PORTBbits.RB3
#define SDO2_WPU                  WPUBbits.WPUB3
#define SDO2_OD                   ODCONBbits.ODCB3
#define SDO2_ANS                  ANSELBbits.ANSB3
#define SDO2_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define SDO2_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define SDO2_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define SDO2_GetValue()           PORTBbits.RB3
#define SDO2_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define SDO2_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define SDO2_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define SDO2_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define SDO2_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define SDO2_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define SDO2_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define SDO2_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set S1 aliases
#define S1_TRIS                 TRISBbits.TRISB4
#define S1_LAT                  LATBbits.LATB4
#define S1_PORT                 PORTBbits.RB4
#define S1_WPU                  WPUBbits.WPUB4
#define S1_OD                   ODCONBbits.ODCB4
#define S1_ANS                  ANSELBbits.ANSB4
#define S1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define S1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define S1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define S1_GetValue()           PORTBbits.RB4
#define S1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define S1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define S1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define S1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define S1_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define S1_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define S1_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define S1_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set oledC_EN aliases
#define oledC_EN_TRIS                 TRISBbits.TRISB5
#define oledC_EN_LAT                  LATBbits.LATB5
#define oledC_EN_PORT                 PORTBbits.RB5
#define oledC_EN_WPU                  WPUBbits.WPUB5
#define oledC_EN_OD                   ODCONBbits.ODCB5
#define oledC_EN_ANS                  ANSELBbits.ANSB5
#define oledC_EN_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define oledC_EN_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define oledC_EN_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define oledC_EN_GetValue()           PORTBbits.RB5
#define oledC_EN_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define oledC_EN_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define oledC_EN_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define oledC_EN_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define oledC_EN_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define oledC_EN_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define oledC_EN_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define oledC_EN_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set oledC_DC aliases
#define oledC_DC_TRIS                 TRISCbits.TRISC2
#define oledC_DC_LAT                  LATCbits.LATC2
#define oledC_DC_PORT                 PORTCbits.RC2
#define oledC_DC_WPU                  WPUCbits.WPUC2
#define oledC_DC_OD                   ODCONCbits.ODCC2
#define oledC_DC_ANS                  ANSELCbits.ANSC2
#define oledC_DC_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define oledC_DC_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define oledC_DC_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define oledC_DC_GetValue()           PORTCbits.RC2
#define oledC_DC_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define oledC_DC_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define oledC_DC_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define oledC_DC_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define oledC_DC_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define oledC_DC_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define oledC_DC_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define oledC_DC_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set S2 aliases
#define S2_TRIS                 TRISCbits.TRISC5
#define S2_LAT                  LATCbits.LATC5
#define S2_PORT                 PORTCbits.RC5
#define S2_WPU                  WPUCbits.WPUC5
#define S2_OD                   ODCONCbits.ODCC5
#define S2_ANS                  ANSELCbits.ANSC5
#define S2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define S2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define S2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define S2_GetValue()           PORTCbits.RC5
#define S2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define S2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define S2_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define S2_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define S2_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define S2_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define S2_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define S2_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set oledC_RST aliases
#define oledC_RST_TRIS                 TRISDbits.TRISD0
#define oledC_RST_LAT                  LATDbits.LATD0
#define oledC_RST_PORT                 PORTDbits.RD0
#define oledC_RST_WPU                  WPUDbits.WPUD0
#define oledC_RST_OD                   ODCONDbits.ODCD0
#define oledC_RST_ANS                  ANSELDbits.ANSD0
#define oledC_RST_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define oledC_RST_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define oledC_RST_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define oledC_RST_GetValue()           PORTDbits.RD0
#define oledC_RST_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define oledC_RST_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define oledC_RST_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define oledC_RST_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define oledC_RST_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define oledC_RST_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define oledC_RST_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define oledC_RST_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set SIO aliases
#define SIO_TRIS                 TRISDbits.TRISD1
#define SIO_LAT                  LATDbits.LATD1
#define SIO_PORT                 PORTDbits.RD1
#define SIO_WPU                  WPUDbits.WPUD1
#define SIO_OD                   ODCONDbits.ODCD1
#define SIO_ANS                  ANSELDbits.ANSD1
#define SIO_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define SIO_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define SIO_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define SIO_GetValue()           PORTDbits.RD1
#define SIO_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define SIO_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define SIO_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define SIO_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define SIO_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define SIO_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define SIO_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define SIO_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/