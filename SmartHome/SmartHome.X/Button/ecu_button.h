/* 
 * File:   ecu_button.h
 * Author: Mohamed Samy
 *
 * Created on April 12, 2024, 9:26 PM
 */

#ifndef ECU__BUTTON_H
#define	ECU__BUTTON_H
/*Include Section*/
#include "ecu_button_cfg.h"
#include "../GPIO_MODULES/hal_GPIO.h"
/*Macros Declarations Section



/*Macros Function Declarations Section*/



/*Data Type Function Declarations Section*/
typedef enum {
    BUTTON_RELEASED,
    BUTTON_PUSHED
}button_t;

typedef enum{
    ACTIVE_LOW,
    ACTIVE_HIGH
    
}button_active_t;

typedef struct {
   pin_config_t button_pin;
   button_active_t button_connection;      
}button_chs_t;


/*Function Declarations Section*/

Std_ReturnType ecu_button_initialization (const button_chs_t *my_button);
Std_ReturnType ecu_button_read_status(const button_chs_t *my_button,button_t *status);


#endif	/* ECU__BUTTON_H */

