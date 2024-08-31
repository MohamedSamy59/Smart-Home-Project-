/* 
 * File:   ecu_led.h
 * Author: Mohamed Samy
 *
 * Created on March 19, 2024, 9:05 PM
 */


/*Include Interfaces Header File Section */
#include "ecu_led.h"


/*Global Variable Definition Section*/



/*APIs Definition Section*/

#if LED_Config == LED_ENABLE
Std_ReturnType ecu_led_initialization(const led_t *led){
    
    Std_ReturnType ret = E_OK;
    if(NULL==led){
        ret=E_NOK;
    }
    else{
        pin_config_t mid_term={.port=led->port ,.pin=led->pin, .direction=GPIO_DIRECTION_OUTPUT, .logic=led->led_logic};
        gpio_pin_direction_intialization(&mid_term);
    }
    return ret;
}
#endif


#if LED_Config == LED_ENABLE

Std_ReturnType ecu_led_on(const led_t *led){
    
    Std_ReturnType ret = E_OK;
    if(NULL==led){
        ret=E_NOK;
    }
    else{
        pin_config_t mid_term={.port=led->port ,.pin=led->pin, .direction=GPIO_DIRECTION_OUTPUT, .logic=led->led_logic};
        gpio_pin_write_logic(&mid_term,GPIO_HIGH);
    }
    return ret;
}
#endif


#if LED_Config == LED_ENABLE

Std_ReturnType ecu_led_off(const led_t *led){
    
    Std_ReturnType ret = E_OK;
    if(NULL==led){
        ret=E_NOK;
    }
    else{
        pin_config_t mid_term={.port=led->port ,.pin=led->pin, .direction=GPIO_DIRECTION_OUTPUT, .logic=led->led_logic};
        gpio_pin_write_logic(&mid_term,GPIO_LOW);
    }
    return ret;
}
#endif


#if LED_Config == LED_ENABLE

Std_ReturnType ecu_led_toggle(const led_t *led){
    
    Std_ReturnType ret = E_OK;
    if(NULL==led){
        ret=E_NOK;
    }
    else{
        pin_config_t mid_term={.port=led->port ,.pin=led->pin, .direction=GPIO_DIRECTION_OUTPUT, .logic=led->led_logic};
        gpio_pin_toggle_logic(&mid_term);
    }
    return ret;
}
#endif

