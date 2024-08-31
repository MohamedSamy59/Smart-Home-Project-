/* 
 * File:   mcal_interrupt_manager.c
 * Author: Mohamed Samy
 *
 * Created on May 15, 2024, 3:09 PM
 */

/*Include Interfaces Header File Section */
#include "mcal_interrupt_manager.h"
//#include "../../ECU_layer/ecu_layer_init.h"

/*Global Variable Definition Section*/
static volatile uint8  flag4=1,flag5=1,flag6=1,flag7=1;
/*APIs Definition Section*/

 #if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
void __interrupt(high_priority)interrupt_high(void){

        /*INTX INTERRUPT MANAGER*/
//
//    if((INTCONbits.INT0IE == INTERRUPT_ENABLE)&&(INTCONbits.INT0IF == 1)){
//        ISR0();
//    }
//    else{}
//    if((INTCON3bits.INT1E == INTERRUPT_ENABLE)&&(INTCON3bits.INT1IF == 1)){
//        ISR1();
//    }
//    else{}
//    if((INTCON3bits.INT2IE == INTERRUPT_ENABLE)&&(INTCON3bits.INT2IF == 1)){
//        ISR2();
//    }
//    else{}
//    
//        /*RBX INTERRUPT MANAGER*/
//
//      /*RBX INTERRUPT MANAGER*/
//    if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_HIGH== PORTBbits.KBI0)&&(1== flag4)){
//        ISR_RBX4(0);
//    }    
//    else{}
//    
//        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_LOW== PORTBbits.KBI0)&&(0== flag4)){
//        ISR_RBX4(1);
//    }    
//    else{}
//    
//        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_HIGH== PORTBbits.KBI1)&&(1== flag5)){
//        ISR_RBX5(0);
//    }    
//    else{}
//    
//        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_LOW== PORTBbits.KBI1)&&(0== flag5)){
//        ISR_RBX5(1);
//    }    
//    else{}
//    
//        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_HIGH== PORTBbits.KBI2)&&(1== flag6)){
//        ISR_RBX6(0);
//    }    
//    else{}
//    
//        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_LOW== PORTBbits.KBI2)&&(0== flag6)){
//        ISR_RBX6(1);
//    }    
//    else{}
//    
//        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_HIGH== PORTBbits.KBI3)&&(1== flag7)){
//        ISR_RBX7(0);
//    }    
//    else{}
//    
//        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_LOW== PORTBbits.KBI3)&&(0== flag7)){
//        ISR_RBX7(1);
//    }    
//    else{}
//    
//    
//    /*ADC INTERRUPT MANAGER */
//     if((PIE1bits.ADIE==INTERRUPT_ENABLE)&&(PIR1bits.ADIF==1)){
//             ISR_ADC(); 
//
//    }    
//    else{}
    
       /*Timer0 INTERRUPT MANAGER */
     if((INTCONbits.T0IF==1)&&(INTCONbits.T0IE==INTERRUPT_ENABLE)){
             ISR_TIMER0(); 

    }    
    else{}
    
           /*Timer1 INTERRUPT MANAGER */
//     if((PIR1bits.TMR1IF==1)&&(PIE1bits.TMR1IE==INTERRUPT_ENABLE)){
//             ISR_TIMER1(); 
//
//    }    
//    else{}
//    
//               /*Timer2 INTERRUPT MANAGER */
//     if((PIR1bits.TMR2IF==1)&&(PIE1bits.TMR2IE==INTERRUPT_ENABLE)){
//             ISR_TIMER2(); 
//
//    }    
//    else{}
//    
//                   /*Timer3 INTERRUPT MANAGER */
//     if((PIR2bits.TMR3IF==1)&&(PIE2bits.TMR3IE==INTERRUPT_ENABLE)){
//             ISR_TIMER3(); 
//
//    }    
//    else{}
//    
//                       /*CCP1 INTERRUPT MANAGER */
//     if((PIR1bits.CCP1IF==1)&&(PIE1bits.CCP1IE==INTERRUPT_ENABLE)){
//             ISR_CCP1(); 
//
//    }    
//    else{}
//    
//                           /*Euasrt TX INTERRUPT MANAGER */
//     if((PIR1bits.TXIF==1)&&(PIE1bits.TXIE==INTERRUPT_ENABLE)&&(TXSTAbits.TRMT==1)){
//             ISR_EUSART_TX(); 
//
//    }    
//    else{}
//    
//                               /*Euasrt RX INTERRUPT MANAGER */
//     if((PIR1bits.RCIF==1)&&(PIE1bits.RCIE==INTERRUPT_ENABLE)){
//             ISR_EUSART_RX(); 
//
//    }    
//    else{}
//    
//                                   /*SPI INTERRUPT MANAGER */
//     if((PIR1bits.SSPIF==1)&&(PIE1bits.SSPIE==INTERRUPT_ENABLE)){
//             ISR_SPI(); 
//
//    }    
//    else{}
//    
//                                       /*I2C INTERRUPT MANAGER */
//
//     if((INTERRUPT_ENABLE == PIE1bits.SSPIE) && (1 == PIR1bits.SSPIF)){
//        MSSP_I2C_ISR();
//    }
//    else{ /* Nothing */ }
//    if((INTERRUPT_ENABLE == PIE2bits.BCLIE) && (1 == PIR2bits.BCLIF)){
//        MSSP_I2C_BC_ISR();
//    }
//    else{ /* Nothing */ }
}


void __interrupt(low_priority)interrupt_low(void){
    
        /*INTX INTERRUPT MANAGER*/

//    if((INTCON3bits.INT1E == INTERRUPT_ENABLE)&&(INTCON3bits.INT1IF == 1)){
//        ISR1();
//    }
//    else{}
//    if((INTCON3bits.INT2IE == INTERRUPT_ENABLE)&&(INTCON3bits.INT2IF == 1)){
//        ISR2();
//    }
//    else{}
//    
//    
//       /*RBX INTERRUPT MANAGER*/
//    if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_HIGH== PORTBbits.KBI0)&&(1== flag4)){
//        ISR_RBX4(0);
//    }    
//    else{}
//    
//        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_LOW== PORTBbits.KBI0)&&(0== flag4)){
//        ISR_RBX4(1);
//    }    
//    else{}
//    
//        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_HIGH== PORTBbits.KBI1)&&(1== flag5)){
//        ISR_RBX5(0);
//    }    
//    else{}
//    
//        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_LOW== PORTBbits.KBI1)&&(0== flag5)){
//        ISR_RBX5(1);
//    }    
//    else{}
//    
//        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_HIGH== PORTBbits.KBI2)&&(1== flag6)){
//        ISR_RBX6(0);
//    }    
//    else{}
//    
//        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_LOW== PORTBbits.KBI2)&&(0== flag6)){
//        ISR_RBX6(1);
//    }    
//    else{}
//    
//        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_HIGH== PORTBbits.KBI3)&&(1== flag7)){
//        ISR_RBX7(0);
//    }    
//    else{}
//    
//        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_LOW== PORTBbits.KBI3)&&(0== flag7)){
//        ISR_RBX7(1);
//    }    
//    else{}
//    
//    
//     /*ADC INTERRUPT MANAGER */
//     if((PIE1bits.ADIE==INTERRUPT_ENABLE)&&(PIR1bits.ADIF==1)){
//             ISR_ADC(); 
//
//    }    
//    else{}
//    
           /*Timer0 INTERRUPT MANAGER */
     if((INTCONbits.T0IF==1)&&(INTCONbits.T0IE==INTERRUPT_ENABLE)){
             ISR_TIMER0(); 

    }    
    else{}
    
               /*Timer1 INTERRUPT MANAGER */
//     if((PIR1bits.TMR1IF==1)&&(PIE1bits.TMR1IE==INTERRUPT_ENABLE)){
//             ISR_TIMER1(); 
//
//    }    
//    else{}
//    
//                  /*Timer2 INTERRUPT MANAGER */
//     if((PIR1bits.TMR2IF==1)&&(PIE1bits.TMR2IE==INTERRUPT_ENABLE)){
//             ISR_TIMER2(); 
//
//    }    
//    else{}
//    
//                       /*Timer3 INTERRUPT MANAGER */
//     if((PIR2bits.TMR3IF==1)&&(PIE2bits.TMR3IE==INTERRUPT_ENABLE)){
//             ISR_TIMER3(); 
//
//    }    
//    else{}
//    
//                           /*CCP1 INTERRUPT MANAGER */
//     if((PIR1bits.CCP1IF==1)&&(PIE1bits.CCP1IE==INTERRUPT_ENABLE)){
//             ISR_CCP1(); 
//
//    }    
//    else{}
//    
//                               /*Euasrt TX INTERRUPT MANAGER */
//     if((PIR1bits.TXIF==1)&&(PIE1bits.TXIE==INTERRUPT_ENABLE)&&(TXSTAbits.TRMT==1)){
//             ISR_EUSART_TX(); 
//
//    }    
//    else{}
//    
//                                   /*Euasrt RX INTERRUPT MANAGER */
//     if((PIR1bits.RCIF==1)&&(PIE1bits.RCIE==INTERRUPT_ENABLE)){
//             ISR_EUSART_RX(); 
//
//    }    
//    else{}
//                                       /*SPI INTERRUPT MANAGER */
//     if((PIR1bits.SSPIF==1)&&(PIE1bits.SSPIE==INTERRUPT_ENABLE)){
//             ISR_SPI(); 
//
//    }    
//    else{}
//    
//    
//                                           /*I2C INTERRUPT MANAGER */
//
//     if((INTERRUPT_ENABLE == PIE1bits.SSPIE) && (1 == PIR1bits.SSPIF)){
//        MSSP_I2C_ISR();
//    }
//    else{ /* Nothing */ }
//    if((INTERRUPT_ENABLE == PIE2bits.BCLIE) && (1 == PIR2bits.BCLIF)){
//        MSSP_I2C_BC_ISR();
//    }
//    else{ /* Nothing */ }
//    
}


#else
    /*INTX INTERRUPT MANAGER*/

void __interrupt()interrupt_fun(void){
    /*INTX INTERRUPT MANAGER*/
    if((INTCONbits.INT0IE == INTERRUPT_ENABLE)&&(INTCONbits.INT0IF == 1)){
        ISR0();
    }
    else{}
    if((INTCON3bits.INT1E == INTERRUPT_ENABLE)&&(INTCON3bits.INT1IF == 1)){
        ISR1();
    }
    else{}
    if((INTCON3bits.INT2IE == INTERRUPT_ENABLE)&&(INTCON3bits.INT2IF == 1)){
        ISR2();
    }
    else{}

    
    /*RBX INTERRUPT MANAGER*/
    if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_HIGH== PORTBbits.RB4)&&(1== flag4)){
         flag4=0;
        ISR_RBX4(0);
    }    
    else{}
    
        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_LOW== PORTBbits.RB4)&&(0== flag4)){
                 flag4=1;

            ISR_RBX4(1);
    }    
    else{}
    
        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_HIGH== PORTBbits.RB5)&&(1== flag5)){
                 flag5=0;

            ISR_RBX5(0);
    }    
    else{}
    
        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_LOW== PORTBbits.RB5)&&(0== flag5)){
        flag5=1;
            ISR_RBX5(1);
    }    
    else{}
   
        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_HIGH== PORTBbits.RB6)&&(1== flag6)){
                 flag6=0;

            ISR_RBX6(0);
    }    
    else{}
    
        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_LOW== PORTBbits.RB6)&&(0== flag6)){
        flag6=1;
            ISR_RBX6(1);
    }    
    else{}
    
        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_HIGH== PORTBbits.RB7)&&(1== flag7)){
                 flag7=0;

            ISR_RBX7(0);
    }    
    else{}
    
        if((INTCONbits.RBIE==INTERRUPT_ENABLE)&&(INTCONbits.RBIF==1)&&(GPIO_LOW== PORTBbits.RB7)&&(0== flag7)){
        flag7=1;
            ISR_RBX7(1);
    }    
    else{}
    
    
     /*ADC INTERRUPT MANAGER */
     if((PIE1bits.ADIE==INTERRUPT_ENABLE)&&(PIR1bits.ADIF==1)){
             ISR_ADC(); 

    }    
    else{}
    
           /*Timer0 INTERRUPT MANAGER */
     if((INTCONbits.T0IF==1)&&(INTCONbits.T0IE==INTERRUPT_ENABLE)){
             ISR_TIMER0(); 

    }    
    else{}
    
               /*Timer1 INTERRUPT MANAGER */
     if((PIR1bits.TMR1IF==1)&&(PIE1bits.TMR1IE==INTERRUPT_ENABLE)){
             ISR_TIMER1(); 

    }    
    else{}
                  /*Timer2 INTERRUPT MANAGER */
     if((PIR1bits.TMR2IF==1)&&(PIE1bits.TMR2IE==INTERRUPT_ENABLE)){
             ISR_TIMER2(); 

    }    
    else{}
    
                       /*Timer3 INTERRUPT MANAGER */
     if((PIR2bits.TMR3IF==1)&&(PIE2bits.TMR3IE==INTERRUPT_ENABLE)){
             ISR_TIMER3(); 

    }    
    else{}
    
                           /*CCP1 INTERRUPT MANAGER */
     if((PIR1bits.CCP1IF==1)&&(PIE1bits.CCP1IE==INTERRUPT_ENABLE)){
             ISR_CCP1(); 

    }    
    else{}
    
                               /*Euasrt TX INTERRUPT MANAGER */
     if((PIR1bits.TXIF==1)&&(PIE1bits.TXIE==INTERRUPT_ENABLE)&&(TXSTAbits.TRMT==1)){
             ISR_EUSART_TX(); 

    }    
    else{}
    
                                   /*Euasrt RX INTERRUPT MANAGER */
     if((PIR1bits.RCIF==1)&&(PIE1bits.RCIE==INTERRUPT_ENABLE)){
             ISR_EUSART_RX(); 

    }    
    else{}
    
                                       /*SPI INTERRUPT MANAGER */
     if((PIR1bits.SSPIF==1)&&(PIE1bits.SSPIE==INTERRUPT_ENABLE)){
             ISR_SPI(); 

    }    
    else{}
    
                                           /*I2C INTERRUPT MANAGER */

     if((INTERRUPT_ENABLE == PIE1bits.SSPIE) && (1 == PIR1bits.SSPIF)){
        MSSP_I2C_ISR();
    }
    else{ /* Nothing */ }
    if((INTERRUPT_ENABLE == PIE2bits.BCLIE) && (1 == PIR2bits.BCLIF)){
        MSSP_I2C_BC_ISR();
    }
    else{ /* Nothing */ }
    
}


#endif
