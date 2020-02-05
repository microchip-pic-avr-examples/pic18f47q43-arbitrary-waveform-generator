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

#include "mcc_generated_files/mcc.h"
#include "dma.h"
#include "constants.h"
#include "file_manager.h"
#include "button.h"

static void configure(void) {
    SYSTEM_Initialize();
    ADCC_StartConversion(POTENTIOMETER);
    dma_initialize();
    enumerate_files();
    lcd_setContrast(0x20);
}

void menu(void) {
    static uint8_t menu_selection = 0;
    static current_source = 255; // No current source

    if (s2_was_pressed()) {
        if(menu_selection == current_source){
            // Was displaying CURRENT_STRING, so change it
            lcd_writeString(SELECT_STRING, 0);
        }
        
        menu_selection++;

        if (menu_selection == num_files) {
            menu_selection = 0;
        }
        
        if(menu_selection == current_source){
            lcd_writeString(CURRENT_STRING, 0);
        }

        lcd_writeString(file_metadata[menu_selection], 1);
    }

    if (s1_is_pressed()) {
        load_waveform(menu_selection);
        current_source = menu_selection;
    }
}

void main(void) {
    configure();   

    lcd_writeString(file_metadata[0], 1);
    lcd_writeString(SELECT_STRING, 0);

    uint8_t empty_buffer[] = {0, 0, 0};
    dma_setSource(0, empty_buffer, 1);


    while (1) {
        menu();
    }

}
