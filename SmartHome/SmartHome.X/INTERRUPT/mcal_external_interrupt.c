/* 
 * File:   mcal_external_interrupt.c
 * Author: Mohamed Samy
 *
 * Created on May 15, 2024, 3:06 PM
 */
/*Include Interfaces Header File Section */

#include "mcal_external_interrupt.h" 

#define _XTAL_FREQ 8000000


/*Global Variable Definition Section*/

/*APIs Definition Section*/

/*INTX HELPER FUNCTION*/
static Ptr_interruupt_handler INT0_CALL_BACK_HANDLER;
static Ptr_interruupt_handler INT1_CALL_BACK_HANDLER;
static Ptr_interruupt_handler INT2_CALL_BACK_HANDLER;

static Std_ReturnType intx_enabel_handler(const intx_t *obj);
static Std_ReturnType intx_disabel_handler(const intx_t *obj);
static Std_ReturnType intx_priority_handler(const intx_t *obj);
static Std_ReturnType intx_edge_handler(const intx_t *obj);
static Std_ReturnType intx_clear_flag_handler(const intx_t *obj);
static Std_ReturnType intx_call_back_handler(const intx_t *obj);
static Std_ReturnType intx_pin_handler(const intx_t *obj);

/*RBX HELPER FUNCTION*/
volatile static  uint8 rbx_arr[4];


static Ptr_interruupt_handler RBX_CALL_BACK_HANDLER_RISING_4;
static Ptr_interruupt_handler RBX_CALL_BACK_HANDLER2_FALLING_4;
static Ptr_interruupt_handler RBX_CALL_BACK_HANDLER_RISING_5;
static Ptr_interruupt_handler RBX_CALL_BACK_HANDLER2_FALLING_5;
static Ptr_interruupt_handler RBX_CALL_BACK_HANDLER_RISING_6;
static Ptr_interruupt_handler RBX_CALL_BACK_HANDLER2_FALLING_6;
static Ptr_interruupt_handler RBX_CALL_BACK_HANDLER_RISING_7;
static Ptr_interruupt_handler RBX_CALL_BACK_HANDLER2_FALLING_7;
static Std_ReturnType rbx_call_back_handler(const rbx_t *obj);
static Std_ReturnType rbx_priority_handler(const intx_t *obj);








Std_ReturnType mcal_interrupt_intx_init(const intx_t *obj){
    Std_ReturnType ret = E_OK;
    if(NULL==obj){
        ret = E_NOK;
    }
    else{
     ret=intx_disabel_handler(obj);
     ret|= intx_clear_flag_handler(obj);
     ret|= intx_pin_handler(obj);
     ret|= intx_edge_handler(obj);
  #if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE

    ret|= intx_priority_handler(obj);
   
  #endif
     ret|= intx_call_back_handler(obj);
     ret|= intx_enabel_handler(obj);
    }
    return ret;
}

static Std_ReturnType intx_enabel_handler(const intx_t *obj){
    Std_ReturnType ret = E_OK;
    if(NULL==obj){
        ret = E_NOK;
    }
    else{
        

        
        switch(obj->source){
            case INTERRUPT_INT0: 
                
                  #if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
                            GIEH_ENABLE();
                            GIEL_ENABLE();
                    #else
                            GIE_ENABLE();
                            PEIE_ENABLE();
                    #endif
                INT0_ENABLE();
                ret = E_OK;
            break;
            
            
            case INTERRUPT_INT1: 
                IPEN_ENABLE();
                    #if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
                        if(INTERRUPT_HIGH_PRIORITY==obj->priority){
                               GIEH_ENABLE();
                        }
                        else if(INTERRUPT_LOW_PRIORITY==obj->priority){
                            GIEL_ENABLE();
                            }
                        else{}
                    #else
                            GIE_ENABLE();
                            PEIE_ENABLE();
                    #endif
                INT1_ENABLE();
                ret = E_OK;
            break;
            case INTERRUPT_INT2: 
                IPEN_ENABLE();
                    #if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
                        if(INTERRUPT_HIGH_PRIORITY==obj->priority){
                               GIEH_ENABLE();
                        }
                        else if(INTERRUPT_LOW_PRIORITY==obj->priority){
                            GIEL_ENABLE();
                            }
                        else{}
                    #else
                            GIE_ENABLE();
                            PEIE_ENABLE();
                    #endif
                INT2_ENABLE();
                ret = E_OK;
            break;
            default:ret = E_NOK;
            
        }
    }
    return ret;
}
static Std_ReturnType intx_disabel_handler(const intx_t *obj){
    Std_ReturnType ret = E_NOK;
    if(NULL==obj){
        ret = E_OK;
    }
    else{
            switch(obj->source){
            case INTERRUPT_INT0: INT0_DISABLE();
            ret = E_OK;
            break;
            case INTERRUPT_INT1: INT1_DISABLE();
            ret = E_OK;
            break;
            case INTERRUPT_INT2: INT2_DISABLE();
            ret = E_OK;
            break;
            default:ret = E_NOK;
            
        }
    }
     return ret;
}


   #if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE

static Std_ReturnType intx_priority_handler(const intx_t *obj){
    Std_ReturnType ret = E_OK;
    if(NULL==obj){
        ret = E_NOK;
    }
    else{
         switch(obj->source){
            case INTERRUPT_INT1: 
                if(INTERRUPT_HIGH_PRIORITY==obj->priority){
                               INT1_HIGH_PRIORITY();
                        }
                        else if(INTERRUPT_LOW_PRIORITY==obj->priority){
                            INT1_LOW_PRIORITY();
                            
                            }
                        else{}
                ret = E_OK;
            break;
            case INTERRUPT_INT2: 
                          if(INTERRUPT_HIGH_PRIORITY==obj->priority){
                               INT2_HIGH_PRIORITY();
                        }
                        else if(INTERRUPT_LOW_PRIORITY==obj->priority){
                            INT2_LOW_PRIORITY();
                            }
                        else{}
                         ret = E_OK;
            break;
            default:ret = E_NOK;
            
        }
    }
        return ret;

}
#endif
static Std_ReturnType intx_edge_handler(const intx_t *obj){
    Std_ReturnType ret = E_OK;
    if(NULL==obj){
        ret = E_NOK;
    }
    else{
         switch(obj->source){
                 case INTERRUPT_INT0: 
                if(INTx_RISING_EDGE==obj->edge){
                               INT0_RISING_EDGE();
                        }
                        else if(INTx_FALLING_EDGE==obj->edge){
                            INT0_FALLING_EDGE();
                            }
                        else{}
                ret = E_OK;
            break;
            case INTERRUPT_INT1: 
                if(INTx_RISING_EDGE==obj->edge){
                               INT1_RISING_EDGE();
                        }
                        else if(INTx_FALLING_EDGE==obj->edge){
                            INT1_FALLING_EDGE();
                            }
                        else{}
               ret = E_OK;
            break;
            case INTERRUPT_INT2: 
                if(INTx_RISING_EDGE==obj->edge){
                               INT2_RISING_EDGE();
                        }
                        else if(INTx_FALLING_EDGE==obj->edge){
                            INT2_FALLING_EDGE();
                            }
                        else{}
                ret = E_OK;
            break;
            default:ret = E_NOK;
            
        }
    }
        return ret;

}
static Std_ReturnType intx_clear_flag_handler(const intx_t *obj){
    Std_ReturnType ret = E_OK;
    if(NULL==obj){
        ret = E_OK;
    }
    else{
         switch(obj->source){
                 case INTERRUPT_INT0: 
                     INT0_CLEAR();
                ret = E_OK;
            break;
            case INTERRUPT_INT1: 
                     INT1_CLEAR();
               ret = E_OK;
            break;
            case INTERRUPT_INT2: 
                    INT2_CLEAR();
                ret = E_OK;
            break;
            default:ret = E_NOK;
            
        }
    }
        return ret;

}
static Std_ReturnType intx_pin_handler(const intx_t *obj)  {
    Std_ReturnType ret = E_OK;
    if(NULL==obj){
        ret = E_NOK;
    }
    else{
        ret=gpio_pin_direction_intialization((&obj->pin));
    }
        return ret;

}

static Std_ReturnType intx_call_back_handler(const intx_t *obj){
    Std_ReturnType ret = E_OK;
    if(NULL==obj){
        ret = E_NOK;
    }
    else{
         switch(obj->source){
                 case INTERRUPT_INT0: 
                     INT0_CALL_BACK_HANDLER=obj->Int_interrupt_handler;
                ret = E_OK;
            break;
            case INTERRUPT_INT1: 
                     INT1_CALL_BACK_HANDLER=obj->Int_interrupt_handler;
               ret = E_OK;
            break;
            case INTERRUPT_INT2: 
                     INT2_CALL_BACK_HANDLER=obj->Int_interrupt_handler;
                ret = E_OK;
            break;
            default:ret = E_NOK;
            
        }
    }
        return ret;

}



/*RBX FUNCTION DEFINITION*/
Std_ReturnType mcal_interrupt_RBx_init(const rbx_t *obj){
        Std_ReturnType ret = E_OK;
    if(NULL==obj){
        ret = E_NOK;
    }
    else{
        RBX_DISABLE();
        RBX_CLEAR();
        ret=gpio_pin_direction_intialization(&(obj->pin));
        ret|=rbx_call_back_handler(obj);
        

        
        #if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
                            IPEN_ENABLE();
                             ret|=rbx_priority_handler(obj);

                    #else
                            GIE_ENABLE();
                            PEIE_ENABLE();
                    #endif
   
         RBX_ENABLE();

    }
    return ret;
}

static Std_ReturnType rbx_call_back_handler(const rbx_t *obj){
        Std_ReturnType ret = E_OK;
    if(NULL==obj){
        ret = E_NOK;
    }
    else{
        switch(obj->pin.pin){
             case INTERRUPT_RB4: 
                RBX_CALL_BACK_HANDLER_RISING_4 = obj->RBx_interrupt_handler_rising;
                RBX_CALL_BACK_HANDLER2_FALLING_4 = obj->RBx_interrupt_handler_falling;
                ret = E_OK;
            break;
            case INTERRUPT_RB5: 
                RBX_CALL_BACK_HANDLER_RISING_5 = obj->RBx_interrupt_handler_rising;
                RBX_CALL_BACK_HANDLER2_FALLING_5 = obj->RBx_interrupt_handler_falling;
                ret = E_OK;
            break;
            case INTERRUPT_RB6: 
                RBX_CALL_BACK_HANDLER_RISING_6 = obj->RBx_interrupt_handler_rising;
                RBX_CALL_BACK_HANDLER2_FALLING_6 = obj->RBx_interrupt_handler_falling;
                ret = E_OK;
            break;
            case INTERRUPT_RB7: 
                RBX_CALL_BACK_HANDLER_RISING_7 = obj->RBx_interrupt_handler_rising;
                RBX_CALL_BACK_HANDLER2_FALLING_7 = obj->RBx_interrupt_handler_falling;
                ret = E_OK;
            break;
            default:ret = E_NOK;
            
        }
    }
    return ret;
}

#if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE

static Std_ReturnType rbx_priority_handler(const intx_t *obj){
        Std_ReturnType ret = E_OK;
    if(NULL==obj){
        ret = E_NOK;
    }
    else{
        if((obj->priority)==INTERRUPT_HIGH_PRIORITY){
             GIEH_ENABLE();
            RBX_HIGH_PRIORITY();
           

        }
        else if((obj->priority)==INTERRUPT_LOW_PRIORITY){
            GIEL_ENABLE();
            RBX_LOW_PRIORITY();
             

        }
        else{}
    }
    return ret;
}
#endif





void ISR0(void){
    INT0_CLEAR();
    /*code of ISR*/
  if(INT0_CALL_BACK_HANDLER){
        INT0_CALL_BACK_HANDLER();   
    }
}
void ISR1(void){
    INT1_CLEAR();
    /*code of ISR*/
    if(INT1_CALL_BACK_HANDLER){
        INT1_CALL_BACK_HANDLER();          

    }
}
void ISR2(void){
    INT2_CLEAR();
    /*code of ISR*/
    if(INT2_CALL_BACK_HANDLER){
        INT2_CALL_BACK_HANDLER();
    }
}

 
 void ISR_RBX4(uint8 num){     
     PORTBbits.RB4;
       RBX_CLEAR();

    /*code of ISR*/
       if(0==num){
    if((RBX_CALL_BACK_HANDLER_RISING_4)){

        (RBX_CALL_BACK_HANDLER_RISING_4());
        
    }
    else{}
    
    }
       else if(1==num){
           
      if((RBX_CALL_BACK_HANDLER2_FALLING_4)){

        (RBX_CALL_BACK_HANDLER2_FALLING_4());
        
    }
    else{}
       
       }
       else{}
 }

 
 void ISR_RBX5(uint8 num){  
     PORTBbits.RB4;
       RBX_CLEAR();

    /*code of ISR*/
       if(0==num){
    if((RBX_CALL_BACK_HANDLER_RISING_5)){

        (RBX_CALL_BACK_HANDLER_RISING_5());
        
    }
    else{}
    
    }
       else if(1==num){
      if((RBX_CALL_BACK_HANDLER2_FALLING_5)){

        (RBX_CALL_BACK_HANDLER2_FALLING_5());
        
    }
    else{}
       
       }
       else{}
 }

 
 void ISR_RBX6(uint8 num){      
       RBX_CLEAR();

    /*code of ISR*/
       if(0==num){
    if((RBX_CALL_BACK_HANDLER_RISING_6)){

        (RBX_CALL_BACK_HANDLER_RISING_6());
        
    }
    else{}
    
    }
       else if(1==num){
      if((RBX_CALL_BACK_HANDLER2_FALLING_6)){

        (RBX_CALL_BACK_HANDLER2_FALLING_6());
        
    }
    else{}
       
       }
       else{}
 }
 
 
  
 void ISR_RBX7(uint8 num){      
       RBX_CLEAR();

    /*code of ISR*/
       if(0==num){
    if((RBX_CALL_BACK_HANDLER_RISING_7)){

        (RBX_CALL_BACK_HANDLER_RISING_7());
        
    }
    else{}
    
    }
       else if(1==num){
      if((RBX_CALL_BACK_HANDLER2_FALLING_7)){

        (RBX_CALL_BACK_HANDLER2_FALLING_7());
        
    }
    else{}
       
       }
       else{}
 }