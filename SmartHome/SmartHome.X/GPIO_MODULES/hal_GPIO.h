/* 
 * File:   hal_GPIO.h
 * Author: Mohamed Samy
 *
 * Created on March 19, 2024, 8:19 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H


/*Include Section*/
#include "../proc/pic18f46k20.h"

#include "compiler.h"
#include "mcal_std_types.h"
#include "std_libraries.h"
#include "hal_gpio_cfg.h"
#include "device_config.h"
/*Macros Declarations Section*/

#define BIT_MASK (uint8)1
#define PIN_MAX_NUMBER  8
#define PORT_MAX_NUMBER 5
#define PORT_MASK       0xFF

/*Macros Function Declarations Section*/

#define HWREG8(x)               (*((volatile uint8 *)(x)))
#define SET_BIT(reg,pos)        (reg |= (BIT_MASK << pos))
#define CLEAR_BIT(reg,pos)      (reg &= ~(BIT_MASK << pos))
#define TOGGLE_BIT(reg,pos)     (reg ^= (BIT_MASK << pos))
#define GET_BIT(reg,pos)        (BIT_MASK & (reg >> pos))


/*Data Type Function Declarations Section*/

typedef enum {
    GPIO_PIN0,  
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7,
}pin_index_t;

typedef enum{
    
    GPIO_LOW,
    GPIO_HIGH
}logic_t;

typedef enum {
    GPIO_DIRECTION_OUTPUT,
    GPIO_DIRECTION_INPUT,
}direction_t;

typedef enum {
    PORTA_INDEX,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX,
}port_index_t;

typedef struct {
    uint8 port          :3;
    uint8 pin           :3;
    uint8 direction     :1;
    uint8 logic         :1;

}pin_config_t;


/*Function Declarations Section*/
/**
 * 
 * @param _pin_config: pointer to struct of pin details
 * @return return the status of the funcion :
             E_OK  : when the function execute successfully
             E_NOK : when the function failed to execute 
 */
Std_ReturnType gpio_pin_direction_intialization (const pin_config_t *_pin_config);

/**
 * 
 * @param _pin_config: pointer to struct of pin details
 * @param direction_status: has the status of pin direction 
 * @return ret: return the status of the funcion :
             E_OK  : when the function execute successfully
             E_NOK : when the function failed to execute
 */
Std_ReturnType gpio_pin_direction_status (const pin_config_t *_pin_config, direction_t *direction_status);

/**
 * 
 * @param _pin_config: pointer to struct of pin details
 * @param logic: the logic of the pin
 * @return ret: return the status of the funcion :
             E_OK  : when the function execute successfully
             E_NOK : when the function failed to execute
 */
Std_ReturnType gpio_pin_write_logic (const pin_config_t *_pin_config, logic_t logic);

/**
 * 
 * @param _pin_config: pointer to struct of pin details
 * @param logic: the status of pin logic
 * @return ret: return the status of the funcion :
             E_OK  : when the function execute successfully
             E_NOK : when the function failed to execute
 */
Std_ReturnType gpio_pin_read_logic (const pin_config_t *_pin_config, logic_t *logic);

/**
 * 
 * @param _pin_config: pointer to struct of pin details
 * @return ret:  the status of the funcion :
             E_OK  : when the function execute successfully
             E_NOK : when the function failed to execute
 */
Std_ReturnType gpio_pin_toggle_logic (const pin_config_t *_pin_config);

/**
 * 
 * @param _pin_config: pointer to struct of pin details
 * @return ret: return the status of the funcion :
             E_OK  : when the function execute successfully
             E_NOK : when the function failed to execute
 */
Std_ReturnType gpio_pin_initialization (const pin_config_t *_pin_config);



/**
 * 
 * @param port: the port number
 * @param direction: the direction of the overall port
 * @return ret: return the status of the funcion :
             E_OK  : when the function execute successfully
             E_NOK : when the function failed to execute
 */
Std_ReturnType gpio_port_direction_intialization (port_index_t port,uint8 direction);

/**
 * 
 * @param port: the port number
 * @param direction_status: the direction status of the overall port
 * @return ret: return the status of the funcion :
             E_OK  : when the function execute successfully
             E_NOK : when the function failed to execute
 */
Std_ReturnType gpio_port_direction_status (port_index_t port, uint8 *direction_status);

/**
 * 
 * @param port: the port number[0:4]
 * @param logic: the logic of overall port
 * @return ret: return the status of the funcion :
             E_OK  : when the function execute successfully
             E_NOK : when the function failed to execute
 */
Std_ReturnType gpio_port_write_logic (port_index_t port, uint8 logic);

/**
 * 
 * @param port: the port number
 * @param logic: the logic status of overall port
 * @return ret: return the status of the funcion :
             E_OK  : when the function execute successfully
             E_NOK : when the function failed to execute
 */
Std_ReturnType gpio_port_read_logic (port_index_t port, uint8 *logic);

/**
 * 
 * @param port: the port number
 * @return ret: return the status of the funcion :
             E_OK  : when the function execute successfully
             E_NOK : when the function failed to execute
 */
Std_ReturnType gpio_port_toggle_logic (port_index_t port);


#endif	/* HAL_GPIO_H */

