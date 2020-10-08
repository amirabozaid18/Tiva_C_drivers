#include "LCD.h"

uint8_t LINES_NUMBER, RS_PIN,	RW_PIN, E_PIN	;
char DATA_PORT_DATA_R;
char CONTROL_PORT_DATA_R;
mode WORKING_MODE;

void LCD_init(uint8_t lines_number, char data_port_name, char control_port_name, uint8_t rs_pin, uint8_t rw_pin, uint8_t e_pin, mode working_mode)
{
	DATA_PORT_DATA_R	= data_port_name;
	CONTROL_PORT_DATA_R = control_port_name;
	LINES_NUMBER = lines_number;
	RS_PIN = rs_pin;
	RW_PIN = rw_pin;
	E_PIN = e_pin;
	WORKING_MODE = working_mode;
	if ( working_mode == EIGHT_BITS)
		initialize_port(data_port_name,OUTPUT);

	else		//FOUR_BITS
	{
		initialize_pin(data_port_name,4,OUTPUT);
		initialize_pin(data_port_name,5,OUTPUT);
		initialize_pin(data_port_name,6,OUTPUT);
		initialize_pin(data_port_name,7,OUTPUT);
	}

	
	initialize_pin(control_port_name,rs_pin,OUTPUT);	
	initialize_pin(control_port_name,rw_pin,OUTPUT);	
	initialize_pin(control_port_name,e_pin,OUTPUT);	
	
	LCD_command(0x01);				//clear screen				
	
	if (lines_number	== 1	&& working_mode == EIGHT_BITS)
		LCD_command(0x30);												//1 line 8-bits mode			
	else if (lines_number == 2  && working_mode == EIGHT_BITS)
		LCD_command(0x38);												//2 lines 8-bits mode				
	else if (lines_number	== 1  && working_mode == FOUR_BITS)
			LCD_command(0x20);											//1 line 4-bits mode			
	else if	(lines_number == 2  && working_mode == FOUR_BITS)
			LCD_command(0x28);											//2 lines 4-bits mode		

	LCD_command(0x06);													//entry mode		
	LCD_command(0x80)	;													//move cursor to beginning of first line	
	LCD_command(0x0E);													//Display on cursor on	
	
}


void LCD_command(uint8_t command)
{
		
	if (WORKING_MODE	== EIGHT_BITS)
	{

		set_output_port(DATA_PORT_DATA_R,command);
		clear_output_pin(CONTROL_PORT_DATA_R,RS_PIN);						// send a command
		clear_output_pin(CONTROL_PORT_DATA_R,RW_PIN);						//write to LCD
		clear_output_pin(CONTROL_PORT_DATA_R,E_PIN);						// send a higt-to-low pulse on enable pin
		if (command < 4 )																				// return home or clear display commands need long time
			delayMs(3);
		else																										// any other command
			delayUs(60);
		set_output_pin(CONTROL_PORT_DATA_R,E_PIN);							// ready for next command or data to be sent
	}


	else //FOUR_BITS
	{
		set_half_port(DATA_PORT_DATA_R,UPPER,(command >> 4) );	// send the upper half of command
		clear_output_pin(CONTROL_PORT_DATA_R,RS_PIN);						// send a command
		clear_output_pin(CONTROL_PORT_DATA_R,RW_PIN);						//write to LCD
		clear_output_pin(CONTROL_PORT_DATA_R,E_PIN);						// send a higt-to-low pulse on enable pin
		if (command < 4 )																				// return home or clear display commands need long time
			delayMs(3);
		else																										// any other command
			delayUs(60);
		set_output_pin(CONTROL_PORT_DATA_R,E_PIN);							// ready for next command or data to be sent
		
		
		set_half_port(DATA_PORT_DATA_R,UPPER, command );				// send the lower half of command
		clear_output_pin(CONTROL_PORT_DATA_R,RS_PIN);						// send a command
		clear_output_pin(CONTROL_PORT_DATA_R,RW_PIN);						//write to LCD
		clear_output_pin(CONTROL_PORT_DATA_R,E_PIN);						// send a higt-to-low pulse on enable pin
		if (command < 4 )																				// return home or clear display commands need long time
			delayMs(3);
		else																										// any other command
			delayUs(60);
		set_output_pin(CONTROL_PORT_DATA_R,E_PIN);							// ready for next command or data to be sent
	}

	
}

void LCD_char(uint8_t mychar)
{
	
	
	if (WORKING_MODE	== EIGHT_BITS)
	{	
		set_output_port(DATA_PORT_DATA_R,mychar);
		set_output_pin(CONTROL_PORT_DATA_R,RS_PIN); 						// send data
		clear_output_pin(CONTROL_PORT_DATA_R,RW_PIN);						//write to LCD
		clear_output_pin(CONTROL_PORT_DATA_R,E_PIN);						// send a higt-to-low pulse on enable pin
		delayUs(60);
		set_output_pin(CONTROL_PORT_DATA_R,E_PIN);							// ready for next command or data to be sent
	}
		
		

	else 		//FOUR_BITS
	{
		set_half_port(DATA_PORT_DATA_R,UPPER, (mychar >> 4) );	// send the upper half of data
		set_output_pin(CONTROL_PORT_DATA_R,RS_PIN); 						// send data
		clear_output_pin(CONTROL_PORT_DATA_R,RW_PIN);						//write to LCD
		clear_output_pin(CONTROL_PORT_DATA_R,E_PIN);						// send a higt-to-low pulse on enable pin
		delayUs(60);
		set_output_pin(CONTROL_PORT_DATA_R,E_PIN);							// ready for next command or data to be sent

		
		set_half_port(DATA_PORT_DATA_R,UPPER,mychar);						// send the lower half of data
		set_output_pin(CONTROL_PORT_DATA_R,RS_PIN); 						// send data
		clear_output_pin(CONTROL_PORT_DATA_R,RW_PIN);						//write to LCD
		clear_output_pin(CONTROL_PORT_DATA_R,E_PIN);						// send a higt-to-low pulse on enable pin
		delayUs(60);
		set_output_pin(CONTROL_PORT_DATA_R,E_PIN);							// ready for next command or data to be sent
	}

	
}	

void LCD_display(char* mystring)
{
	uint8_t	display_position = 0;
	LCD_command(0x01);																									//clear screen
	while(*(mystring))
	{
		LCD_char( *(mystring++) );
		display_position++;
		if ( (!(display_position %32))	&& 	LINES_NUMBER	== 2)					// 2 lines are full
		{
			display_position = 0;
			delayMs(3000);
			LCD_command(0x01);																						//clear screen
			LCD_command(0x80);																						//move cursor to beginning of first line
		}
		else if (!(display_position	% 16))															// first line is full
		{
			if (LINES_NUMBER	== 2)
				LCD_command(0xC0);																					//move cursor to beginning of second line
			
			else if (LINES_NUMBER	== 1)
			{
				delayMs(3000);
				LCD_command(0x01);																					//clear screen
				LCD_command(0x80);																					//move cursor to beginning of first line
			}
				
		}
			
	}
}

