/* 
 * File:   spi.c
 * Author: Mohamed Samy
 *
 * Created on June 26, 2024, 12:40 PM
 */

/*Include Interfaces Header File Section */
#include "spi.h"

/*Global Variable Definition Section*/
    


/*APIs Definition Section*/
static void(*SPI_INTERRUPT_HANDLER)(void);
static Std_ReturnType mode_select(const spi_t *spi);
static Std_ReturnType sample_select(const spi_t *spi);
static Std_ReturnType polarity_select(const spi_t *spi);
static Std_ReturnType phase_select(const spi_t *spi);

Std_ReturnType mcal_spi_initialization(const spi_t *spi){
    Std_ReturnType ret = E_OK;
    if(NULL==spi){
        ret=E_NOK;
    }
    else{
        DISABLE_SERIAL_PORT();

        ret=mode_select(spi);
        ret|=sample_select(spi);
        ret|=polarity_select(spi);
        ret|=phase_select(spi);

        CLEAR_BIT(TRISC,_TRISC_RC5_POSITION);
        SET_BIT(TRISA,_TRISC_RC5_POSITION);

#if SPI_RECEIVER_INTERRUPT_ENABLE_CFG == _SPI_RECEIVER_INTERRUPT_ENABLE_
        SPI_RECEIVER_CLEAR_FLAG();
                        
        SPI_RECEIVER_INTERRUPT_ENABLE();
        
#if INTERRUPT_PRIORITY_FEATURE==PRIORITY_ENABLE
            IPEN_ENABLE();
            if(spi->priority==INTERRUPT_HIGH_PRIORITY){
                GIEH_ENABLE();
                SPI_RECEIVER_HIGH_PRIORITY();
            }
            else if(spi->priority==INTERRUPT_LOW_PRIORITY){
                GIEH_ENABLE();
                GIEL_ENABLE();
                SPI_RECEIVER_LOW_PRIORITY();
            }
            else{   
            }

#else
            GIE_ENABLE();
            PEIE_ENABLE();
#endif
            SPI_INTERRUPT_HANDLER=spi->SPI_ptr_handler;
#endif
        
        
        
        ENABLE_SERIAL_PORT();

    }
    return ret;
}
Std_ReturnType mcal_spi_DeInitialization(const spi_t *spi){
        Std_ReturnType ret = E_OK;
    if(NULL==spi){
        ret=E_NOK;
    }
    else{
        DISABLE_SERIAL_PORT();

#if SPI_RECEIVER_INTERRUPT_ENABLE_CFG == _SPI_RECEIVER_INTERRUPT_ENABLE_
                        
        SPI_RECEIVER_INTERRUPT_DISABLE();
#endif
    }
    return ret;
}


Std_ReturnType mcal_spi_write_byte_Blocking(uint8 data){
    Std_ReturnType ret = E_OK;
            DISABLE_SERIAL_PORT();

           SSPBUF=(uint8)data;
        /*while(!(PIR1bits.SSPIF)); 
        SPI_RECEIVER_CLEAR_FLAG();*/
            ENABLE_SERIAL_PORT();

    return ret;
}

Std_ReturnType mcal_spi_write_string_Blocking(uint8 *data){
    Std_ReturnType ret = E_OK;
    if(NULL==data){
              ret=E_NOK;

    }
    else{
          while(*data!='\0'){
           ret= mcal_spi_write_byte_Blocking(*data);

            data++;
        }
    }
    
    return ret;
}


Std_ReturnType mcal_spi_read_data_Blocking(uint8 *data){
    Std_ReturnType ret = E_OK;
    if(NULL==data){
              ret=E_NOK;

    }
    else{     
        while(!(PIR1bits.SSPIF));
        *data=SSPBUF;
        PIR1bits.SSPIF = 0;
        
    }
    
    return ret;
}


static Std_ReturnType mode_select(const spi_t *spi){
        Std_ReturnType ret = E_OK;

        switch(spi->mode){
            case MASTER_MODE_Fosc_DIV_4 : SSPCON1bits.SSPM=MASTER_MODE_Fosc_DIV_4;
                    CLEAR_BIT(TRISC,_TRISC_RC3_POSITION);
                    gpio_pin_direction_intialization(&(spi->master_ss_pin));

            break;
            case MASTER_MODE_Fosc_DIV_16 : SSPCON1bits.SSPM=MASTER_MODE_Fosc_DIV_16;
                    CLEAR_BIT(TRISC,_TRISC_RC3_POSITION);
                    gpio_pin_direction_intialization(&(spi->master_ss_pin));

            break;            
            case MASTER_MODE_Fosc_DIV_64 : SSPCON1bits.SSPM=MASTER_MODE_Fosc_DIV_64;
                    CLEAR_BIT(TRISC,_TRISC_RC3_POSITION);
                    gpio_pin_direction_intialization(&(spi->master_ss_pin));

            break;            
            case MASTER_MODE_CLK_TM2_DIV_2 : SSPCON1bits.SSPM=MASTER_MODE_CLK_TM2_DIV_2;
                    CLEAR_BIT(TRISC,_TRISC_RC3_POSITION);
                    gpio_pin_direction_intialization(&(spi->master_ss_pin));

            break;            
            case SLAVE_MODE_SCLK_ENABLE_SS : SSPCON1bits.SSPM=SLAVE_MODE_SCLK_ENABLE_SS;
                    SET_BIT(TRISC,_TRISC_RC3_POSITION);

            break;
            case SLAVE_MODE_SCLK_DISABLE_SS : SSPCON1bits.SSPM=SLAVE_MODE_SCLK_DISABLE_SS;
                                SET_BIT(TRISC,_TRISC_RC3_POSITION);

            break;            
            default  : ret=E_NOK;
            break;
        
        
        }
            return ret;

}

static Std_ReturnType sample_select(const spi_t *spi){
        Std_ReturnType ret = E_OK;

        if(SAMPLE_AT_END==spi->sample_state){
            MAS_SAMPLE_AT_END();
        }
        else if(SAMPLE_AT_MIDDLE==spi->sample_state){
            MAS_SAMPLE_AT_MIDDLE();
        }
        else{
            ret=E_NOK;
        }
        
            return ret;

}

static Std_ReturnType polarity_select(const spi_t *spi){
        Std_ReturnType ret = E_OK;

        if(HIGH_LEVEL_IDEL==spi->polarity_state){
            HIGH_LEVEL_IDEL_STATE();
        }
        else if(LOW_LEVEL_IDEL==spi->polarity_state){
            LOW_LEVEL_IDEL_STATE();
        }
        else{
            ret=E_NOK;
        }
        
            return ret;

}

static Std_ReturnType phase_select(const spi_t *spi){
        Std_ReturnType ret = E_OK;

        if(TRANS_FROM_ACTIVE_TO_IDEL==spi->clk_phase_state){
            CLK_TRANS_FROM_ACTIVE_TO_IDEL();
        }
        else if(TRANS_FROM_IDLE_TO_ACTIVE==spi->polarity_state){
            CLK_TRANS_FROM_IDLE_TO_ACTIVE();
        }
        else{
            ret=E_NOK;
        }
        
            return ret;

}

void ISR_SPI(void){
    SPI_RECEIVER_CLEAR_FLAG();
    if(SPI_INTERRUPT_HANDLER){
        SPI_INTERRUPT_HANDLER();
    }
}
        