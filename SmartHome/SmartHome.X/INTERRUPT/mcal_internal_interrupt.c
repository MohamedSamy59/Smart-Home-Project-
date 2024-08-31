/* 
 * File:   mcal_internal_interrupt.C
 * Author: Mohamed Samy
 *
 * Created on May 15, 2024, 3:02 PM
 */

/*Include Interfaces Header File Section */
#include "mcal_internal_interrupt.h"


/*Global Variable Definition Section*/
  static void (*ADC_handler)(void);  

/*APIs Definition Section*/

 void ADC_handler_init(void (*_handler)(void)){
     
     ADC_handler=_handler;
     
 }
void ISR_ADC(void){
    ADC_CLEAR_FLAG();
    /*ISR CODE*/
    if(ADC_handler){
        ADC_handler();
    }
}
