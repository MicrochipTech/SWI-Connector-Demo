/*******************************************************************************
FileName:			XTEA.h
Processor:			PIC16F18875
Compiler:			XC8 v2.05
IDE:				MPLABX IDE v5.20
Author:				Erik Fasnacht
Company:			Microchip Technology, Inc.

Summary:			Header file for XTEA.c
    
Description:		Header file for XTEA.c
*******************************************************************************/
/*******************************************************************************
    (c) 2019 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software
    and any derivatives exclusively with Microchip products. It is your
    responsibility to comply with third party license terms applicable to your
    use of third party software (including open source software) that may
    accompany Microchip software.

    You may not export or re-export Software, technical data, direct 
    products thereof or any other items which would violate any applicable
    export control laws and regulations including, but not limited to, 
    those of the United States or United Kingdom.  You agree that it is
    your responsibility to obtain copies of and to familiarize yourself
    fully with these laws and regulations to avoid violation.
    
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

#ifndef XTEA_H
#define	XTEA_H

//******************************************************************************
//******************************************************************************
//Include Declarations
#include "mcc_generated_files/mcc.h"

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

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

