/* 
 * File:   ecu_dc_motor.h
 * Author: Mohamed Samy
 *
 * Created on April 18, 2024, 6:52 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/*Include Section*/
#include "ecu_dc_motor_cfg.h"
#include "../GPIO_MODULES/hal_GPIO.h"
/*Macros Declarations Section



/*Macros Function Declarations Section*/



/*Data Type Function Declarations Section*/


typedef enum {
    DC_MOTOR_OFF_STATUS,
    DC_MOTOR_ON_STATUS
}dc_motor_status;

typedef struct {
    pin_config_t motor[2];
}motor_t;

/*Function Declarations Section*/

/**
 * @brief           : initialization the pin
 * @param motor     : pointer to structure motor_t
 * @return          : return the status of the funcion :
                         E_OK  : when the function execute successfully
                         E_NOK : when the function failed to execute 
 */
Std_ReturnType ecu_motor_initialization(const motor_t *my_motor);


/**
 * @brief           : move the motor forward
 * @param motor     : pointer to structure motor_t
 * @return          : return the status of the funcion :
                         E_OK  : when the function execute successfully
                         E_NOK : when the function failed to execute 
 */
Std_ReturnType ecu_motor_move_right(const motor_t *my_motor);


/**
 * @brief           : move the motor backward
 * @param motor     : pointer to structure motor_t
 * @return          : return the status of the funcion :
                         E_OK  : when the function execute successfully
                         E_NOK : when the function failed to execute 
 */
Std_ReturnType ecu_motor_move_left(const motor_t *my_motor);


/**
 * @brief           : stopping the motor moving
 * @param motor     : pointer to structure motor_t
 * @return          : return the status of the funcion :
                         E_OK  : when the function execute successfully
                         E_NOK : when the function failed to execute 
 */
Std_ReturnType ecu_motor_stop(const motor_t *my_motor);

#endif	/* ECU_DC_MOTOR_H */

