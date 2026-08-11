/*******************************************************************************
FileName:			XTEA.h
Processor:			PIC18F47Q10
Compiler:			XC8 v4.00
IDE:				MPLABX IDE v6.35
Author:				Erik Fasnacht
Company:			Microchip Technology, Inc.

Summary:			Header file for XTEA.c
    
Description:		Header file for XTEA.c
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

#ifndef XTEA_H
#define	XTEA_H

#include <xc.h>

//******************************************************************************
//******************************************************************************
//Include Declarations

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef	__cplusplus
}
#endif /* __cplusplus */

//******************************************************************************
//******************************************************************************
//XTEA Function Declarations
void encryption(uint8_t iterations, uint32_t data[2]);
void decryption(uint8_t iterations, uint32_t data[2]);


//******************************************************************************
//******************************************************************************              
//Variable Declaration  
static const uint32_t key [4]= {0x4d434850, 0x20415432, 0x31435320, 0x44656d6f};        //key = MCHP AT21CS Demo in ASCII

#endif	/* XTEA_H */
