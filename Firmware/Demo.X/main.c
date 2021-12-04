/*******************************************************************************
FileName:			main.c
Processor:			PIC16F18875
Compiler:			XC8 v2.05
IDE:				MPLABX IDE v5.20
Author:				Erik Fasnacht
Company:			Microchip Technology, Inc.

Summary:			AT21CS Series Connector Demo Solution
    
Description:		This solution shows a simple Single-Wire implementation of
					writing to and reading from an AT21CS Series Serial EEPROM
					using a PIC16F18875 MCU. Hardware used in creating this
					example solution is the Curiosity HPC Board.
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

//******************************************************************************
//******************************************************************************
//Include Declarations
#include "mcc_generated_files/mcc.h"
#include "XTEA.h"
#include "screen.h"
#include "operations.h"

//******************************************************************************
//******************************************************************************               
//global variable declarations
uint8_t slaveAddress = 0x00;                            //slave address = 000b (initial)
uint8_t communicationSpeed = 0;                         //0=high-speed; 1=Standard
uint16_t count = 0x0000;                                //global variable for connector count

//******************************************************************************
//******************************************************************************         
//******************************************************************************
//******************************************************************************
//Main Application
void main(void)
{
    
    SYSTEM_Initialize();                                //MCC, initialize the device

// When using interrupts, set the Global and Peripheral Interrupt Enable bits
// Use the following macros to:
    INTERRUPT_GlobalInterruptEnable();                  //enable Global Interrupts
    INTERRUPT_PeripheralInterruptEnable();              //enable Peripheral Interrupts
    //INTERRUPT_GlobalInterruptDisable();               //disable Global Interrupts
    //INTERRUPT_PeripheralInterruptDisable();           //disable Peripheral Interrupts       
    
//******************************************************************************
//******************************************************************************              
//SI/O pin initialization               
    SIO_SetOpenDrain();                                 //sets SIO pin to be open drain
    SIO_SetHigh();                                      //initial set HIGH for SI/O
    SIO_SetDigitalOutput();                             //sets SI/O pin to be digital
     
//******************************************************************************
//******************************************************************************              
//Variable Declaration   
    uint8_t testCount = 0;                              //count for comparing data read from eeprom
    uint8_t pressed = 0;                                //variable for if S1 or S2 is pressed to stop incrementing count
    uint8_t lowData[64] = { 0 };                        //array for lower half of array
    uint8_t highData[64] = { 0 };                       //array for upper half of array
    uint8_t snData[8] = { 0 };                          //array for the serial number read from security register
    static const uint8_t erasePage[8] = {               //sets page = 0xFF
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};      
    static const uint8_t eraseCountPage[8] = {
        0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};       //resets count and remainder bytes = 0xFF
    
    union data                                          //union used to overlay 8-bit and 32-bit variables
    {
        uint8_t readsnData[8];                          //8-bit array for data for write/read of eeprom
        uint32_t readecData[2];                         //32-bit array for data for encryption/decryption
    };
    union data dataval;                                 //variable dataval for calling union data (8-bit readsnData or 32-bit readecData) 

//******************************************************************************
//******************************************************************************              
//encrypt data and reset counter      
    if (S1_GetValue() == 0)                             //switch S1 pressed
    {
        oledC_encrypt();                                //encrypt eeprom screen
               
        scanDeviceAddress();                            //scan to determine slave address                

        randomRead(0xB0,0x00,dataval.readsnData,8);     //read the 64-bit serial number

        encryption(64,dataval.readecData);              //encrypt serial number

        discoveryResponse();                            //discovery reset
        
        eepromWrite(0xA0, 0x08,dataval.readsnData,8);   //write encrypted data to page 1 of the array
        
        countWrite(0xA0,0x00,0x0001);                   //write the count to 1

        while (S1_GetValue() == 0);                     //wait while S1 is pressed 
        pressed = 1;                                    //count won't increment

    }
        
//******************************************************************************
//******************************************************************************              
//clear (write to 0xFF) entire eeprom array
    if (S2_GetValue() == 0)                             //switch S2 pressed
    {          
        oledC_clear();                                  //clear eeprom screen

        scanDeviceAddress();                            //scan to determine slave address  
        
        eepromWrite(0xA0, 0x00,eraseCountPage,8);       //erase page0 and initialize count to 1

        for (uint8_t ii = 0; ii < 120; ii+=8)           //loop to write rest of array to 0xFF
        {                    
            eepromWrite(0xA0,ii+0x08,erasePage,8);      //write operation
        }

        randomRead(0xA0, 0x00, lowData, 64);            //read lower half of array
        
        randomRead(0xA0, 0x40, highData, 64);           //read upper half of array
            
        while (S2_GetValue() == 0);                     //wait while S2 is pressed
        pressed = 1;                                    //count won't increment                            
    }          

//******************************************************************************
//******************************************************************************              
//oled initialization        
    oledC_startup();                                    //initial screen on startup        

//******************************************************************************
//******************************************************************************              
//MAIN CODE LOOP            
    while (1)
    {
           
//******************************************************************************
//******************************************************************************              
//while loop for a wait until connector is connected 
        SIO_SetLow();                                   //initial set LOW for SI/O
        SIO_SetHigh();                                  //initial set HIGH for SI/O        
        while(SIO_GetValue() == 0);                     //wait until the SWI Board is connected (look for pull-up)
        
        while(discoveryResponse() == 0xFF);             //wait until an ACK  (connector connected)
        __delay_ms(100);                                //delay after detection for SI/O to reset (pulled to logic '1')
    
//******************************************************************************
//******************************************************************************              
//read serial number and encrypted data from main array     
        scanDeviceAddress();                            //scan to determine slave address 
        
        randomRead(0xB0,0x00,snData,8);                 //read the 64-bit serial number 
        
        randomRead(0xA0,0x08,dataval.readsnData,8);     //read the encrypted data from main array 

        decryption(64,dataval.readecData);              //decrypt serial number from main array
       
        testCount = 0;                                  //reset count for data read
        for (uint8_t ii = 0; ii < 8; ii++){
            snData[ii];                                 
            dataval.readsnData[ii];
            if (snData[ii] == dataval.readsnData[ii]){  //compare Serial number to decrypted data
                testCount++;                            //if equal, increment the count
            }
        }
              
//******************************************************************************
//******************************************************************************              
//test for whether the connector is genuine and incrementing the count         
        count = countRead(0xA0,0x00);                   //read count before the increment
        if (pressed == 0)
        {
            count++;                                    //increment the count 
            countWrite(0xA0,0x00,count);                //write the count 
        }
                      
        count = countRead(0xA0,0x00);                   //read count (confirmation of write & increment)
        pressed = 0;                                    //reinitialize pressed variable
     
        if (testCount == 8) { oledC_correct(); }        //genuine connector
        else    { oledC_incorrect(); }                  //counterfeit connector screen
                       
//******************************************************************************
//******************************************************************************              
//while loop for a wait as the connector is still connected       
        while(discoveryResponse() == 0x00)              //wait until a NACK  (connector disconnected)
        {
            
//******************************************************************************
//******************************************************************************              
//read data from the eeprom array and save in ram       
            if (S1_GetValue() == 0)                     //switch S1 pressed
            {
                oledC_read();                           //read from eeprom screen

                //printf("lower half Data Read\n"); 
                randomRead(0xA0, 0x00, lowData, 64);    //read lower half of array
                //printf("upper half Data Read\n"); 
                randomRead(0xA0, 0x40, highData, 64);   //read upper half of array

                while (S1_GetValue() == 0);             //wait while S1 is pressed 
                pressed = 1;                            //count won't increment
                break;                                  //break to main code loop
            }
        
//******************************************************************************
//******************************************************************************              
//clone data saved in ram and write to the entire eeprom array
            if (S2_GetValue() == 0)                     //switch S2 pressed
            {          
                oledC_write();                          //write to eeprom screen
                               
                uint8_t ii;
                for (ii = 0; ii < 64; ii+=8)            //write lower half of array
                {                    
                    eepromWrite(0xA0,ii,lowData+ii,8);  //write operation
                }
                for (ii = 0; ii < 64; ii+=8)            //write upper half of array
                {
                    eepromWrite(0xA0,ii+0x40,highData+ii,8);
                }

                while (S2_GetValue() == 0);             //wait while S2 is pressed                
                pressed = 1;                            //count won't increment                
                break;                                  //break to main code loop
            }        
        }

//******************************************************************************
//******************************************************************************              
//move back to startup                
        oledC_startup();                                //move screen back to startup
    }                
}
/**
 End of File
*/