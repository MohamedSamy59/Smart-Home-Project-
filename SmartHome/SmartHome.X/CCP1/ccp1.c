/* 
 * File:   ccp1.c
 * Author: Mohamed Samy
 *
 * Created on June 14, 2024, 10:21 AM
 */

/*Include Interfaces Header File Section */
#include "ccp1.h"

/*Global Variable Definition Section*/


/*APIs Definition Section*/
static void (*CCP1_ptr_handler)(void);
static Std_ReturnType timer_cfg_helper(const ccp1_t *ccp1);
Std_ReturnType mcal_ccp1_initialization(const ccp1_t *ccp1){
    Std_ReturnType ret = E_OK;
    uint16 l_duty_temp = 0;

    if(NULL==ccp1){
        ret = E_NOK;
    }
    else{
         CCP_CFG(CCP_DISABLE);
#if CCP1_MODE == CCP1_CAPTURE_MODE || CCP1_MODE == CCP1_COMPARE_MODE

         timer_cfg_helper(ccp1);
#endif
         if(ccp1->ccp1_mode==CAPTURE_MODE){
#if CCP1_MODE == CCP1_CAPTURE_MODE || CCP1_MODE == CCP1_COMPARE_MODE

             SET_BIT(TRISC,_PORTC_CCP1_POSITION);
             switch(ccp1->ccp1_variant){
                 case CAPTURE_MODE_AT_EVERY_FALLING_EDGE : CCP_CFG(CAPTURE_MODE_AT_EVERY_FALLING_EDGE);
                     break;
                 case CAPTURE_MODE_AT_EVERY_RISING_EDGE : CCP_CFG(CAPTURE_MODE_AT_EVERY_RISING_EDGE);
                     break;
                 case CAPTURE_MODE_AT_EVERY_4_RISING_EDGE : CCP_CFG(CAPTURE_MODE_AT_EVERY_4_RISING_EDGE);
                     break; 
                 case CAPTURE_MODE_AT_EVERY_16_RISING_EDGE : CCP_CFG(CAPTURE_MODE_AT_EVERY_16_RISING_EDGE);
                     break;
                     
                 default : ret = E_NOK;
                     break;
             }
#endif
         }
         else if(ccp1->ccp1_mode==COMPARE_MODE){
             
#if CCP1_MODE == CCP1_CAPTURE_MODE || CCP1_MODE == CCP1_COMPARE_MODE

             CLEAR_BIT(TRISC,_PORTC_CCP1_POSITION);
             switch(ccp1->ccp1_variant){
                 case COMPARE_MODE_TOGGLE_OUTPUT_ON_MATCH : CCP_CFG(COMPARE_MODE_TOGGLE_OUTPUT_ON_MATCH);
                     break;
                 case COMPARE_MODE_SET_CCP1_PIN : CCP_CFG(COMPARE_MODE_SET_CCP1_PIN);
                     break;
                 case COMPARE_MODE_CLEAR_CCP1_PIN : CCP_CFG(COMPARE_MODE_CLEAR_CCP1_PIN);
                     break; 
                 case COMPARE_MODE_GENERATE_SW_INTERRUPT : CCP_CFG(COMPARE_MODE_GENERATE_SW_INTERRUPT);
                     break;
                 case COMPARE_MODE_TRIGGER_SPECIAL_EVENT : CCP_CFG(COMPARE_MODE_TRIGGER_SPECIAL_EVENT);
                     break;       
                 default : ret = E_NOK;
                     break;
             }
#endif
         }
         else if(ccp1->ccp1_mode==PWM_MODE){
             
#if CCP1_MODE == CCP1_PWM_MODE 

                /* PWM Frequency Initialization */
            PR2 = (uint8)((_XTAL_FREQ / (ccp1->PWM_Frequency * 4.0 * ccp1->timer2_prescaler * 
                    ccp1->postscaler_mode)) - 1);
            /* Duty Cycle Initialization */
            l_duty_temp=(uint16)(4 * (PR2 + 1) * ((100-(ccp1->duty_value)) / 100.0));
            CCP1CONbits.DC1B = (uint8)(l_duty_temp & 0x0003);
            CCPR1L = (uint8)(l_duty_temp >> 2);
            
            /*Pin configuration*/
             CLEAR_BIT(TRISC,_PORTC_CCP1_POSITION);
             
             /*Timer2 Post and Prescaler configuration*/
             T2CONbits.T2CKPS=ccp1->timer2_prescaler;
             T2CONbits.T2OUTPS=ccp1->postscaler_mode;
             
             TIMER2_ENABLE();
             if(ccp1->ccp1_variant==PWM_MODE_ENABLE){
                 CCP_CFG(PWM_MODE_ENABLE);
             }

             else{
                 ret = E_NOK;
             }
#endif

         }   

         else{/*NoThing*/}
         
//#if CCP1_INTERRUPT_ENABLE_CFG == _CCP1_INTERRUPT_ENABLE_
//        CCP1_CLEAR_FLAG();
//                        
//        CCP1_INTERRUPT_ENABLE();
//        
//#if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
//            IPEN_ENABLE();
//            if(ccp1->priority==INTERRUPT_HIGH_PRIORITY){
//                GIEH_ENABLE();
//                CCP1_HIGH_PRIORITY();
//            }
//            else if(ccp1->priority==INTERRUPT_LOW_PRIORITY){
//               
//                GIEH_ENABLE();
//                GIEL_ENABLE();
//                CCP1_LOW_PRIORITY();
//            }
//            else{   
//            }
//
//#else
//            GIE_ENABLE();
//            PEIE_ENABLE();
//#endif
//              CCP1_ptr_handler=(ccp1->CCP1_Interrupt_handler);
//
//#endif
    }
    return ret;
}


Std_ReturnType mcal_ccp1_DeInitialization(const ccp1_t *ccp1){
    Std_ReturnType ret = E_OK;
    if(NULL==ccp1){
        ret= E_NOK;
    }
    else{
         CCP_CFG(CCP_DISABLE);
       
      
        /*Interrupt DeInitialization*/
//#if CCP1_INTERRUPT_ENABLE_CFG == _CCP1_INTERRUPT_ENABLE_
//                        
//        CCP1_INTERRUPT_DISABLE();
//#endif

    }
    return ret;
}

#if CCP1_MODE == CCP1_CAPTURE_MODE || CCP1_MODE == CCP1_COMPARE_MODE

Std_ReturnType mcal_ccp1_capture_get_value(const ccp1_t *ccp1,uint16 *value){
    Std_ReturnType ret = E_OK;
        CCP_REG_T capture_temp_value = {.ccpr_low = 0, .ccpr_high = 0};

    if(NULL==ccp1){
        ret= E_NOK;
    }
    else{
        /* Copy captured value */
        capture_temp_value.ccpr_low = CCPR1L;
        capture_temp_value.ccpr_high = CCPR1H;
        /* Write the 16-bit capture value */
        *value = capture_temp_value.ccpr_16Bit;
    }
    return ret;
}
#endif

#if CCP1_MODE == CCP1_CAPTURE_MODE || CCP1_MODE == CCP1_COMPARE_MODE

Std_ReturnType mcal_ccp1_compare_write_value(const ccp1_t *ccp1,uint16 value){
    Std_ReturnType ret = E_OK;
        CCP_REG_T capture_temp_value = {.ccpr_low = 0, .ccpr_high = 0};

    if(NULL==ccp1){
        ret= E_NOK;
    }
    else{
          /* Copy compared value */
        capture_temp_value.ccpr_16Bit = value;
            CCPR1L = capture_temp_value.ccpr_low;
            CCPR1H = capture_temp_value.ccpr_high;
    }
    return ret;
}
#endif


#if CCP1_MODE == CCP1_PWM_MODE 

Std_ReturnType mcal_ccp1_pwm_set_duty(const ccp1_t *ccp1,uint16 value){
    Std_ReturnType ret = E_OK;
    uint16 l_duty_temp = 0;

    if(NULL==ccp1){
        ret= E_NOK;
    }
    else{
    
            
            /* Duty Cycle Initialization */
            l_duty_temp=(uint16)(4 * (PR2 + 1) * ((100-(value)) / 100.0));
            CCP1CONbits.DC1B = (uint8)(l_duty_temp & 0x0003);
            CCPR1L = (uint8)(l_duty_temp >> 2);
    }
    return ret;
}
#endif



#if CCP1_MODE == CCP1_CAPTURE_MODE || CCP1_MODE == CCP1_COMPARE_MODE

static Std_ReturnType timer_cfg_helper(const ccp1_t *ccp1){
        Std_ReturnType ret = E_OK;
        if(ccp1->timer_cfg==TIMER1_COMPARE_CAPTURE_CLK_CCP){
                 T3CONbits.T3CCP1=0;
                 T3CONbits.T3CCP2=0;
        }
        else if(ccp1->timer_cfg==TIMER3_TIMER1_COMPARE_CAPTURE_CLK_CCP2_CCP1){
                 T3CONbits.T3CCP1=1;
                 T3CONbits.T3CCP2=0;
        }
          else if(ccp1->timer_cfg==TIMER3_COMPARE_CAPTURE_CLK_CCP){
                 T3CONbits.T3CCP1=1;
                 T3CONbits.T3CCP2=1;
        }
                 else{/*NoThing*/}

            return ret;

}
#endif

void ISR_CCP1(void){
     CCP1_CLEAR_FLAG();

     /*code here*/
     if(CCP1_ptr_handler){
         CCP1_ptr_handler();
     }
     else{/*NOThing*/}
}