/*******************************************************************************
FileName:			operations.h
Processor:			PIC16F18875
Compiler:			XC8 v4.00
IDE:				MPLABX IDE v6.35
Author:				Erik Fasnacht
Company:			Microchip Technology, Inc.

Summary:			Header file for operations.c
    
Description:		Header file for operations.c
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

#ifndef OPERATIONS_H
#define	OPERATIONS_H

//******************************************************************************
//******************************************************************************
//Include Declarations
#include "mcc_generated_files/system/system.h"
#include "low-level.h"

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

//******************************************************************************
//******************************************************************************
//SWI Function Declarations
uint8_t scanDeviceAddress();
void eepromWrite(uint8_t dByte, uint8_t aByte, uint8_t writeData[],uint8_t count);
void countWrite(uint8_t dByte, uint8_t aByte, uint16_t writeData);
void randomRead(uint8_t dByte, uint8_t aByte, uint8_t *readData, uint8_t count);
uint16_t countRead(uint8_t dByte, uint8_t aByte);

//******************************************************************************
//******************************************************************************               
//Global Variable Declarations
extern uint8_t slaveAddress;
extern uint8_t communicationSpeed;              //0=high-speed; 1=Standard

#endif	/* OPERATIONS_H */

