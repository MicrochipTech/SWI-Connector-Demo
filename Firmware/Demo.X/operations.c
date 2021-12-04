/*******************************************************************************
FileName:			operations.c
Processor:			PIC16F18875
Compiler:			XC8 v2.05
IDE:				MPLABX IDE v5.20
Author:				Erik Fasnacht
Company:			Microchip Technology, Inc.

Summary:			Functions for various operations in single-wire protocol
    
Description:		This file includes functions for the various operations used
                    by the AT21CS Series devices.
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
//Include Declarations
#include "mcc_generated_files/mcc.h"
#include "operations.h"
#include "low-level.h"

//******************************************************************************
//******************************************************************************        
//Scan for Slave Address Routine

uint8_t scanDeviceAddress(){

    uint8_t temp;
    uint8_t address;
    
    for(uint8_t ii =0; ii < 8; ii++)            //loop for all 8 slave addresses
	{
		if(discoveryResponse() == 0)            //perform device discovery
		{
			startHS();                          //start condition 
			temp = ii;
			temp <<= 1;                         //shift address to proper bit position
			temp |= 0xA0;                       //add EEPROM op code and set R/W = 0		 
			if(txByte(temp) == 0x00)            //If the device ACKs
			{
				address = ii;                   //set slave address equal to loop count
				address <<= 1;                  //shift address to proper bit position
				startHS();                      //start condition 
				break;                          //break from loop
			}
		}
	}
    
return address;                                 //return ACK'd slave address
}


//******************************************************************************
//******************************************************************************                       
//Write Sequence
void eepromWrite(uint8_t dByte, uint8_t aByte, uint8_t writeData[],uint8_t count){
    
    dByte |= slaveAddress;   //set slave address 
    
    startHS();                                  //start condition    
    txByte(dByte);                              //Device Address Byte     
    txByte(aByte);                              //Word Address Byte
    for (uint8_t ii = 0; ii < count; ii++)	{   //loop for data to be written
        txByte(writeData[ii]);                  //Data Byte(s) to be written   
    }
    startHS();                                  //stop condition
    __delay_ms(5);                              //tWC Delay  
}

//******************************************************************************
//******************************************************************************                       
//Write count Sequence
void countWrite(uint8_t dByte, uint8_t aByte, uint16_t writeData){
    
    uint8_t temp;                               //temp variable
    dByte |= slaveAddress;   //set slave address 
    
    startHS();                                  //start condition    
    txByte(dByte);                              //Device Address Byte     
    txByte(aByte);                              //Word Address Byte
    temp = ((writeData >> 8) & 0xFF);           //shift write data to the right by 8 anded with mask
    txByte(temp);                               //write temp byte to device
    temp = (writeData & 0xFF);                  //write data anded with mask
    txByte(temp);                               //write temp byte to device
    startHS();                                  //stop condition
    __delay_ms(5);                              //tWC Delay  
}

//******************************************************************************
//******************************************************************************                       
//Random Address Read Sequence
void randomRead(uint8_t dByte, uint8_t aByte, uint8_t *readData, uint8_t count){

    dByte |= slaveAddress;   //set slave address                

    startHS();                                  //start condition    
    txByte(dByte);                              //Device Address Byte     
    txByte(aByte);                              //Word Address Byte
    startHS();                                  //start condition 
    txByte((uint8_t)(dByte | 0x01));            //Device Address Byte
    for (uint8_t ii = 0; ii < count; ii++)	{   //loop for bytes to be written         
        readData[ii] = readByte();              //read a byte 
        if (ii < (count-1)) {   tx0();  }       //send an ACK
    }    
    tx1();                                      //send a NACK
    startHS();                                  //stop condition
/*    
    printf("    Data Read =");                  //TX character string over UART
    for (uint8_t ii = 0; ii < count; ii++)  {
        printf(" 0x");                          //TX character string over UART
        printf("%02X", readData[ii]);           //"%02X" for two char ^case hex
    }
    printf("\n");                               //create a new line
*/
}

//******************************************************************************
//******************************************************************************                       
//Random Address Read Sequence
uint16_t countRead(uint8_t dByte, uint8_t aByte){
    
    uint16_t temp;
    uint8_t msb;                               //temp variable 
    uint8_t lsb;                               //temp variable  
    dByte |= slaveAddress;   //set slave address                

    startHS();                                  //start condition    
    txByte(dByte);                              //Device Address Byte     
    txByte(aByte);                              //Word Address Byte
    startHS();                                  //start condition 
    txByte((uint8_t)(dByte | 0x01));            //Device Address Byte        
    msb = readByte();                          //read a byte
    tx0();                                      //send ACK
    //readData = ((temp << 8)& 0xFF);             //sets temp as MSB of readData
    //readData = (temp & 0xFF);
    //readData = (temp & 0xFF);
    //(readData << 8) & 0xFF00;
    lsb = readByte();                          //read a byte       
    tx1();                                      //send NACK
    //readData = (temp & 0xFF);                   //sets temp as LSB of readData
    //readData = ((temp >> 8)& 0xFF); 
   
    temp = (msb <<8)|(lsb & 0xFF);
    startHS();                                  //stop condition
/*   
    printf("MSB = "); 
    printf("%02X\n", msb); 
    printf("LSB = "); 
    printf("%02X\n", lsb); 
    printf("count = "); 
    printf("%02X\n", temp); 
*/
    return temp;
}
