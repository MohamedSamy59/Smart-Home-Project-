///**
//  Generated Main Source File
//
//  Company:
//    Microchip Technology Inc.
//
//  File Name:
//    main.c
//
//  Summary:
//    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs
//
//  Description:
//    This header file provides implementations for driver APIs for all modules selected in the GUI.
//    Generation Information :
//        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
//        Device            :  PIC18F46K20
//        Driver Version    :  2.00
//*/
//
///*
//    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
//    
//    Subject to your compliance with these terms, you may use Microchip software and any 
//    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
//    license terms applicable to your use of third party software (including open source software) that 
//    may accompany Microchip software.
//    
//    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
//    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
//    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
//    FOR A PARTICULAR PURPOSE.
//    
//    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
//    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
//    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
//    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
//    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
//    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
//    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
//    SOFTWARE.
//*/
//
#include "main.h"
#include "mcc_generated_files/examples/i2c_master_example.h"
//
//
//
///*
//                         Main application
// */
//
/*I2C PART*/
mssp_i2c_t i2c_obj;
uint8 slave_ack;
uint8 master_rec_data;

void MSSP_I2C_Send_1_Byte(uint8 slave_add, uint8 _data){
    Std_ReturnType ret = E_NOK;
    ret = MSSP_I2C_Master_Send_Start(&i2c_obj);__delay_ms(185);
    ret = MSSP_I2C_Master_Write_Blocking(&i2c_obj, slave_add, &slave_ack);__delay_ms(185);
    ret = MSSP_I2C_Master_Write_Blocking(&i2c_obj, _data, &slave_ack);__delay_ms(185);
    ret = MSSP_I2C_Master_Send_Stop(&i2c_obj);__delay_ms(185);
}

void room_1(void);
void fire_check(void);
void check_password(void);
void room_2(void);
void garage(void);
 void home_page(void);

led_t led={.port = 2,.pin=0,.led_logic=0};

motor_t motor={.motor[0].direction=0,
               .motor[0].logic=0,
               .motor[0].pin=6,
               .motor[0].port=3,
               .motor[1].direction=0,
               .motor[1].logic=0,
               .motor[1].pin=7,
               .motor[1].port=3,

};
     mode_4_bits_t lcd={.lcd_enable_pin.direction=0,
                    .lcd_enable_pin.pin=GPIO_PIN0,
                    .lcd_enable_pin.port=3,
                    .lcd_enable_pin.logic=1,

                    .lcd_register_select.direction=0,
                    .lcd_register_select.logic=1,
                    .lcd_register_select.pin=GPIO_PIN1,
                    .lcd_register_select.port=3,

                        .lcd_data[0].pin=GPIO_PIN2,
                        .lcd_data[0].port=3,
                        .lcd_data[0].direction=0,
                        .lcd_data[0].logic=1,

                        .lcd_data[1].pin=GPIO_PIN3,
                        .lcd_data[1].port=3,
                        .lcd_data[1].direction=0,
                        .lcd_data[1].logic=1,
                        .lcd_data[2].pin=GPIO_PIN4,
                        .lcd_data[2].port=3,
                        .lcd_data[2].direction=0,
                        .lcd_data[2].logic=1,
                        .lcd_data[3].pin=GPIO_PIN5,
                        .lcd_data[3].port=3,
                        .lcd_data[3].direction=0,
                        .lcd_data[3].logic=1,

};



uint32 t_check=0;
uint8_t password[5];
char astrik[5];
uint8_t valid_password[5]={250,250,250,250,250};
uint8_t new_password[5];
uint8_t password_irritation;
uint8_t read_irritation;
uint8_t i;
uint8_t return_val;
uint8_t place;
adc_result_t device;
adc_result_t lm35_res_1_Celsius_mv;
uint8_t inter=0;
uint8_t arr_compare(uint8_t *arr1,uint8_t *arr2,uint8_t length);
 int main() {
//  
//{
//    // Initialize the device
     SYSTEM_Initialize();
     CLEAR_BIT(TRISB,5);
     i2c_obj.i2c_clock = 100000;
    i2c_obj.i2c_cfg.i2c_mode = I2C_MSSP_MASTER_MODE;
    i2c_obj.i2c_cfg.i2c_mode_cfg = I2C_MASTER_MODE_DEFINED_CLOCK;
    i2c_obj.i2c_cfg.i2c_SMBus_control = I2C_SMBus_DISABLE;
    i2c_obj.i2c_cfg.i2c_slew_rate = I2C_SLEW_RATE_DISABLE;

     MSSP_I2C_Init(&i2c_obj);
     
MSSP_I2C_Send_1_Byte(0x06, 'o');
__delay_ms(100);
//    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
//    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
//    // Use the following macros to:
//
//    // Enable the Global Interrupts
//    //INTERRUPT_GlobalInterruptEnable();
//
//    // Disable the Global Interrupts
//    //INTERRUPT_GlobalInterruptDisable();
//
//    // Enable the Peripheral Interrupts
//    //INTERRUPT_PeripheralInterruptEnable();
//
//    // Disable the Peripheral Interrupts
//    //INTERRUPT_PeripheralInterruptDisable();
//
//
ecu_lcd_4_bits_initialization(&lcd);
             ecu_lcd_4_bits_send_string_data_pos(&lcd,"Welcome..!",2,5);

    __delay_ms(1000);
         ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
         
/*Password Detection*/
         check_password();

/*========================================================*/
    
                       ecu_lcd_4_bits_send_string_data_pos(&lcd," Welcome Home..!",2,1);
                       __delay_ms(2000);
                       ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
                             home_page();



    while (1)
    {
      ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
      ecu_lcd_4_bits_send_string_data_pos(&lcd," 1-ROOM 1",1,1);
      ecu_lcd_4_bits_send_string_data_pos(&lcd," 2-ROOM 2",2,1);
      ecu_lcd_4_bits_send_string_data_pos(&lcd," 3-GARAGE",3,1);
      ecu_lcd_4_bits_send_string_data_pos(&lcd," 4-RETURN",4,1);
      place = EUSART_Read();
      switch(place){
          case 252 : 
                    ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
                    ecu_lcd_4_bits_send_string_data_pos(&lcd," Welcome to first room",1,1);
                    room_1();
                    break;
          case 253 : 
                    ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
                    ecu_lcd_4_bits_send_string_data_pos(&lcd," Welcome to second room",1,1);
                    room_2();
              break;
          case 254 :
                    ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
                    ecu_lcd_4_bits_send_string_data_pos(&lcd," Welcome to garage",1,1);
                    garage();
              break;
          
          case 255 :
              
                    home_page();
              
              break;
          default:
                    ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
                    ecu_lcd_4_bits_send_string_data_pos(&lcd," please Choose Correct Place",1,1);
      }
}
     

        // Add your application code
    
             return (EXIT_SUCCESS);

}

 void home_page(void){
     ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
     inter=0;
                     while(inter==0){
                         
                            ecu_lcd_4_bits_send_string_data_pos(&lcd," Choose : ",1,5);
                            ecu_lcd_4_bits_send_string_data_pos(&lcd,"1-Control Home",2,2);
                            ecu_lcd_4_bits_send_string_data_pos(&lcd,"2-Change Password : ",3,2);
                            inter =EUSART_Read();
                           if(inter == 252){
                                    break;
                           }
                           else if(inter==253){
                                    ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
                                    memset(astrik, ' ', 5);
//                                    ecu_lcd_4_bits_send_string_data_pos(&lcd,astrik,2,1);
                                    check_password();
                                    read_irritation=0;
                                    ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
                                    ecu_lcd_4_bits_send_string_data_pos(&lcd,"enter new password : ",1,1);
                                     memset(astrik, ' ',5);
//                                     ecu_lcd_4_bits_send_string_data_pos(&lcd,astrik,2,1);
                              for(read_irritation=0;read_irritation<5;read_irritation++){

                                    new_password[read_irritation] =EUSART_Read();
                                    astrik[read_irritation]='*';
                                    ecu_lcd_4_bits_send_char_data_pos(&lcd,'*',2,read_irritation+16);
                                
                               }
                                     
                              read_irritation=0;
                              ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
                              for(read_irritation=0;read_irritation<5;read_irritation++){
                                  valid_password[read_irritation]=new_password[read_irritation];
                               }
                                memset(astrik, ' ', 5);
//                                ecu_lcd_4_bits_send_string_data_pos(&lcd,astrik,2,1);
                                check_password();
                           }
                           else{}
                       }
                            
                            inter=0;
 }

uint8_t arr_compare(uint8_t *arr1,uint8_t *arr2,uint8_t length){
    if(NULL==arr1 || NULL==arr2){
        return 0;
    }
    else{
        for(uint8_t itiration =0;itiration<length;itiration++){
            if(arr1[itiration]!=arr2[itiration]){
                return 0;
            }
            else{}
        }
       return 1;
    }
}
       
void check_password(void){
        for(i=0;i<3;i++){
         ecu_lcd_4_bits_send_string_data_pos(&lcd," Enter password : ",1,1);
            read_irritation=0;
            char ma='*';
            for(read_irritation=0;read_irritation<5;read_irritation++){

                       password[read_irritation] =EUSART_Read();
                       astrik[read_irritation]='*';
                       
                       ecu_lcd_4_bits_send_char_data_pos(&lcd,'*',2,read_irritation+16);
//                       ecu_lcd_4_bits_send_string_data_pos(&lcd,' ',2,read_irritation+6);
            }
             

            return_val = arr_compare(password,valid_password,5);
                if(1==return_val){
                        ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
                        break;
                        }
                else{
                        password_irritation++;
                        ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
                        ecu_lcd_4_bits_send_string_data_pos(&lcd," Wrong password ! ",2,1);
                            __delay_ms(2500);
                            ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
                        if(password_irritation==3){
                            /*turn buzz on*/
                            ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
                           ecu_lcd_4_bits_send_string_data_pos(&lcd," Wait 10s to try!",2,1);

                            /*delay 10s*/
                            __delay_ms(10000);
                            ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
                            i=0;
                            /*trun buzz off*/
                        }

        }
       
    }
}
void room_1(void){
    uint8_t room=0;
    uint8_t stat=0;
    uint8_t door_status1=0;
    uint8_t door_status2=0;
    uint8_t temp_string[]={0};

          
    while (!room){
        
      ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
      ecu_lcd_4_bits_send_string_data_pos(&lcd," 1-Fan",1,1);
      ecu_lcd_4_bits_send_string_data_pos(&lcd," 2-led",2,1);
      ecu_lcd_4_bits_send_string_data_pos(&lcd," 3-read temperature",3,1);
      ecu_lcd_4_bits_send_string_data_pos(&lcd," 4-Door ",4,1);
      ecu_lcd_4_bits_send_string_data_pos(&lcd," 5-RETURN",4,8);
      place =EUSART_Read();
      
      switch(place){
          case 252 : 
              ecu_motor_initialization(&motor);
            while(!stat){
                fire_check();
                
              ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
              
              ecu_lcd_4_bits_send_string_data_pos(&lcd," 1-Fan_ON",1,1);
              ecu_lcd_4_bits_send_string_data_pos(&lcd," 2-Fan_OFF",2,1);
              ecu_lcd_4_bits_send_string_data_pos(&lcd," 3-RETURN",3,1);
              device=0;
              device =EUSART_Read(); 
              if(252==device){
                  ecu_motor_move_right(&motor);
              }
              else if(253==device){
                  ecu_motor_stop(&motor);
              }
              else if(254==device){
                  break;
              }
              else{}
            }
              break;
              
          case 253 : 
              ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
              ecu_led_initialization(&led);
            while(!stat){
              ecu_lcd_4_bits_send_string_data_pos(&lcd," 1-LED_ON",1,1);
              ecu_lcd_4_bits_send_string_data_pos(&lcd," 2-LED_OFF",2,1);
              ecu_lcd_4_bits_send_string_data_pos(&lcd," 3-RETURN",3,1);
              device=0;
              device =EUSART_Read(); 
              if(252==device){
                  ecu_led_on(&led);
              }
              else if(253==device){
                  ecu_led_off(&led);
              }
              else if(254==device){
                  break;
              }
              else{}
            }
              break;
          case 254 :
               device=0;
//                  __delay_ms(5);
                  ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
                  ecu_lcd_4_bits_send_string_data_pos(&lcd," Temperature : ",1,1);
                  device=ADC_GetConversion(0);
                    lm35_res_1_Celsius_mv = device * 4.88f;
                     lm35_res_1_Celsius_mv /= 620;
                  ecu_lcd_conver_16_bits_to_string(temp_string,lm35_res_1_Celsius_mv);
                  ecu_lcd_4_bits_send_string_data_pos(&lcd,temp_string,1,16);
                  __delay_ms(3000);

                  break;
          case 255 :
                    //CLEAR_BIT(TRISE,0);
                  ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);

            while(!stat){

                ecu_lcd_4_bits_send_string_data_pos(&lcd," 1-OPEN DOOR",1,1);
                  ecu_lcd_4_bits_send_string_data_pos(&lcd," 2-CLOSE DOOR",2,1);
                  ecu_lcd_4_bits_send_string_data_pos(&lcd," 3-RETURN",3,1);
                    device=0;
                    device =EUSART_Read(); 
                         CLEAR_BIT(TRISE,1);

                    if(252==device && 0==door_status1 ){
                        SET_BIT(LATE,1);
                        __delay_ms(.5);
                        CLEAR_BIT(LATE,1);
                       __delay_ms(1000);
                        door_status2=0;
                        door_status1++;
                   
                    }
                    else if(253==device && 0==door_status2){
                            SET_BIT(LATE,1);
                       __delay_ms(10.4999);
                       CLEAR_BIT(LATE,1);
                       __delay_ms(1000);
                         door_status2++;
                        door_status1=0;

                    }
                    else if(254==device){
                        break;
                    }
                    else{}
            }
              break;
              
             case 250 :
                 __delay_ms(5);
                 room=1;
              break;
          default:
                     ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
                    ecu_lcd_4_bits_send_string_data_pos(&lcd," please Choose Correct Device",1,1);
      }
    }  
}

void room_2(void){

    uint8_t room=0;
    uint8_t stat=0;
    uint8_t door_status1=0;
    uint8_t door_status2=0;
    uint8_t temp_string[]={0};

          
    while (!room){

        ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
      ecu_lcd_4_bits_send_string_data_pos(&lcd," 1-Fan",1,1);
      ecu_lcd_4_bits_send_string_data_pos(&lcd," 2-led",2,1);
      ecu_lcd_4_bits_send_string_data_pos(&lcd," 3-read temperature",3,1);
      ecu_lcd_4_bits_send_string_data_pos(&lcd," 4-Door ",4,1);
      ecu_lcd_4_bits_send_string_data_pos(&lcd," 5-RETURN",4,8);
      place =EUSART_Read();
      
      switch(place){
          case 252 : 
            while(!stat){ 
              ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
              
              ecu_lcd_4_bits_send_string_data_pos(&lcd," 1-Fan_ON",1,1);
              ecu_lcd_4_bits_send_string_data_pos(&lcd," 2-Fan_OFF",2,1);
              ecu_lcd_4_bits_send_string_data_pos(&lcd," 3-RETURN",3,1);
              device=0;
              device =EUSART_Read(); 
              if(252==device){
                  MSSP_I2C_Send_1_Byte(0x06, 'a');
                  __delay_ms(251);
              }
              else if(253==device){
                  MSSP_I2C_Send_1_Byte(0x06, 'b');
                  __delay_ms(251);
              }
              else if(254==device){
                  break;
              }
              else{}
            }
              break;
              
          case 253 : 
              ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
            while(!stat){
              ecu_lcd_4_bits_send_string_data_pos(&lcd," 1-LED_ON",1,1);
              ecu_lcd_4_bits_send_string_data_pos(&lcd," 2-LED_OFF",2,1);
              ecu_lcd_4_bits_send_string_data_pos(&lcd," 3-RETURN",3,1);
              device=0;
              device =EUSART_Read(); 
              if(252==device){
                  MSSP_I2C_Send_1_Byte(0x06, 'c');
                  __delay_ms(251);
                  
              }
              else if(253==device){
                  MSSP_I2C_Send_1_Byte(0x06, 'd');
                  __delay_ms(251);
                  
              }
              else if(254==device){
                  break;
              }
              else{}
            }
              break;
          case 254 :
               device=0;
//                  __delay_ms(5);
                  ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
                  
                  ecu_lcd_4_bits_send_string_data_pos(&lcd," Temperature : ",1,1);
                  device=ADC_GetConversion(1);
                    lm35_res_1_Celsius_mv = device * 4.88f;
                     lm35_res_1_Celsius_mv /= 620;
                  ecu_lcd_conver_16_bits_to_string(temp_string,lm35_res_1_Celsius_mv);
                  ecu_lcd_4_bits_send_string_data_pos(&lcd,temp_string,1,16);
                  __delay_ms(3000);
                  break;
          case 255 :
                    //CLEAR_BIT(TRISE,0);
                  ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);

            while(!stat){
                  ecu_lcd_4_bits_send_string_data_pos(&lcd," 1-OPEN DOOR",1,1);
                  ecu_lcd_4_bits_send_string_data_pos(&lcd," 2-CLOSE DOOR",2,1);
                  ecu_lcd_4_bits_send_string_data_pos(&lcd," 3-RETURN",3,1);
                    device=0;
                    device =EUSART_Read(); 
                         

                    if(252==device && 0==door_status1 ){
                        MSSP_I2C_Send_1_Byte(0x06, 'e');
//                        SET_BIT(LATE,1);
//                        __delay_ms(.5);
//                        CLEAR_BIT(LATE,1);
//                       __delay_ms(1000);
                        door_status2=0;
                        door_status1++;
                   
                    }
                    else if(253==device && 0==door_status2){
                        MSSP_I2C_Send_1_Byte(0x06, 'q');
//                            SET_BIT(LATE,1);
//                       __delay_ms(10.4999);
//                       CLEAR_BIT(LATE,1);
//                       __delay_ms(1000);
                         door_status2++;
                        door_status1=0;

                    }
                    else if(254==device){
                        break;
                    }
                    else{}
                    
            }
              break;
              
             case 250 :
                 __delay_ms(5);
                 room=1;
              break;
          default:
                    ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
                    ecu_lcd_4_bits_send_string_data_pos(&lcd," please Choose Correct Device",1,1);
      }
    }  

}
   
void garage(void){
     uint8_t room=0;
    uint8_t stat=0;
    uint8_t door_status1=0;
    uint8_t door_status2=0;
    uint8_t temp_string[]={0};

          
    while (!room){
      ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
      ecu_lcd_4_bits_send_string_data_pos(&lcd," 1-read temperature",1,1);
      ecu_lcd_4_bits_send_string_data_pos(&lcd," 2-Door ",2,1);
      ecu_lcd_4_bits_send_string_data_pos(&lcd," 3-RETURN",3,1);
      place =EUSART_Read();
                         

      switch(place){
          MSSP_I2C_Send_1_Byte(0x06, 'o');
          case 252 : 
                  device=0;
//                  __delay_ms(5);
                  ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
                  
                  ecu_lcd_4_bits_send_string_data_pos(&lcd," Temperature : ",1,1);
                  device=ADC_GetConversion(2);
                    lm35_res_1_Celsius_mv = device * 4.88f;
                     lm35_res_1_Celsius_mv /= 620;
                  ecu_lcd_conver_16_bits_to_string(temp_string,lm35_res_1_Celsius_mv);
                  ecu_lcd_4_bits_send_string_data_pos(&lcd,temp_string,1,16);
                  __delay_ms(3000);
                  break;
              break;
              
 

          case 253 :
                    //CLEAR_BIT(TRISE,0);
                  ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);

            while(!stat){
                  ecu_lcd_4_bits_send_string_data_pos(&lcd," 1-OPEN DOOR",1,1);
                  ecu_lcd_4_bits_send_string_data_pos(&lcd," 2-CLOSE DOOR",2,1);
                  ecu_lcd_4_bits_send_string_data_pos(&lcd," 3-RETURN",3,1);
                    device=0;
                    device =EUSART_Read(); 


                    if(252==device && 0==door_status1 ){
                        //MSSP_I2C_Send_1_Byte(0x06, 'h');
                        __delay_ms(251);
                        SET_BIT(LATB,5);
                        __delay_ms(.5);
                        CLEAR_BIT(LATB,5);
                       __delay_ms(1000);
                        
                        door_status2=0;
                        door_status1++;
                   
                    }
                    else if(253==device && 0==door_status2){
                        //MSSP_I2C_Send_1_Byte(0x06, 'i');
                        __delay_ms(251);
                            SET_BIT(LATB,5);
                       __delay_ms(10.4999);
                       CLEAR_BIT(LATB,5);
                       __delay_ms(1000);
                         door_status2++;
                        door_status1=0;

                    }
                    else if(254==device){
                        break;
                    }
                    else{}
            }
              break;
              
             case 250 :
                 __delay_ms(5);
                 room=1;
              break;
          default:
                    ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
                    ecu_lcd_4_bits_send_string_data_pos(&lcd," please Choose Correct Device",1,1);
      }
    }  

}


void fire_check(void){
    t_check=0;
    t_check = ADC_GetConversion(3);
//     t_check= t_check * 4.88f;
//     t_check/=5;
//     t_check=(t_check+.095)/.009f;
    if(24128<=t_check){
        MSSP_I2C_Send_1_Byte(0x06, 'm');
        __delay_ms(15);
        while(t_check>=24128){
        t_check = ADC_GetConversion(3);
        ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
        ecu_lcd_4_bits_send_string_data_pos(&lcd," FIRE................!",1,1);
        }
    }
    else {
        ecu_lcd_4_bits_send_command(&lcd,LCD_CLEAR_DISPLAY);
        MSSP_I2C_Send_1_Byte(0x06, 'l');
    }
}
