/* 
 * File:   mcal_interrupt_common_config.h
 * Author: Mohamed Samy
 *
 * Created on May 15, 2024, 3:08 PM
 */

#ifndef MCAL_INTERRUPT_COMMON_CONFIG_H
#define	MCAL_INTERRUPT_COMMON_CONFIG_H

/*Include Section*/
#include "../proc/pic18f46k20.h"
#include "../GPIO_MODULES/mcal_std_types.h"
#include "mcal_interrupt_gen_cfg.h"
#include "../GPIO_MODULES/hal_GPIO.h"

/*Macros Declarations Section*/

typedef enum{
    INTERRUPT_LOW_PRIORITY,
    INTERRUPT_HIGH_PRIORITY
}priority_t;

typedef enum{
    INTERRUPT_DISABLE,
    INTERRUPT_ENABLE
}interrupt_state_t;

#define CLEAR_FLAG      0U

/*Macros Function Declarations Section*/



/*Data Type Function Declarations Section*/

/*Function Declarations Section*/       

#endif	/* MCAL_INTERRUPT_COMMON_CONFIG_H */

