 /**
   PWM5 Generated Driver File  
 
   @Company
     Microchip Technology Inc. 

   @File Name
     pwm5.c

   @Summary
     This is the generated driver implementation file for the PWM5 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs 

   @Description
     This header file provides implementations for driver APIs for PWM5.
     Generation Information :
         Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs  - 1.45
         Device            :  PIC16F18313
         Driver Version    :  2.00
     The generated drivers are tested against the following:
         Compiler          :  XC8 1.35
         MPLAB             :  MPLAB X 3.40
 */

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

 #ifndef _PWM5_H
 #define _PWM5_H
 
 /**
   Section: Included Files
 */

 #include <xc.h>
 #include <stdint.h>

 #ifdef __cplusplus  // Provide C++ Compatibility

     extern "C" {

 #endif

 /**
   Section: Macro Declarations
 */

 #define PWM5_INITIALIZE_DUTY_VALUE    9

 /**
   Section: PWM Module APIs
 */

 /**
   @Summary
     Initializes the PWM5

   @Description
     This routine initializes the EPWM5_Initialize
     This routine must be called before any other PWM5 routine is called.
     This routine should only be called once during system initialization.

   @Preconditions
     None

   @Param
     None

   @Returns
     None

   @Comment
     

  @Example
     <code>
     uint16_t dutycycle;

     PWM5_Initialize();
     PWM5_LoadDutyValue(dutycycle);
     </code>
  */
 void PWM5_Initialize(void);

 /**
   @Summary
     Loads 16-bit duty cycle.

   @Description
     This routine loads the 16 bit duty cycle value.

   @Preconditions
     PWM5_Initialize() function should have been called 
         before calling this function.

   @Param
     Pass 16bit duty cycle value.

   @Returns
     None

   @Example
     <code>
     uint16_t dutycycle;

     PWM5_Initialize();
     PWM5_LoadDutyValue(dutycycle);
     </code>
 */
 void PWM5_LoadDutyValue(uint16_t dutyValue);
 
 #ifdef __cplusplus  // Provide C++ Compatibility

     }

 #endif

 #endif	//PWM5_H
 /**
  End of File
 */