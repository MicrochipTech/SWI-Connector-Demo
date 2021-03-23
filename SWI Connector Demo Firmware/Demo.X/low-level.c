/*******************************************************************************
FileName:			low-level.c
Processor:			PIC16F18875
Compiler:			XC8 v2.05
IDE:				MPLABX IDE v5.20
Author:				Erik Fasnacht
Company:			Microchip Technology, Inc.

Summary:			Low-Level Functions for single-wire protocol
    
Description:		This file includes low-level functions used to create 
                    single-wire protocol using a standard I/O pin.
*******************************************************************************/
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

//******************************************************************************
//******************************************************************************               
//include declarations
#include "mcc_generated_files/mcc.h"
#include "low-level.h"

//******************************************************************************
//******************************************************************************               
//Global Variable Declarations
//extern uint8_t communicationSpeed;              //0=high-speed; 1=Standard

//******************************************************************************
//******************************************************************************        
//Discovery Reset Response Routine
uint8_t discoveryResponse(){
  
uint8_t temp;                                   //temp variable

    SIO_SetHigh();
    __delay_us(200);                            //delay for tHTSS (STD Speed)
    SIO_SetLow();
    __delay_us(500);                            //delay for tRESET (STD Speed)
    SIO_SetHigh();
    __delay_us(20);                             //delay for tRRT

    SIO_SetLow();
    __delay_us(1);                              //delay for tDRR
    SIO_SetHigh();
    __delay_us(2);                              //delay for tMSDR
    if(SIO_GetValue() == 0){ temp = 0x00; }     //if device ACKs
    else { temp = 0xFF; }                       //if device NACKs
    __delay_us(21);                             //delay (tDACK-(tDDR+tMSDR))
    SIO_SetHigh();
    
communicationSpeed = 0;                         //device defaults to high-speed    
return temp;
}  

//******************************************************************************
//******************************************************************************                       
//Start/Stop Condition Routine
void startHS(){
    SIO_SetHigh();
    if (communicationSpeed == 0)    {           //DUT set for High-Speed
        __delay_us(200);                        //delay tHTSS (High Speed)
    }
    
    else    {
        __delay_us(650);                        //delay tHTSS (Standard Speed)
    }        
}   

//******************************************************************************
//******************************************************************************                        
//Transmit Logic '1' Routine
void tx1(){
    
    if (communicationSpeed == 0)    {           //DUT set for High-Speed
        SIO_SetLow();
        __delay_us(1);                          //delay tLOW1 (High Speed)
        SIO_SetHigh();
        __delay_us(14);                         //delaytBIT (High Speed)
    }
    
    else    {                                   //DUT set for Standard Speed
        SIO_SetLow();
        __delay_us(4);                          //delay tLOW1 (Standard Speed)
        SIO_SetHigh();
        __delay_us(41);                         //delay tBIT (Standard Speed)
    }
}      

//******************************************************************************
//******************************************************************************                        
//Transmit Logic '0' Routine
void tx0(){
    
    if (communicationSpeed == 0)    {           //DUT set for High-Speed
        SIO_SetLow();
        __delay_us(10);                         //delay tLOW0 (High Speed)
        SIO_SetHigh();
        __delay_us(5);                          //delay tBIT (High Speed)
    }
    
    else    {                                   //DUT set for Standard Speed
        SIO_SetLow();
        __delay_us(24);                         //delay tLOW0 (Standard Speed)
        SIO_SetHigh();
        __delay_us(21);                         //delay tBIT (Standard Speed)
    }     
} 

//******************************************************************************
//******************************************************************************                       
//Receive ACK/NACK Routine 
uint8_t ackNack(){
    
uint8_t temp;                                   //temp variable

    if (communicationSpeed == 0)    {           //DUT set for High-Speed
        SIO_SetLow();
        __delay_us(1);                          //delay tRD (High Speed)
        SIO_SetHigh();                          //DUT will drive SI/O for ACK
        __delay_us(1);                          //delay tMRS  (High Speed)
        if(SIO_GetValue() == 0){ temp = 0x00;}  //if device ACKs
        else { temp = 0xFF; }                   //if device NACKs
        __delay_us(9);                          //delay tBIT (High Speed)
        SIO_SetHigh(); 
    }

    else    {                                   //DUT set for Standard Speed
        SIO_SetLow();
        __delay_us(4);                          //delay tRD (Standard Speed)
        SIO_SetHigh();                          //DUT will drive SI/O for ACK
        __delay_us(2);                          //delay tMRS (Standard Speed)
        if(SIO_GetValue() == 0){ temp = 0x00;}  //if device ACKs
        else { temp = 0xFF; }                   //if device NACKs
        __delay_us(34);                         //delay tBIT (Standard Speed)
        SIO_SetHigh(); 
    }
        
return temp;       
}

//******************************************************************************
//******************************************************************************                       
//Transmit Byte Routine 
uint8_t txByte(uint8_t dataByte){
    
uint8_t temp;                                   //temp variable
            
    for (uint8_t ii = 0; ii < 8 ; ii++){        //transmit data byte
        if (0x80  & dataByte)  {   tx1();  }
        else   {   tx0();  }
        dataByte <<= 1;
    } 
    temp = ackNack();                           //ACK/NACK Bit
return temp;
}

//******************************************************************************
//******************************************************************************         
//Receive Byte Routine
uint8_t readByte (){

uint8_t temp;                                   //temp variable
uint8_t dataByte = 0x00;                        //variable for data read

    if (communicationSpeed == 0)    {           //DUT set for High-Speed
        for (int8_t ii = 0; ii < 8 ; ii++){
            SIO_SetLow();
            __delay_us(1);                      //delay tRD (High Speed)
            SIO_SetHigh();
            __delay_us(1);                      //delay tMRS  (High Speed)
            NOP();                              //add. delay tMRS  (High Speed)
            NOP();                              //add. delay tMRS  (High Speed)
            temp = SIO_GetValue();              //read state of the SI/O pin
            temp &= 0x01;                       //NDs the bit read w/ bitMask 
            dataByte = (uint8_t)((dataByte << 1) | temp);
            __delay_us(9);                      //delay tBIT (High Speed)
        }   
    }
        
    else    {                                   //DUT set for Standard Speed    
        for (int8_t ii = 0; ii < 8 ; ii++){
            SIO_SetLow();
            __delay_us(4);                      //delay tRD (Standard Speed)
            SIO_SetHigh();
            __delay_us(2);                      //delay tMRS (Standard Speed)     
            temp = SIO_GetValue();              //read state of the SI/O pin
            temp &= 0x01;                       //NDs the bit read w/ bitMask 
            dataByte = (uint8_t)((dataByte << 1) | temp);
            __delay_us(34);                     //delay tBIT (Standard Speed)
        }
    }
return dataByte;
}