#ifndef DIO_H

#define DIO_H

#include "tm4c123gh6pm.h"
#include "stdint.h"

typedef enum direction_type { INPUT , OUTPUT } type;
typedef enum index_type { LOWER , UPPER } location;

// for following functions, we deal with PORTC as it contains only bits 4-7 since bits 0-3 are used for JTAG pins

void initialize_port(char port_name, type port_type);
void set_output_port(char port_name, uint8_t port_value);
void set_half_port(char port_name, location half_port_location, uint8_t half_port_value);
void clear_output_port(char port_name);
void clear_half_port(char port_name, location half_port_location);
void update_port_except_last_pin(char port_name, uint8_t updated_value);
void update_port_except_last_two_pins(char port_name, uint8_t updated_value);
uint8_t is_whole_port_output(char port_name);
uint8_t is_whole_port_input(char port_name);
uint8_t read_input_port(char port_name);
void initialize_pin(char port_name, uint8_t pin_number , type pin_type); 					// this function is used if the port containing this pin is not initialized
void change_pin_direction (char port_name, uint8_t pin_number, type pin_type);		// this function must be used after initialize_port() only if port is defined as output and you want to define a pin it this port as input and vice versa
void set_output_pin(char port_name, uint8_t pin_number);		// this function must be used after change_pin_direction() only if this pin is in a port which was defined as input port, else you can call it directly after port initiallization
void clear_output_pin(char port_name, uint8_t pin_number);		// this function must be used after change_pin_direction() only if this pin is in a port which was defined as input port, else you can call it directly after port initiallization
void toggle_output_pin(char port_name, uint8_t pin_number);		// this function must be used after change_pin_direction() only if this pin is in a port which was defined as input port, else you can call it directly after port initiallization
uint8_t read_input_pin(char port_name, uint8_t pin_number);

void delayMs(int n);
void delayUs(int n);

#endif
