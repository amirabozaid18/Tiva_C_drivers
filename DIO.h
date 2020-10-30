#ifndef DIO_H

#define DIO_H

#include "tm4c123gh6pm.h"
#include "stdint.h"

typedef enum direction_type { INPUT , OUTPUT } type;
typedef enum index_type { LOWER , UPPER } location;
typedef enum current_status {ENABLED, DISABLED} status;
typedef enum external_interrupt_sensitivity { EDGE, LEVEL} sensitivity;
typedef enum external_interrupt_edge_count { SINGLE, BOTH } count;
typedef enum external_interrupt_event { RISING, FALLING } EVENT;

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
void initialize_pin(char port_name, uint8_t pin_number , type pin_type);
void change_pin_direction (char port_name, uint8_t pin_number, type pin_type);
void set_pin_alternative_function(char port_name,uint8_t pin_number,uint8_t control_value);
void set_output_pin(char port_name, uint8_t pin_number);	
void clear_output_pin(char port_name, uint8_t pin_number);	
void toggle_output_pin(char port_name, uint8_t pin_number);		
uint8_t read_input_pin(char port_name, uint8_t pin_number);		
void trigger_external_interrupt(char port_name, uint8_t pin_number, sensitivity interrupt_sensitivity, count edge_count, EVENT interrupt_event, uint8_t interrupt_priority);



void delayMs(uint64_t n);
void delayUs(uint64_t n);
uint64_t power(uint32_t base, uint8_t exponent);


#endif
