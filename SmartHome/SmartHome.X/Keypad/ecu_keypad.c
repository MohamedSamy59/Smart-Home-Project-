/* 
 * File:   ecu_keypad.c
 * Author: Mohamed Samy
 *
 * Created on April 26, 2024, 10:20 PM
 */

/*Include Interfaces Header File Section */
#include "ecu_keypad.h"
#define _XTAL_FREQ 8000000

/*Global Variable Definition Section*/

static const uint8 arr[KEYPAD_ROWS_NUMBER][KEYPAD_COLUMNS_NUMBER] = {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'#','0','=','+'}};

/*APIs Definition Section*/

Std_ReturnType ecu_keypad_initialization(const keypad_t *keypad){
    Std_ReturnType ret = E_OK;
    uint8 counter1 = ZERO_INIT;
    uint8 counter2 = ZERO_INIT;

    if(NULL == keypad){
        ret = E_NOK;
    }
    else{
        for(counter1=ZERO_INIT;counter1<KEYPAD_ROWS_NUMBER;counter1++){
            ret = gpio_pin_initialization(&(keypad->row_pin[counter1]));
        }
         for(counter2=ZERO_INIT;counter2<KEYPAD_COLUMNS_NUMBER;counter2++){
            ret = gpio_pin_initialization(&(keypad->column_pin[counter2]));
        }
    }
    return ret;
            
}


Std_ReturnType ecu_keypad_get_value(const keypad_t *keypad,uint8 *value){
    Std_ReturnType ret = E_OK;
    uint8 counter1 = ZERO_INIT;
    uint8 counter2 = ZERO_INIT;
    uint8 counter3 = ZERO_INIT;
    uint8 counter4 = ZERO_INIT;
    uint8 logic    = ZERO_INIT;     
    if((NULL == keypad)||(NULL == value)){
        ret = E_NOK;
    }
    else{
        for(counter1=ZERO_INIT;counter1<KEYPAD_ROWS_NUMBER;counter1++){
            counter2 = pow(2,counter1);
            for(counter3=ZERO_INIT ; counter3<KEYPAD_ROWS_NUMBER;counter3++){
                  ret =gpio_pin_write_logic(&(keypad->row_pin[counter3]),(counter2 >> counter3) & 0x01);
                 
            }


         for(counter4=ZERO_INIT;counter4<KEYPAD_COLUMNS_NUMBER;counter4++){
            ret = gpio_pin_read_logic (&(keypad->column_pin[counter4]),&logic );
            if(logic==1){
              *value = arr[counter1][counter4];
              //__delay_ms (100);

            }
                              
        }
    }
        }
    return ret;
            
}
