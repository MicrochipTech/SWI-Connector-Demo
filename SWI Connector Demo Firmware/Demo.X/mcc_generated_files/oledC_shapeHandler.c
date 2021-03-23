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
/*
#include <stdint.h>
#include <stdbool.h>
#include "oledC_shapeHandler.h"
#include "oledC_shapes.h"

#define MAX_NUMBER_OF_SHAPES 32

static void dummyshape(shape_t *shape)
{
}

static shape_t allParsedShapes[MAX_NUMBER_OF_SHAPES];

void initShapesMem(void)
{
    uint8_t i;
    for(i = 0; i < MAX_NUMBER_OF_SHAPES; i++)
    {
        allParsedShapes[i].active = false;
        allParsedShapes[i].draw = dummyshape;
    }
}

void oledC_removeShape(uint8_t drawIndex)
{
    uint8_t i;
    for(i = drawIndex; i < (MAX_NUMBER_OF_SHAPES - 1); i++)
    {
        allParsedShapes[i] = allParsedShapes[i+1];
    }
    allParsedShapes[MAX_NUMBER_OF_SHAPES-1].active = false;
}

shape_t* oledC_getShape(uint8_t index)
{
    index = index > MAX_NUMBER_OF_SHAPES ? MAX_NUMBER_OF_SHAPES : index;
    return &allParsedShapes[index];
}

void oledC_addShape(uint8_t drawIndex, enum OLEDC_SHAPE shape_type, shape_params_t *params)
{
    uint8_t i;
    shape_t *newShape;
    drawIndex = drawIndex >= MAX_NUMBER_OF_SHAPES ? (MAX_NUMBER_OF_SHAPES-1) : drawIndex;
    for(i = (MAX_NUMBER_OF_SHAPES-1); i > drawIndex && i > 0; i--)
    {
        allParsedShapes[i] = allParsedShapes[i-1];
    }   
    
    newShape = &allParsedShapes[drawIndex];
    oledC_createShape(shape_type, params, newShape);
}

void oledC_redrawIndex(uint8_t indShape)
{
    allParsedShapes[indShape].draw(&allParsedShapes[indShape]);
}

void oledC_redrawTo(uint8_t endInd)
{
    oledC_redrawSome(0,endInd);
}

void oledC_redrawFrom(uint8_t startInd)
{
    oledC_redrawSome(startInd, MAX_NUMBER_OF_SHAPES);
}

void oledC_redrawSome(uint8_t startInd, uint8_t endInd)
{
    uint8_t i;
    endInd = endInd > MAX_NUMBER_OF_SHAPES ? MAX_NUMBER_OF_SHAPES : endInd;
    for(i = startInd; i < endInd; i++)
    {
        if(allParsedShapes[i].active)
        {
            allParsedShapes[i].draw(&allParsedShapes[i]);
        }
    }
}

void oledC_eraseShape(uint8_t indShape,uint16_t eraseColor)
{
    shape_t* ourShape = oledC_getShape(indShape);
    uint16_t saveColor = ourShape->params.point.color;
    ourShape->params.point.color = eraseColor;
    ourShape->draw(ourShape);
    ourShape->params.point.color = saveColor;
}

void oledC_eraseAll(uint16_t eraseColor)
{
    uint8_t i;
    for(i = 0; i < MAX_NUMBER_OF_SHAPES; i++)
    {
        if(allParsedShapes[i].active)
        {
            oledC_eraseShape(i,eraseColor);
        }
    }
}

void oledC_redrawAll(void)
{
    oledC_redrawSome(0,MAX_NUMBER_OF_SHAPES);
}
*/