/* 
 * File:   hal_GPIO.c
 * Author: Mohamed Samy
 *
 * Created on March 19, 2024, 5:39 PM
 */

/*Include Interfaces Header File Section */
#include "hal_GPIO.h"

/*Global Variable Definition Section*/
uint8 *tris_reg[]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
uint8 *lat_reg[] = {&LATA,&LATB,&LATC,&LATD,&LATE};
uint8 *port_reg[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};

/*APIs Definition Section*/
#if pin_port_configurations == config_enable
Std_ReturnType gpio_pin_direction_intialization (const pin_config_t *_pin_config){
     
    Std_ReturnType ret = E_OK;
    
    if(NULL == _pin_config || (_pin_config ->pin) > PIN_MAX_NUMBER ){
        ret = E_NOK;
    }
    else
    {
        switch(_pin_config->direction)
        {
            case GPIO_DIRECTION_OUTPUT:
                CLEAR_BIT(*(tris_reg[_pin_config->port]),(_pin_config->pin));
                break;
            case GPIO_DIRECTION_INPUT:
                SET_BIT(*(tris_reg[_pin_config->port]),(_pin_config->pin));
                break;
            default:
                ret = E_NOK;
                break;
        
        }
    }
    return ret;
}
#endif


#if pin_port_configurations==config_enable
Std_ReturnType gpio_pin_write_logic (const pin_config_t *_pin_config, logic_t logic){
    
  Std_ReturnType ret = E_OK;
    
    if(NULL == _pin_config || (_pin_config ->pin) > PIN_MAX_NUMBER-1 ){
        ret = E_NOK;
    }
    else
    {
        switch(logic)
        {
            case GPIO_LOW:
                CLEAR_BIT(*(lat_reg[_pin_config->port]),(_pin_config->pin));
                break;
            case GPIO_HIGH:
                SET_BIT(*(lat_reg[_pin_config->port]),(_pin_config->pin));
                break;
            default:
                ret = E_NOK;
                break;
        
        }
    }
    return ret;

};
#endif


#if pin_port_configurations == config_enable
Std_ReturnType gpio_pin_direction_status (const pin_config_t *_pin_config, direction_t *direction_status)
{
    Std_ReturnType ret = E_OK;
    if(NULL==_pin_config || NULL==direction_status || _pin_config->pin > PIN_MAX_NUMBER-1)
    {
        ret= E_NOK;
    }
    else {
        *direction_status = GET_BIT(*tris_reg[_pin_config->port],_pin_config->pin);
    }
    return ret;
}
#endif


#if pin_port_configurations == config_enable
Std_ReturnType gpio_pin_read_logic (const pin_config_t *_pin_config, logic_t *logic){
     Std_ReturnType ret = E_OK;
    if(NULL==_pin_config || NULL==logic )
    {
        ret= E_NOK;
    }
    else
    {
   *logic = GET_BIT(*port_reg[_pin_config->port],_pin_config->pin);
    }
    return ret;
}
#endif


#if pin_port_configurations == config_enable
Std_ReturnType gpio_pin_toggle_logic (const pin_config_t *_pin_config){
     Std_ReturnType ret = E_OK;
    
    if(NULL==_pin_config || _pin_config->pin > PIN_MAX_NUMBER-1)
    {
        ret= E_NOK;
    }
    else
    {
        TOGGLE_BIT(*lat_reg[_pin_config->port],_pin_config->pin);
    }
    return ret;
    
}
#endif


#if pin_port_configurations == config_enable
Std_ReturnType gpio_pin_initialization (const pin_config_t *_pin_config){
    Std_ReturnType ret = E_OK;
   ret = gpio_pin_direction_intialization(_pin_config);
   ret = gpio_pin_write_logic(_pin_config,_pin_config->logic);
}
#endif


#if pin_port_configurations == config_enable
Std_ReturnType gpio_port_direction_intialization (port_index_t port,uint8 direction){
     Std_ReturnType ret = E_OK;
    
    if(port>PORT_MAX_NUMBER-1)
    {
        ret= E_NOK;
    }
    else
    {
        *tris_reg[port]=direction;
    }
    return ret;
}
#endif


#if pin_port_configurations == config_enable
Std_ReturnType gpio_port_direction_status (port_index_t port, uint8 *direction_status){
     Std_ReturnType ret = E_OK;
    
    if(port>PORT_MAX_NUMBER-1 || direction_status ==NULL)
    {
        ret= E_NOK;
    }
    else
    {
        *direction_status = *tris_reg[port];
    }
    return ret;
}
#endif



#if pin_port_configurations == config_enable
Std_ReturnType gpio_port_write_logic (port_index_t port, uint8 logic){
     Std_ReturnType ret = E_OK;
    
    if(port>PORT_MAX_NUMBER-1)
    {
        ret= E_NOK;
    }
    else
    {
         *lat_reg[port]=logic;
    }
    return ret;
}
#endif



#if pin_port_configurations == config_enable
Std_ReturnType gpio_port_read_logic (port_index_t port, uint8 *logic){
     Std_ReturnType ret = E_OK;
    
    if(port>PORT_MAX_NUMBER-1 || logic ==NULL)
    {
        ret= E_NOK;
    }
    else
    {
        *logic =  *port_reg[port];
    }
    return ret;
}
#endif


#if pin_port_configurations == config_enable
Std_ReturnType gpio_port_toggle_logic (port_index_t port){
     Std_ReturnType ret = E_OK;
    
    if(port>PORT_MAX_NUMBER-1)
    {
        ret= E_NOK;
    }
    else
    {
        *lat_reg[port] ^= PORT_MASK;
    }
    return ret;
}
#endif