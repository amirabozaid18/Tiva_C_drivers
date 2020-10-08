#include "SSD.h"

uint8_t DOT_ENABLED;
char DATA_PORT_NAME;
SSD_type   CONFIGURATION;

void SSD_init(char data_port_name,char control_port_name, uint8_t control_pin, status dot_status, SSD_type  configuration)		
{
	CONFIGURATION = configuration;
	DATA_PORT_NAME	= data_port_name;
	
	if (configuration == COMMON_CATHODE)
	{
		if (dot_status == ENABLED)
		{
			initialize_port(data_port_name,OUTPUT);
			DOT_ENABLED	= 1;
		}
		else	//DISABLED  (we will not initialize pin 7 since it's not used for SSD)
		{
			initialize_pin(data_port_name, 0, OUTPUT);
			initialize_pin(data_port_name, 1, OUTPUT);
			initialize_pin(data_port_name, 2, OUTPUT);
			initialize_pin(data_port_name, 3, OUTPUT);
			initialize_pin(data_port_name, 4, OUTPUT);
			initialize_pin(data_port_name, 5, OUTPUT);
			initialize_pin(data_port_name, 6, OUTPUT);
			DOT_ENABLED = 0;
		}
			
		initialize_pin(control_port_name, control_pin, OUTPUT);
		clear_output_pin(control_port_name,control_pin);
	}
	
	
	else // COMMON ANODE
	{
		if (dot_status == ENABLED)
		{
			initialize_port(data_port_name,OUTPUT);
			set_output_port(data_port_name,0xFF);
			DOT_ENABLED	= 1;
		}
		else	//DISABLED  (we will not initialize pin 7 since it's not used for SSD)
		{
			initialize_pin(data_port_name, 0, OUTPUT);
			set_output_pin(data_port_name,0);
			initialize_pin(data_port_name, 1, OUTPUT);
			set_output_pin(data_port_name,1);
			initialize_pin(data_port_name, 2, OUTPUT);
			set_output_pin(data_port_name,2);
			initialize_pin(data_port_name, 3, OUTPUT);
			set_output_pin(data_port_name,3);
			initialize_pin(data_port_name, 4, OUTPUT);
			set_output_pin(data_port_name,4);
			initialize_pin(data_port_name, 5, OUTPUT);
			set_output_pin(data_port_name,5);
			initialize_pin(data_port_name, 6, OUTPUT);
			set_output_pin(data_port_name,6);
			DOT_ENABLED = 0;
		}
			
		initialize_pin(control_port_name, control_pin, OUTPUT);
		set_output_pin(control_port_name,control_pin);
	}
	
	
}

void SSD_show(char myinput)
{
	if (CONFIGURATION  == COMMON_CATHODE)
	{
			if (DOT_ENABLED)
		{
			switch (myinput)
			{
				case '0': set_output_port(DATA_PORT_NAME,0xBF); break;
				case '1': set_output_port(DATA_PORT_NAME,0x86); break;
				case '2': set_output_port(DATA_PORT_NAME,0xDB); break;
				case '3': set_output_port(DATA_PORT_NAME,0xCF); break;
				case '4': set_output_port(DATA_PORT_NAME,0xE6); break;
				case '5': set_output_port(DATA_PORT_NAME,0xED); break;
				case '6': set_output_port(DATA_PORT_NAME,0xFC); break;
				case '7': set_output_port(DATA_PORT_NAME,0x87); break;
				case '8': set_output_port(DATA_PORT_NAME,0xFF); break;
				case '9': set_output_port(DATA_PORT_NAME,0xE7); break;
				case 'A': set_output_port(DATA_PORT_NAME,0xF7); break;
				case 'B': set_output_port(DATA_PORT_NAME,0xFC); break;
				case 'C': set_output_port(DATA_PORT_NAME,0xB9); break;
				case 'D': set_output_port(DATA_PORT_NAME,0xDE); break;
				case 'E': set_output_port(DATA_PORT_NAME,0xF9); break;
				case 'F': set_output_port(DATA_PORT_NAME,0xF1); break;
				default : set_output_port(DATA_PORT_NAME,0x8F); break;
			}
		}
		
		else			// dot disabled
		{
			switch (myinput)
			{
				case '0': update_port_except_last_pin(DATA_PORT_NAME,0x3F); break; 
				case '1': update_port_except_last_pin(DATA_PORT_NAME,0x06); break;
				case '2': update_port_except_last_pin(DATA_PORT_NAME,0x5B); break;
				case '3': update_port_except_last_pin(DATA_PORT_NAME,0x4F); break;
				case '4': update_port_except_last_pin(DATA_PORT_NAME,0x66); break;
				case '5': update_port_except_last_pin(DATA_PORT_NAME,0x6D); break;
				case '6': update_port_except_last_pin(DATA_PORT_NAME,0x7C); break;
				case '7': update_port_except_last_pin(DATA_PORT_NAME,0x07); break;
				case '8': update_port_except_last_pin(DATA_PORT_NAME,0x7F); break;
				case '9': update_port_except_last_pin(DATA_PORT_NAME,0x67); break;
				case 'A': update_port_except_last_pin(DATA_PORT_NAME,0x77); break;
				case 'B': update_port_except_last_pin(DATA_PORT_NAME,0x7C); break;
				case 'C': update_port_except_last_pin(DATA_PORT_NAME,0x39); break;
				case 'D': update_port_except_last_pin(DATA_PORT_NAME,0x5E); break;
				case 'E': update_port_except_last_pin(DATA_PORT_NAME,0x79); break;
				case 'F': update_port_except_last_pin(DATA_PORT_NAME,0x71); break;
				default : update_port_except_last_pin(DATA_PORT_NAME,0x0F); break;
			}
		}
	}
	
	
	else if (CONFIGURATION  == COMMON_ANODE)
	{
			if (DOT_ENABLED)
		{
			switch (myinput)
			{
				case '0': set_output_port(DATA_PORT_NAME,0x40); break;
				case '1': set_output_port(DATA_PORT_NAME,0x79); break;
				case '2': set_output_port(DATA_PORT_NAME,0x24); break;
				case '3': set_output_port(DATA_PORT_NAME,0x30); break;
				case '4': set_output_port(DATA_PORT_NAME,0x19); break;
				case '5': set_output_port(DATA_PORT_NAME,0x12); break;
				case '6': set_output_port(DATA_PORT_NAME,0x03); break;
				case '7': set_output_port(DATA_PORT_NAME,0x78); break;
				case '8': set_output_port(DATA_PORT_NAME,0x00); break;
				case '9': set_output_port(DATA_PORT_NAME,0x18); break;
				case 'A': set_output_port(DATA_PORT_NAME,0x08); break;
				case 'B': set_output_port(DATA_PORT_NAME,0x03); break;
				case 'C': set_output_port(DATA_PORT_NAME,0x46); break;
				case 'D': set_output_port(DATA_PORT_NAME,0x21); break;
				case 'E': set_output_port(DATA_PORT_NAME,0x06); break;
				case 'F': set_output_port(DATA_PORT_NAME,0x0E); break;
				default : set_output_port(DATA_PORT_NAME,0x70); break;
			}
		}
		
		else			// dot disabled
		{
			switch (myinput)
			{
				case '0': update_port_except_last_pin(DATA_PORT_NAME,0xC0); break;
				case '1': update_port_except_last_pin(DATA_PORT_NAME,0xF9); break;
				case '2': update_port_except_last_pin(DATA_PORT_NAME,0xA4); break;
				case '3': update_port_except_last_pin(DATA_PORT_NAME,0xB0); break;
				case '4': update_port_except_last_pin(DATA_PORT_NAME,0x99); break;
				case '5': update_port_except_last_pin(DATA_PORT_NAME,0x92); break;
				case '6': update_port_except_last_pin(DATA_PORT_NAME,0x83); break;
				case '7': update_port_except_last_pin(DATA_PORT_NAME,0xF8); break;
				case '8': update_port_except_last_pin(DATA_PORT_NAME,0x80); break;
				case '9': update_port_except_last_pin(DATA_PORT_NAME,0x98); break;
				case 'A': update_port_except_last_pin(DATA_PORT_NAME,0x88); break;
				case 'B': update_port_except_last_pin(DATA_PORT_NAME,0x83); break;
				case 'C': update_port_except_last_pin(DATA_PORT_NAME,0xC6); break;
				case 'D': update_port_except_last_pin(DATA_PORT_NAME,0xA1); break;
				case 'E': update_port_except_last_pin(DATA_PORT_NAME,0x86); break;
				case 'F': update_port_except_last_pin(DATA_PORT_NAME,0x8E); break;
				default : update_port_except_last_pin(DATA_PORT_NAME,0xF0); break;
			}
		}
	}
	
	
}


void turn_SSD_on(char control_port_name, uint8_t control_pin)
{
	if (CONFIGURATION == COMMON_CATHODE)
	{
		if (DOT_ENABLED)
				clear_output_port(DATA_PORT_NAME);
		
		else		// dot disabled
		{
			clear_output_pin(DATA_PORT_NAME,0);
			clear_output_pin(DATA_PORT_NAME,1);
			clear_output_pin(DATA_PORT_NAME,2);
			clear_output_pin(DATA_PORT_NAME,3);
			clear_output_pin(DATA_PORT_NAME,4);
			clear_output_pin(DATA_PORT_NAME,5);
			clear_output_pin(DATA_PORT_NAME,6);
		}
		
		clear_output_pin(control_port_name, control_pin);
	}
	
	
	else if (CONFIGURATION == COMMON_ANODE)
	{
		if (DOT_ENABLED)
				set_output_port(DATA_PORT_NAME,0xFF);
		
		else		// dot disabled
		{
			set_output_pin(DATA_PORT_NAME,0);
			set_output_pin(DATA_PORT_NAME,1);
			set_output_pin(DATA_PORT_NAME,2);
			set_output_pin(DATA_PORT_NAME,3);
			set_output_pin(DATA_PORT_NAME,4);
			set_output_pin(DATA_PORT_NAME,5);
			set_output_pin(DATA_PORT_NAME,6);
		}
		
		set_output_pin(control_port_name, control_pin);
	}
	
	
}


void turn_SSD_off(char control_port_name, uint8_t control_pin)
{
	if (CONFIGURATION == COMMON_CATHODE)
	{
		set_output_pin(control_port_name, control_pin);
	}
	
	
	else if (CONFIGURATION == COMMON_ANODE)
	{
		
		clear_output_pin(control_port_name, control_pin);
	}
	
	
}
