/* 
 * File:   ccp1.h
 * Author: Mohamed Samy
 *
 * Created on June 14, 2024, 10:21 AM
 */

#ifndef CCP1_H
#define	CCP1_H

/*Include Section*/
#include "ccp1_cfg.h"
#include "../GPIO_MODULES/hal_GPIO.h"
#include "../proc/pic18f46k20.h"
#include "../GPIO_MODULES/hal_GPIO.h"
#include "../TIMER2/timer2.h"
/*Macros Declarations Section*/



#define CCP_DISABLE                                 0X0
#define COMPARE_MODE_TOGGLE_OUTPUT_ON_MATCH         0X2
#define CAPTURE_MODE_AT_EVERY_FALLING_EDGE          0X4
#define CAPTURE_MODE_AT_EVERY_RISING_EDGE           0X5
#define CAPTURE_MODE_AT_EVERY_4_RISING_EDGE         0X6
#define CAPTURE_MODE_AT_EVERY_16_RISING_EDGE        0X7
#define COMPARE_MODE_SET_CCP1_PIN                   0X8
#define COMPARE_MODE_CLEAR_CCP1_PIN                 0X9
#define COMPARE_MODE_GENERATE_SW_INTERRUPT          0X10
#define COMPARE_MODE_TRIGGER_SPECIAL_EVENT          0X11
#define PWM_MODE_ENABLE                             0X0F


#define CAPTURE_MODE                                0U
#define COMPARE_MODE                                1U
#define PWM_MODE                                    2U

/*Macros Function Declarations Section*/

#define CCP_CFG(_MODE_)             (CCP1CONbits.CCP1M=_MODE_)






/*Data Type Function Declarations Section*/
typedef enum{
    TIMER1_COMPARE_CAPTURE_CLK_CCP,
    TIMER3_TIMER1_COMPARE_CAPTURE_CLK_CCP2_CCP1,
    TIMER3_COMPARE_CAPTURE_CLK_CCP,
}ccp_timer_cfg;

typedef union{
    struct{
        uint8 ccpr_low;  /* CCPR1 low register */
        uint8 ccpr_high; /* CCPR1 high register */
    };
    struct{
        uint16 ccpr_16Bit; /* Read CCPR1 as a 16 Bit value */
    };
}CCP_REG_T;


typedef struct{
//#if CCP1_INTERRUPT_ENABLE_CFG == _CCP1_INTERRUPT_ENABLE_
//    void(*CCP1_Interrupt_handler)(void);
//    priority_t priority;
//#endif
    uint8 ccp1_mode;
    uint16 ccp1_variant;
#if CCP1_MODE == CCP1_CAPTURE_MODE || CCP1_MODE == CCP1_COMPARE_MODE
    uint8 timer_cfg;
#elif CCP1_MODE == CCP1_PWM_MODE
    uint16 duty_value;
    uint8 PWM_Frequency;
    uint8 timer2_prescaler;
    uint8 postscaler_mode  :4;
#endif
}ccp1_t;

/*Function Declarations Section*/
Std_ReturnType mcal_ccp1_initialization(const ccp1_t *ccp1);
Std_ReturnType mcal_ccp1_DeInitialization(const ccp1_t *ccp1);
Std_ReturnType mcal_ccp1_capture_get_value(const ccp1_t *ccp1,uint16 *value);

Std_ReturnType mcal_ccp1_compare_write_value(const ccp1_t *ccp1,uint16 value);

Std_ReturnType mcal_ccp1_pwm_set_duty(const ccp1_t *ccp1,uint16 value);

#endif	/* CCP1_H */

