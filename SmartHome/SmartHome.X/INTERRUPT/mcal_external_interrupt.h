/* 
 * File:   mcal_external_interrupt.h
 * Author: Mohamed Samy
 *
 * Created on May 15, 2024, 3:06 PM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/*Include Section*/
#include "mcal_interrupt_common_config.h"


/*Macros Declarations Section*/
 typedef enum{
      INTx_FALLING_EDGE,
     INTx_RISING_EDGE
 }edge_t;

 typedef enum{
    INTERRUPT_INT0,
    INTERRUPT_INT1,
    INTERRUPT_INT2
 }source_t;
 
  typedef enum{
    INTERRUPT_RB4=4,
    INTERRUPT_RB5=5,
    INTERRUPT_RB6=6,
    INTERRUPT_RB7=7

 }rbx_source_t;

 typedef void (*Ptr_interruupt_handler)(void);

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
 
/*INT0 ENABLE*/
#define INT0_ENABLE() (INTCONbits.INT0IE=INTERRUPT_ENABLE)
/*INT0 DISABLE*/
#define INT0_DISABLE() (INTCONbits.INT0IE=INTERRUPT_DISABLE)
/*INT0 CLEAR FLAG*/
#define INT0_CLEAR() (INTCONbits.INT0IF=CLEAR_FLAG)
/*INT0 RISING EDGRE*/
#define INT0_RISING_EDGE() (INTCON2bits.INTEDG0=INTx_RISING_EDGE)
/*INT0 FALLING EDGRE*/
#define INT0_FALLING_EDGE() (INTCON2bits.INTEDG0=INTx_FALLING_EDGE)
 
/*INT1 ENABLE*/
#define INT1_ENABLE() (INTCON3bits.INT1E=INTERRUPT_ENABLE)
 /*INT1 DISABLE*/
#define INT1_DISABLE() (INTCON3bits.INT1E=INTERRUPT_DISABLE)
 
   #if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE

/*INT1 PRIORITY HIGH*/
#define INT1_HIGH_PRIORITY() (INTCON3bits.INT1IP=INTERRUPT_HIGH_PRIORITY)
/*INT1 PRIORITY LOW*/
#define INT1_LOW_PRIORITY() (INTCON3bits.INT1IP=INTERRUPT_LOW_PRIORITY)
 
#endif
/*INT1 CLEAR FLAG*/
#define INT1_CLEAR() (INTCON3bits.INT1IF=CLEAR_FLAG)
 /*INT1 RISING EDGRE*/
#define INT1_RISING_EDGE() (INTCON2bits.INTEDG1=INTx_RISING_EDGE)
/*INT1 FALLING EDGRE*/
#define INT1_FALLING_EDGE() (INTCON2bits.INTEDG1=INTx_FALLING_EDGE)
 
 

/*INT2 ENABLE*/
#define INT2_ENABLE() (INTCON3bits.INT2IE=INTERRUPT_ENABLE)
 /*INT2 DISABLE*/
#define INT2_DISABLE() (INTCON3bits.INT2IE=INTERRUPT_DISABLE)
 
  #if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
 
 
/*INT2 PRIORITY HIGH*/
#define INT2_HIGH_PRIORITY() (INTCON3bits.INT2IP=INTERRUPT_HIGH_PRIORITY)
/*INT2 PRIORITY LOW*/
#define INT2_LOW_PRIORITY() (INTCON3bits.INT2IP=INTERRUPT_LOW_PRIORITY)
 
#endif
 
/*INT2 CLEAR FLAG*/
#define INT2_CLEAR() (INTCON3bits.INT2IF=CLEAR_FLAG)
 /*INT2 RISING EDGRE*/
#define INT2_RISING_EDGE() (INTCON2bits.INTEDG2=INTx_RISING_EDGE)
/*INT2 FALLING EDGRE*/
#define INT2_FALLING_EDGE() (INTCON2bits.INTEDG2=INTx_FALLING_EDGE)
 
/*RBX ENABLE*/
#define RBX_ENABLE()  (INTCONbits.RBIE=INTERRUPT_ENABLE)
/*RBX DISABLE*/
#define RBX_DISABLE()  (INTCONbits.RBIE=INTERRUPT_DISABLE)
 
/*RBX CLEAR FLAG*/
#define RBX_CLEAR()  (INTCONbits.RBIF=CLEAR_FLAG)
 
#if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
/*RBX RIORITY HIGH*/
#define RBX_HIGH_PRIORITY() (INTCON2bits.RBIP=INTERRUPT_HIGH_PRIORITY)
 /*RBX PRIORITY LOW*/
#define RBX_LOW_PRIORITY() (INTCON2bits.RBIP=INTERRUPT_LOW_PRIORITY)

#endif
 
 
 
 
/*Data Type Function Declarations Section*/
typedef struct{
    pin_config_t pin;
    edge_t edge;
    source_t source;
    priority_t priority;
    Ptr_interruupt_handler Int_interrupt_handler;
}intx_t;
        

typedef struct{
    pin_config_t pin;
    priority_t priority;
    Ptr_interruupt_handler RBx_interrupt_handler_rising;
    Ptr_interruupt_handler RBx_interrupt_handler_falling;

}rbx_t;

/*Function Declarations Section*/   


/**
 * @brief           : initialization the pin
 * @param motor     : pointer to structure intx_t
 * @return          : return the status of the funcion :
                         E_OK  : when the function execute successfully
                         E_NOK : when the function failed to execute 
 */
Std_ReturnType mcal_interrupt_intx_init(const intx_t *obj);

/**
 * @brief           : Dinitialization the pin
 * @param motor     : pointer to structure intx_t
 * @return          : return the status of the funcion :
                         E_OK  : when the function execute successfully
                         E_NOK : when the function failed to execute 
 */
Std_ReturnType mcal_interrupt_intx_Dinit(const intx_t *obj);

/**
 * @brief           : initialization the pin
 * @param motor     : pointer to structure intx_t
 * @return          : return the status of the funcion :
                         E_OK  : when the function execute successfully
                         E_NOK : when the function failed to execute 
 */
Std_ReturnType mcal_interrupt_RBx_init(const rbx_t *obj);



#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

