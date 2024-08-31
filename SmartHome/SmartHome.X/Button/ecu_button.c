/* 
 * File:   ecu_ button.c
 * Author: Mohamed Samy
 *
 * Created on April 12, 2024, 9:26 PM
 */

/*Include Interfaces Header File Section */
#include "ecu_button.h" 


/*Global Variable Definition Section*/

/*APIs Definition Section*/
Std_ReturnType ecu_button_initialization (const button_chs_t *my_button){
    
    Std_ReturnType ret = E_OK;
    if(NULL==my_button){
        ret = E_NOK;
    }       
    
    else{
         gpio_pin_direction_intialization(&(my_button->button_pin));
    }
    return ret;
}

Std_ReturnType ecu_button_read_status(const button_chs_t *my_button,button_t *status){
    Std_ReturnType ret = E_OK;
    logic_t logic;
    if(NULL==my_button || NULL == status){
        ret = E_NOK;
    }       
    
    else{
         gpio_pin_read_logic (&(my_button->button_pin), &logic);

        if(my_button->button_connection == ACTIVE_HIGH){
            if(logic == GPIO_HIGH ){
                *status = BUTTON_PUSHED;
            }
            else{
                 *status = BUTTON_RELEASED;
            }
        }
         
        else if (my_button->button_connection == ACTIVE_LOW){
            if(logic == GPIO_HIGH ){
                *status = BUTTON_RELEASED;
            }
            else{
                 *status = BUTTON_PUSHED;
            }
         }
         
        else{/*Nothing*/}
        }
        return ret;

    }


