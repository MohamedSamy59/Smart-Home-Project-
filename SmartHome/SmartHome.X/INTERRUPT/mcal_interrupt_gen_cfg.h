/* 
 * File:   mcal_interrupt_gen_cfg.h
 * Author: Mohamed Samy
 *
 * Created on May 15, 2024, 3:11 PM
 */

#ifndef MCAL_INTERRUPT_GEN_CFG_H
#define	MCAL_INTERRUPT_GEN_CFG_H


/*Include Section*/


/*Macros Declarations Section*/
#define PRIORITY_ENABLE                              1U
#define _INTERRUPT_DISABLE                           0U
#define _INTERRUPT_ENABLE                            1U
/*ADC MACRO*/
#define ENABLE_ADC_INTERRUPT                         1U
#define DISABLE_ADC_INTERRUPT                        0U

/*TIMER0 MACRO*/
#define _TIMER0_INTERRUPT_ENABLE_                      1U
#define _TIMER0_INTERRUPT_DISABLE_                     0U

/*TIMER1 MACRO*/
#define _TIMER1_INTERRUPT_ENABLE_                      1U
#define _TIMER1_INTERRUPT_DISABLE_                     0U

/*TIMER2 MACRO*/
#define _TIMER2_INTERRUPT_ENABLE_                      1U
#define _TIMER2_INTERRUPT_DISABLE_                     0U


/*TIMER3 MACRO*/
#define _TIMER3_INTERRUPT_ENABLE_                      1U
#define _TIMER3_INTERRUPT_DISABLE_                     0U


/*CC1 MACRO*/
#define _CCP1_INTERRUPT_ENABLE_                        1U
#define _CCP1_INTERRUPT_DISABLE_                       0U


/*EUSART TX MACRO*/
#define _EUSART_TX_INTERRUPT_ENABLE_                        1U
#define _EUSART_TX_INTERRUPT_DISABLE_                       0U
/*EUSART RX MACRO*/
#define _EUSART_RX_INTERRUPT_ENABLE_                        1U
#define _EUSART_RX_INTERRUPT_DISABLE_                       0U

/*SPI RECEIVER MACRO*/
#define _SPI_RECEIVER_INTERRUPT_ENABLE_                        1U
#define _SPI_RECEIVER_INTERRUPT_DISABLE_                       0U


/*I2c RECEIVER MACRO*/
#define I2C_INTERRUPT_FEATURE_ENABLE                         1U
#define I2C_INTERRUPT_FEATURE_DISABLE                        0U



#define INTERRUPT_PRIORITY_FEATURE              PRIORITY_ENABLE
#define INTERRUPT_ENABLE_CFG                    _INTERRUPT_ENABLE
#define ADC_INTERRUPT_ENABLE_CFG                ENABLE_ADC_INTERRUPT
#define TIMER0_INTERRUPT_ENABLE_CFG             _TIMER0_INTERRUPT_ENABLE_
#define TIMER1_INTERRUPT_ENABLE_CFG             _TIMER1_INTERRUPT_ENABLE_
#define TIMER2_INTERRUPT_ENABLE_CFG             _TIMER2_INTERRUPT_ENABLE_
#define TIMER3_INTERRUPT_ENABLE_CFG             _TIMER3_INTERRUPT_ENABLE_
#define CCP1_INTERRUPT_ENABLE_CFG               _CCP1_INTERRUPT_ENABLE_
#define EUSART_TX_INTERRUPT_ENABLE_CFG          _EUSART_TX_INTERRUPT_ENABLE_
#define EUSART_RX_INTERRUPT_ENABLE_CFG          _EUSART_RX_INTERRUPT_ENABLE_
#define SPI_RECEIVER_INTERRUPT_ENABLE_CFG       _SPI_RECEIVER_INTERRUPT_ENABLE_
#define MSSP_I2C_INTERRUPT_FEATURE_ENABLE       I2C_INTERRUPT_FEATURE_DISABLE




/*Macros Function Declarations Section*/



/*Data Type Function Declarations Section*/

/*Function Declarations Section*/       

#endif	/* MCAL_INTERRUPT_GEN_CFG_H */

