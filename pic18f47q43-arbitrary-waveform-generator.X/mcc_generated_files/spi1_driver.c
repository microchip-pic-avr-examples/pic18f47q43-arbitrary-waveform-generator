/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <xc.h>
#include "spi1_driver.h"

#pragma warning disable 520

void (*spi1_interruptHandler)(void); 

inline void spi1_close(void)
{
    SPI1CON0bits.EN = 0;
}

//con0 == SPIxCON0, con1 == SPIxCON1, con2 == SPIxCON2, baud == SPIxBAUD, operation == Master/Slave
typedef struct { uint8_t con0; uint8_t con1; uint8_t con2; uint8_t baud; uint8_t operation;} spi1_configuration_t;
static const spi1_configuration_t spi1_configuration[] = {   
    { 0x2, 0x40, 0x0, 0x1f, 0 },
    { 0x2, 0x40, 0x0, 0xff, 0 },
    { 0x2, 0x40, 0x0, 0xff, 0 }
};

//Setup SPI
bool spi1_open(spi1_modes spiUniqueConfiguration)
{
    if(!SPI1CON0bits.EN)
    {
        SPI1CON0 = spi1_configuration[spiUniqueConfiguration].con0;
        SPI1CON1 = spi1_configuration[spiUniqueConfiguration].con1;
        SPI1CON2 = spi1_configuration[spiUniqueConfiguration].con2 | 0x03;
        SPI1CLK = 0x00;
        SPI1BAUD = spi1_configuration[spiUniqueConfiguration].baud;
        
        SPI1CON0bits.EN = 1;
        TRISBbits.TRISB1 = spi1_configuration[spiUniqueConfiguration].operation;
        return true;
    }
    return false;
}

// Full Duplex SPI Functions
uint8_t spi1_exchangeByte(uint8_t b)
{
    SPI1TCNTL = 1;
    SPI1TXB = b;
    while(!PIR3bits.SPI1RXIF);
    return SPI1RXB;
}

void spi1_exchangeBlock(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        *data = spi1_exchangeByte(*data );
        data++;
    }
}

// Half Duplex SPI Functions
void spi1_writeBlock(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        spi1_exchangeByte(*data++);
    }
}

void spi1_readBlock(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        *data++ = spi1_exchangeByte(0);
    }
}

void spi1_writeByte(uint8_t byte){
    SPI1TXB = byte;
}

uint8_t spi1_readByte(void){
    return SPI1RXB;
}

/**
 * Interrupt from SPI on bit 8 received and SR moved to buffer
 * If interrupts are not being used, then call this method from the main while(1) loop
 */
void spi1_isr(void){
    if(PIR3bits.SPI1RXIF == 1){
        if(spi1_interruptHandler){
            spi1_interruptHandler();
        }
        PIR3bits.SPI1RXIF = 0;
    }
}

void spi1_setSpiISR(void(*handler)(void)){
    spi1_interruptHandler = handler;
}
