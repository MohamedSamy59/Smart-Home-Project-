/* 
 * File:   ecu_dc_motor.c
 * Author: Mohamed Samy
 *
 * Created on April 18, 2024, 6:52 PM
 */

/*Include Interfaces Header File Section */
#include "ecu_dc_motor.h"


/*Global Variable Definition Section*/
  static  pin_config_t dc_motor_pin_1;
  static  pin_config_t dc_motor_pin_2;

/*APIs Definition Section*/

Std_ReturnType ecu_motor_initialization(const motor_t *my_motor){
    Std_ReturnType ret = E_OK;
    if(NULL == my_motor){
        ret = E_NOK;
    }
    else{

        
         gpio_pin_direction_intialization (&(my_motor->motor[0]));
         gpio_pin_direction_intialization (&(my_motor->motor[1]));


    }
    return ret;
}


Std_ReturnType ecu_motor_move_right(const motor_t *my_motor){
    Std_ReturnType ret = E_OK;
    if(NULL == my_motor){
        ret = E_NOK;
    }
    else{
  
        gpio_pin_write_logic (&(my_motor->motor[0]), GPIO_HIGH);
        gpio_pin_write_logic (&(my_motor->motor[1]), GPIO_LOW);


    }
    return ret;
}


Std_ReturnType ecu_motor_move_left(const motor_t *my_motor){
    Std_ReturnType ret = E_OK;
    if(NULL == my_motor){
        ret = E_NOK;
    }
    else{
 
        gpio_pin_write_logic (&(my_motor->motor[0]), GPIO_LOW);
        gpio_pin_write_logic (&(my_motor->motor[1]), GPIO_HIGH);


    }
    return ret;
}


Std_ReturnType ecu_motor_stop(const motor_t *my_motor){
    Std_ReturnType ret = E_OK;
    if(NULL == my_motor){
        ret = E_NOK;
    }
    else{

        gpio_pin_write_logic (&(my_motor->motor[0]), GPIO_LOW);
        gpio_pin_write_logic (&(my_motor->motor[1]), GPIO_LOW);


    }
    return ret;
}
