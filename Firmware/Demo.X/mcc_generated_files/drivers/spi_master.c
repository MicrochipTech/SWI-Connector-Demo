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

/**
  Section: Included Files
 */

#include "spi_master.h"

bool oledC_open(void);

const spi_master_functions_t spiMaster[] = {   
    //{ SPI2_Close, oledC_open, SPI2_ExchangeByte, SPI2_ExchangeBlock, SPI2_WriteBlock, SPI2_ReadBlock, SPI2_WriteByte, SPI2_ReadByte, NULL, NULL }
    { SPI2_Close, oledC_open, SPI2_ExchangeByte, SPI2_ExchangeBlock, SPI2_WriteBlock, NULL, NULL }
};

bool oledC_open(void){
    return SPI2_Open(oledC_CONFIG);
}

//This function serves keep backwards compatibility with older api users
/*
bool spi_master_open(spi_master_configurations_t config){
    switch(config){
        case oledC:
            return oledC_open();
        default:
            return 0;
    }
}
*/
/**
 End of File
 */
