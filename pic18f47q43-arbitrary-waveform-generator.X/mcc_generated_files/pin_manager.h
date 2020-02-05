/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F47Q43
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set POTENTIOMETER aliases
#define POTENTIOMETER_TRIS                 TRISAbits.TRISA0
#define POTENTIOMETER_LAT                  LATAbits.LATA0
#define POTENTIOMETER_PORT                 PORTAbits.RA0
#define POTENTIOMETER_WPU                  WPUAbits.WPUA0
#define POTENTIOMETER_OD                   ODCONAbits.ODCA0
#define POTENTIOMETER_ANS                  ANSELAbits.ANSELA0
#define POTENTIOMETER_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define POTENTIOMETER_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define POTENTIOMETER_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define POTENTIOMETER_GetValue()           PORTAbits.RA0
#define POTENTIOMETER_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define POTENTIOMETER_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define POTENTIOMETER_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define POTENTIOMETER_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define POTENTIOMETER_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define POTENTIOMETER_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define POTENTIOMETER_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define POTENTIOMETER_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set LCDMini_nCS2 aliases
#define LCDMini_nCS2_TRIS                 TRISAbits.TRISA2
#define LCDMini_nCS2_LAT                  LATAbits.LATA2
#define LCDMini_nCS2_PORT                 PORTAbits.RA2
#define LCDMini_nCS2_WPU                  WPUAbits.WPUA2
#define LCDMini_nCS2_OD                   ODCONAbits.ODCA2
#define LCDMini_nCS2_ANS                  ANSELAbits.ANSELA2
#define LCDMini_nCS2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LCDMini_nCS2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LCDMini_nCS2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LCDMini_nCS2_GetValue()           PORTAbits.RA2
#define LCDMini_nCS2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LCDMini_nCS2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LCDMini_nCS2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LCDMini_nCS2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LCDMini_nCS2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LCDMini_nCS2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LCDMini_nCS2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define LCDMini_nCS2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set CS_SD aliases
#define CS_SD_TRIS                 TRISAbits.TRISA3
#define CS_SD_LAT                  LATAbits.LATA3
#define CS_SD_PORT                 PORTAbits.RA3
#define CS_SD_WPU                  WPUAbits.WPUA3
#define CS_SD_OD                   ODCONAbits.ODCA3
#define CS_SD_ANS                  ANSELAbits.ANSELA3
#define CS_SD_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define CS_SD_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define CS_SD_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define CS_SD_GetValue()           PORTAbits.RA3
#define CS_SD_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define CS_SD_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define CS_SD_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define CS_SD_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define CS_SD_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define CS_SD_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define CS_SD_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define CS_SD_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSELB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSELB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set S1_BUTTON aliases
#define S1_BUTTON_TRIS                 TRISBbits.TRISB4
#define S1_BUTTON_LAT                  LATBbits.LATB4
#define S1_BUTTON_PORT                 PORTBbits.RB4
#define S1_BUTTON_WPU                  WPUBbits.WPUB4
#define S1_BUTTON_OD                   ODCONBbits.ODCB4
#define S1_BUTTON_ANS                  ANSELBbits.ANSELB4
#define S1_BUTTON_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define S1_BUTTON_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define S1_BUTTON_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define S1_BUTTON_GetValue()           PORTBbits.RB4
#define S1_BUTTON_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define S1_BUTTON_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define S1_BUTTON_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define S1_BUTTON_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define S1_BUTTON_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define S1_BUTTON_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define S1_BUTTON_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define S1_BUTTON_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSELB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set S2_BUTTON aliases
#define S2_BUTTON_TRIS                 TRISCbits.TRISC5
#define S2_BUTTON_LAT                  LATCbits.LATC5
#define S2_BUTTON_PORT                 PORTCbits.RC5
#define S2_BUTTON_WPU                  WPUCbits.WPUC5
#define S2_BUTTON_OD                   ODCONCbits.ODCC5
#define S2_BUTTON_ANS                  ANSELCbits.ANSELC5
#define S2_BUTTON_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define S2_BUTTON_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define S2_BUTTON_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define S2_BUTTON_GetValue()           PORTCbits.RC5
#define S2_BUTTON_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define S2_BUTTON_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define S2_BUTTON_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define S2_BUTTON_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define S2_BUTTON_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define S2_BUTTON_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define S2_BUTTON_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define S2_BUTTON_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set LCDMini_nReset aliases
#define LCDMini_nReset_TRIS                 TRISDbits.TRISD2
#define LCDMini_nReset_LAT                  LATDbits.LATD2
#define LCDMini_nReset_PORT                 PORTDbits.RD2
#define LCDMini_nReset_WPU                  WPUDbits.WPUD2
#define LCDMini_nReset_OD                   ODCONDbits.ODCD2
#define LCDMini_nReset_ANS                  ANSELDbits.ANSELD2
#define LCDMini_nReset_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define LCDMini_nReset_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define LCDMini_nReset_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define LCDMini_nReset_GetValue()           PORTDbits.RD2
#define LCDMini_nReset_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define LCDMini_nReset_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define LCDMini_nReset_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define LCDMini_nReset_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define LCDMini_nReset_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define LCDMini_nReset_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define LCDMini_nReset_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define LCDMini_nReset_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set LCDMini_nCS aliases
#define LCDMini_nCS_TRIS                 TRISDbits.TRISD3
#define LCDMini_nCS_LAT                  LATDbits.LATD3
#define LCDMini_nCS_PORT                 PORTDbits.RD3
#define LCDMini_nCS_WPU                  WPUDbits.WPUD3
#define LCDMini_nCS_OD                   ODCONDbits.ODCD3
#define LCDMini_nCS_ANS                  ANSELDbits.ANSELD3
#define LCDMini_nCS_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define LCDMini_nCS_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define LCDMini_nCS_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define LCDMini_nCS_GetValue()           PORTDbits.RD3
#define LCDMini_nCS_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define LCDMini_nCS_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define LCDMini_nCS_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define LCDMini_nCS_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define LCDMini_nCS_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define LCDMini_nCS_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define LCDMini_nCS_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define LCDMini_nCS_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/