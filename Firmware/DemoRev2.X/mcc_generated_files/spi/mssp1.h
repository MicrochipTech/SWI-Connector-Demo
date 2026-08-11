/**
 * SPI1 Generated Driver API Header File
 *
 * @file mssp1.h
 *
 * @defgroup spi1 SPI1
 *
 * @brief This header file provides API prototypes for the SPI1 driver.
 *
 * @version SPI1 Driver Version v5.0.0
 */

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

#ifndef MSSP1_H
#define MSSP1_H

// Section: Included Files
#include "spi_interface.h"

extern const struct SPI_INTERFACE SPI1_Host;

#define SPI1_Host_Initialize SPI1_Initialize
#define SPI1_Host_Deinitialize SPI1_Deinitialize
#define SPI1_Host_Close SPI1_Close
#define SPI1_Host_Open SPI1_Open
#define SPI1_Host_ByteExchange SPI1_ByteExchange
#define SPI1_Host_BufferExchange SPI1_BufferExchange
#define SPI1_Host_BufferWrite SPI1_BufferWrite
#define SPI1_Host_BufferRead SPI1_BufferRead
#define SPI1_Host_ByteWrite SPI1_ByteWrite
#define SPI1_Host_ByteRead SPI1_ByteRead
#define SPI1_Host_IsRxReady SPI1_IsRxReady
#define SPI1_Host_IsTxReady SPI1_IsTxReady

typedef enum {
    HOST_CONFIG,
    MSSP1_DEFAULT
} spi1_configuration_name_t;

void SPI1_Initialize(void);
void SPI1_Deinitialize(void);
bool SPI1_Open(uint8_t spiConfigIndex);
void SPI1_Close(void);
void SPI1_BufferExchange(void *bufferData, size_t bufferSize);
void SPI1_BufferWrite(void *bufferData, size_t bufferSize);
void SPI1_BufferRead(void *bufferData, size_t bufferSize);
uint8_t SPI1_ByteExchange(uint8_t byteData);
void SPI1_ByteWrite(uint8_t byteData);
uint8_t SPI1_ByteRead(void);
bool SPI1_IsRxReady(void);
bool SPI1_IsTxReady(void);

#endif
