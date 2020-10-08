#ifndef  SSD_H
#define SSD_H

#include	"DIO.h"

typedef	enum	pin_status	{ENABLED, DISABLED}	status;
typedef	enum  configuration_type	{ COMMON_ANODE, COMMON_CATHODE}  SSD_type;

void SSD_init(char data_port_name,char control_port_name, uint8_t control_pin, status dot_status, SSD_type  configuration);		// pins are ordered as A-B-C-D-E-F-G-DOT(if enabled) and map to pin0-pin6(if DOT is disabled) or pin0-pin7((if DOT is enabled)) respectively 
void SSD_show(char myinput);
void turn_SSD_on(char control_port_name, uint8_t control_pin);
void turn_SSD_off(char control_port_name, uint8_t control_pin);




#endif