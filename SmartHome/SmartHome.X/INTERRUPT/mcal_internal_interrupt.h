/* 
 * File:   mcal_internal_interrupt.h
 * Author: Mohamed Samy
 *
 * Created on May 15, 2024, 3:02 PM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define MCAL_INTERNAL_INTERRUPT_H

/*Include Section*/
#include "mcal_interrupt_common_config.h"


/*Macros Declarations Section



/*Macros Function Declarations Section*/

 
/* ENABLE INTERRUPT FEATURE*/
#define IPEN_ENABLE() (RCONbits.IPEN=INTERRUPT_ENABLE)
/*DISABLE INTERRUPT FEATURE*/
#define IPEN_DISABLE() (RCONbits.IPEN=INTERRUPT_DISABLE)
 
 /* ENABLE GLOBAL INTERRUPT*/
#define GIE_ENABLE() (INTCONbits.GIE=INTERRUPT_ENABLE)
/*DISABLE GLOBAL INTERRUPT*/
#define GIE_DISABLE() (INTCONbits.GIE=INTERRUPT_DISABLE)
 
/* ENABLE PERIPHERAL GLOBAL INTERRUPT*/
#define PEIE_ENABLE() (INTCONbits.PEIE=INTERRUPT_ENABLE)
/*DISABLE PERIPHERAL GLOBAL INTERRUPT*/
#define PEIE_DISABLE() (INTCONbits.PEIE=INTERRUPT_DISABLE)

 /* ENABLE GLOBAL HIGH INTERRUPT*/
#define GIEH_ENABLE() (INTCONbits.GIEH=INTERRUPT_ENABLE)
/*DISABLE GLOBAL HIGH INTERRUPT*/
#define GIEH_DISABLE() (INTCONbits.GIEH=INTERRUPT_DISABLE)
 
/* ENABLE GLOBAL LOW INTERRUPT*/
#define GIEL_ENABLE() (INTCONbits.GIEL=INTERRUPT_ENABLE)
/*DISABLE GLOBAL LOW INTERRUPT*/
#define GIEL_DISABLE() (INTCONbits.GIEL=INTERRUPT_DISABLE)

/*ADC Interrupt*/
#define  ADC_CLEAR_FLAG()             (PIR1bits.ADIF=0)

#define  ADC_INTERRUPT_ENABLE()       (PIE1bits.ADIE=1)
#define  ADC_INTERRUPT_DISABLE()      (PIE1bits.ADIE=0)

#if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
    #define  ADC_HIGH_PRIORITY()         (IPR1bits.ADIP=1)
    #define  ADC_LOW_PRIORITY()          (IPR1bits.ADIP=0)
#endif

/*Timer0 Interrupt*/
#define  TIMER0_CLEAR_FLAG()             (INTCONbits.T0IF=0)

#define  TIMER0_INTERRUPT_ENABLE()       (INTCONbits.T0IE=1)
#define  TIMER0_INTERRUPT_DISABLE()      (INTCONbits.T0IE=0)

#if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
    #define  TIMER0_HIGH_PRIORITY()         (INTCON2bits.TMR0IP=1)
    #define  TIMER0_LOW_PRIORITY()          (INTCON2bits.TMR0IP=0)
#endif

/*Timer1 Interrupt*/
#define  TIMER1_CLEAR_FLAG()             (PIR1bits.TMR1IF=0)

#define  TIMER1_INTERRUPT_ENABLE()       (PIE1bits.TMR1IE=1)
#define  TIMER1_INTERRUPT_DISABLE()      (PIE1bits.TMR1IE=0)

#if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
    #define  TIMER1_HIGH_PRIORITY()         (IPR1bits.TMR1IP=1)
    #define  TIMER1_LOW_PRIORITY()          (IPR1bits.TMR1IP=0)
#endif


/*Timer2 Interrupt*/
#define  TIMER2_CLEAR_FLAG()             (PIR1bits.TMR2IF=0)

#define  TIMER2_INTERRUPT_ENABLE()       (PIE1bits.TMR2IE=1)
#define  TIMER2_INTERRUPT_DISABLE()      (PIE1bits.TMR2IE=0)

#if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
    #define  TIMER2_HIGH_PRIORITY()         (IPR1bits.TMR2IP=1)
    #define  TIMER2_LOW_PRIORITY()          (IPR1bits.TMR2IP=0)
#endif

/*Timer3 Interrupt*/
#define  TIMER3_CLEAR_FLAG()             (PIR2bits.TMR3IF=0)

#define  TIMER3_INTERRUPT_ENABLE()       (PIE2bits.TMR3IE=1)
#define  TIMER3_INTERRUPT_DISABLE()      (PIE2bits.TMR3IE=0)

#if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
    #define  TIMER3_HIGH_PRIORITY()         (IPR2bits.TMR3IP=1)
    #define  TIMER3_LOW_PRIORITY()          (IPR2bits.TMR3IP=0)
#endif

/*CCP1 Interrupt*/
#define  CCP1_CLEAR_FLAG()             (PIR1bits.CCP1IF=0)

#define  CCP1_INTERRUPT_ENABLE()       (PIE1bits.CCP1IE=1)
#define  CCP1_INTERRUPT_DISABLE()      (PIE1bits.CCP1IE=0)

#if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
    #define  CCP1_HIGH_PRIORITY()         (IPR1bits.CCP1IP=1)
    #define  CCP1_LOW_PRIORITY()          (IPR1bits.CCP1IP=0)
#endif


/*EUSART TX Interrupt*/
#define  EUART_TX_INTERRUPT_ENABLE()       (PIE1bits.TXIE=1)
#define  EUART_TX_INTERRUPT_DISABLE()      (PIE1bits.TXIE=0)

#if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
    #define  EUART_TX_HIGH_PRIORITY()         (IPR1bits.TXIP=1)
    #define  EUART_TX_LOW_PRIORITY()          (IPR1bits.TXIP=0)
#endif

/*EUSART RX Interrupt*/
#define  EUART_RX_INTERRUPT_ENABLE()       (PIE1bits.RCIE=1)
#define  EUART_RX_INTERRUPT_DISABLE()      (PIE1bits.RCIE=0)

#if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
    #define  EUART_RX_HIGH_PRIORITY()         (IPR1bits.RCIP=1)
    #define  EUART_RX_LOW_PRIORITY()          (IPR1bits.RCIP=0)
#endif


/*SPI Receiver Interrupt*/
#define  SPI_RECEIVER_CLEAR_FLAG()             (PIR1bits.SSPIF=0)

#define  SPI_RECEIVER_INTERRUPT_ENABLE()       (PIE1bits.SSPIE=1)
#define  SPI_RECEIVER_INTERRUPT_DISABLE()      (PIE1bits.SSPIE=0)

#if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
    #define  SPI_RECEIVER_HIGH_PRIORITY()         (IPR1bits.SSPIP=1)
    #define  SPI_RECEIVER_LOW_PRIORITY()          (IPR1bits.SSPIP=0)
#endif


/*I2C Receiver Interrupt*/
/* This routine clears the interrupt enable for the MSSP I2C Module */
#define MSSP_I2C_InterruptDisable()         (PIE1bits.SSPIE = 0)
#define MSSP_I2C_BUS_COL_InterruptDisable() (PIE2bits.BCLIE = 0)
/* This routine sets the interrupt enable for the MSSP I2C Module */
#define MSSP_I2C_InterruptEnable()          (PIE1bits.SSPIE = 1)
#define MSSP_I2C_BUS_COL_InterruptEnable()  (PIE2bits.BCLIE = 1)
/* This routine clears the interrupt flag for the MSSP I2C Module */
#define MSSP_I2C_InterruptFlagClear()         (PIR1bits.SSPIF = 0)
#define MSSP_I2C_BUS_COL_InterruptFlagClear() (PIR2bits.BCLIF = 0)
#if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
/* This routine set the MSSP I2C Module Interrupt Priority to be High priority */
#define MSSP_I2C_HighPrioritySet()          (IPR1bits.SSPIP = 1)
#define MSSP_I2C_BUS_COL_HighPrioritySet()  (IPR2bits.BCLIP = 1)
/* This routine set the MSSP I2C Module Interrupt Priority to be Low priority */
#define MSSP_I2C_LowPrioritySet()           (IPR1bits.SSPIP = 0)
#define MSSP_I2C_BUS_COL_LowPrioritySet()   (IPR2bits.BCLIP = 0)
#endif


/*Data Type Function Declarations Section*/

/*Function Declarations Section*/       

 void ADC_handler_init(void (*_handler)(void));



#endif/* MCAL_INTERNAL_INTERRUPT_H */

