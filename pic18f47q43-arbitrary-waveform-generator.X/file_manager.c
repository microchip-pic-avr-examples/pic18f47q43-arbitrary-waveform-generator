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

#include "file_manager.h"
#include "mcc_generated_files/mcc.h"
#include "pff/pff.h"
#include "pff/diskio.h"
#include "dma.h"

void enumerate_files(void) {
    FATFS fs; /* File system object */
    FRESULT status;
    do {
        status = pf_mount(&fs);
    } while (status != FR_OK);

    char location_string[] = {'0'};
    uint8_t placeholder;

    // Scan through possible files
    while (num_files < MAX_NUM_FILES) {


        uint8_t status = pf_open(location_string);

        if (status != FR_OK) { // File doesn't exist, therefore all files read
            return;
        }

        pf_read(file_metadata[num_files], FILE_METADATA_LENGTH, placeholder);

        num_files++;
        location_string[0]++;
    }
}

void load_waveform(uint8_t waveform) {
    uint8_t length = file_metadata[waveform][LENGTH_LOCATION];
    static uint8_t file_buffer[READ_SIZE];
    uint8_t placeholder;

    char location_string[] = "0";
    location_string[0] += waveform;

    pf_open(location_string);
    lcd_writeString(CURRENT_STRING, 0);

    pf_read(file_buffer, FILE_METADATA_LENGTH, placeholder);
    pf_read(file_buffer, length, &length);

    // Set the DMA to output the contents of file buffer for length bytes
    dma_setSource(0, file_buffer, length);

}
