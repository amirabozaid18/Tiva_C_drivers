#include "ADC.h"


void initialize_analog_pin(char port_name, uint8_t pin_number)
{
	switch ( port_name)
	{
		case 'B':
		{
			SYSCTL_RCGCGPIO_R	|= (1<<1);
			while ( ! ( SYSCTL_PRGPIO_R & (1 << 1) ) );
			
			GPIO_PORTB_DIR_R	&= ~(1<<pin_number);
			GPIO_PORTB_DEN_R	&= ~(1<<pin_number);
			GPIO_PORTB_AMSEL_R	|= (1<<pin_number);
			GPIO_PORTB_AFSEL_R	|= (1<<pin_number);
			break;
		}
		case 'D':
		{
			SYSCTL_RCGCGPIO_R	|= (1<<3);
			while ( ! ( SYSCTL_PRGPIO_R & (1 << 3) ) );
			
			GPIO_PORTD_DIR_R	&= ~(1<<pin_number);
			GPIO_PORTD_DEN_R	&= ~(1<<pin_number);
			GPIO_PORTD_AMSEL_R	|= (1<<pin_number);
			GPIO_PORTD_AFSEL_R	|= (1<<pin_number);
			break;
		}
		case 'E':
		{
			SYSCTL_RCGCGPIO_R	|= (1<<4);
			while ( ! ( SYSCTL_PRGPIO_R & (1 << 4) ) );
			
			GPIO_PORTE_DIR_R	&= ~(1<<pin_number);
			GPIO_PORTE_DEN_R	&= ~(1<<pin_number);
			GPIO_PORTE_AMSEL_R	|= (1<<pin_number);
			GPIO_PORTE_AFSEL_R	|= (1<<pin_number);
			break;
		}
		default : break;	
	}
}


void ADC_pin_init(uint8_t input_number, clock ADC0_clock, clock ADC1_clock)
{
	if ( ADC0_clock == CONNECTED)
	{
		SYSCTL_RCGCADC_R	|= (1<<0);
		while (! ( SYSCTL_PRADC_R	& (1<<0) ) );
	}
	
	if ( ADC1_clock == CONNECTED)
	{
		SYSCTL_RCGCADC_R	|= (1<<1);
		while (! ( SYSCTL_PRADC_R	& (1<<1) ) );
	}
	
	switch ( input_number)
	{
		case 0: initialize_analog_pin('E',3); break;
		case 1: initialize_analog_pin('E',2); break;
		case 2: initialize_analog_pin('E',1); break;
		case 3: initialize_analog_pin('E',0); break;
		case 4: initialize_analog_pin('D',3); break;
		case 5: initialize_analog_pin('D',2); break;
		case 6: initialize_analog_pin('D',1); break;
		case 7: initialize_analog_pin('D',0); break;
		case 8: initialize_analog_pin('E',5); break;
		case 9: initialize_analog_pin('E',4); break;
		case 10: initialize_analog_pin('B',4); break;
		case 11: initialize_analog_pin('B',5); break;
		default: break;
	}
	
	
		
}


void set_sequencers_priorities(uint8_t ADC_number, uint8_t sequencer0_priority, uint8_t sequencer1_priority, uint8_t sequencer2_priority, uint8_t sequencer3_priority)
{
	
	switch (ADC_number)
	{
		case 0 : 
		{
			ADC0_SSPRI_R = 0;
			ADC0_SSPRI_R = (sequencer0_priority << 0) | (sequencer1_priority << 4) | (sequencer2_priority << 8) | (sequencer3_priority << 12) ;
			break;
		}
		case 1 :
		{
			ADC1_SSPRI_R = 0;
			ADC1_SSPRI_R = (sequencer0_priority << 0) | (sequencer1_priority << 4) | (sequencer2_priority << 8) | (sequencer3_priority << 12) ;			
			break;
		}
		default: break;
	}
}


void sequencer0_init(uint8_t ADC_number,initiation sequencer_initiation,uint8_t samples_number, state sequence_interrupt, uint8_t interrupt_priority, uint8_t first_input, uint8_t second_input, uint8_t third_input, uint8_t fourth_input, uint8_t fifth_input, uint8_t sixth_input, uint8_t seventh_input, uint8_t eighth_input)
{
	switch (ADC_number)
	{
		case 0 :
		{
			ADC0_ACTSS_R	&= ~(1<<0);
			
			if ( sequencer_initiation == ONCE)
				ADC0_EMUX_R = ( ADC0_EMUX_R & 0xFFF0) | (0x0 << 0);
			
			else if ( sequencer_initiation == ALWAYS)
				ADC0_EMUX_R = ( ADC0_EMUX_R & 0xFFF0) | (0xF << 0);
			
			ADC0_SSMUX0_R = 0;
			
			ADC0_SSMUX0_R |= ( first_input << 0);
			
			ADC0_SSMUX0_R |= ( second_input << 4);
			
			ADC0_SSMUX0_R |= ( third_input << 8);
			
			ADC0_SSMUX0_R |= ( fourth_input << 12);
			
			ADC0_SSMUX0_R |= ( fifth_input << 16);
			
			ADC0_SSMUX0_R |= ( sixth_input << 20);
			
			ADC0_SSMUX0_R |= ( seventh_input << 24);
			
			ADC0_SSMUX0_R |= ( eighth_input << 28);
			
			switch ( samples_number)
			{
				case 1 :
				{
					ADC0_SSCTL0_R |= (1<<1); 
					ADC0_SSCTL0_R |= (1<<2);
					break;
				}					
				case 2 :
				{
					ADC0_SSCTL0_R |= (1<<5); 
					ADC0_SSCTL0_R |= (1<<6);
					break;
				}
				case 3 :
				{
					ADC0_SSCTL0_R |= (1<<9); 
					ADC0_SSCTL0_R |= (1<<10);
					break;
				}
				case 4 :
				{
					ADC0_SSCTL0_R |= (1<<13); 
					ADC0_SSCTL0_R |= (1<<14);
					break;
				}
				case 5 :
				{
					ADC0_SSCTL0_R |= (1<<17); 
					ADC0_SSCTL0_R |= (1<<18);
					break;
				}
				case 6 :
				{
					ADC0_SSCTL0_R |= (1<<21); 
					ADC0_SSCTL0_R |= (1<<22);
					break;
				}
				case 7 :
				{
					ADC0_SSCTL0_R |= (1<<25); 
					ADC0_SSCTL0_R |= (1<<26);
					break;
				}
				case 8 :
				{
					ADC0_SSCTL0_R |= (1<<29); 
					ADC0_SSCTL0_R |= (1<<30);
					break;
				}
				default: break;
			}
			
			if (sequence_interrupt == ON)
				enable_ADC_interrupt(0,0,interrupt_priority);
				
		
				
			
			ADC0_ACTSS_R	|= (1<<0);
			
			break;
		}
		
		case 1 :
		{
			ADC1_ACTSS_R	&= ~(1<<0);
			
			if ( sequencer_initiation == ONCE)
				ADC1_EMUX_R = ( ADC1_EMUX_R & 0xFFF0) | (0x0 << 0);
			
			else if ( sequencer_initiation == ALWAYS)
				ADC1_EMUX_R = ( ADC1_EMUX_R & 0xFFF0) | (0xF << 0);
			
			ADC1_SSMUX0_R = 0;
			
			ADC1_SSMUX0_R |= ( first_input << 0);
			
			ADC1_SSMUX0_R |= ( second_input << 4);
			
			ADC1_SSMUX0_R |= ( third_input << 8);
			
			ADC1_SSMUX0_R |= ( fourth_input << 12);
			
			ADC1_SSMUX0_R |= ( fifth_input << 16);
			
			ADC1_SSMUX0_R |= ( sixth_input << 20);
			
			ADC1_SSMUX0_R |= ( seventh_input << 24);
			
			ADC1_SSMUX0_R |= ( eighth_input << 28);
			
			switch ( samples_number)
			{
				case 1 :
				{
					ADC1_SSCTL0_R |= (1<<1); 
					ADC1_SSCTL0_R |= (1<<2);
					break;
				}					
				case 2 :
				{
					ADC1_SSCTL0_R |= (1<<5); 
					ADC1_SSCTL0_R |= (1<<6);
					break;
				}
				case 3 :
				{
					ADC1_SSCTL0_R |= (1<<9); 
					ADC1_SSCTL0_R |= (1<<10);
					break;
				}
				case 4 :
				{
					ADC1_SSCTL0_R |= (1<<13); 
					ADC1_SSCTL0_R |= (1<<14);
					break;
				}
				case 5 :
				{
					ADC1_SSCTL0_R |= (1<<17); 
					ADC1_SSCTL0_R |= (1<<18);
					break;
				}
				case 6 :
				{
					ADC1_SSCTL0_R |= (1<<21); 
					ADC1_SSCTL0_R |= (1<<22);
					break;
				}
				case 7 :
				{
					ADC1_SSCTL0_R |= (1<<25); 
					ADC1_SSCTL0_R |= (1<<26);
					break;
				}
				case 8 :
				{
					ADC1_SSCTL0_R |= (1<<29); 
					ADC1_SSCTL0_R |= (1<<30);
					break;
				}
				default: break;
			}
			
			if (sequence_interrupt == ON)
				enable_ADC_interrupt(1,0,interrupt_priority);
				
			
				
			
			ADC1_ACTSS_R	|= (1<<0);
			
			break;
		}
		
		default: break;
	}
}


void sequencer1_init(uint8_t ADC_number,initiation sequencer_initiation,uint8_t samples_number, state sequence_interrupt, uint8_t interrupt_priority, uint8_t first_input, uint8_t second_input, uint8_t third_input, uint8_t fourth_input)
{
	switch (ADC_number)
	{
		case 0 :
		{
			ADC0_ACTSS_R	&= ~(1<<1);
			
			if ( sequencer_initiation == ONCE)
				ADC0_EMUX_R = ( ADC0_EMUX_R & 0xFF0F) | (0x0 << 4);
			
			else if ( sequencer_initiation == ALWAYS)
				ADC0_EMUX_R = ( ADC0_EMUX_R & 0xFF0F) | (0xF << 4);
			
			ADC0_SSMUX1_R = 0;
			
			ADC0_SSMUX1_R |= ( first_input << 0);
			
			ADC0_SSMUX1_R |= ( second_input << 4);
			
			ADC0_SSMUX1_R |= ( third_input << 8);
			
			ADC0_SSMUX1_R |= ( fourth_input << 12);
			
			
			switch ( samples_number)
			{
				case 1 :
				{
					ADC0_SSCTL1_R |= (1<<1); 
					ADC0_SSCTL1_R |= (1<<2);
					break;
				}					
				case 2 :
				{
					ADC0_SSCTL1_R |= (1<<5); 
					ADC0_SSCTL1_R |= (1<<6);
					break;
				}
				case 3 :
				{
					ADC0_SSCTL1_R |= (1<<9); 
					ADC0_SSCTL1_R |= (1<<10);
					break;
				}
				case 4 :
				{
					ADC0_SSCTL1_R |= (1<<13); 
					ADC0_SSCTL1_R |= (1<<14);
					break;
				}
				default: break;
			}
			
			if (sequence_interrupt == ON)
				enable_ADC_interrupt(0,1,interrupt_priority);
				
			
			ADC0_ACTSS_R	|= (1<<1);
			
			break;
		}
		
		case 1 :
		{
			ADC1_ACTSS_R	&= ~(1<<1);
			
			if ( sequencer_initiation == ONCE)
				ADC1_EMUX_R = ( ADC1_EMUX_R & 0xFF0F) | (0x0 << 4);
			
			else if ( sequencer_initiation == ALWAYS)
				ADC1_EMUX_R = ( ADC1_EMUX_R & 0xFF0F) | (0xF << 4);
			
			ADC1_SSMUX1_R = 0;
			
			ADC1_SSMUX1_R |= ( first_input << 0);
			
			ADC1_SSMUX1_R |= ( second_input << 4);
			
			ADC1_SSMUX1_R |= ( third_input<< 8);
			
			ADC1_SSMUX1_R |= ( fourth_input << 12);
			
			
			switch ( samples_number)
			{
				case 1 :
				{
					ADC1_SSCTL1_R |= (1<<1); 
					ADC1_SSCTL1_R |= (1<<2);
					break;
				}					
				case 2 :
				{
					ADC1_SSCTL1_R |= (1<<5); 
					ADC1_SSCTL1_R |= (1<<6);
					break;
				}
				case 3 :
				{
					ADC1_SSCTL1_R |= (1<<9); 
					ADC1_SSCTL1_R |= (1<<10);
					break;
				}
				case 4 :
				{
					ADC1_SSCTL1_R |= (1<<13); 
					ADC1_SSCTL1_R |= (1<<14);
					break;
				}
				default: break;
			}
			
			if (sequence_interrupt == ON)
				enable_ADC_interrupt(1,1,interrupt_priority);
			

			
			ADC1_ACTSS_R	|= (1<<1);
			
			break;
		}
		
		default: break;
	}
}


void sequencer2_init(uint8_t ADC_number,initiation sequencer_initiation,uint8_t samples_number, state sequence_interrupt, uint8_t interrupt_priority, uint8_t first_input, uint8_t second_input, uint8_t third_input, uint8_t fourth_input)
{
	switch (ADC_number)
	{
		case 0 :
		{
			ADC0_ACTSS_R	&= ~(1<<2);
			
			if ( sequencer_initiation == ONCE)
				ADC0_EMUX_R = ( ADC0_EMUX_R & 0xF0FF) | (0x0 << 8);
			
			else if ( sequencer_initiation == ALWAYS)
				ADC0_EMUX_R = ( ADC0_EMUX_R & 0xF0FF) | (0xF << 8);
			
			ADC0_SSMUX2_R = 0;
			
			ADC0_SSMUX2_R |= ( first_input << 0);
			
			ADC0_SSMUX2_R |= ( second_input << 4);
			
			ADC0_SSMUX2_R |= ( third_input << 8);
			
			ADC0_SSMUX2_R |= ( fourth_input << 12);
			
			
			switch ( samples_number)
			{
				case 1 :
				{
					ADC0_SSCTL2_R |= (1<<1); 
					ADC0_SSCTL2_R |= (1<<2);
					break;
				}					
				case 2 :
				{
					ADC0_SSCTL2_R |= (1<<5); 
					ADC0_SSCTL2_R |= (1<<6);
					break;
				}
				case 3 :
				{
					ADC0_SSCTL2_R |= (1<<9); 
					ADC0_SSCTL2_R |= (1<<10);
					break;
				}
				case 4 :
				{
					ADC0_SSCTL2_R |= (1<<13); 
					ADC0_SSCTL2_R |= (1<<14);
					break;
				}
				default: break;
			}
			
			if (sequence_interrupt == ON)
				enable_ADC_interrupt(0,2,interrupt_priority);
				
			
			ADC0_ACTSS_R	|= (1<<2);
			
			break;
		}
		
		case 1 :
		{
			ADC1_ACTSS_R	&= ~(1<<2);
			
			if ( sequencer_initiation == ONCE)
				ADC1_EMUX_R = ( ADC1_EMUX_R & 0xF0FF) | (0x0 << 8);
			
			else if ( sequencer_initiation == ALWAYS)
				ADC1_EMUX_R = ( ADC1_EMUX_R & 0xF0FF) | (0xF << 8);
			
			ADC1_SSMUX2_R = 0;
			
			ADC1_SSMUX2_R |= ( first_input << 0);
			
			ADC1_SSMUX2_R |= ( second_input << 4);
			
			ADC1_SSMUX2_R |= ( third_input << 8);
			
			ADC1_SSMUX2_R |= ( fourth_input << 12);
			
			
			switch ( samples_number)
			{
				case 1 :
				{
					ADC1_SSCTL2_R |= (1<<1); 
					ADC1_SSCTL2_R |= (1<<2);
					break;
				}					
				case 2 :
				{
					ADC1_SSCTL2_R |= (1<<5); 
					ADC1_SSCTL2_R |= (1<<6);
					break;
				}
				case 3 :
				{
					ADC1_SSCTL2_R |= (1<<9); 
					ADC1_SSCTL2_R |= (1<<10);
					break;
				}
				case 4 :
				{
					ADC1_SSCTL2_R |= (1<<13); 
					ADC1_SSCTL2_R |= (1<<14);
					break;
				}
				default: break;
			}
			
			if (sequence_interrupt == ON)
				enable_ADC_interrupt(1,2,interrupt_priority);
				
			
			ADC1_ACTSS_R	|= (1<<2);
			
			break;
		}
		
		default: break;
	}
}


void sequencer3_init(uint8_t ADC_number,initiation sequencer_initiation, state sequence_interrupt, uint8_t interrupt_priority, uint8_t sequencer_input)
{
	switch (ADC_number)
	{
		case 0 :
		{
			ADC0_ACTSS_R	&= ~(1<<3);
			
			if ( sequencer_initiation == ONCE)
				ADC0_EMUX_R = ( ADC0_EMUX_R & 0x0FFF) | (0x0 << 12);
			
			else if ( sequencer_initiation == ALWAYS)
				ADC0_EMUX_R = ( ADC0_EMUX_R & 0x0FFF) | (0xF << 12);
			
			ADC0_SSMUX3_R = sequencer_input;
			
			ADC0_SSCTL3_R |= (1<<1); 
			ADC0_SSCTL3_R |= (1<<2);

			
			if (sequence_interrupt == ON)
				enable_ADC_interrupt(0,3,interrupt_priority);
				
			
			ADC0_ACTSS_R	|= (1<<3);
			
			break;
		}
		
		case 1 :
		{
			ADC1_ACTSS_R	&= ~(1<<3);
			
			if ( sequencer_initiation == ONCE)
				ADC1_EMUX_R = ( ADC1_EMUX_R & 0x0FFF) | (0x0 << 12);
			
			else if ( sequencer_initiation == ALWAYS)
				ADC1_EMUX_R = ( ADC1_EMUX_R & 0x0FFF) | (0xF << 12);
			
			ADC1_SSMUX3_R = sequencer_input;
			
			ADC1_SSCTL3_R |= (1<<1); 
			ADC1_SSCTL3_R |= (1<<2);

			
			if (sequence_interrupt == ON)
				enable_ADC_interrupt(1,3,interrupt_priority);
				
			
			ADC1_ACTSS_R	|= (1<<3);
			
			break;
		}
		
		default: break;
	}
}



void run_sequencer(uint8_t ADC_number,uint8_t sequencer_number)
{
	switch ( ADC_number)
	{
		case 0:
		{
			switch ( sequencer_number)
			{
				case 0:	ADC0_PSSI_R |= (1<<0);	break;
				case 1:	ADC0_PSSI_R |= (1<<1);	break;
				case 2:	ADC0_PSSI_R |= (1<<2);	break;
				case 3:	ADC0_PSSI_R |= (1<<3);	break;
				default: break;
			}
			break;
			
		}
		case 1:
		{
			switch ( sequencer_number)
			{
				case 0:	ADC1_PSSI_R |= (1<<0);	break;
				case 1:	ADC1_PSSI_R |= (1<<1);	break;
				case 2:	ADC1_PSSI_R |= (1<<2);	break;
				case 3:	ADC1_PSSI_R |= (1<<3);	break;
				default: break;
			}
			break;
			
		}
		default: break;
	}
}


void disable_sequencer(uint8_t ADC_number,uint8_t sequencer_number)
{
	switch ( ADC_number)
	{
		case 0:
		{
			switch ( sequencer_number)
			{
				case 0:	ADC0_ACTSS_R &=~ (1<<0);	break;
				case 1:	ADC0_ACTSS_R &=~ (1<<1);	break;
				case 2:	ADC0_ACTSS_R &=~ (1<<2);	break;
				case 3:	ADC0_ACTSS_R &=~ (1<<3);	break;
				default: break;
			}
			break;
			
		}
		case 1:
		{
			switch ( sequencer_number)
			{
				case 0:	ADC1_ACTSS_R &=~ (1<<0);	break;
				case 1:	ADC1_ACTSS_R &=~ (1<<1);	break;
				case 2:	ADC1_ACTSS_R &=~ (1<<2);	break;
				case 3:	ADC1_ACTSS_R &=~ (1<<3);	break;
				default: break;
			}
			break;
			
		}
		default: break;
	}
}



void enable_sequencer(uint8_t ADC_number,uint8_t sequencer_number)
{
	switch ( ADC_number)
	{
		case 0:
		{
			switch ( sequencer_number)
			{
				case 0:	ADC0_ACTSS_R |= (1<<0);	break;
				case 1:	ADC0_ACTSS_R |= (1<<1);	break;
				case 2:	ADC0_ACTSS_R |= (1<<2);	break;
				case 3:	ADC0_ACTSS_R |= (1<<3);	break;
				default: break;
			}
			break;
			
		}
		case 1:
		{
			switch ( sequencer_number)
			{
				case 0:	ADC1_ACTSS_R |= (1<<0);	break;
				case 1:	ADC1_ACTSS_R |= (1<<1);	break;
				case 2:	ADC1_ACTSS_R |= (1<<2);	break;
				case 3:	ADC1_ACTSS_R |= (1<<3);	break;
				default: break;
			}
			break;
			
		}
		default: break;
	}
}


uint16_t conversion_result(uint8_t ADC_number, uint8_t sequencer_number)
{
	switch ( ADC_number)
	{
		case 0:
		{
			switch (sequencer_number)
			{
				case 0 :	return ADC0_SSFIFO0_R & 0x0FFF;
				case 1 :	return ADC0_SSFIFO1_R & 0x0FFF;
				case 2 :	return ADC0_SSFIFO2_R & 0x0FFF;
				case 3 :	return ADC0_SSFIFO3_R & 0x0FFF;
				default: return 0xF000;
			}
		}
		case 1:
		{
			switch (sequencer_number)
			{
				case 0 :	return ADC1_SSFIFO0_R & 0x0FFF;
				case 1 :	return ADC1_SSFIFO1_R & 0x0FFF;
				case 2 :	return ADC1_SSFIFO2_R & 0x0FFF;
				case 3 :	return ADC1_SSFIFO3_R & 0x0FFF;
				default: return 0xF000;
			}
		}
		default: return 0xF000;
	}
}

uint8_t is_FIFO_full(uint8_t ADC_number, uint8_t sequencer_number)
{
	switch ( ADC_number)
	{
		case 0:
		{
			switch (sequencer_number)
			{
				case 0 :	return ( ( ADC0_SSFSTAT0_R & (1<<12) ) >> 11);
				case 1 :	return ( ( ADC0_SSFSTAT1_R & (1<<12) ) >> 11);
				case 2 :	return ( ( ADC0_SSFSTAT2_R & (1<<12) ) >> 11);
				case 3 :	return ( ( ADC0_SSFSTAT3_R & (1<<12) ) >> 11);
				default: return 0xFF;
			}
		}
		case 1:
		{
			switch (sequencer_number)
			{
				case 0 :	return ( ( ADC1_SSFSTAT0_R & (1<<12) ) >> 11);
				case 1 :	return ( ( ADC1_SSFSTAT1_R & (1<<12) ) >> 11);
				case 2 :	return ( ( ADC1_SSFSTAT2_R & (1<<12) ) >> 11);
				case 3 :	return ( ( ADC1_SSFSTAT3_R & (1<<12) ) >> 11);
				default: return 0xFF;
			}
		}
		default: return 0xFF;
	}
}


uint8_t is_FIFO_empty(uint8_t ADC_number, uint8_t sequencer_number)
{
	switch ( ADC_number)
	{
		case 0:
		{
			switch (sequencer_number)
			{
				case 0 :	return ( ( ADC0_SSFSTAT0_R & (1<<8) ) >> 7);
				case 1 :	return ( ( ADC0_SSFSTAT1_R & (1<<8) ) >> 7);
				case 2 :	return ( ( ADC0_SSFSTAT2_R & (1<<8) ) >> 7);
				case 3 :	return ( ( ADC0_SSFSTAT3_R & (1<<8) ) >> 7);
				default: return 0xFF;
			}
		}
		case 1:
		{
			switch (sequencer_number)
			{
				case 0 :	return ( ( ADC1_SSFSTAT0_R & (1<<8) ) >> 7);
				case 1 :	return ( ( ADC1_SSFSTAT1_R & (1<<8) ) >> 7);
				case 2 :	return ( ( ADC1_SSFSTAT2_R & (1<<8) ) >> 7);
				case 3 :	return ( ( ADC1_SSFSTAT3_R & (1<<8) ) >> 7);
				default: return 0xFF;
			}
		}
		default: return 0xFF;
	}
}

uint8_t next_entry_to_be_read(uint8_t ADC_number, uint8_t sequencer_number)
{
	switch ( ADC_number)
	{
		case 0:
		{
			switch (sequencer_number)
			{
				case 0 :	return ( ADC0_SSFSTAT0_R & (0x000F) );
				case 1 :	return ( ADC0_SSFSTAT1_R & (0x000F) );
				case 2 :	return ( ADC0_SSFSTAT2_R & (0x000F) );
				case 3 :	return ( ADC0_SSFSTAT3_R & (0x000F) );
				default: return 0xFF;
			}
		}
		
		case 1:
		{
			switch (sequencer_number)
			{
				case 0 :	return ( ADC1_SSFSTAT0_R & (0x000F) );
				case 1 :	return ( ADC1_SSFSTAT1_R & (0x000F) );
				case 2 :	return ( ADC1_SSFSTAT2_R & (0x000F) );
				case 3 :	return ( ADC1_SSFSTAT3_R & (0x000F) );
				default: return 0xFF;
			}
		}
		default: return 0xFF;
	}
}

uint8_t next_entry_to_be_written(uint8_t ADC_number, uint8_t sequencer_number)
{
	switch ( ADC_number)
	{
		case 0:
		{
			switch (sequencer_number)
			{
				case 0 :	return ( ADC0_SSFSTAT0_R & (0x00F0) );
				case 1 :	return ( ADC0_SSFSTAT1_R & (0x00F0) );
				case 2 :	return ( ADC0_SSFSTAT2_R & (0x00F0) );
				case 3 :	return ( ADC0_SSFSTAT3_R & (0x00F0) );
				default: return 0xFF;
			}
		}
		case 1:
		{
			switch (sequencer_number)
			{
				case 0 :	return ( ADC1_SSFSTAT0_R & (0x00F0) );
				case 1 :	return ( ADC1_SSFSTAT1_R & (0x00F0) );
				case 2 :	return ( ADC1_SSFSTAT2_R & (0x00F0) );
				case 3 :	return ( ADC1_SSFSTAT3_R & (0x00F0) );
				default: return 0xFF;
			}
		}
		default: return 0xFF;
	}
}

void enable_ADC_interrupt(uint8_t ADC_number,uint8_t sequencer_number,uint8_t interrupt_priority)
{
	switch(ADC_number)
	{
		case 0: 
		{
			switch (sequencer_number)
			{
				case 0: ADC0_ISC_R |= (1<<0); ADC0_IM_R |= (1<<0); NVIC_EN0_R |= (1<<14);
				NVIC_PRI3_R = (NVIC_PRI3_R & 0xFF00FFFF) | (interrupt_priority << 21); __enable_irq();  break;
				
				case 1: ADC0_ISC_R |= (1<<1); ADC0_IM_R |= (1<<1); NVIC_EN0_R |= (1<<15);
				NVIC_PRI3_R = (NVIC_PRI3_R & 0x00FFFFFF) | (interrupt_priority << 29); __enable_irq();  break;
				
				case 2: ADC0_ISC_R |= (1<<2); ADC0_IM_R |= (1<<2); NVIC_EN0_R |= (1<<16);
				NVIC_PRI4_R = (NVIC_PRI4_R & 0xFFFFFF00) | (interrupt_priority << 5); __enable_irq();  break;
				
				case 3: ADC0_ISC_R |= (1<<3); ADC0_IM_R |= (1<<3); NVIC_EN0_R |= (1<<17);
				NVIC_PRI4_R = (NVIC_PRI4_R & 0xFFFF00FF) | (interrupt_priority << 13); __enable_irq();  break;
			}
			break;
		}
		
		case 1: 
		{
			switch (sequencer_number)
			{
				case 0: ADC1_ISC_R |= (1<<0); ADC1_IM_R |= (1<<0); NVIC_EN1_R |= (1<<16);
				NVIC_PRI12_R = (NVIC_PRI12_R & 0xFFFFFF00) | (interrupt_priority << 5); __enable_irq();  break;
				
				case 1: ADC1_ISC_R |= (1<<1); ADC1_IM_R |= (1<<1); NVIC_EN1_R |= (1<<17);
				NVIC_PRI12_R = (NVIC_PRI12_R & 0xFFFF00FF) | (interrupt_priority << 13); __enable_irq();  break;
				
				case 2: ADC1_ISC_R |= (1<<2); ADC1_IM_R |= (1<<2); NVIC_EN1_R |= (1<<18);
				NVIC_PRI12_R = (NVIC_PRI12_R & 0xFF00FFFF) | (interrupt_priority << 21); __enable_irq();  break;
				
				case 3: ADC1_ISC_R |= (1<<3); ADC1_IM_R |= (1<<3); NVIC_EN1_R |= (1<<19);
				NVIC_PRI12_R = (NVIC_PRI12_R & 0x00FFFFFF) | (interrupt_priority << 29); __enable_irq();  break;
			}
			break;
		}
		
		default: break;
	}
}

void synchronize_ADC_modules(uint8_t first_module_sequecner_number, uint8_t first_module_lag_multiplier, uint8_t second_module_sequecner_number, uint8_t second_module_lag_multiplier)
{
	ADC0_PSSI_R	|= (1<<27);
	ADC1_PSSI_R	|= (1<<27);
	ADC0_SPC_R	= first_module_lag_multiplier;
	ADC1_SPC_R	= second_module_lag_multiplier;
	ADC0_PSSI_R	|= (1<<first_module_sequecner_number);
	ADC1_PSSI_R	|= (1<<second_module_sequecner_number);
	ADC0_PSSI_R	|= 0x80000000;
	ADC1_PSSI_R	|= 0x80000000;
}


void set_differntial_pair(uint8_t ADC_number, uint8_t sequencer_number, uint8_t positive_sample_index,uint8_t negative_sample_index)
{
	switch(ADC_number)
	{
		case 0: 
		{
			switch(sequencer_number)
			{
				case 0: ADC0_SSCTL0_R |= (1<<(4*positive_sample_index) ) | (1<<(4*negative_sample_index)); break;
				case 1: ADC0_SSCTL1_R |= (1<<(4*positive_sample_index) ) | (1<<(4*negative_sample_index)); break;
				case 2: ADC0_SSCTL2_R |= (1<<(4*positive_sample_index) ) | (1<<(4*negative_sample_index)); break;
				case 3: ADC0_SSCTL3_R |= (1<<(4*positive_sample_index) ) | (1<<(4*negative_sample_index)); break;
			}
			break;
		}
		case 1: 
		{
			switch(sequencer_number)
			{
				case 0: ADC1_SSCTL0_R |= (1<<(4*positive_sample_index) ) | (1<<(4*negative_sample_index)); break;
				case 1: ADC1_SSCTL1_R |= (1<<(4*positive_sample_index) ) | (1<<(4*negative_sample_index)); break;
				case 2: ADC1_SSCTL2_R |= (1<<(4*positive_sample_index) ) | (1<<(4*negative_sample_index)); break;
				case 3: ADC1_SSCTL3_R |= (1<<(4*positive_sample_index) ) | (1<<(4*negative_sample_index)); break;
			}
			break;
		}
		default: break;
	}
}



uint8_t is_ADC_busy(uint8_t ADC_number)
{
	switch (ADC_number)
	{
		case 0 : return ( (ADC0_ACTSS_R & (1<<16) ) >> 15);
		case 1 : return ( (ADC1_ACTSS_R & (1<<16) ) >> 15);
		default: return 0xFF;
	}
}

void set_averaging_rate(uint8_t ADC_number,uint8_t average_rate)
{
	switch (ADC_number)
	{
		case 0: 
		{
			switch(average_rate)
			{
				case 1 : ADC0_SAC_R = 0; break;
				case 2 : ADC0_SAC_R = 1; break;
				case 4 : ADC0_SAC_R = 2; break;
				case 8 : ADC0_SAC_R = 3; break;
				case 16: ADC0_SAC_R = 4; break;
				case 32: ADC0_SAC_R = 5; break;
				case 64: ADC0_SAC_R = 6; break;
			}
			break;
		}
		
		case 1: 
		{
			switch(average_rate)
			{
				case 1 : ADC1_SAC_R = 0; break;
				case 2 : ADC1_SAC_R = 1; break;
				case 4 : ADC1_SAC_R = 2; break;
				case 8 : ADC1_SAC_R = 3; break;
				case 16: ADC1_SAC_R = 4; break;
				case 32: ADC1_SAC_R = 5; break;
				case 64: ADC1_SAC_R = 6; break;
			}
			break;
		}
		
		default: break;
		
	}
}

