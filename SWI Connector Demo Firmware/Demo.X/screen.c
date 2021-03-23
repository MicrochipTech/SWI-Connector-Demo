/*******************************************************************************
FileName:			screen.c
Processor:			PIC16F18875
Compiler:			XC8 v2.05
IDE:				MPLABX IDE v5.20
Author:				Erik Fasnacht
Company:			Microchip Technology, Inc.

Summary:			OLED C Solution
    
Description:		This solution implements what is shown on the OLED screen
                    for the connector demo.
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
#include "screen.h"

//******************************************************************************
//******************************************************************************               
//reverse and itoa function implementation

/* A utility function to reverse a string  */
void reverse(char str[], int length) 
{ 
    int start = 0; 
    int end = length -1; 
    uint8_t temp;                    //temp variable
    while (start < end) 
    { 
        temp = str[start];          //temp equals address of str + start
        str[start] = str[end];      //str[start] equals address of str + stop
        str[end] = temp;            //str[end] equals temp swapping start and stop
        start++;                    //increment start variable
        end--;                      //decrement end variable
    } 
} 

// Implementation of itoa() 
char* itoa(int num, char* str, int base) 
{ 
    int i = 0; 
    bool isNegative = false; 
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
  
    // In standard itoa(), negative numbers are handled only with  
    // base 10. Otherwise numbers are considered unsigned. 
    if (num < 0 && base == 10) 
    { 
        isNegative = true; 
        num = -num; 
    } 
  
    // Process individual digits 
    while (num != 0) 
    { 
        int rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
  
    // If number is negative, append '-' 
    if (isNegative) 
        str[i++] = '-'; 
  
    str[i] = '\0'; // Append string terminator 
  
    // Reverse the string 
    reverse(str, i); 
  
    return str; 
} 

//******************************************************************************
//******************************************************************************               
//Set background color and clear screen
void oledC_clearScreen(void) 
{    
    uint8_t x;
    uint8_t y;
    oledC_setColumnAddressBounds(0,96);
    oledC_setRowAddressBounds(0,96);
    for(x = 0; x < 96; x++)
    {
        for(y = 0; y < 96; y++)
        {
            oledC_sendColorInt(background_color);
        }
    }
}

void oledC_setBackground(uint16_t color)
{
    background_color = color;
    oledC_clearScreen();
}

//******************************************************************************
//******************************************************************************               
//startup screens with meatball and text
void oledC_startup(void)
{          
    oledC_setBackground(OLEDC_COLOR_WHITE);
    
    oledC_DrawBitmap(14,5,OLEDC_COLOR_RED,2,2,(uint32_t*)&logo[0],23);
    oledC_DrawBitmap(14,7,OLEDC_COLOR_BLACK,2,2,(uint32_t*)&copyright[0],1);
   
    oledC_DrawString(22,55,1,1,mchp,OLEDC_COLOR_BLACK);

    oledC_DrawString(5,75,2,2,swi,OLEDC_COLOR_BLACK);
}

//******************************************************************************
//******************************************************************************               
//screen for reading EEPROM
void oledC_read(void)
{   
    oledC_setBackground(OLEDC_COLOR_WHITE);
        
    oledC_DrawString(15,85,1,1,read, OLEDC_COLOR_BLACK);
    
    oledC_DrawBitmap(14,56,OLEDC_COLOR_BLACK,2,2,(uint32_t*)&body2[0], 13);                      
    oledC_DrawBitmap(14,58,OLEDC_COLOR_DARKGRAY,2,2,(uint32_t*)&pin2[0], 11);        
    __delay_ms(500);
    
    oledC_DrawBitmap(14,44,OLEDC_COLOR_RED,2,2,(uint32_t*)&arrowfrom[0], 5);        
    __delay_ms(500);
    
    oledC_DrawBitmap(14,6,OLEDC_COLOR_BLACK,2,2,(uint32_t*)&body1[0], 16); 
    oledC_DrawBitmap(14,2,OLEDC_COLOR_DARKGRAY,2,2,(uint32_t*)&pin1[0], 20);
    oledC_DrawString(38,17,1,1, mcu,OLEDC_COLOR_WHITE);
    __delay_ms(500);
}

//******************************************************************************
//******************************************************************************               
//screen for writing to EEPROM
void oledC_write(void)
{   
    oledC_setBackground(OLEDC_COLOR_WHITE);   
    
    oledC_DrawString(13,85,1,1,write,OLEDC_COLOR_BLACK);  
    
    oledC_DrawBitmap(14,6,OLEDC_COLOR_BLACK,2,2,(uint32_t*)&body1[0],16); 
    oledC_DrawBitmap(14,2,OLEDC_COLOR_DARKGRAY,2,2,(uint32_t*)&pin1[0],20);
    oledC_DrawString(38,17,1,1, mcu,OLEDC_COLOR_WHITE);
    __delay_ms(500);
    
    oledC_DrawBitmap(14,44,OLEDC_COLOR_RED,2,2,(uint32_t*)&arrowto[0],5);       
    __delay_ms(500);
    
    oledC_DrawBitmap(14,56,OLEDC_COLOR_BLACK,2,2,(uint32_t*)&body2[0],13);
    oledC_DrawBitmap(14,58,OLEDC_COLOR_DARKGRAY,2,2,(uint32_t*)&pin2[0],11);
    __delay_ms(500);
}
//******************************************************************************
//******************************************************************************               
//screen when device is detected from Discovery
void oledC_correct(void)
{            
    oledC_setBackground(OLEDC_COLOR_WHITE);   
    
    oledC_DrawBitmap(18,1,OLEDC_COLOR_GREEN,2,2,(uint32_t*)&check[0],28);
    
    oledC_DrawString(10,62,2,2,genuine,OLEDC_COLOR_BLACK);
    //__delay_ms(500);
     
    oledC_DrawString(9,85,1,1,cntPrint,OLEDC_COLOR_BLACK);

    char countStringc[6];
    itoa(count,countStringc,10);  //convert integer to string for DrawString function    
    oledC_DrawString(57,85,1,1,countStringc,OLEDC_COLOR_BLACK);  
    //__delay_ms(500);
}

//******************************************************************************
//******************************************************************************               
//screen when device is detected from Discovery
void oledC_incorrect(void)
{      
    /* //removed as Chris suggested the count be shown even when incorrect
    oledC_setBackground(OLEDC_COLOR_WHITE);   
    
    oledC_DrawBitmap(14,2,OLEDC_COLOR_RED,2,2,(uint32_t*)&x[0],32);
    
    oledC_DrawString(10,75,2,2,fake,OLEDC_COLOR_BLACK);
    __delay_ms(500);   
    oledC_setBackground(OLEDC_COLOR_WHITE);   
    
    oledC_DrawBitmap(14,2,OLEDC_COLOR_RED,2,2,(uint32_t*)&x[0],32);
    
    oledC_DrawString(10,75,2,2,fake,OLEDC_COLOR_BLACK);
    __delay_ms(500);  
    */
    
    oledC_setBackground(OLEDC_COLOR_WHITE);   
    
    oledC_DrawBitmap(14,1,OLEDC_COLOR_RED,2,2,(uint32_t*)&x[0],32);
    
    oledC_DrawString(10,67,2,2,fake,OLEDC_COLOR_BLACK);
    //__delay_ms(500);  
     
    oledC_DrawString(9,85,1,1,cntPrint,OLEDC_COLOR_BLACK);

    char countStringi[6];
    itoa(count,countStringi,10);  //convert integer to string for DrawString function    
    oledC_DrawString(57,85,1,1,countStringi,OLEDC_COLOR_BLACK);  
    //__delay_ms(500);   
  
}

//******************************************************************************
//******************************************************************************               
//screen for erasing EEPROM (count & encryption)
void oledC_clear(void)
{   
    oledC_setBackground(OLEDC_COLOR_WHITE);   
    
         
    oledC_DrawString(3, 85, 1,1,rstCount,OLEDC_COLOR_BLACK); 
    __delay_ms(1000);
    
    oledC_DrawRectangle(0,70,100,100,OLEDC_COLOR_WHITE);
    oledC_DrawString(13,85,1,1,erase,OLEDC_COLOR_BLACK);   
    
    oledC_DrawBitmap(14,6,OLEDC_COLOR_BLACK,2,2,(uint32_t *)&body1[0],16); 
    oledC_DrawBitmap(14,2,OLEDC_COLOR_DARKGRAY,2,2,(uint32_t *)&pin1[0],20);
    __delay_ms(500);
    
    oledC_DrawBitmap(14,44,OLEDC_COLOR_RED,2, 2,(uint32_t *)&arrowto[0],5);       
    __delay_ms(500);
    
    oledC_DrawBitmap(14,56,OLEDC_COLOR_BLACK,2, 2,(uint32_t *)&body2[0],13);
    oledC_DrawBitmap(14,58,OLEDC_COLOR_DARKGRAY,2,2,(uint32_t *)&pin2[0],11);   
    //__delay_ms(500);
}

//******************************************************************************
//******************************************************************************               
//screen for encrypting EEPROM
void oledC_encrypt(void)
{   
    oledC_setBackground(OLEDC_COLOR_WHITE);
    
    
    oledC_DrawString(9,85,1,1,snRead,OLEDC_COLOR_BLACK);
    
    oledC_DrawBitmap(14,56,OLEDC_COLOR_BLACK,2,2,(uint32_t *)&body2[0],13);                      
    oledC_DrawBitmap(14,58,OLEDC_COLOR_DARKGRAY,2,2,(uint32_t *)&pin2[0],11);
    __delay_ms(500);
    
    oledC_DrawBitmap(14,44,OLEDC_COLOR_RED,2,2,(uint32_t *)&arrowfrom[0],5);        
    __delay_ms(500);
    
    oledC_DrawBitmap(14,6,OLEDC_COLOR_BLACK,2,2,(uint32_t *)&body1[0],16); 
    oledC_DrawBitmap(14,2,OLEDC_COLOR_DARKGRAY,2,2,(uint32_t *)&pin1[0],20);
    __delay_ms(500);
    
    oledC_DrawRectangle(0,70,100,100,OLEDC_COLOR_WHITE);  
    
      
    oledC_DrawString(3, 85, 1,1,encrypt,OLEDC_COLOR_BLACK);     
    oledC_DrawRectangle(0,42,70,70,OLEDC_COLOR_WHITE);  
    __delay_ms(500);
    //__delay_ms(1000);
    
    oledC_DrawRectangle(0,70,100,100,OLEDC_COLOR_WHITE);     
    oledC_DrawString(3, 85, 1,1,rstCount,OLEDC_COLOR_BLACK); 
    __delay_ms(500);
    //__delay_ms(1000);
    
    oledC_DrawRectangle(0,70,100,100,OLEDC_COLOR_WHITE);     
    oledC_DrawString(13,85,1,1,write,OLEDC_COLOR_BLACK);    
    __delay_ms(500);
    
    oledC_DrawBitmap(14,44,OLEDC_COLOR_RED,2,2,(uint32_t *)&arrowto[0],5);       
    __delay_ms(500);
    
    oledC_DrawBitmap(14,56,OLEDC_COLOR_BLACK,2,2,(uint32_t *)&body2[0],13);  
    oledC_DrawBitmap(14,58,OLEDC_COLOR_DARKGRAY,2,2,(uint32_t *)&pin2[0],11);
    __delay_ms(500);
}