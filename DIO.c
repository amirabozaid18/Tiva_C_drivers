#include "DIO.h"


void initialize_port(char port_name, type port_type)
{
	
	if (port_name == 'A')
	{
		SYSCTL_RCGCGPIO_R |= (1<<0);			// connect clock to PORTA
		while ( (SYSCTL_PRGPIO_R & (1<<0) ) == 0);		// check if clock is connected to PORTA
		GPIO_PORTA_AFSEL_R = 0;						// all pins in PORTA are used as digital inputs/outputs
		GPIO_PORTA_AMSEL_R = 0;						// all pins in PORTA are used as digital inputs/outputs
		GPIO_PORTA_DEN_R	 = 0xFF;				// all pins in PORTA are used as digital inputs/outputs
		if (port_type == INPUT)
		{
			GPIO_PORTA_DIR_R = 0x00;				// all pins in PORTA are inputs
			GPIO_PORTA_PUR_R = 0xFF;				// pull-up resistors are enabled for all PORTA pins
		}
		else
			GPIO_PORTA_DIR_R = 0xFF;				// all pins in PORTA are outputs
		
	}
	
	else if (port_name == 'B')
	{
		SYSCTL_RCGCGPIO_R |= (1<<1);			// connect clock to PORTB
		while ( (SYSCTL_PRGPIO_R & (1<<1) ) == 0);		// check if clock is connected to PORTB
		GPIO_PORTB_AFSEL_R = 0;						// all pins in PORTB are used as digital inputs/outputs
		GPIO_PORTB_AMSEL_R = 0;						// all pins in PORTB are used as digital inputs/outputs
		GPIO_PORTB_DEN_R	 = 0xFF;				// all pins in PORTB are used as digital inputs/outputs
		if (port_type == INPUT)
		{
			GPIO_PORTB_DIR_R = 0x00;				// all pins in PORTB are inputs
			GPIO_PORTB_PUR_R = 0xFF;				// pull-up resistors are enabled for all PORTB pins
		}
		else
			GPIO_PORTB_DIR_R = 0xFF;				// all pins in PORTB are outputs
		
	}
	
	else if (port_name == 'C')					// this port is special because pins 0-3 are JTAG pins so we avoid them
	{
		SYSCTL_RCGCGPIO_R |= (1<<2);			// connect clock to PORTC
		while ( (SYSCTL_PRGPIO_R & (1<<2) ) == 0);		// check if clock is connected to PORTC
		GPIO_PORTC_AFSEL_R &= 0x0F;						// pins 4-7 in PORTC are used as digital inputs/outputs
		GPIO_PORTC_AMSEL_R &= 0x0F;						// pins 4-7 in PORTC are used as digital inputs/outputs
		GPIO_PORTC_DEN_R	 |= 0xF0;						// pins 4-7 in PORTC are used as digital inputs/outputs
		if (port_type == INPUT)
		{
			GPIO_PORTC_DIR_R &= 0x0F;				// pins 4-7 in PORTC are inputs
			GPIO_PORTC_PUR_R |= 0xF0;				// pull-up resistors are enabled for pins 4-7 in PORTC
		}
		else
			GPIO_PORTC_DIR_R |= 0xF0;				// pins 4-7 in PORTC are outputs
		
	}
	
	else if (port_name == 'D')
	{
		SYSCTL_RCGCGPIO_R |= (1<<3);			// connect clock to PORTD
		while ( (SYSCTL_PRGPIO_R & (1<<3) ) == 0);		// check if clock is connected to PORTD
		GPIO_PORTD_LOCK_R = 0x4C4F434B;		// unlocking commit register
		GPIO_PORTD_CR_R |= (1<<7);				// enable following registers to be modified
		GPIO_PORTD_AFSEL_R = 0;						// all pins in PORTD are used as digital inputs/outputs
		GPIO_PORTD_AMSEL_R = 0;						// all pins in PORTD are used as digital inputs/outputs
		GPIO_PORTD_DEN_R	 = 0xFF;				// all pins in PORTD are used as digital inputs/outputs
		if (port_type == INPUT)
		{
			GPIO_PORTD_DIR_R = 0x00;				// all pins in PORTD are inputs
			GPIO_PORTD_PUR_R = 0xFF;				// pull-up resistors are enabled for all PORTD pins
		}
		else
			GPIO_PORTD_DIR_R = 0xFF;				// all pins in PORTD are outputs
		
	}
	
	else if (port_name == 'E')
	{
		SYSCTL_RCGCGPIO_R |= (1<<4);			// connect clock to PORTE
		while ( (SYSCTL_PRGPIO_R & (1<<4) ) == 0);		// check if clock is connected to PORTE
		GPIO_PORTE_AFSEL_R = 0;						// all pins in PORTE are used as digital inputs/outputs
		GPIO_PORTE_AMSEL_R = 0;						// all pins in PORTE are used as digital inputs/outputs
		GPIO_PORTE_DEN_R	 = 0xFF;				// all pins in PORTE are used as digital inputs/outputs
		if (port_type == INPUT)
		{
			GPIO_PORTE_DIR_R = 0x00;				// all pins in PORTE are inputs
			GPIO_PORTE_PUR_R = 0xFF;				// pull-up resistors are enabled for all PORTE pins
		}
		else
			GPIO_PORTE_DIR_R = 0xFF;				// all pins in PORTE are outputs
		
	}
	
		else if (port_name == 'F')
	{
		SYSCTL_RCGCGPIO_R |= (1<<5);			// connect clock to PORTF
		while ( (SYSCTL_PRGPIO_R & (1<<5) ) == 0);		// check if clock is connected to PORTF
		GPIO_PORTF_LOCK_R = 0x4C4F434B;		// unlocking commit register
		GPIO_PORTF_CR_R |= (1<<0);				// enable following registers to be modified
		GPIO_PORTF_AFSEL_R = 0;						// all pins in PORTF are used as digital inputs/outputs
		GPIO_PORTF_AMSEL_R = 0;						// all pins in PORTF are used as digital inputs/outputs
		GPIO_PORTF_DEN_R	 = 0xFF;				// all pins in PORTF are used as digital inputs/outputs
		if (port_type == INPUT)
		{
			GPIO_PORTF_DIR_R = 0x00;				// all pins in PORTF are inputs
			GPIO_PORTF_PUR_R = 0xFF;				// pull-up resistors are enabled for all PORTF pins
		}
		else
			GPIO_PORTF_DIR_R = 0xFF;				// all pins in PORTF are outputs
		
	}
	
	if (port_type == OUTPUT)
		clear_output_port(port_name);
}

void set_output_port(char port_name,uint8_t port_value)		
{
	if (port_name == 'A')
		GPIO_PORTA_DATA_R = port_value;
	
	else if (port_name == 'B')
		GPIO_PORTB_DATA_R = port_value;
	
	else if (port_name == 'C')
		GPIO_PORTC_DATA_R = ( (GPIO_PORTC_DATA_R & (0x0F) ) | (port_value << 4) ); 					// because pins 0-3 in port C are JTAG pins
	
	else if (port_name == 'D')
		GPIO_PORTD_DATA_R = port_value;
	
	else if (port_name == 'E')
		GPIO_PORTE_DATA_R = port_value;
	
	else if (port_name == 'F')
		GPIO_PORTF_DATA_R = port_value;
}

void set_half_port(char port_name, location half_port_location, uint8_t half_port_value)		
{
	if (port_name == 'A')
	{
		if (half_port_location  == LOWER)
			GPIO_PORTA_DATA_R = ( GPIO_PORTA_DATA_R & 0xF0) | ( half_port_value & 0x0F);
		else		//UPPER
			GPIO_PORTA_DATA_R = ( GPIO_PORTA_DATA_R & 0x0F) | ( half_port_value << 4);
	}
		
	
	else if (port_name == 'B')
	{
		if (half_port_location  == LOWER)
			GPIO_PORTB_DATA_R = ( GPIO_PORTB_DATA_R & 0xF0) | ( half_port_value & 0x0F);
		else		//UPPER
			GPIO_PORTB_DATA_R = ( GPIO_PORTB_DATA_R & 0x0F) | ( half_port_value << 4);
	}
	
	else if (port_name == 'C')
	{
		/*if (half_port_location  == LOWER)														// forbidden since pins 0-3 are used for JTAG
			GPIO_PORTA_DATA_R = ( GPIO_PORTA_DATA_R & 0xF0) | ( half_port_value & 0x0F);*/
		if (half_port_location  == UPPER)	
			GPIO_PORTC_DATA_R = ( GPIO_PORTC_DATA_R & 0x0F) | ( half_port_value << 4);
	}
	
	else if (port_name == 'D')
	{
		if (half_port_location  == LOWER)
			GPIO_PORTD_DATA_R = ( GPIO_PORTD_DATA_R & 0xF0) | ( half_port_value & 0x0F);
		else		//UPPER
			GPIO_PORTD_DATA_R = ( GPIO_PORTD_DATA_R & 0x0F) | ( half_port_value << 4);
	}
	
	else if (port_name == 'E')
	{
		if (half_port_location  == LOWER)
			GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xF0) | ( half_port_value & 0x0F);
		else		//UPPER
			GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0x0F) | ( half_port_value << 4);
	}
	
	else if (port_name == 'F')
	{
		if (half_port_location  == LOWER)
			GPIO_PORTF_DATA_R = ( GPIO_PORTF_DATA_R & 0xF0) | ( half_port_value & 0x0F);
		else		//UPPER
			GPIO_PORTF_DATA_R = ( GPIO_PORTF_DATA_R & 0x0F) | ( half_port_value << 4);
	}
}


void clear_output_port(char port_name)
{
	if (port_name == 'A')
		GPIO_PORTA_DATA_R = 0;
	
	else if (port_name == 'B')
		GPIO_PORTB_DATA_R = 0;
	
	else if (port_name == 'C')
		GPIO_PORTC_DATA_R &= 0x0F;					// because pins 0-3 in port C are JTAG pins
	
	else if (port_name == 'D')
		GPIO_PORTD_DATA_R = 0;
	
	else if (port_name == 'E')
		GPIO_PORTE_DATA_R = 0;
	
	else if (port_name == 'F')
		GPIO_PORTF_DATA_R = 0;
}

void clear_half_port(char port_name, location half_port_location)
{
	if (port_name == 'A')
	{
		if ( half_port_location == LOWER)
			GPIO_PORTA_DATA_R &= 0xF0;
		else 			//UPPER
			GPIO_PORTA_DATA_R &= 0x0F;
	}
		
	
	else if (port_name == 'B')
	{
		if ( half_port_location == LOWER)
			GPIO_PORTB_DATA_R &= 0xF0;
		else 			//UPPER
			GPIO_PORTB_DATA_R &= 0x0F;
	}
	
	else if (port_name == 'C')
	{
		/*if ( half_port_location == LOWER)			// forbidden since pins 0-3 are used for JTAG
			GPIO_PORTA_DATA_R &= 0xF0;*/
		if ( half_port_location == UPPER)
			GPIO_PORTC_DATA_R &= 0x0F;
	}
	
	else if (port_name == 'D')
	{
		if ( half_port_location == LOWER)
			GPIO_PORTD_DATA_R &= 0xF0;
		else 			//UPPER
			GPIO_PORTD_DATA_R &= 0x0F;
	}
	
	else if (port_name == 'E')
	{
		if ( half_port_location == LOWER)
			GPIO_PORTE_DATA_R &= 0xF0;
		else 			//UPPER
			GPIO_PORTE_DATA_R &= 0x0F;
	}
	
	else if (port_name == 'F')
	{
		if ( half_port_location == LOWER)
			GPIO_PORTF_DATA_R &= 0xF0;
		else 			//UPPER
			GPIO_PORTF_DATA_R &= 0x0F;
	}
}

void update_port_except_last_pin(char port_name, uint8_t updated_value)
{
	if (port_name  == 'A')
		GPIO_PORTA_DATA_R		= (GPIO_PORTA_DATA_R & 0x80) | ( updated_value & 0x7F);
	
	else if (port_name  == 'B')
		GPIO_PORTB_DATA_R		= (GPIO_PORTB_DATA_R & 0x80) | ( updated_value & 0x7F);
	
	else if (port_name  == 'C')
		GPIO_PORTC_DATA_R		= (GPIO_PORTC_DATA_R & 0x8F) | ( updated_value & 0x70);		// since pins 0-3 are used for JTAG pins
	
	else if (port_name  == 'D')
		GPIO_PORTD_DATA_R		= (GPIO_PORTD_DATA_R & 0x80) | ( updated_value & 0x7F);
	
	else if (port_name  == 'E')
		GPIO_PORTE_DATA_R		= (GPIO_PORTE_DATA_R & 0x80) | ( updated_value & 0x7F);
	
	else if (port_name  == 'F')
		GPIO_PORTF_DATA_R		= (GPIO_PORTF_DATA_R & 0x80) | ( updated_value & 0x7F);
}


void update_port_except_last_two_pins(char port_name, uint8_t updated_value)
{
	if (port_name  == 'A')
		GPIO_PORTA_DATA_R		= (GPIO_PORTA_DATA_R & 0xC0) | ( updated_value & 0x3F);
	
	else if (port_name  == 'B')
		GPIO_PORTB_DATA_R		= (GPIO_PORTB_DATA_R & 0xC0) | ( updated_value & 0x3F);
	
	else if (port_name  == 'C')
		GPIO_PORTC_DATA_R		= (GPIO_PORTC_DATA_R & 0xCF) | ( updated_value & 0x30);		// since pins 0-3 are used for JTAG pins
	
	else if (port_name  == 'D')
		GPIO_PORTD_DATA_R		= (GPIO_PORTD_DATA_R & 0xC0) | ( updated_value & 0x3F);
	
	else if (port_name  == 'E')
		GPIO_PORTE_DATA_R		= (GPIO_PORTE_DATA_R & 0xC0) | ( updated_value & 0x3F);
	
	else if (port_name  == 'F')
		GPIO_PORTF_DATA_R		= (GPIO_PORTF_DATA_R & 0xC0) | ( updated_value & 0x3F);
}


uint8_t is_whole_port_output(char port_name)
{
	if (port_name == 'A')
		return ( (GPIO_PORTA_DIR_R & (0xFF) ) == 0xFF );
	
	else if (port_name == 'B')
		return ( (GPIO_PORTB_DIR_R & (0xFF) ) == 0xFF );
	
	else if (port_name == 'C')
		return ( (GPIO_PORTC_DIR_R & (0xF0) ) == 0xF0 );		// we check pins 4-7 only since pins 0-3 are JTAG pins
	
	else if (port_name == 'D')
		return ( (GPIO_PORTD_DIR_R & (0xFF) ) == 0xFF );
	
	else if (port_name == 'E')
		return ( (GPIO_PORTE_DIR_R & (0x3F) ) == 0x3F );		// because PORTE has only 6 bits
	
	else if (port_name == 'F')
		return ( (GPIO_PORTF_DIR_R & (0x1F) ) == 0x1F );		// because PORTF has only 5 bits
	
	
}

uint8_t is_whole_port_input(char port_name)				// we care about first 8 bits only since any register is 32 bits
{
	if (port_name == 'A')
		return ( ((GPIO_PORTA_DIR_R & (0xFF)) | (0x00) ) == 0x00 );
	
	else if (port_name == 'B')
		return ( ((GPIO_PORTB_DIR_R & (0xFF)) | (0x00) ) == 0x00 );
	
	else if (port_name == 'C')
		return ( ((GPIO_PORTC_DIR_R & (0xFF)) | (0x0F) ) == 0x0F );		// we check pins 4-7 only since pins 0-3 are JTAG pins
	
	else if (port_name == 'D')
		return ( ((GPIO_PORTD_DIR_R & (0xFF)) | (0x00) ) == 0x00 );
	
	else if (port_name == 'E')
		return ( ((GPIO_PORTE_DIR_R & (0xFF)) | (0xC0) ) == 0xC0 );		// because PORTE has only 6 bits
	
	else if (port_name == 'F')
		return ( ((GPIO_PORTF_DIR_R & (0xFF)) | (0xE0) ) == 0xE0 );		// because PORTF has only 5 bits
	
	
}
uint8_t read_input_port(char port_name)				// we care about first 8 bits only since any register is 32 bits
{
	if (port_name == 'A')
		return (GPIO_PORTA_DATA_R & 0xFF) ;	

	else if (port_name == 'B')
		return (GPIO_PORTB_DATA_R & 0xFF) ;
	
	else if (port_name == 'C')
		return (GPIO_PORTC_DATA_R & 0xF0) ;
	
	else if (port_name == 'D')
		return (GPIO_PORTD_DATA_R & 0xFF) ;
	
	else if (port_name == 'E')
		return (GPIO_PORTE_DATA_R & 0x3F) ;
	
	else if (port_name == 'F')
		return (GPIO_PORTF_DATA_R & 0x1F) ;
}


void initialize_pin(char port_name, uint8_t pin_number , type pin_type)					// this function is used if the port containing this pin is not initialized
{
	if (port_name == 'A')
	{
		SYSCTL_RCGCGPIO_R |= (1<<0);												// connect clock to the port containint this pin
		while ( (SYSCTL_PRGPIO_R & (1<<0) ) == 0);					// check if clock is connected to the port containint this pin
		GPIO_PORTA_AFSEL_R &= ~(1 << pin_number);						// this pin is  used as digital input/output
		GPIO_PORTA_AMSEL_R &= ~(1 << pin_number);						// this pin is  used as digital input/output
		GPIO_PORTA_DEN_R	 |= (1 << pin_number);						// this pin is used as digital input/output
		if (pin_type == INPUT)
		{
			GPIO_PORTA_DIR_R &= ~(1 << pin_number);						// the pin direction is input
			GPIO_PORTA_PUR_R |= (1 << pin_number);						// pull-up resistor is enabled for this pin
		}
		else
			GPIO_PORTA_DIR_R |= (1 << pin_number);						// the pin direction is output
	}
	
	else if (port_name == 'B')
	{
		SYSCTL_RCGCGPIO_R |= (1<<1);												// connect clock to the port containint this pin
		while ( (SYSCTL_PRGPIO_R & (1<<1) ) == 0);					// check if clock is connected to the port containint this pin
		GPIO_PORTB_AFSEL_R &= ~(1 << pin_number);						// this pin is  used as digital input/output
		GPIO_PORTB_AMSEL_R &= ~(1 << pin_number);						// this pin is  used as digital input/output
		GPIO_PORTB_DEN_R	 |= (1 << pin_number);						// this pin is used as digital input/output
		if (pin_type == INPUT)
		{
			GPIO_PORTB_DIR_R &= ~(1 << pin_number);						// the pin direction is input
			GPIO_PORTB_PUR_R |= (1 << pin_number);						// pull-up resistor is enabled for this pin
		}
		else
			GPIO_PORTB_DIR_R |= (1 << pin_number);						// the pin direction is output
	}
	
	else if (port_name == 'C')
	{
		SYSCTL_RCGCGPIO_R |= (1<<2);												// connect clock to the port containint this pin
		while ( (SYSCTL_PRGPIO_R & (1<<2) ) == 0);					// check if clock is connected to the port containint this pin
		GPIO_PORTC_AFSEL_R &= ~(1 << pin_number);						// this pin is  used as digital input/output
		GPIO_PORTC_AMSEL_R &= ~(1 << pin_number);						// this pin is  used as digital input/output
		GPIO_PORTC_DEN_R	 |= (1 << pin_number);						// this pin is used as digital input/output
		if (pin_type == INPUT)
		{
			GPIO_PORTC_DIR_R &= ~(1 << pin_number);						// the pin direction is input
			GPIO_PORTC_PUR_R |= (1 << pin_number);						// pull-up resistor is enabled for this pin
		}
		else
			GPIO_PORTC_DIR_R |= (1 << pin_number);						// the pin direction is output
	}
	
	else if (port_name == 'D')
	{
		SYSCTL_RCGCGPIO_R |= (1<<3);												// connect clock to the port containint this pin
		while ( (SYSCTL_PRGPIO_R & (1<<3) ) == 0);					// check if clock is connected to the port containint this pin
		if (pin_number == 7)
		{
			GPIO_PORTD_LOCK_R = 0x4C4F434B;		// unlocking commit register
			GPIO_PORTD_CR_R |= (1<<7);				// enable following registers to be modified
		}
		GPIO_PORTD_AFSEL_R &= ~(1 << pin_number);						// this pin is  used as digital input/output
		GPIO_PORTD_AMSEL_R &= ~(1 << pin_number);						// this pin is  used as digital input/output
		GPIO_PORTD_DEN_R	 |= (1 << pin_number);						// this pin is used as digital input/output
		if (pin_type == INPUT)
		{
			GPIO_PORTD_DIR_R &= ~(1 << pin_number);						// the pin direction is input
			GPIO_PORTD_PUR_R |= (1 << pin_number);						// pull-up resistor is enabled for this pin
		}
		else
			GPIO_PORTD_DIR_R |= (1 << pin_number);						// the pin direction is output
	}
	
	else if (port_name == 'E')
	{
		SYSCTL_RCGCGPIO_R |= (1<<4);												// connect clock to the port containint this pin
		while ( (SYSCTL_PRGPIO_R & (1<<4) ) == 0);					// check if clock is connected to the port containint this pin
		GPIO_PORTE_AFSEL_R &= ~(1 << pin_number);						// this pin is  used as digital input/output
		GPIO_PORTE_AMSEL_R &= ~(1 << pin_number);						// this pin is  used as digital input/output
		GPIO_PORTE_DEN_R	 |= (1 << pin_number);						// this pin is used as digital input/output
		if (pin_type == INPUT)
		{
			GPIO_PORTE_DIR_R &= ~(1 << pin_number);						// the pin direction is input
			GPIO_PORTE_PUR_R |= (1 << pin_number);						// pull-up resistor is enabled for this pin
		}
		else
			GPIO_PORTE_DIR_R |= (1 << pin_number);						// the pin direction is output
	}
	
	else if (port_name == 'F')
	{
		SYSCTL_RCGCGPIO_R |= (1<<5);												// connect clock to the port containint this pin
		while ( (SYSCTL_PRGPIO_R & (1<<5) ) == 0);					// check if clock is connected to the port containint this pin
		if (pin_number == 0)
		{
			GPIO_PORTF_LOCK_R = 0x4C4F434B;		// unlocking commit register
			GPIO_PORTF_CR_R |= (1<<0);				// enable following registers to be modified
		}
		GPIO_PORTF_AFSEL_R &= ~(1 << pin_number);						// this pin is  used as digital input/output
		GPIO_PORTF_AMSEL_R &= ~(1 << pin_number);						// this pin is  used as digital input/output
		GPIO_PORTF_DEN_R	 |= (1 << pin_number);						// this pin is used as digital input/output
		if (pin_type == INPUT)
		{
			GPIO_PORTF_DIR_R &= ~(1 << pin_number);						// the pin direction is input
			GPIO_PORTF_PUR_R |= (1 << pin_number);						// pull-up resistor is enabled for this pin
		}
		else
			GPIO_PORTF_DIR_R |= (1 << pin_number);						// the pin direction is output
	}
	
	
	if (pin_type == OUTPUT)
		clear_output_pin(port_name,pin_number);
}


void change_pin_direction (char port_name, uint8_t pin_number, type pin_type)			// this function must be used after initialize_port() only if port is defined as output and you want to define a pin it this port as input and vice versa
{
	if ( port_name == 'A' )
	{
			if ( pin_type == INPUT )
			{
				GPIO_PORTA_PUR_R |= (1<< pin_number);
				GPIO_PORTA_DIR_R &= ~(1<<pin_number);
			}
			else			//output
			{
				GPIO_PORTA_PUR_R &= ~(1<< pin_number);
				GPIO_PORTA_DIR_R |= (1<<pin_number);
			}
				
	}
	
	else if ( port_name == 'B' )
	{
			if ( pin_type == INPUT )
			{
				GPIO_PORTB_PUR_R |= (1<< pin_number);
				GPIO_PORTB_DIR_R &= ~(1<<pin_number);
			}
			else			//output
			{
				GPIO_PORTB_PUR_R &= ~(1<< pin_number);
				GPIO_PORTB_DIR_R |= (1<<pin_number);
			}
				
	}
	
		else if ( port_name == 'C' )
	{
			if ( pin_type == INPUT )
			{
				GPIO_PORTC_PUR_R |= (1<< pin_number);
				GPIO_PORTC_DIR_R &= ~(1<<pin_number);
			}
			else				//output
			{
				GPIO_PORTC_PUR_R &= ~(1<< pin_number);
				GPIO_PORTC_DIR_R |= (1<<pin_number);
			}
				
	}
	
		else if ( port_name == 'D' )
	{
			if ( pin_type == INPUT )
			{
				GPIO_PORTD_PUR_R |= (1<< pin_number);
				GPIO_PORTD_DIR_R &= ~(1<<pin_number);
			}
			else				//output
			{
				GPIO_PORTD_PUR_R &= ~(1<< pin_number);
				GPIO_PORTD_DIR_R |= (1<<pin_number);
			}
				
	}
	
		else if ( port_name == 'E' )
	{
			if ( pin_type == INPUT )
			{
				GPIO_PORTE_PUR_R |= (1<< pin_number);
				GPIO_PORTE_DIR_R &= ~(1<<pin_number);
			}
			else			//output
			{
				GPIO_PORTE_PUR_R &= ~(1<< pin_number);
				GPIO_PORTE_DIR_R |= (1<<pin_number);
			}
				
	}
	
		else if ( port_name == 'F' )
	{
			if ( pin_type == INPUT )
			{
				GPIO_PORTF_PUR_R |= (1<< pin_number);
				GPIO_PORTF_DIR_R &= ~(1<<pin_number);
			}
			else				//output
			{
				GPIO_PORTF_PUR_R &= ~(1<< pin_number);
				GPIO_PORTF_DIR_R |= (1<<pin_number);
			}
				
	}
	
	if (pin_type == OUTPUT)
		clear_output_pin(port_name,pin_number);
	
}

void set_output_pin(char port_name, uint8_t pin_number)		// this function must be used after change_pin_direction() only if this pin is in a port which was defined as input port, else you can call it directly after port initiallization
{
	if (port_name == 'A')
		GPIO_PORTA_DATA_R |= (1<<pin_number);
	
	else if (port_name == 'B')
		GPIO_PORTB_DATA_R |= (1<<pin_number);
	
	else if (port_name == 'C')
		GPIO_PORTC_DATA_R |= (1<<pin_number);
	
	else if (port_name == 'D')
		GPIO_PORTD_DATA_R |= (1<<pin_number);
	
	else if (port_name == 'E')
		GPIO_PORTE_DATA_R |= (1<<pin_number);
	
	else if (port_name == 'F')
		GPIO_PORTF_DATA_R |= (1<<pin_number);
}


void clear_output_pin(char port_name, uint8_t pin_number)		// this function must be used after change_pin_direction() only if this pin is in a port which was defined as input port, else you can call it directly after port initiallization
{
	if (port_name == 'A')
		GPIO_PORTA_DATA_R &= ~(1<<pin_number);
	
	else if (port_name == 'B')
		GPIO_PORTB_DATA_R &= ~(1<<pin_number);
	
	else if (port_name == 'C')
		GPIO_PORTC_DATA_R &= ~(1<<pin_number);
	
	else if (port_name == 'D')
		GPIO_PORTD_DATA_R &= ~(1<<pin_number);
	
	else if (port_name == 'E')
		GPIO_PORTE_DATA_R &= ~(1<<pin_number);
	
	else if (port_name == 'F')
		GPIO_PORTF_DATA_R &= ~(1<<pin_number);
}

void toggle_output_pin(char port_name, uint8_t pin_number)		// this function must be used after change_pin_direction() only if this pin is in a port which was defined as input port, else you can call it directly after port initiallization
{
	if (port_name == 'A')
		GPIO_PORTA_DATA_R ^= (1<<pin_number);
	
	else if (port_name == 'B')
		GPIO_PORTB_DATA_R ^= (1<<pin_number);
	
	else if (port_name == 'C')
		GPIO_PORTC_DATA_R ^= (1<<pin_number);
	
	else if (port_name == 'D')
		GPIO_PORTD_DATA_R ^= (1<<pin_number);
	
	else if (port_name == 'E')
		GPIO_PORTE_DATA_R ^= (1<<pin_number);
	
	else if (port_name == 'F')
		GPIO_PORTF_DATA_R ^= (1<<pin_number);
}
	

uint8_t read_input_pin(char port_name, uint8_t pin_number)
{
	if (port_name == 'A' )
		return ( ( GPIO_PORTA_DATA_R & (1<<pin_number) ) == (1<<pin_number) );
			
	else if (port_name == 'B' )
		return ( ( GPIO_PORTB_DATA_R & (1<<pin_number) ) == (1<<pin_number) );
	
	else if (port_name == 'C' )
		return ( ( GPIO_PORTC_DATA_R & (1<<pin_number) ) == (1<<pin_number) );
	
	else if (port_name == 'D' )
		return ( ( GPIO_PORTD_DATA_R & (1<<pin_number) ) == (1<<pin_number) );
	
	else if (port_name == 'E' )
		return ( ( GPIO_PORTE_DATA_R & (1<<pin_number) ) == (1<<pin_number) );
	
	else if (port_name == 'F' )
		return ( ( GPIO_PORTF_DATA_R & (1<<pin_number) ) == (1<<pin_number) );
}

void delayMs(int n)
{
int i, j;
for(i = 0 ; i < n; i++)
	for(j = 0; j < 3180; j++);

}

void delayUs(int n)
{
int i, j;
for(i = 0 ; i < n; i++)
	for(j = 0; j < 3; j++);

}
