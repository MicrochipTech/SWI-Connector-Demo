/*******************************************************************************
FileName:			XTEA.c
Processor:			PIC16F18875
Compiler:			XC8 v4.00
IDE:				MPLABX IDE v6.35
Author:				Erik Fasnacht
Company:			Microchip Technology, Inc.

Summary:			Encryption/Decryption solution using XTEA
    
Description:		Module for encrypting/decrypting data using 
                    the second revision of the Tiny Encryption Algorithm
  				    (commonly called XTEA, TEAN, and TEA-n).
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

//******************************************************************************
//******************************************************************************
//Include Declarations
#include "XTEA.h"

//******************************************************************************
//******************************************************************************              
//encryption function 
void encryption(uint8_t iterations, uint32_t data[2]) {
    
    uint32_t data0 = data[0];
    uint32_t data1 = data[1];
    uint32_t sum = 0;
    uint32_t magicConst = 0x9E3779B9;
    
    for (uint8_t ii = 0; ii < iterations; ii++) 
    {
        data0 += (((data1 << 4) ^ (data1 >> 5)) +data1) ^ (sum + key[sum & 3]);
        sum += magicConst;
        data1 += (((data0 << 4) ^ (data0 >> 5)) + data0) ^ (sum + key[(sum>>11) & 3]);
    }
    
    data[0]=data0; data[1]=data1;
}

//******************************************************************************
//******************************************************************************              
//decryption function 
void decryption(uint8_t iterations, uint32_t data[2]) {
    
    uint32_t data0 = data[0];
    uint32_t data1 = data[1];
    uint32_t magicConst = 0x9E3779B9;
    uint32_t sum = magicConst*iterations;
    
    for (uint8_t ii = 0; ii < iterations; ii++) 
    {
        data1 -= (((data0 << 4) ^ (data0 >> 5)) + data0) ^ (sum + key[(sum>>11) & 3]);
        sum -= magicConst;
        data0 -= (((data1 << 4) ^ (data1 >> 5)) + data1) ^ (sum + key[sum & 3]);
    }
    
    data[0]=data0; data[1]=data1;
}