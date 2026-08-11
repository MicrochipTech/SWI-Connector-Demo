/*******************************************************************************
FileName:			low-level.h
Processor:			PIC18F47Q10
Compiler:			XC8 v4.00
IDE:				MPLABX IDE v6.35
Author:				Erik Fasnacht
Company:			Microchip Technology, Inc.

Summary:			Header file for low-level.c
    
Description:		Header file for low-level.c
*******************************************************************************/

/*
� [2026] Microchip Technology Inc. and its subsidiaries.

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

#ifndef LOW_LEVEL_H
#define	LOW_LEVEL_H

//******************************************************************************
//******************************************************************************
//Include Declarations
#include <xc.h>

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

//******************************************************************************
//******************************************************************************               
//Function Declarations
uint8_t discoveryResponse(void);
void startHS(void);
void tx1(void);
void tx0(void);
uint8_t txByte(uint8_t dataByte);
uint8_t ackNack(void);
uint8_t readByte(void);

//******************************************************************************
//******************************************************************************               
//Global Variable Declarations
//extern uint8_t slaveAddress;
extern uint8_t communicationSpeed;              //0=high-speed; 1=Standard

#endif	/* LOW_LEVEL_H */