/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
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
*/

#include "dma.h"
#include <xc.h>

void dma_initialize(void){
    // LUT to DAC
    DMASELECT = 0;
    
    DMAnCON1bits.DMODE = 0b00; // Destination pointer unchanged
    DMAnCON1bits.SMODE = 0b01; // Increment source pointer
     
    DMAnDSA = &DAC1DATL;
    
    DMAnDSZL = 1; // Destination size 1
    
    DMAnSIRQ = 0x1B; // TMR2 trigger
    DMAnCON0bits.SIRQEN = 1; // Allow hardware to trigger start
    
    
    
    //ADC to Timer
    DMASELECT = 1;
    
    // Destination TMR0H
    DMAnDSA = &T2PR;
    
    DMAnDSZL = 1; // Destination size 1
    
    DMAnSSZH = 0;
    DMAnSSZL = 1; // Source size 1
    
    // Source ADC
    DMAnSSA = &ADRESH;
    
    DMAnSIRQ = 0xA; // ADC Conversion
    DMAnCON0bits.SIRQEN = 1; // Allow hardware to trigger start
    DMAnCON0bits.EN = 1;
    
    
    
    // Start DMA
    PRLOCK = 0x55;
    PRLOCK = 0xAA;
    PRLOCKbits.PRLOCKED = 1;
}

void dma_setSource(uint8_t dma, void * source, uint16_t length){
    DMASELECT = dma;
    DMAnCON0bits.EN = 0;
    
    DMAnSSA = source;
    
    DMAnSSZH = (length >> 8) & 0xFF;
    DMAnSSZL = length & 0xFF;
    
    DMAnCON0bits.EN = 1;
}
