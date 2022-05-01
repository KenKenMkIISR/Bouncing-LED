/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.26
        Device            :  PIC16F18313
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA0 aliases
#define IO_RA0_TRIS               TRISAbits.TRISA0
#define IO_RA0_LAT                LATAbits.LATA0
#define IO_RA0_PORT               PORTAbits.RA0
#define IO_RA0_WPU                WPUAbits.WPUA0
#define IO_RA0_OD                ODCONAbits.ODCA0
#define IO_RA0_ANS                ANSELAbits.ANSA0
#define IO_RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define IO_RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define IO_RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define IO_RA0_GetValue()           PORTAbits.RA0
#define IO_RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define IO_RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define IO_RA0_SetPullup()      do { WPUAbits.WPUA0 = 1; } while(0)
#define IO_RA0_ResetPullup()    do { WPUAbits.WPUA0 = 0; } while(0)
#define IO_RA0_SetPushPull()    do { ODCONAbits.ODCA0 = 1; } while(0)
#define IO_RA0_SetOpenDrain()   do { ODCONAbits.ODCA0 = 0; } while(0)
#define IO_RA0_SetAnalogMode()  do { ANSELAbits.ANSA0 = 1; } while(0)
#define IO_RA0_SetDigitalMode() do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA1 procedures
#define RA1_SetHigh()    do { LATAbits.LATA1 = 1; } while(0)
#define RA1_SetLow()   do { LATAbits.LATA1 = 0; } while(0)
#define RA1_Toggle()   do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RA1_GetValue()         PORTAbits.RA1
#define RA1_SetDigitalInput()   do { TRISAbits.TRISA1 = 1; } while(0)
#define RA1_SetDigitalOutput()  do { TRISAbits.TRISA1 = 0; } while(0)
#define RA1_SetPullup()     do { WPUAbits.WPUA1 = 1; } while(0)
#define RA1_ResetPullup()   do { WPUAbits.WPUA1 = 0; } while(0)
#define RA1_SetAnalogMode() do { ANSELAbits.ANSA1 = 1; } while(0)
#define RA1_SetDigitalMode()do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set IO_RA2 aliases
#define IO_RA2_TRIS               TRISAbits.TRISA2
#define IO_RA2_LAT                LATAbits.LATA2
#define IO_RA2_PORT               PORTAbits.RA2
#define IO_RA2_WPU                WPUAbits.WPUA2
#define IO_RA2_OD                ODCONAbits.ODCA2
#define IO_RA2_ANS                ANSELAbits.ANSA2
#define IO_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IO_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IO_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IO_RA2_GetValue()           PORTAbits.RA2
#define IO_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IO_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IO_RA2_SetPullup()      do { WPUAbits.WPUA2 = 1; } while(0)
#define IO_RA2_ResetPullup()    do { WPUAbits.WPUA2 = 0; } while(0)
#define IO_RA2_SetPushPull()    do { ODCONAbits.ODCA2 = 1; } while(0)
#define IO_RA2_SetOpenDrain()   do { ODCONAbits.ODCA2 = 0; } while(0)
#define IO_RA2_SetAnalogMode()  do { ANSELAbits.ANSA2 = 1; } while(0)
#define IO_RA2_SetDigitalMode() do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RA3 procedures
#define RA3_GetValue()         PORTAbits.RA3
#define RA3_SetPullup()     do { WPUAbits.WPUA3 = 1; } while(0)
#define RA3_ResetPullup()   do { WPUAbits.WPUA3 = 0; } while(0)

// get/set IO_RA4 aliases
#define IO_RA4_TRIS               TRISAbits.TRISA4
#define IO_RA4_LAT                LATAbits.LATA4
#define IO_RA4_PORT               PORTAbits.RA4
#define IO_RA4_WPU                WPUAbits.WPUA4
#define IO_RA4_OD                ODCONAbits.ODCA4
#define IO_RA4_ANS                ANSELAbits.ANSA4
#define IO_RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define IO_RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define IO_RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define IO_RA4_GetValue()           PORTAbits.RA4
#define IO_RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define IO_RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define IO_RA4_SetPullup()      do { WPUAbits.WPUA4 = 1; } while(0)
#define IO_RA4_ResetPullup()    do { WPUAbits.WPUA4 = 0; } while(0)
#define IO_RA4_SetPushPull()    do { ODCONAbits.ODCA4 = 1; } while(0)
#define IO_RA4_SetOpenDrain()   do { ODCONAbits.ODCA4 = 0; } while(0)
#define IO_RA4_SetAnalogMode()  do { ANSELAbits.ANSA4 = 1; } while(0)
#define IO_RA4_SetDigitalMode() do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RA5 procedures
#define RA5_SetHigh()    do { LATAbits.LATA5 = 1; } while(0)
#define RA5_SetLow()   do { LATAbits.LATA5 = 0; } while(0)
#define RA5_Toggle()   do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_GetValue()         PORTAbits.RA5
#define RA5_SetDigitalInput()   do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_SetDigitalOutput()  do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_SetPullup()     do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_ResetPullup()   do { WPUAbits.WPUA5 = 0; } while(0)
#define RA5_SetAnalogMode() do { ANSELAbits.ANSA5 = 1; } while(0)
#define RA5_SetDigitalMode()do { ANSELAbits.ANSA5 = 0; } while(0)

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