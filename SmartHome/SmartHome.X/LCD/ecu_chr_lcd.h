/* 
 * File:   ecu_chr_lcd.h
 * Author: Mohamed Samy
 *
 * Created on May 2, 2024, 6:11 PM
 */

#ifndef ECU_CHR_LCD_H
#define	ECU_CHR_LCD_H

/*Include Section*/
#include "ecu_chr_lcd_cfg.h"
#include "../GPIO_MODULES/hal_GPIO.h"

/*Macros Declarations Section*/




#define LCD_CLEAR_DISPLAY                               0X01
#define LCD_RETURN_HOME                                 0X02
#define LCD_ENTRY_MODE_DEC_SHIFT_OFF                    0X04
#define LCD_ENTRY_MODE_DEC_SHIFT_ON                     0X05
#define LCD_ENTRY_MODE_INC_SHIFT_OFF                    0X06
#define LCD_ENTRY_MODE_INC_SHIFT_ON                     0X07
#define LCD_MOVE_CUSOR_SHIFT_LEFT                       0X10
#define LCD_MOVE_CUSOR_SHIFT_RIGHT                      0X14
#define LCD_DISPLAY_SHIFT_LEFT                          0X18
#define LCD_DISPLAY_SHIFT_RIGHT                         0X1C
#define LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF         0X0C
#define LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON          0X0D
#define LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF          0X0E
#define LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON           0X0F
#define LCD_DISPLAY_OFF_CURSOR_OFF                      0X08
#define LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON          0X0D
#define LCD_8_BITS_MODE_2_LINE_5_8_MATRIX               0X38
#define LCD_4_BITS_MODE_2_LINE_5_8_MATRIX               0X28
#define LCD_CGRAM_START_ADDRESS                         0X40
#define LCD_DDRAM_START_ADDRESS                         0X80

#define ROW_1                                             1       
#define ROW_2                                             2       
#define ROW_3                                             3      
#define ROW_4                                             4       

/*Macros Function Declarations Section*/



/*Data Type Function Declarations Section*/
typedef struct{
    pin_config_t lcd_data[4];
    pin_config_t lcd_enable_pin;
    pin_config_t lcd_register_select;
}mode_4_bits_t;

typedef struct{
    pin_config_t lcd_data[8];
    pin_config_t lcd_enable_pin;
    pin_config_t lcd_register_select;
}mode_8_bits_t;

/*Function Declarations Section*/

Std_ReturnType ecu_lcd_4_bits_initialization(const mode_4_bits_t *lcd);
Std_ReturnType ecu_lcd_4_bits_send_command(const mode_4_bits_t *lcd,uint8 command);
Std_ReturnType ecu_lcd_4_bits_send_char_data(const mode_4_bits_t *lcd,uint8 data);
Std_ReturnType ecu_lcd_4_bits_send_char_data_pos(const mode_4_bits_t *lcd,uint8 data,uint8 row,uint8 column);
Std_ReturnType ecu_lcd_4_bits_send_string_data(const mode_4_bits_t *lcd,uint8 *str);
Std_ReturnType ecu_lcd_4_bits_send_string_data_pos(const mode_4_bits_t *lcd,uint8 *str,uint8 row,uint8 column);
Std_ReturnType ecu_lcd_4_bits_send_custom_char_data_pos(const mode_4_bits_t *lcd,const uint8 cha[],uint8 row,uint8 column,uint8 cha_mem_pos);


Std_ReturnType ecu_lcd_8_bits_initialization(const mode_8_bits_t *lcd);
Std_ReturnType ecu_lcd_8_bits_send_command(const mode_8_bits_t *lcd,uint8 command);
Std_ReturnType ecu_lcd_8_bits_send_char_data(const mode_8_bits_t *lcd,uint8 data);
Std_ReturnType ecu_lcd_8_bits_send_char_data_pos(const mode_8_bits_t *lcd,uint8 data,uint8 row,uint8 column);
Std_ReturnType ecu_lcd_8_bits_send_string_data(const mode_8_bits_t *lcd,uint8 *str);
Std_ReturnType ecu_lcd_8_bits_send_string_data_pos(const mode_8_bits_t *lcd,uint8 *str,uint8 row,uint8 column);
Std_ReturnType ecu_lcd_8_bits_send_custom_char_data_pos(const mode_8_bits_t *lcd,const uint8 cha[],uint8 row,uint8 column,uint8 cha_mem_pos);


Std_ReturnType ecu_lcd_conver_8_bits_to_string(uint8 *char_arr,uint8 value);
Std_ReturnType ecu_lcd_conver_16_bits_to_string(uint8 *char_arr,uint16 value);
Std_ReturnType ecu_lcd_conver_32_bits_to_string(uint8 *char_arr,uint32 value);
#endif	/* ECU_CHR_LCD_H */

