/* 
 * File:   ecu_led.c
 * Author: Mohamed Samy
 *
 * Created on March 19, 2024, 9:05 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/*Include Section*/
#include "../GPIO_MODULES/hal_GPIO.h"
#include "ecu_led_cfg.h"
/*Macros Declarations Section*/



/*Macros Function Declarations Section*/



/*Data Type Function Declarations Section*/

typedef enum {
    LED_OFF,
    LED_ON
}led_status;

typedef struct{
    uint8 port : 4;
    uint8 pin   :3;
    uint8 led_logic    :1;
}led_t;


/*Function Declarations Section*/

/**
 * 
 * @param   : pointer to struct of led Details
 * @return  return the status of the funcion :
             E_OK  : when the function execute successfully
             E_NOK : when the function failed to execute 
 */
Std_ReturnType ecu_led_initialization(const led_t *led);


/**
 * 
 * @param   : pointer to struct of led Details
 * @return  return the status of the funcion :
             E_OK  : when the function execute successfully
             E_NOK : when the function failed to execute 
 */
Std_ReturnType ecu_led_on(const led_t *led);



/**
 * 
 * @param   : pointer to struct of led Details
 * @return  return the status of the funcion :
             E_OK  : when the function execute successfully
             E_NOK : when the function failed to execute 
 */
Std_ReturnType ecu_led_off(const led_t *led);




/**
 * 
 * @param   : pointer to struct of led Details
 * @return  return the status of the funcion :
             E_OK  : when the function execute successfully
             E_NOK : when the function failed to execute 
 */
Std_ReturnType ecu_led_toggle(const led_t *led);


#endif	/* ECU_LED_H */

