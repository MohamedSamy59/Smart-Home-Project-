/* 
 * File:   timer0.h
 * Author: Mohamed Samy
 *
 * Created on June 3, 2024, 12:58 PM
 */



/*Include Interfaces Header File Section */

#include "timer0.h" 



/*Global Variable Definition Section*/

/*APIs Definition Section*/
static void (*Timer0_interrrupt_ptr)(void);


static Std_ReturnType prescaler_helper(timer0_t *timer);
static Std_ReturnType timer_mode_helper(timer0_t *timer);
static Std_ReturnType timer_reg_size_helper(timer0_t *timer);
static uint16 saved_preload_value=ZERO_INIT;
Std_ReturnType mcal_timer0_initialization (timer0_t *timer){
    Std_ReturnType ret = E_OK;
    if(NULL==timer){
        ret= E_NOK;
    }
    else{
        TIMER0_DISABLE();
        
        timer_mode_helper(timer);
        prescaler_helper(timer);
        timer_reg_size_helper(timer);
        saved_preload_value=timer->preload_value;
        
        /*Interrupt Initialization*/
#if TIMER0_INTERRUPT_ENABLE_CFG == _TIMER0_INTERRUPT_ENABLE_
        TIMER0_CLEAR_FLAG();
                        
        TIMER0_INTERRUPT_ENABLE();
        
#if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
            IPEN_ENABLE();
            if(timer->priority==INTERRUPT_HIGH_PRIORITY){
                GIEH_ENABLE();
                TIMER0_HIGH_PRIORITY();
            }
            else if(timer->priority==INTERRUPT_LOW_PRIORITY){
                               GIEH_ENABLE();

                GIEL_ENABLE();
                TIMER0_LOW_PRIORITY();
            }
            else{   
            }

#else
            GIE_ENABLE();
            PEIE_ENABLE();
#endif
              Timer0_interrrupt_ptr=timer->Timer0_interrrupt_handler;

#endif
        TIMER0_ENABLE();
    }
    return ret;
}
Std_ReturnType mcal_timer0_DeInitialization (timer0_t *timer)    {
    Std_ReturnType ret = E_OK;
    if(NULL==timer){
        ret= E_NOK;
    }
    else{
        TIMER0_DISABLE();
       
      
        /*Interrupt DeInitialization*/
#if TIMER0_INTERRUPT_ENABLE_CFG == _TIMER0_INTERRUPT_ENABLE_                        
        TIMER0_INTERRUPT_ENABLE();
#endif

    }
    return ret;
}
Std_ReturnType mcal_timer0_write (timer0_t *timer,uint16 preload_value){
    Std_ReturnType ret = E_OK;

    if(timer->timer_reg_size == TIMER0_8BITS_MODE){
        TMR0L=(uint8)(preload_value);
    }
    else if(timer->timer_reg_size == TIMER0_16BITS_MODE){
        TMR0H=(uint8)((preload_value)>>8);
        TMR0L=(uint8)((preload_value));
    }
    else{/*NOThing*/}
    return ret;

}
Std_ReturnType mcal_timer0_read (timer0_t *timer,uint16 *value){
    Std_ReturnType ret = E_OK;
    uint8 timer0_L=ZERO_INIT,timer0_H=ZERO_INIT;
    if((NULL==timer)||(NULL==value)){
        ret= E_NOK;
    }
    else{
           if(timer->timer_reg_size == TIMER0_8BITS_MODE){
                        timer0_L = TMR0L;
                        *value =(uint8)(timer0_L);

            }
            else if(timer->timer_reg_size == TIMER0_16BITS_MODE){
                        timer0_L = TMR0L;
                         timer0_H = TMR0H;
                         *value =(uint16)((timer0_H<<8)+timer0_L);

            }
            else{/*NOThing*/}
    
    }
    return ret;
}


static Std_ReturnType timer_mode_helper(timer0_t *timer){
    if(timer->timer_mode == TIMER_MODE){
        TIMER0_TIMER_MODE();
    }
    else if(timer->timer_mode == COUNTER_MODE){
        TIMER0_COUNTER_MODE();
        SET_BIT(TRISA,_PORTA_RA4_POSITION);
        if(timer->timer_edge == RISING_EDGE){
            TIMER0_RISING_EDGE();
        }
        else if(timer->timer_edge == FALIING_EDGE){
            TIMER0_FALLING_EDGE();
        }
        else{/*NOThing*/}
    }
    else{/*NOThing*/}
}

static Std_ReturnType prescaler_helper(timer0_t *timer){
    if(timer->prescaler_on_off == PRESCALER_ENABLE){
        TIMER0_PRESCALER_ENABLE();
        T0CONbits.T0PS=timer->prescaler_mode;
    }
    else if(timer->prescaler_on_off == PRESCALER_DISABLE){
        TIMER0_PRESCALER_DISABLE();
    }
    else{/*NOThing*/}
}
static Std_ReturnType timer_reg_size_helper(timer0_t *timer){
    if(timer->timer_reg_size == TIMER0_8BITS_MODE){
        TIMER0_8BITS_CFG();
        TMR0L=(uint8)((timer->preload_value));
    }
    else if(timer->timer_reg_size == TIMER0_16BITS_MODE){
        TIMER0_16BITS_CFG();
        TMR0H=(uint8)((timer->preload_value)>>8);
        TMR0L=(uint8)((timer->preload_value));
    }
    else{/*NOThing*/}
}

void ISR_TIMER0(void){
     TIMER0_CLEAR_FLAG();
        TMR0H=(uint8)((saved_preload_value)>>8);
        TMR0L=(uint8)((saved_preload_value));
     
     /*code here*/
     if(Timer0_interrrupt_ptr){
         Timer0_interrrupt_ptr();
     }
     else{/*NOThing*/}
}