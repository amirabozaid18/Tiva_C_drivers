#ifndef KEYPAD_H
#define KEYPAD_H

#include "DIO.h"


void keypad_init_one_port(char port_name);
void keypad_init_two_half_ports( char row_half_port_name, location row_half_port_location, char column_half_port_name, location column_half_port_location);
uint8_t is_key_pressed(void);
char get_key_pressed(void);
uint8_t is_key_released(void);


#endif
