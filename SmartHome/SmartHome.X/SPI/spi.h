/* 
 * File:   spi.h
 * Author: Mohamed Samy
 *
 * Created on June 26, 2024, 12:40 PM
 */

#ifndef SPI_H
#define	SPI_H


/*Include Section*/
#include "spi_cfg.h"
#include "../proc/pic18f46k20.h"
#include "../GPIO_MODULES/mcal_std_types.h"
#include "../INTERRUPT/mcal_internal_interrupt.h"
/*Macros Declarations Section*/

#define SAMPLE_AT_END                   1U
#define SAMPLE_AT_MIDDLE                0U
#define HIGH_LEVEL_IDEL                 1U
#define LOW_LEVEL_IDEL                  0U
#define TRANS_FROM_ACTIVE_TO_IDEL       1U
#define TRANS_FROM_IDLE_TO_ACTIVE       0U

/*Macros Function Declarations Section*/
#define MAS_SAMPLE_AT_END()                     (SSPSTATbits.SMP=1)
#define MAS_SAMPLE_AT_MIDDLE()                  (SSPSTATbits.SMP=0)
#define CLK_TRANS_FROM_ACTIVE_TO_IDEL()         (SSPSTATbits.CKE=1)
#define CLK_TRANS_FROM_IDLE_TO_ACTIVE()         (SSPSTATbits.CKE=0)
#define HIGH_LEVEL_IDEL_STATE()                 (SSPCON1bits.CKP=1)
#define LOW_LEVEL_IDEL_STATE()                  (SSPCON1bits.CKP=0)
#define ENABLE_SERIAL_PORT()                    (SSPCON1bits.SSPEN=1)
#define DISABLE_SERIAL_PORT()                   (SSPCON1bits.SSPEN=0)





/*Data Type Function Declarations Section*/
typedef enum{
    MASTER_MODE_Fosc_DIV_4,
    MASTER_MODE_Fosc_DIV_16,
    MASTER_MODE_Fosc_DIV_64,
    MASTER_MODE_CLK_TM2_DIV_2,
    SLAVE_MODE_SCLK_ENABLE_SS,
    SLAVE_MODE_SCLK_DISABLE_SS,
}serial_mode;


typedef struct{
#if SPI_RECEIVER_INTERRUPT_ENABLE_CFG == _SPI_RECEIVER_INTERRUPT_ENABLE_
    void (*SPI_ptr_handler)(void);  
    priority_t priority;
#endif
 serial_mode mode;
 uint8 sample_state:1;
 uint8 polarity_state:1;
 uint8 clk_phase_state:1;
 uint8 reserved:5;
 pin_config_t master_ss_pin;
}spi_t;

/*Function Declarations Section*/

Std_ReturnType mcal_spi_initialization(const spi_t *spi);
Std_ReturnType mcal_spi_DeInitialization(const spi_t *spi);
Std_ReturnType mcal_spi_read_data_Non_Blocking(uint8 *data);
Std_ReturnType mcal_spi_read_data_Blocking(uint8 *data);
Std_ReturnType mcal_spi_write_byte_Non_Blocking(uint8 data);
Std_ReturnType mcal_spi_write_string_Non_Blocking(uint8 *data);
Std_ReturnType mcal_spi_write_byte_Blocking(uint8 data);
Std_ReturnType mcal_spi_write_string_Blocking(uint8 *data);


#endif	/* SPI_H */

