/* 
 * File:   timer2.h
 * Author: Mohamed Samy
 *
 * Created on June 13, 2024, 1:47 PM
 */

#ifndef TIMER2_H
#define	TIMER2_H

/*Include Section*/
#include "timer2_cfg.h"
#include "../GPIO_MODULES/hal_GPIO.h"
#include "../proc/pic18f46k20.h"
#include "../GPIO_MODULES/mcal_std_types.h"

/*Macros Function Declarations Section*/

#define TIMER2_ENABLE()                     (T2CONbits.TMR2ON=1)
#define TIMER2_DISABLE()                    (T2CONbits.TMR2ON=0)

#define POSTSCALER_SELECT(_cfg_)             (T2CONbits.T2OUTPS=_cfg_)
    



/*Data Type Function Declarations Section*/

/*Enum Data Type for Prescaler Format*/
typedef enum{
    TIMER2_PRESCALER_DIV_BY_1,
    TIMER2_PRESCALER_DIV_BY_4,
    TIMER2_PRESCALER_DIV_BY_16,

}timer2_prescaler_cfg;


/*Struct Data Type for Timer2 Configurations*/
typedef struct {
//#if TIMER2_INTERRUPT_ENABLE_CFG == _TIMER2_INTERRUPT_DISABLE_
//    void (*Timer2_interrrupt_handler)(void);
//    priority_t priority;
//#endif
    uint8 prescaler_mode   :2;
    uint8 postscaler_mode  :4;
    uint8 reserved_bits    :2;
    uint8 preload_value;

}timer2_t;

/*Macros Declarations Section*/

#define TIM2_POSTSCALER_DIV_BY_1                      0
#define TIM2_POSTSCALER_DIV_BY_2                      1
#define TIM2_POSTSCALER_DIV_BY_3                      2
#define TIM2_POSTSCALER_DIV_BY_4                      3
#define TIM2_POSTSCALER_DIV_BY_5                      4
#define TIM2_POSTSCALER_DIV_BY_6                      5
#define TIM2_POSTSCALER_DIV_BY_7                      6
#define TIM2_POSTSCALER_DIV_BY_8                      7
#define TIM2_POSTSCALER_DIV_BY_9                      8
#define TIM2_POSTSCALER_DIV_BY_10                     9
#define TIM2_POSTSCALER_DIV_BY_11                     10
#define TIM2_POSTSCALER_DIV_BY_12                     11
#define TIM2_POSTSCALER_DIV_BY_13                     12
#define TIM2_POSTSCALER_DIV_BY_14                     13
#define TIM2_POSTSCALER_DIV_BY_15                     14
#define TIM2_POSTSCALER_DIV_BY_16                     15

/*Function Declarations Section*/

/**
 * @brief       :Timer2 initialization by specified configuration 
 * @param timer   : pointer to struct of Timer2 configuration
 * @return      : Std_ReturnType has to cases :
 *                  E_OK :- indicate that the function work and finished it's functionality successfully
 *                  E_NOK:- indicate that the function failed to finish it's functionality 
 */
Std_ReturnType mcal_timer2_initialization (timer2_t *timer);

/**
 * @brief       :Timer2 DeInitialization by specified configuration 
 * @param timer   : pointer to struct of Timer2 configuration
 * @return      : Std_ReturnType has to cases :
 *                  E_OK :- indicate that the function work and finished it's functionality successfully
 *                  E_NOK:- indicate that the function failed to finish it's functionality 
 */
Std_ReturnType mcal_timer2_DeInitialization (timer2_t *timer);

/**
 * @brief                   : Write Value in Timer2 Counter Regesters 
 * @param timer             : pointer to struct of Timer2 configuration
 *@param preload_value      : Argument to pass the preload_value which will be written in TM2 Regester to compare it with PR2
 * @return                  : Std_ReturnType has to cases :
*                           E_OK :- indicate that the function work and finished it's functionality successfully
*                           E_NOK:- indicate that the function failed to finish it's functionality 
 */
Std_ReturnType mcal_timer2_write_in_tmr2 (timer2_t *timer,uint8 preload_value);


/**
 * @brief                   : Write Value in Timer2 Counter Regesters 
 * @param timer             : pointer to struct of Timer2 configuration
 *@param pr2_value          : Argument to pass the pr2_value which will be written in pr2 Regester to compare it with TM2
 * @return                  : Std_ReturnType has to cases :
*                           E_OK :- indicate that the function work and finished it's functionality successfully
*                           E_NOK:- indicate that the function failed to finish it's functionality 
 */
Std_ReturnType mcal_timer2_write_in_pr2 (timer2_t *timer,uint8 pr2_value);

/**
 * @brief           : Read Value From Timer2 Counter Regesters 
 * @param timer     : pointer to struct of Timer2 configuration
 * @param value     : pointer to uint16 to store the value of Timer2 Counter Regesters
 * @return          : Std_ReturnType has to cases :
 *                  E_OK :- indicate that the function work and finished it's functionality successfully
 *                  E_NOK:- indicate that the function failed to finish it's functionality 
 */
Std_ReturnType mcal_timer2_read (timer2_t *timer,uint8 *value);




#endif	/* TIMER2_H */

