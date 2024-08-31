/* 
 * File:   timer0.h
 * Author: Mohamed Samy
 *
 * Created on June 3, 2024, 12:58 PM
 */

#ifndef TIMER0_H
#define	TIMER0_H

/*Include Section*/
#include "timer0_cfg.h"
#include "../GPIO_MODULES/hal_GPIO.h"
#include "../INTERRUPT/mcal_internal_interrupt.h"
#include "../proc/pic18f46k20.h"
#include "../GPIO_MODULES/mcal_std_types.h"

/*Macros Function Declarations Section*/

#define TIMER0_ENABLE()                     (T0CONbits.TMR0ON=1)
#define TIMER0_DISABLE()                    (T0CONbits.TMR0ON=0)

#define TIMER0_8BITS_CFG()                  (T0CONbits.T08BIT=1)
#define TIMER0_16BITS_CFG()                 (T0CONbits.T08BIT=0)

#define TIMER0_TIMER_MODE()                 (T0CONbits.T0CS=0)
#define TIMER0_COUNTER_MODE()               (T0CONbits.T0CS=1)

#define TIMER0_RISING_EDGE()                (T0CONbits.T0SE=0)
#define TIMER0_FALLING_EDGE()               (T0CONbits.T0SE=1)
    
#define TIMER0_PRESCALER_ENABLE()           (T0CONbits.PSA=0)
#define TIMER0_PRESCALER_DISABLE()          (T0CONbits.PSA=1)


/*Data Type Function Declarations Section*/

/*Enum Data Type for Prescaler Format*/
typedef enum{
    PRESCALER_DIV_BY_2,
    PRESCALER_DIV_BY_4,
    PRESCALER_DIV_BY_8,
    PRESCALER_DIV_BY_16,
    PRESCALER_DIV_BY_32,
    PRESCALER_DIV_BY_64,
    PRESCALER_DIV_BY_128,
    PRESCALER_DIV_BY_256,

}timer0_prescaler_cfg;


/*Struct Data Type for Timer0 Configurations*/
typedef struct {
#if TIMER0_INTERRUPT_ENABLE_CFG == _TIMER0_INTERRUPT_ENABLE_
    void (*Timer0_interrrupt_handler)(void);
    priority_t priority;
#endif
    uint8 prescaler_on_off :1;
    uint8 prescaler_mode   :3;
    uint8 timer_mode       :1;
    uint8 timer_reg_size   :1;
    uint8 timer_edge       :1;
    uint8 reserved_bits    :1;
    uint16 preload_value;

}timer0_t;

/*Macros Declarations Section*/
#define TIMER0_8BITS_MODE               1
#define TIMER0_16BITS_MODE              0
#define TIMER_MODE                      0
#define COUNTER_MODE                    1
#define RISING_EDGE                     0
#define FALIING_EDGE                    1
#define PRESCALER_ENABLE                0
#define PRESCALER_DISABLE               1
/*Function Declarations Section*/

/**
 * @brief       :Timer0 initialization by specified configuration 
 * @param timer   : pointer to struct of Timer0 configuration
 * @return      : Std_ReturnType has to cases :
 *                  E_OK :- indicate that the function work and finished it's functionality successfully
 *                  E_NOK:- indicate that the function failed to finish it's functionality 
 */
Std_ReturnType mcal_timer0_initialization (timer0_t *timer);

/**
 * @brief       :Timer0 DeInitialization by specified configuration 
 * @param timer   : pointer to struct of Timer0 configuration
 * @return      : Std_ReturnType has to cases :
 *                  E_OK :- indicate that the function work and finished it's functionality successfully
 *                  E_NOK:- indicate that the function failed to finish it's functionality 
 */
Std_ReturnType mcal_timer0_DeInitialization (timer0_t *timer);

/**
 * @brief                   : Write Value in Timer0 Counter Regesters 
 * @param timer             : pointer to struct of Timer0 configuration
 *@param preload_value      : Argument to pass the preload_value which will be written in Timer0 Counter Regesters
 * @return                  : Std_ReturnType has to cases :
*                           E_OK :- indicate that the function work and finished it's functionality successfully
*                           E_NOK:- indicate that the function failed to finish it's functionality 
 */
Std_ReturnType mcal_timer0_write (timer0_t *timer,uint16 preload_value);

/**
 * @brief           : Read Value From Timer0 Counter Regesters 
 * @param timer     : pointer to struct of Timer0 configuration
 * @param value     : pointer to uint16 to store the value of Timer0 Counter Regesters
 * @return          : Std_ReturnType has to cases :
 *                  E_OK :- indicate that the function work and finished it's functionality successfully
 *                  E_NOK:- indicate that the function failed to finish it's functionality 
 */
Std_ReturnType mcal_timer0_read (timer0_t *timer,uint16 *value);


#endif	/* TIMER0_H */

