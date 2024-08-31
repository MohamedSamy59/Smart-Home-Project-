/* 
 * File:   ecu_chr_lcd.c
 * Author: Mohamed Samy
 *
 * Created on May 2, 2024, 6:11 PM
 */

/*Include Interfaces Header File Section */
#include "ecu_chr_lcd.h"


/*Global Variable Definition Section*/



/*APIs Definition Section*/

static Std_ReturnType send_4bits_data_command(const mode_4_bits_t *lcd,uint8 data);
static Std_ReturnType send_8bits_data_command(const mode_8_bits_t *lcd,uint8 data);

static Std_ReturnType send_4bits_enable(const mode_4_bits_t *lcd);
static Std_ReturnType send_8bits_enable(const mode_8_bits_t *lcd);

static Std_ReturnType send_4bits_set_cursor(const mode_4_bits_t *lcd,uint8 row,uint8 column);
static Std_ReturnType send_8bits_set_cursor(const mode_8_bits_t *lcd,uint8 row,uint8 column);

Std_ReturnType ecu_lcd_4_bits_initialization(const mode_4_bits_t *lcd){
    Std_ReturnType ret = E_OK;
    uint8 counter = ZERO_INIT;
    if(NULL == lcd){
        ret = E_NOK;
    }
    else{
        ret = gpio_pin_direction_intialization(&(lcd->lcd_register_select));
        ret = gpio_pin_direction_intialization(&(lcd->lcd_enable_pin));
        for(counter = ZERO_INIT;counter<4;counter++){
         ret = gpio_pin_direction_intialization(&(lcd->lcd_data[counter]));

        }
        __delay_ms(20);
        ret = ecu_lcd_4_bits_send_command(lcd,LCD_8_BITS_MODE_2_LINE_5_8_MATRIX);
        __delay_ms(5);
        ret = ecu_lcd_4_bits_send_command(lcd,LCD_8_BITS_MODE_2_LINE_5_8_MATRIX);
        __delay_us(150);
        ret = ecu_lcd_4_bits_send_command(lcd,LCD_8_BITS_MODE_2_LINE_5_8_MATRIX);

        ret = ecu_lcd_4_bits_send_command(lcd,LCD_CLEAR_DISPLAY);
        ret = ecu_lcd_4_bits_send_command(lcd,LCD_RETURN_HOME);
        ret = ecu_lcd_4_bits_send_command(lcd,LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = ecu_lcd_4_bits_send_command(lcd,LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        ret = ecu_lcd_4_bits_send_command(lcd,LCD_DDRAM_START_ADDRESS);

        
        ret = ecu_lcd_4_bits_send_command(lcd,LCD_4_BITS_MODE_2_LINE_5_8_MATRIX);

    }
    return ret;
}


Std_ReturnType ecu_lcd_4_bits_send_command(const mode_4_bits_t *lcd,uint8 command){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOK;
    }
    else{
        ret=gpio_pin_write_logic(&(lcd->lcd_register_select),GPIO_LOW);
        ret = send_4bits_data_command(lcd,command>>4);
        ret=send_4bits_enable(lcd);
        ret = send_4bits_data_command(lcd,command);
        ret=send_4bits_enable(lcd);
    }
    return ret;
}


Std_ReturnType ecu_lcd_4_bits_send_char_data(const mode_4_bits_t *lcd,uint8 data){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOK;
    }
    else{
        ret=gpio_pin_write_logic(&(lcd->lcd_register_select),GPIO_HIGH);
        ret = send_4bits_data_command(lcd,data>>4);
        ret=send_4bits_enable(lcd);
        ret = send_4bits_data_command(lcd,data);
        ret=send_4bits_enable(lcd);
    }
    return ret;
}


Std_ReturnType ecu_lcd_4_bits_send_char_data_pos(const mode_4_bits_t *lcd,uint8 data,uint8 row,uint8 column){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOK;
    }
    else{
        ret = send_4bits_set_cursor(lcd,row,column);
        ret = ecu_lcd_4_bits_send_char_data(lcd,data);
    }
    return ret;
}


Std_ReturnType ecu_lcd_4_bits_send_string_data(const mode_4_bits_t *lcd,uint8 *str){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd || NULL == str){
        ret = E_NOK;
    }
    else{
        while(*(str)){
           ret = ecu_lcd_4_bits_send_char_data(lcd,*str++);
        }
       
    }
    return ret;
}


Std_ReturnType ecu_lcd_4_bits_send_string_data_pos(const mode_4_bits_t *lcd,uint8 *str,uint8 row,uint8 column){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd || NULL == str){
        ret = E_NOK;
    }
    else{
        ret = send_4bits_set_cursor(lcd,row,column);
        while(*(str)){
                 
                    ret = ecu_lcd_4_bits_send_char_data(lcd,*str++);
        }
       
    }
    return ret;
}


Std_ReturnType ecu_lcd_4_bits_send_custom_char_data_pos(const mode_4_bits_t *lcd,const uint8 cha[],uint8 row,uint8 column,uint8 cha_mem_pos){
    Std_ReturnType ret = E_OK;
    uint8 counter = ZERO_INIT;
    if(NULL == lcd ){
        ret = E_NOK;
    }
    else{
        ret=ecu_lcd_4_bits_send_command(lcd,(LCD_CGRAM_START_ADDRESS+cha_mem_pos*8));
        for(counter = ZERO_INIT;counter<8;counter++){
            ret = ecu_lcd_4_bits_send_char_data(lcd,cha[counter]);
        }
        
             ret=ecu_lcd_4_bits_send_char_data_pos(lcd,cha_mem_pos,row,column);

    }
    return ret;
}


Std_ReturnType ecu_lcd_8_bits_initialization(const mode_8_bits_t *lcd){
    Std_ReturnType ret = E_OK;
    uint8 counter = ZERO_INIT;
    if(NULL == lcd){
        ret = E_NOK;
    }
    else{
        ret = gpio_pin_direction_intialization(&(lcd->lcd_register_select));
        ret = gpio_pin_direction_intialization(&(lcd->lcd_enable_pin));
        for(counter = ZERO_INIT;counter<=7;counter++){
         ret = gpio_pin_direction_intialization(&(lcd->lcd_data[counter]));

        }
        __delay_ms(20);
        ret = ecu_lcd_8_bits_send_command(lcd,LCD_8_BITS_MODE_2_LINE_5_8_MATRIX);
        __delay_ms(5);
        ret = ecu_lcd_8_bits_send_command(lcd,LCD_8_BITS_MODE_2_LINE_5_8_MATRIX);
        __delay_us(150);
        ret = ecu_lcd_8_bits_send_command(lcd,LCD_8_BITS_MODE_2_LINE_5_8_MATRIX);

        ret = ecu_lcd_8_bits_send_command(lcd,LCD_CLEAR_DISPLAY);
        ret = ecu_lcd_8_bits_send_command(lcd,LCD_RETURN_HOME);
        ret = ecu_lcd_8_bits_send_command(lcd,LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = ecu_lcd_8_bits_send_command(lcd,LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        
        ret = ecu_lcd_8_bits_send_command(lcd,LCD_DDRAM_START_ADDRESS);
        

    }
    return ret;
}


Std_ReturnType ecu_lcd_8_bits_send_command(const mode_8_bits_t *lcd,uint8 command){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOK;
    }
    else{
        ret=gpio_pin_write_logic(&(lcd->lcd_register_select),GPIO_LOW);
 
        ret = send_8bits_data_command(lcd,command);
        ret=send_8bits_enable(lcd);
    }
    return ret;
}


Std_ReturnType ecu_lcd_8_bits_send_char_data(const mode_8_bits_t *lcd,uint8 data){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOK;
    }
    else{
        ret=gpio_pin_write_logic(&(lcd->lcd_register_select),GPIO_HIGH);

        ret = send_8bits_data_command(lcd,data);
        ret=send_8bits_enable(lcd);
    }
    return ret;
}



Std_ReturnType ecu_lcd_8_bits_send_char_data_pos(const mode_8_bits_t *lcd,uint8 data,uint8 row,uint8 column){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOK;
    }
    else{
        ret = send_8bits_set_cursor(lcd,row,column);
        ret = ecu_lcd_8_bits_send_char_data(lcd,data);
    }
    return ret;
}


Std_ReturnType ecu_lcd_8_bits_send_string_data(const mode_8_bits_t *lcd,uint8 *str){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd || NULL == str){
        ret = E_NOK;
    }
    else{
        while(*(str)){
           ret = ecu_lcd_8_bits_send_char_data(lcd,*str++);
        }
       
    }
    return ret;
}


Std_ReturnType ecu_lcd_8_bits_send_string_data_pos(const mode_8_bits_t *lcd,uint8 *str,uint8 row,uint8 column){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd || NULL == str){
        ret = E_NOK;
    }
    else{
              ret = send_8bits_set_cursor(lcd,row,column);

        while(*(str)){
        ret = ecu_lcd_8_bits_send_char_data(lcd,*str++);        }
       
    }
    return ret;
}


Std_ReturnType ecu_lcd_8_bits_send_custom_char_data_pos(const mode_8_bits_t *lcd,const uint8 cha[],uint8 row,uint8 column,uint8 cha_mem_pos){
    Std_ReturnType ret = E_OK;
    uint8 counter = ZERO_INIT;
    if(NULL == lcd ){
        ret = E_NOK;
    }
    else{
        ret=ecu_lcd_8_bits_send_command(lcd,(LCD_CGRAM_START_ADDRESS+cha_mem_pos*8));
        for(counter = ZERO_INIT;counter<8;counter++){
            ret = ecu_lcd_8_bits_send_char_data(lcd,cha[counter]);
        }

      ret=ecu_lcd_8_bits_send_char_data_pos(lcd,cha_mem_pos,row,column);
    }
    return ret;
}


Std_ReturnType ecu_lcd_conver_8_bits_to_string(uint8 *char_arr,uint8 value){
 Std_ReturnType ret = E_OK;
    if(NULL == char_arr){
        ret = E_NOK;
    }
    else{
        memset(char_arr,'\0',4);
        sprintf(char_arr,"%i",value);

    }
    return ret;
}

Std_ReturnType ecu_lcd_conver_16_bits_to_string(uint8 *char_arr,uint16 value){
 Std_ReturnType ret = E_OK;
    if(NULL == char_arr){
        ret = E_NOK;
    }
    else{
        memset(char_arr,' ',5);
        char_arr[5]='\0';
        sprintf(char_arr,"%i",value);
    
    }
    return ret;
}

Std_ReturnType ecu_lcd_conver_32_bits_to_string(uint8 *char_arr,uint32 value){
 Std_ReturnType ret = E_OK;
    if(NULL == char_arr){
        ret = E_NOK;
    }
    else{
        memset(char_arr,'\0',11);
        sprintf(char_arr,"%i",value);

    }
    return ret;
}


static Std_ReturnType send_4bits_data_command(const mode_4_bits_t *lcd,uint8 data){
    Std_ReturnType ret = E_OK;
   
            ret=gpio_pin_write_logic(&(lcd->lcd_data[0]),(data>>0)&(uint8)0x01);
            ret=gpio_pin_write_logic(&(lcd->lcd_data[1]),(data>>1)&(uint8)0x01);
            ret=gpio_pin_write_logic(&(lcd->lcd_data[2]),(data>>2)&(uint8)0x01);
            ret=gpio_pin_write_logic(&(lcd->lcd_data[3]),(data>>3)&(uint8)0x01);
            
    return ret;
}

static Std_ReturnType send_8bits_data_command(const mode_8_bits_t *lcd,uint8 data){
    Std_ReturnType ret = E_OK;
   
            ret=gpio_pin_write_logic(&(lcd->lcd_data[0]),(data>>0)&(uint8)0x01);
            ret=gpio_pin_write_logic(&(lcd->lcd_data[1]),(data>>1)&(uint8)0x01);
            ret=gpio_pin_write_logic(&(lcd->lcd_data[2]),(data>>2)&(uint8)0x01);
            ret=gpio_pin_write_logic(&(lcd->lcd_data[3]),(data>>3)&(uint8)0x01);
            ret=gpio_pin_write_logic(&(lcd->lcd_data[4]),(data>>4)&(uint8)0x01);
            ret=gpio_pin_write_logic(&(lcd->lcd_data[5]),(data>>5)&(uint8)0x01);
            ret=gpio_pin_write_logic(&(lcd->lcd_data[6]),(data>>6)&(uint8)0x01);
            ret=gpio_pin_write_logic(&(lcd->lcd_data[7]),(data>>7)&(uint8)0x01);
            
    return ret;
}

static Std_ReturnType send_4bits_enable(const mode_4_bits_t *lcd){
        Std_ReturnType ret = E_OK;
   
            ret=gpio_pin_write_logic(&(lcd->lcd_enable_pin),GPIO_HIGH);
            __delay_us(5);
            ret=gpio_pin_write_logic(&(lcd->lcd_enable_pin),GPIO_LOW);

            
    return ret;
}

static Std_ReturnType send_8bits_enable(const mode_8_bits_t *lcd){
        Std_ReturnType ret = E_OK;
   
            ret=gpio_pin_write_logic(&(lcd->lcd_enable_pin),GPIO_HIGH);
            __delay_us(5);
            ret=gpio_pin_write_logic(&(lcd->lcd_enable_pin),GPIO_LOW);

            
    return ret;
}


static Std_ReturnType send_4bits_set_cursor(const mode_4_bits_t *lcd,uint8 row,uint8 column){
        Std_ReturnType ret = E_OK;
        column--;
        switch(row){
            case ROW_1 : ecu_lcd_4_bits_send_command(lcd,(0x80+column));
            break;
            case ROW_2 : ecu_lcd_4_bits_send_command(lcd,(0xc0+column));
            break;
            case ROW_3 : ecu_lcd_4_bits_send_command(lcd,(0x94+column));
            break;
            case ROW_4 : ecu_lcd_4_bits_send_command(lcd,(0xd4+column));
            break;
            default:;
            
        }

            
    return ret;
}

static Std_ReturnType send_8bits_set_cursor(const mode_8_bits_t *lcd,uint8 row,uint8 column){
        Std_ReturnType ret = E_OK;
        column--;
        switch(row){
            case ROW_1 : ecu_lcd_8_bits_send_command(lcd,(0x80+column));
            break;
            case ROW_2 : ecu_lcd_8_bits_send_command(lcd,(0xc0+column));
            break;

            case ROW_3 : ecu_lcd_8_bits_send_command(lcd,(0x94+column));
            break;

            case ROW_4 : ecu_lcd_8_bits_send_command(lcd,(0xd4+column));
            break;
            default:;


        }

            
    return ret;
}