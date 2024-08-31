/* 
 * File:   timer2.c
 * Author: Mohamed Samy
 *
 * Created on June 13, 2024, 1:47 PM
 */

/*Include Interfaces Header File Section */
#include "timer2.h"

/*Global Variable Definition Section*/

/*APIs Definition Section*/
static void (*Timer2_interrrupt_ptr)(void);


static Std_ReturnType prescaler_helper(timer2_t *timer);
static Std_ReturnType postscaler_helper(timer2_t *timer);
static uint16 saved_preload_value=ZERO_INIT;
Std_ReturnType mcal_timer2_initialization (timer2_t *timer){
    Std_ReturnType ret = E_OK;
    if(NULL==timer){
        ret= E_NOK;
    }
    else{
        TIMER2_DISABLE();
        prescaler_helper(timer);
        postscaler_helper(timer);
        saved_preload_value=timer->preload_value;
        PR2 = (uint8)(255);
        TMR2=(uint8)((timer->preload_value));
            
//        /*Interrupt Initialization*/
//#if TIMER2_INTERRUPT_ENABLE_CFG == _TIMER2_INTERRUPT_DISABLE_
//        TIMER2_CLEAR_FLAG();
//                        
//        TIMER2_INTERRUPT_ENABLE();
//        
//#if INTERRUPT_PRIORITY_FEATURE==0
//            IPEN_ENABLE();
//            if(timer->priority==INTERRUPT_HIGH_PRIORITY){
//                GIEH_ENABLE();
//                TIMER2_HIGH_PRIORITY();
//            }
//            else if(timer->priority==INTERRUPT_LOW_PRIORITY){
//                GIEH_ENABLE();
//                GIEL_ENABLE();
//                TIMER2_LOW_PRIORITY();
//            }
//            else{   
//            }
//
//#else
//            GIE_ENABLE();
//            PEIE_ENABLE();
//#endif
//              Timer2_interrrupt_ptr=timer->Timer2_interrrupt_handler;
//
//#endif
        TIMER2_ENABLE();
    }
    return ret;
}
Std_ReturnType mcal_timer2_DeInitialization (timer2_t *timer)    {
    Std_ReturnType ret = E_OK;
    if(NULL==timer){
        ret= E_NOK;
    }
    else{
        TIMER2_DISABLE();
       
      
        /*Interrupt DeInitialization*/
#if TIMER2_INTERRUPT_ENABLE_CFG == TIMER2_INTERRUPT_ENABLE
                        
        TIMER2_INTERRUPT_DISABLE();
#endif

    }
    return ret;
}
Std_ReturnType mcal_timer2_write_in_pr2 (timer2_t *timer,uint8 pr2_value){
    Std_ReturnType ret = E_OK;
 if((NULL==timer)){
        ret= E_NOK;
    }
    else{

        PR2=(uint8)((pr2_value));
    }
    return ret;

}
Std_ReturnType mcal_timer2_write_in_tmr2 (timer2_t *timer,uint8 preload_value){
    Std_ReturnType ret = E_OK;
 if((NULL==timer)){
        ret= E_NOK;
    }
    else{

        TMR2=(uint8)((preload_value));
    }
    return ret;

}
Std_ReturnType mcal_timer2_read (timer2_t *timer,uint8 *value){
    Std_ReturnType ret = E_OK;
    uint8 timer2=ZERO_INIT;
    if((NULL==timer)||(NULL==value)){
        ret= E_NOK;
    }
    else{
         
          *value =(uint8)TMR2;

     
    }
    return ret;
}




static Std_ReturnType prescaler_helper(timer2_t *timer){
    
        T2CONbits.T2CKPS=timer->prescaler_mode;
    

}
static Std_ReturnType postscaler_helper(timer2_t *timer){
    
        POSTSCALER_SELECT(timer->postscaler_mode); 

}

void ISR_TIMER2(void){
     TIMER2_CLEAR_FLAG();
        TMR2=(uint8)((saved_preload_value));
     
     /*code here*/
     if(Timer2_interrrupt_ptr){
         Timer2_interrrupt_ptr();
     }
     else{/*NOThing*/}
}