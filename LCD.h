#ifndef LCD_H
#define LCD_H

#include "DIO.h"
typedef enum LCD_mode	{ FOUR_BITS, EIGHT_BITS} mode;


void LCD_init(uint8_t lines_number, char data_port_name, char control_port_name, uint8_t rs_pin, uint8_t rw_pin, uint8_t e_pin, mode working_mode);
void LCD_command(uint8_t command);
void LCD_char(uint8_t mychar);
void LCD_display(char* mystring);




#endif
