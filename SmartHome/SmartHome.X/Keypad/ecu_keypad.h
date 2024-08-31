/* 
 * File:   ecu_keypad.h
 * Author: Mohamed Samy
 *
 * Created on April 26, 2024, 10:20 PM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H


/*Include Section*/
#include "../GPIO_MODULES/hal_GPIO.h"
#include "ecu_keypad_cfg.h"

/*Macros Declarations Section*/

#define KEYPAD_ROWS_NUMBER       4
#define KEYPAD_COLUMNS_NUMBER    4

/*Macros Function Declarations Section*/



/*Data Type Function Declarations Section*/
typedef struct {
    pin_config_t row_pin[KEYPAD_ROWS_NUMBER];
    pin_config_t column_pin[KEYPAD_COLUMNS_NUMBER];
}keypad_t;


/*Function Declarations Section*/

Std_ReturnType ecu_keypad_initialization(const keypad_t *keypad);
Std_ReturnType ecu_keypad_get_value(const keypad_t *keypad,uint8 *value);

#endif	/* ECU_KEYPAD_H */

