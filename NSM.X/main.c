/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K20
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/i2c_slave.h"
#include "DC_MOTOR/ecu_dc_motor.h"
#include "LED/ecu_led.h"
#include "GPIO_MODULES/hal_GPIO.h"
#include "GPIO_MODULES/mcal_std_types.h"
/*
                         Main application
 */
uint8_t mmmm=0;
uint8_t ggggg=0;
led_t led={.port = 3,.pin=0,.led_logic=0};

motor_t motor={.motor[0].direction=0,
               .motor[0].logic=0,
               .motor[0].pin=6,
               .motor[0].port=3,
               .motor[1].direction=0,
               .motor[1].logic=0,
               .motor[1].pin=7,
               .motor[1].port=3,

};


void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    I2C_Open();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
              ecu_motor_initialization(&motor);
              ecu_led_initialization(&led);
              CLEAR_BIT(TRISE,1);
              CLEAR_BIT(TRISB,4);
              CLEAR_BIT(TRISB,0);
              CLEAR_BIT(TRISB,2);
              CLEAR_BIT(TRISB,3);
              

    while (1)
    {
        ggggg=SSPBUF;
       
        switch(ggggg){
            case 'a': ecu_motor_move_right(&motor);
                        ggggg=0;
            break;
            case 'b': ecu_motor_stop(&motor);
                        ggggg=0;
            break;
            case 'c': ecu_led_on(&led);
                        ggggg=0;
            break;
            case 'd': ecu_led_off(&led);
                        ggggg=0;
            break;
            case 'e':   SET_BIT(LATE,1);
                        __delay_ms(.5);
                        CLEAR_BIT(LATE,1);
                       __delay_ms(1000);
                        ggggg=0;
            break;
            case 'q':  SET_BIT(LATE,1);
                       __delay_ms(10.4999);
                       CLEAR_BIT(LATE,1);
                       __delay_ms(1000);
                        ggggg=0;
            break;
            case 'm':  SET_BIT(LATB,0);
                       SET_BIT(LATB,2);
                       
                        ggggg=0;
            break;
            case 'l':  CLEAR_BIT(LATB,0);
                       CLEAR_BIT(LATB,2);
                       
                       
                        ggggg=0;
            break;
            default:ggggg=0;
            break;

                
        }
      
              

    }
}
/**
 End of File
*/