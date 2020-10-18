#include "timers.h"

// 16/32 general purpose timers

void disable_timer(uint8_t	timer_number, char channel_name)
{
	switch ( timer_number)
	{
		case 0: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER0_CTL_R &= ~(1<<0); break;
				case 'B':	TIMER0_CTL_R &= ~(1<<8); break;
				default : TIMER0_CTL_R &= ~(1<<0); break;
			}
			break;
		}
		case 1: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER1_CTL_R &= ~(1<<0); break;
				case 'B':	TIMER1_CTL_R &= ~(1<<8); break;
				default : TIMER1_CTL_R &= ~(1<<0); break;
			}
			break;
		}
		case 2: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER2_CTL_R &= ~(1<<0); break;
				case 'B':	TIMER2_CTL_R &= ~(1<<8); break;
				default : TIMER2_CTL_R &= ~(1<<0); break;
			}
			break;
		}
		case 3: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER3_CTL_R &= ~(1<<0); break;
				case 'B':	TIMER3_CTL_R &= ~(1<<8); break;
				default : TIMER3_CTL_R &= ~(1<<0); break;
			}
			break;
		}
		case 4: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER4_CTL_R &= ~(1<<0); break;
				case 'B':	TIMER4_CTL_R &= ~(1<<8); break;
				default : TIMER4_CTL_R &= ~(1<<0); break;
			}
			break;
		}
		case 5: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER5_CTL_R &= ~(1<<0); break;
				case 'B':	TIMER5_CTL_R &= ~(1<<8); break;
				default : TIMER5_CTL_R &= ~(1<<0); break;
			}
			break;
		}
		default:	break;
	}
}

void enable_timer(uint8_t	timer_number, char channel_name)
{
	switch ( timer_number)
	{
		case 0: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER0_CTL_R |= (1<<0); break;
				case 'B':	TIMER0_CTL_R |= (1<<8); break;
				default : TIMER0_CTL_R |= (1<<0); break;
			}
			break;
		}
		case 1: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER1_CTL_R |= (1<<0); break;
				case 'B':	TIMER1_CTL_R |= (1<<8); break;
				default : TIMER1_CTL_R |= (1<<0); break;
			}
			break;
		}
		case 2: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER2_CTL_R |= (1<<0); break;
				case 'B':	TIMER2_CTL_R |= (1<<8); break;
				default : TIMER2_CTL_R |= (1<<0); break;
			}
			break;
		}
		case 3: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER3_CTL_R |= (1<<0); break;
				case 'B':	TIMER3_CTL_R |= (1<<8); break;
				default : TIMER3_CTL_R |= (1<<0); break;
			}
			break;
		}
		case 4: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER4_CTL_R |= (1<<0); break;
				case 'B':	TIMER4_CTL_R |= (1<<8); break;
				default : TIMER4_CTL_R |= (1<<0); break;
			}
			break;
		}
		case 5: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER5_CTL_R |= (1<<0); break;
				case 'B':	TIMER5_CTL_R |= (1<<8); break;
				default : TIMER5_CTL_R |= (1<<0); break;
			}
			break;
		}
		default:	break;
	}
}
void enable_timer_interrupt(uint8_t	timer_number,char channel_name, uint8_t interrupt_priority)
{
	switch (timer_number)
	{
		case 0:
		{
			TIMER0_ICR_R	= 0xFFF;
			switch (channel_name)
			{
				case 'A': NVIC_EN0_R	|= (1<<19);		NVIC_PRI4_R	= (NVIC_PRI4_R & 0x00FFFFFF) | ( interrupt_priority << 29);			break;
				case 'B':	NVIC_EN0_R	|= (1<<20);		NVIC_PRI5_R	= (NVIC_PRI5_R & 0xFFFFFF00) | ( interrupt_priority << 5);			break;
				default: break;
			}
			break;
		}
		case 1:
		{
			TIMER1_ICR_R	= 0xFFF;
			switch (channel_name)
			{
				case 'A': NVIC_EN0_R	|= (1<<21);		NVIC_PRI5_R	= (NVIC_PRI5_R & 0xFFFF00FF) | ( interrupt_priority << 13);			break;
				case 'B':	NVIC_EN0_R	|= (1<<22);		NVIC_PRI5_R	= (NVIC_PRI5_R & 0xFF00FFFF) | ( interrupt_priority << 21);			break;
				default: break;
			}
			break;
		}
		case 2:
		{
			TIMER2_ICR_R	= 0xFFF;
			switch (channel_name)
			{
				case 'A': NVIC_EN0_R	|= (1<<23);		NVIC_PRI5_R	= (NVIC_PRI5_R & 0x00FFFFFF) | ( interrupt_priority << 29);			break;
				case 'B':	NVIC_EN0_R	|= (1<<24);		NVIC_PRI6_R	= (NVIC_PRI6_R & 0xFFFFFF00) | ( interrupt_priority << 5);			break;
				default: break;
			}
			break;
		}
		case 3:
		{
			TIMER3_ICR_R	= 0xFFF;
			switch (channel_name)
			{
				case 'A': NVIC_EN1_R	|= (1<<3);		NVIC_PRI8_R	= (NVIC_PRI8_R & 0x00FFFFFF) | ( interrupt_priority << 29);			break;
				case 'B':	NVIC_EN1_R	|= (1<<4);		NVIC_PRI9_R	= (NVIC_PRI9_R & 0xFFFFFF00) | ( interrupt_priority << 5);			break;
				default: break;
			}
			break;
		}
		case 4:
		{
			TIMER4_ICR_R	= 0xFFF;
			switch (channel_name)
			{
				case 'A': NVIC_EN2_R	|= (1<<6);		NVIC_PRI17_R	= (NVIC_PRI17_R & 0xFF00FFFF) | ( interrupt_priority << 21);	break;
				case 'B':	NVIC_EN2_R	|= (1<<7);		NVIC_PRI17_R	= (NVIC_PRI17_R & 0x00FFFFFF) | ( interrupt_priority << 29);	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			TIMER5_ICR_R	= 0xFFF;
			switch (channel_name)
			{
				case 'A': NVIC_EN2_R	|= (1<<28);		NVIC_PRI23_R	= (NVIC_PRI23_R & 0xFFFFFF00) | ( interrupt_priority << 5);		break;
				case 'B':	NVIC_EN2_R	|= (1<<29);		NVIC_PRI23_R	= (NVIC_PRI23_R & 0xFFFF00FF) | ( interrupt_priority << 13);	break;
				default: break;
			}
			break;
		}
		default: break;
	}
}


void enable_timeout_interrupt(uint8_t timer_number,char channel_name)
{
	switch (timer_number)
	{
		case 0:
		{
			switch (channel_name)
			{
				case 'A':	TIMER0_ICR_R	|= (1<<0);	TIMER0_IMR_R	|= (1<<0);	break;
				case 'B':	TIMER0_ICR_R	|= (1<<8);	TIMER0_IMR_R	|= (1<<8);	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch (channel_name)
			{
				case 'A':	TIMER1_ICR_R	|= (1<<0);	TIMER1_IMR_R	|= (1<<0);	break;
				case 'B':	TIMER1_ICR_R	|= (1<<8);	TIMER1_IMR_R	|= (1<<8);	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch (channel_name)
			{
				case 'A':	TIMER2_ICR_R	|= (1<<0);	TIMER2_IMR_R	|= (1<<0);	break;
				case 'B':	TIMER2_ICR_R	|= (1<<8);	TIMER2_IMR_R	|= (1<<8);	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch (channel_name)
			{
				case 'A':	TIMER3_ICR_R	|= (1<<0);	TIMER3_IMR_R	|= (1<<0);	break;
				case 'B':	TIMER3_ICR_R	|= (1<<8);	TIMER3_IMR_R	|= (1<<8);	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch (channel_name)
			{
				case 'A':	TIMER4_ICR_R	|= (1<<0);	TIMER4_IMR_R	|= (1<<0);	break;
				case 'B':	TIMER4_ICR_R	|= (1<<8);	TIMER4_IMR_R	|= (1<<8);	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch (channel_name)
			{
				case 'A':	TIMER5_ICR_R	|= (1<<0);	TIMER5_IMR_R	|= (1<<0);	break;
				case 'B':	TIMER5_ICR_R	|= (1<<8);	TIMER5_IMR_R	|= (1<<8);	break;
				default: break;
			}
			break;
		}
		default: break;
	}
	__enable_irq();
}

void enable_match_interrupt(uint8_t timer_number,char channel_name)
{
	switch (timer_number)
	{
		case 0:
		{
			switch (channel_name)
			{
				case 'A':	TIMER0_TAMR_R	|= (1<<5);  TIMER0_ICR_R	|= (1<<4);	TIMER0_IMR_R	|= (1<<4);	break;	
				case 'B':	TIMER0_TBMR_R	|= (1<<5);  TIMER0_ICR_R	|= (1<<11);	TIMER0_IMR_R	|= (1<<11);	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch (channel_name)
			{
				case 'A':	TIMER1_TAMR_R	|= (1<<5);  TIMER1_ICR_R	|= (1<<4);	TIMER1_IMR_R	|= (1<<4);	break;
				case 'B':	TIMER1_TBMR_R	|= (1<<5);  TIMER1_ICR_R	|= (1<<11);	TIMER1_IMR_R	|= (1<<11);	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch (channel_name)
			{
				case 'A':	TIMER2_TAMR_R	|= (1<<5);  TIMER2_ICR_R	|= (1<<4);	TIMER2_IMR_R	|= (1<<4);	break;
				case 'B':	TIMER2_TBMR_R	|= (1<<5);  TIMER2_ICR_R	|= (1<<11);	TIMER2_IMR_R	|= (1<<11);	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch (channel_name)
			{
				case 'A':	TIMER3_TAMR_R	|= (1<<5);  TIMER3_ICR_R	|= (1<<4);	TIMER3_IMR_R	|= (1<<4);	break;
				case 'B':	TIMER3_TBMR_R	|= (1<<5);  TIMER3_ICR_R	|= (1<<11);	TIMER3_IMR_R	|= (1<<11);	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch (channel_name)
			{
				case 'A':	TIMER4_TAMR_R	|= (1<<5);  TIMER4_ICR_R	|= (1<<4);	TIMER4_IMR_R	|= (1<<4);	break;
				case 'B':	TIMER4_TBMR_R	|= (1<<5);  TIMER4_ICR_R	|= (1<<11);	TIMER4_IMR_R	|= (1<<11);	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch (channel_name)
			{
				case 'A':	TIMER5_TAMR_R	|= (1<<5);  TIMER5_ICR_R	|= (1<<4);	TIMER5_IMR_R	|= (1<<4);	break;
				case 'B':	TIMER5_TBMR_R	|= (1<<5);  TIMER5_ICR_R	|= (1<<11);	TIMER5_IMR_R	|= (1<<11);	break;
				default: break;
			}
			break;
		}
		default: break;
	}
	__enable_irq();
}


void enable_RTC_interrupt(uint8_t timer_number)
{
	switch (timer_number)
	{
		case 0: TIMER0_ICR_R |= (1<<3);	TIMER0_IMR_R |= (1<<3);	break;
		case 1: TIMER1_ICR_R |= (1<<3);	TIMER1_IMR_R |= (1<<3);	break;
		case 2: TIMER2_ICR_R |= (1<<3);	TIMER2_IMR_R |= (1<<3);	break;
		case 3: TIMER3_ICR_R |= (1<<3);	TIMER3_IMR_R |= (1<<3);	break;
		case 4: TIMER4_ICR_R |= (1<<3);	TIMER4_IMR_R |= (1<<3);	break;
		case 5: TIMER5_ICR_R |= (1<<3);	TIMER5_IMR_R |= (1<<3);	break;
		default: break;
	}
}

void enable_edge_count_interrupt(uint8_t timer_number,char channel_name)
{
	switch (timer_number)
	{
		case 0:
		{
			switch (channel_name)
			{
				case 'A':	TIMER0_ICR_R	|= (1<<1);	TIMER0_IMR_R	|= (1<<1);	break;
				case 'B':	TIMER0_ICR_R	|= (1<<9);	TIMER0_IMR_R	|= (1<<9);	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch (channel_name)
			{
				case 'A':	TIMER1_ICR_R	|= (1<<1);	TIMER1_IMR_R	|= (1<<1);	break;
				case 'B':	TIMER1_ICR_R	|= (1<<9);	TIMER1_IMR_R	|= (1<<9);	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch (channel_name)
			{
				case 'A':	TIMER2_ICR_R	|= (1<<1);	TIMER2_IMR_R	|= (1<<1);	break;
				case 'B':	TIMER2_ICR_R	|= (1<<9);	TIMER2_IMR_R	|= (1<<9);	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch (channel_name)
			{
				case 'A':	TIMER3_ICR_R	|= (1<<1);	TIMER3_IMR_R	|= (1<<1);	break;
				case 'B':	TIMER3_ICR_R	|= (1<<9);	TIMER3_IMR_R	|= (1<<9);	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch (channel_name)
			{
				case 'A':	TIMER4_ICR_R	|= (1<<1);	TIMER4_IMR_R	|= (1<<1);	break;
				case 'B':	TIMER4_ICR_R	|= (1<<9);	TIMER4_IMR_R	|= (1<<9);	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch (channel_name)
			{
				case 'A':	TIMER5_ICR_R	|= (1<<1);	TIMER5_IMR_R	|= (1<<1);	break;
				case 'B':	TIMER5_ICR_R	|= (1<<9);	TIMER5_IMR_R	|= (1<<9);	break;
				default: break;
			}
			break;
		}
		default: break;
	}
	__enable_irq();
}


void enable_edge_time_interrupt(uint8_t timer_number,char channel_name)
{
	switch (timer_number)
	{
		case 0:
		{
			switch (channel_name)
			{
				case 'A':	TIMER0_ICR_R	|= (1<<2);	TIMER0_IMR_R	|= (1<<2);	break;
				case 'B':	TIMER0_ICR_R	|= (1<<10);	TIMER0_IMR_R	|= (1<<10);	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch (channel_name)
			{
				case 'A':	TIMER1_ICR_R	|= (1<<2);	TIMER1_IMR_R	|= (1<<2);	break;
				case 'B':	TIMER1_ICR_R	|= (1<<10);	TIMER1_IMR_R	|= (1<<10);	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch (channel_name)
			{
				case 'A':	TIMER2_ICR_R	|= (1<<2);	TIMER2_IMR_R	|= (1<<2);	break;
				case 'B':	TIMER2_ICR_R	|= (1<<10);	TIMER2_IMR_R	|= (1<<10);	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch (channel_name)
			{
				case 'A':	TIMER3_ICR_R	|= (1<<2);	TIMER3_IMR_R	|= (1<<2);	break;
				case 'B':	TIMER3_ICR_R	|= (1<<10);	TIMER3_IMR_R	|= (1<<10);	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch (channel_name)
			{
				case 'A':	TIMER4_ICR_R	|= (1<<2);	TIMER4_IMR_R	|= (1<<2);	break;
				case 'B':	TIMER4_ICR_R	|= (1<<10);	TIMER4_IMR_R	|= (1<<10);	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch (channel_name)
			{
				case 'A':	TIMER5_ICR_R	|= (1<<2);	TIMER5_IMR_R	|= (1<<2);	break;
				case 'B':	TIMER5_ICR_R	|= (1<<10);	TIMER5_IMR_R	|= (1<<10);	break;
				default: break;
			}
			break;
		}
		default: break;
	}
	__enable_irq();
}
	
void config_full_timer(uint8_t timer_number)
{
	switch (timer_number)
	{
		case 0: TIMER0_CFG_R	= 0x0;	break;
		case 1: TIMER1_CFG_R	= 0x0;	break;
		case 2: TIMER2_CFG_R	= 0x0;	break;
		case 3: TIMER3_CFG_R	= 0x0;	break;
		case 4: TIMER4_CFG_R	= 0x0;	break;
		case 5: TIMER5_CFG_R	= 0x0;	break;
		default:	break;
	}
}

void config_half_timer(uint8_t timer_number)
{
	switch (timer_number)
	{
		case 0: TIMER0_CFG_R	= 0x4;	break;
		case 1: TIMER1_CFG_R	= 0x4;	break;
		case 2: TIMER2_CFG_R	= 0x4;	break;
		case 3: TIMER3_CFG_R	= 0x4;	break;
		case 4: TIMER4_CFG_R	= 0x4;	break;
		case 5: TIMER5_CFG_R	= 0x4;	break;
		default:	break;
	}
}


void config_RTC(uint8_t timer_number)
{
	switch (timer_number)
	{																																							// RTC does not stop counting even in debugging
		case 0: TIMER0_CFG_R	= 0x1; TIMER0_CTL_R |= (1<<4); TIMER0_CTL_R &= ~(1<<1);	break;
		case 1: TIMER1_CFG_R	= 0x1; TIMER1_CTL_R |= (1<<4); TIMER1_CTL_R &= ~(1<<1);	break;
		case 2: TIMER2_CFG_R	= 0x1; TIMER2_CTL_R |= (1<<4); TIMER2_CTL_R &= ~(1<<1); break;
		case 3: TIMER3_CFG_R	= 0x1; TIMER3_CTL_R |= (1<<4); TIMER3_CTL_R &= ~(1<<1);	break;
		case 4: TIMER4_CFG_R	= 0x1; TIMER4_CTL_R |= (1<<4); TIMER4_CTL_R &= ~(1<<1);	break;
		case 5: TIMER5_CFG_R	= 0x1; TIMER5_CTL_R |= (1<<4); TIMER5_CTL_R &= ~(1<<1);	break;
		default:	break;
	}
}

void set_one_shot_timer(uint8_t timer_number,char channel_name)
{
	switch ( timer_number)
	{
		case 0: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER0_TAMR_R	 = ( TIMER0_TAMR_R & 0xFFC )	| 0x001 ; break;
				case 'B':	TIMER0_TBMR_R	 = ( TIMER0_TBMR_R & 0xFFC )	| 0x001 ; break;
				default: break;
			}
			break;
		}
		case 1: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER1_TAMR_R	 = ( TIMER1_TAMR_R & 0xFFC )	| 0x001 ; break;
				case 'B':	TIMER1_TBMR_R	 = ( TIMER1_TBMR_R & 0xFFC )	| 0x001 ; break;
				default: break;
			}
			break;
		}
		case 2: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER2_TAMR_R	 = ( TIMER2_TAMR_R & 0xFFC )	| 0x001 ; break;
				case 'B':	TIMER2_TBMR_R	 = ( TIMER2_TBMR_R & 0xFFC )	| 0x001 ; break;
				default: break;
			}
			break;
		}
		case 3: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER3_TAMR_R	 = ( TIMER3_TAMR_R & 0xFFC )	| 0x001 ; break;
				case 'B':	TIMER3_TBMR_R	 = ( TIMER3_TBMR_R & 0xFFC )	| 0x001 ; break;
				default: break;
			}
			break;
		}
		case 4: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER4_TAMR_R	 = ( TIMER4_TAMR_R & 0xFFC )	| 0x001 ; break;
				case 'B':	TIMER4_TBMR_R	 = ( TIMER4_TBMR_R & 0xFFC )	| 0x001 ; break;
				default: break;
			}
			break;
		}
		case 5: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER5_TAMR_R	 = ( TIMER5_TAMR_R & 0xFFC )	| 0x001 ; break;
				case 'B':	TIMER5_TBMR_R	 = ( TIMER5_TBMR_R & 0xFFC )	| 0x001 ; break;
				default: break;
			}
			break;
		}
		default:	break;
	}
}

void set_periodic_timer(uint8_t timer_number,char channel_name)
{
	switch ( timer_number)
	{
		case 0: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER0_TAMR_R	 = ( TIMER0_TAMR_R & 0xFFC )	| 0x002 ; break;
				case 'B':	TIMER0_TBMR_R	 = ( TIMER0_TBMR_R & 0xFFC )	| 0x002 ; break;
				default: break;
			}
			break;
		}
		case 1: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER1_TAMR_R	 = ( TIMER1_TAMR_R & 0xFFC )	| 0x002 ; break;
				case 'B':	TIMER1_TBMR_R	 = ( TIMER1_TBMR_R & 0xFFC )	| 0x002 ; break;
				default: break;
			}
			break;
		}
		case 2: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER2_TAMR_R	 = ( TIMER2_TAMR_R & 0xFFC )	| 0x002 ; break;
				case 'B':	TIMER2_TBMR_R	 = ( TIMER2_TBMR_R & 0xFFC )	| 0x002 ; break;
				default: break;
			}
			break;
		}
		case 3: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER3_TAMR_R	 = ( TIMER3_TAMR_R & 0xFFC )	| 0x002 ; break;
				case 'B':	TIMER3_TBMR_R	 = ( TIMER3_TBMR_R & 0xFFC )	| 0x002 ; break;
				default: break;
			}
			break;
		}
		case 4: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER4_TAMR_R	 = ( TIMER4_TAMR_R & 0xFFC )	| 0x002 ; break;
				case 'B':	TIMER4_TBMR_R	 = ( TIMER4_TBMR_R & 0xFFC )	| 0x002 ; break;
				default: break;
			}
			break;
		}
		case 5: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER5_TAMR_R	 = ( TIMER5_TAMR_R & 0xFFC )	| 0x002 ; break;
				case 'B':	TIMER5_TBMR_R	 = ( TIMER5_TBMR_R & 0xFFC )	| 0x002 ; break;
				default: break;
			}
			break;
		}
		default:	break;
	}
}

void set_edge_count(uint8_t timer_number,char channel_name)
{
	switch ( timer_number)
	{
		case 0: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER0_TAMR_R	 = ( TIMER0_TAMR_R & 0xFF8 )	| 0x003 ; break;
				case 'B':	TIMER0_TBMR_R	 = ( TIMER0_TBMR_R & 0xFF8 )	| 0x003 ; break;
				default: break;
			}
			break;
		}
		case 1: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER1_TAMR_R	 = ( TIMER1_TAMR_R & 0xFF8 )	| 0x003 ; break;
				case 'B':	TIMER1_TBMR_R	 = ( TIMER1_TBMR_R & 0xFF8 )	| 0x003 ; break;
				default: break;
			}
			break;
		}
		case 2: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER2_TAMR_R	 = ( TIMER2_TAMR_R & 0xFF8 )	| 0x003 ; break;
				case 'B':	TIMER2_TBMR_R	 = ( TIMER2_TBMR_R & 0xFF8 )	| 0x003 ; break;
				default: break;
			}
			break;
		}
		case 3: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER3_TAMR_R	 = ( TIMER3_TAMR_R & 0xFF8 )	| 0x003 ; break;
				case 'B':	TIMER3_TBMR_R	 = ( TIMER3_TBMR_R & 0xFF8 )	| 0x003 ; break;
				default: break;
			}
			break;
		}
		case 4: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER4_TAMR_R	 = ( TIMER4_TAMR_R & 0xFF8 )	| 0x003 ; break;
				case 'B':	TIMER4_TBMR_R	 = ( TIMER4_TBMR_R & 0xFF8 )	| 0x003 ; break;
				default: break;
			}
			break;
		}
		case 5: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER5_TAMR_R	 = ( TIMER5_TAMR_R & 0xFF8 )	| 0x003 ; break;
				case 'B':	TIMER5_TBMR_R	 = ( TIMER5_TBMR_R & 0xFF8 )	| 0x003 ; break;
				default: break;
			}
			break;
		}
		default:	break;
	}
}

void set_edge_time(uint8_t timer_number,char channel_name)
{
	switch ( timer_number)
	{
		case 0: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER0_TAMR_R	 = ( TIMER0_TAMR_R & 0xFF8 )	| 0x007 ; break;
				case 'B':	TIMER0_TBMR_R	 = ( TIMER0_TBMR_R & 0xFF8 )	| 0x007 ; break;
				default: break;
			}
			break;
		}
		case 1: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER1_TAMR_R	 = ( TIMER1_TAMR_R & 0xFF8 )	| 0x007 ; break;
				case 'B':	TIMER1_TBMR_R	 = ( TIMER1_TBMR_R & 0xFF8 )	| 0x007 ; break;
				default: break;
			}
			break;
		}
		case 2: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER2_TAMR_R	 = ( TIMER2_TAMR_R & 0xFF8 )	| 0x007 ; break;
				case 'B':	TIMER2_TBMR_R	 = ( TIMER2_TBMR_R & 0xFF8 )	| 0x007 ; break;
				default: break;
			}
			break;
		}
		case 3: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER3_TAMR_R	 = ( TIMER3_TAMR_R & 0xFF8 )	| 0x007 ; break;
				case 'B':	TIMER3_TBMR_R	 = ( TIMER3_TBMR_R & 0xFF8 )	| 0x007 ; break;
				default: break;
			}
			break;
		}
		case 4: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER4_TAMR_R	 = ( TIMER4_TAMR_R & 0xFF8 )	| 0x007 ; break;
				case 'B':	TIMER4_TBMR_R	 = ( TIMER4_TBMR_R & 0xFF8 )	| 0x007 ; break;
				default: break;
			}
			break;
		}
		case 5: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER5_TAMR_R	 = ( TIMER5_TAMR_R & 0xFF8 )	| 0x007 ; break;
				case 'B':	TIMER5_TBMR_R	 = ( TIMER5_TBMR_R & 0xFF8 )	| 0x007 ; break;
				default: break;
			}
			break;
		}
		default:	break;
	}
}

void set_PWM(uint8_t timer_number,char channel_name)
{
	
	switch ( timer_number)
	{
		case 0: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER0_TAMR_R	 = (TIMER0_TAMR_R & 0xFF0) | ( 0x00A);	TIMER0_CTL_R	&= ~(1<<6); break;
				case 'B':	TIMER0_TBMR_R	 = (TIMER0_TBMR_R & 0xFF0) | ( 0x00A); 	TIMER0_CTL_R	&= ~(1<<14); break;
				default: break;
			}
			break;
		}
		case 1: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER1_TAMR_R	 = (TIMER1_TAMR_R & 0xFF0) | ( 0x00A); TIMER1_CTL_R	&= ~(1<<6); break;
				case 'B':	TIMER1_TBMR_R	 = (TIMER1_TBMR_R & 0xFF0) | ( 0x00A); TIMER1_CTL_R	&= ~(1<<14); break;
				default: break;
			}
			break;
		}
		case 2: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER2_TAMR_R	 = (TIMER2_TAMR_R & 0xFF0) | ( 0x00A); TIMER2_CTL_R	&= ~(1<<6); break;
				case 'B':	TIMER2_TBMR_R	 = (TIMER2_TBMR_R & 0xFF0) | ( 0x00A); TIMER2_CTL_R	&= ~(1<<14); break;
				default: break;
			}
			break;
		}
		case 3: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER3_TAMR_R	 = (TIMER3_TAMR_R & 0xFF0) | ( 0x00A); TIMER3_CTL_R	&= ~(1<<6); break;
				case 'B':	TIMER3_TBMR_R	 = (TIMER3_TBMR_R & 0xFF0) | ( 0x00A); TIMER3_CTL_R	&= ~(1<<14); break;
				default: break;
			}
			break;
		}
		case 4: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER4_TAMR_R	 = (TIMER4_TAMR_R & 0xFF0) | ( 0x00A); TIMER4_CTL_R	&= ~(1<<6); break;
				case 'B':	TIMER4_TBMR_R	 = (TIMER4_TBMR_R & 0xFF0) | ( 0x00A); TIMER4_CTL_R	&= ~(1<<14); break;
				default: break;
			}
			break;
		}
		case 5: 
		{
			switch ( channel_name )
			{
				case 'A':	TIMER5_TAMR_R	 = (TIMER5_TAMR_R & 0xFF0) | ( 0x00A); TIMER5_CTL_R	&= ~(1<<6); break;
				case 'B':	TIMER5_TBMR_R	 = (TIMER5_TBMR_R & 0xFF0) | ( 0x00A); TIMER5_CTL_R	&= ~(1<<14); break;
				default: break;
			}
			break;
		}
		default:	break;
	}
}

void set_event(uint8_t timer_number,char channel_name,event capture_edge)
{
	switch (timer_number)
	{
		case 0: 
		{
			switch (channel_name)
			{
				case 'A':
				{		if (capture_edge == POSITIVE_EDGE)
									TIMER0_CTL_R	= ( TIMER0_CTL_R & 0xFFF3) | ( 0 << 2);
						else if (capture_edge  == NEGATIVE_EDGE)
									TIMER0_CTL_R	= ( TIMER0_CTL_R & 0xFFF3) | ( 1 << 2);
						else if (capture_edge  == BOTH_EDGES)
									TIMER0_CTL_R	= ( TIMER0_CTL_R & 0xFFF3) | ( 3 << 2);
						else 					// NONE
							break;
						break;
				}
				case 'B':
				{		if (capture_edge == POSITIVE_EDGE)
									TIMER0_CTL_R	= ( TIMER0_CTL_R & 0xF3FF) | ( 0 << 10);
						else if (capture_edge  == NEGATIVE_EDGE)
									TIMER0_CTL_R	= ( TIMER0_CTL_R & 0xF3FF) | ( 1 << 10);
						else if (capture_edge  == BOTH_EDGES)
									TIMER0_CTL_R	= ( TIMER0_CTL_R & 0xF3FF) | ( 3 << 10);
						else 					// NONE
							break;
						break;
				}
				default: break;
			}
			break;
		}
		
		case 1: 
		{
			switch (channel_name)
			{
				case 'A':
				{		if (capture_edge == POSITIVE_EDGE)
									TIMER1_CTL_R	= ( TIMER1_CTL_R & 0xFFF3) | ( 0 << 2);
						else if (capture_edge  == NEGATIVE_EDGE)
									TIMER1_CTL_R	= ( TIMER1_CTL_R & 0xFFF3) | ( 1 << 2);
						else if (capture_edge  == BOTH_EDGES)
									TIMER1_CTL_R	= ( TIMER1_CTL_R & 0xFFF3) | ( 3 << 2);
						else 					// NONE
							break;
						break;
				}
				case 'B':
				{		if (capture_edge == POSITIVE_EDGE)
									TIMER1_CTL_R	= ( TIMER1_CTL_R & 0xF3FF) | ( 0 << 10);
						else if (capture_edge  == NEGATIVE_EDGE)
									TIMER1_CTL_R	= ( TIMER1_CTL_R & 0xF3FF) | ( 1 << 10);
						else if (capture_edge  == BOTH_EDGES)
									TIMER1_CTL_R	= ( TIMER1_CTL_R & 0xF3FF) | ( 3 << 10);
						else 					// NONE
							break;
						break;
				}
				default: break;
			}
			break;
		}
		
		case 2: 
		{
			switch (channel_name)
			{
				case 'A':
				{		if (capture_edge == POSITIVE_EDGE)
									TIMER2_CTL_R	= ( TIMER2_CTL_R & 0xFFF3) | ( 0 << 2);
						else if (capture_edge  == NEGATIVE_EDGE)
									TIMER2_CTL_R	= ( TIMER2_CTL_R & 0xFFF3) | ( 1 << 2);
						else if (capture_edge  == BOTH_EDGES)
									TIMER2_CTL_R	= ( TIMER2_CTL_R & 0xFFF3) | ( 3 << 2);
						else 					// NONE
							break;
						break;
				}
				case 'B':
				{		if (capture_edge == POSITIVE_EDGE)
									TIMER2_CTL_R	= ( TIMER2_CTL_R & 0xF3FF) | ( 0 << 10);
						else if (capture_edge  == NEGATIVE_EDGE)
									TIMER2_CTL_R	= ( TIMER2_CTL_R & 0xF3FF) | ( 1 << 10);
						else if (capture_edge  == BOTH_EDGES)
									TIMER2_CTL_R	= ( TIMER2_CTL_R & 0xF3FF) | ( 3 << 10);
						else 					// NONE
							break;
						break;
				}
				default: break;
			}
			break;
		}
		
		case 3: 
		{
			switch (channel_name)
			{
				case 'A':
				{		if (capture_edge == POSITIVE_EDGE)
									TIMER3_CTL_R	= ( TIMER3_CTL_R & 0xFFF3) | ( 0 << 2);
						else if (capture_edge  == NEGATIVE_EDGE)
									TIMER3_CTL_R	= ( TIMER3_CTL_R & 0xFFF3) | ( 1 << 2);
						else if (capture_edge  == BOTH_EDGES)
									TIMER3_CTL_R	= ( TIMER3_CTL_R & 0xFFF3) | ( 3 << 2);
						else 					// NONE
							break;
						break;
				}
				case 'B':
				{		if (capture_edge == POSITIVE_EDGE)
									TIMER3_CTL_R	= ( TIMER3_CTL_R & 0xF3FF) | ( 0 << 10);
						else if (capture_edge  == NEGATIVE_EDGE)
									TIMER3_CTL_R	= ( TIMER3_CTL_R & 0xF3FF) | ( 1 << 10);
						else if (capture_edge  == BOTH_EDGES)
									TIMER3_CTL_R	= ( TIMER3_CTL_R & 0xF3FF) | ( 3 << 10);
						else 					// NONE
							break;
						break;
				}
				default: break;
			}
			break;
		}
		
		case 4: 
		{
			switch (channel_name)
			{
				case 'A':
				{		if (capture_edge == POSITIVE_EDGE)
									TIMER4_CTL_R	= ( TIMER4_CTL_R & 0xFFF3) | ( 0 << 2);
						else if (capture_edge  == NEGATIVE_EDGE)
									TIMER4_CTL_R	= ( TIMER4_CTL_R & 0xFFF3) | ( 1 << 2);
						else if (capture_edge  == BOTH_EDGES)
									TIMER4_CTL_R	= ( TIMER4_CTL_R & 0xFFF3) | ( 3 << 2);
						else 					// NONE
							break;
						break;
				}
				case 'B':
				{		if (capture_edge == POSITIVE_EDGE)
									TIMER4_CTL_R	= ( TIMER4_CTL_R & 0xF3FF) | ( 0 << 10);
						else if (capture_edge  == NEGATIVE_EDGE)
									TIMER4_CTL_R	= ( TIMER4_CTL_R & 0xF3FF) | ( 1 << 10);
						else if (capture_edge  == BOTH_EDGES)
									TIMER4_CTL_R	= ( TIMER4_CTL_R & 0xF3FF) | ( 3 << 10);
						else 					// NONE
							break;
						break;
				}
				default: break;
			}
			break;
		}
		
		case 5: 
		{
			switch (channel_name)
			{
				case 'A':
				{		if (capture_edge == POSITIVE_EDGE)
									TIMER5_CTL_R	= ( TIMER5_CTL_R & 0xFFF3) | ( 0 << 2);
						else if (capture_edge  == NEGATIVE_EDGE)
									TIMER5_CTL_R	= ( TIMER5_CTL_R & 0xFFF3) | ( 1 << 2);
						else if (capture_edge  == BOTH_EDGES)
									TIMER5_CTL_R	= ( TIMER5_CTL_R & 0xFFF3) | ( 3 << 2);
						else 					// NONE
							break;
						break;
				}
				case 'B':
				{		if (capture_edge == POSITIVE_EDGE)
									TIMER5_CTL_R	= ( TIMER5_CTL_R & 0xF3FF) | ( 0 << 10);
						else if (capture_edge  == NEGATIVE_EDGE)
									TIMER5_CTL_R	= ( TIMER5_CTL_R & 0xF3FF) | ( 1 << 10);
						else if (capture_edge  == BOTH_EDGES)
									TIMER5_CTL_R	= ( TIMER5_CTL_R & 0xF3FF) | ( 3 << 10);
						else 					// NONE
							break;
						break;
				}
				default: break;
			}
			break;
		}
		default: break;
	}
	
}


void set_output_ccp(uint8_t	timer_number,char channel_name)
{
	switch (timer_number)
	{
		case 0:
		{
			switch (channel_name)
			{
				case 'A':	/*initialize_pin('B',6,OUTPUT);		set_pin_alternative_function('B',6,7);*/	initialize_pin('F',0,OUTPUT);		set_pin_alternative_function('F',0,7);		break;
				case 'B':	/*initialize_pin('B',7,OUTPUT);		set_pin_alternative_function('B',7,7);*/	initialize_pin('F',1,OUTPUT);		set_pin_alternative_function('F',1,7);	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch (channel_name)
			{
				case 'A':	/*initialize_pin('B',4,OUTPUT);		set_pin_alternative_function('B',4,7);*/	initialize_pin('F',2,OUTPUT);		set_pin_alternative_function('F',2,7);	break;
				case 'B':	/*initialize_pin('B',5,OUTPUT);		set_pin_alternative_function('B',5,7);*/	initialize_pin('F',3,OUTPUT);		set_pin_alternative_function('F',3,7);	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch (channel_name)
			{
				case 'A':	/*initialize_pin('B',0,OUTPUT);		set_pin_alternative_function('B',0,7);*/	initialize_pin('F',4,OUTPUT);		set_pin_alternative_function('F',4,7);	break;
				case 'B':	initialize_pin('B',1,OUTPUT);		set_pin_alternative_function('B',1,7);		break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch (channel_name)
			{
				case 'A':	initialize_pin('B',2,OUTPUT);		set_pin_alternative_function('B',2,7);		break;
				case 'B':	initialize_pin('B',3,OUTPUT);		set_pin_alternative_function('B',3,7);		break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch (channel_name)
			{
				case 'A':	initialize_pin('C',0,OUTPUT);		set_pin_alternative_function('C',0,7);		break;
				case 'B':	initialize_pin('C',1,OUTPUT);		set_pin_alternative_function('C',1,7);		break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch (channel_name)
			{
				case 'A':	initialize_pin('C',2,OUTPUT);		set_pin_alternative_function('C',2,7);		break;
				case 'B':	initialize_pin('C',3,OUTPUT);		set_pin_alternative_function('C',3,7);		break;
				default: break;
			}
			break;
		}
		default: break;
	}
}

void set_input_ccp(uint8_t	timer_number,char channel_name)
{
	switch (timer_number)
	{
		case 0:
		{
			switch (channel_name)
			{
				case 'A':	/*initialize_pin('B',6,INPUT);		set_pin_alternative_function('B',6,7);*/	initialize_pin('F',0,INPUT);		set_pin_alternative_function('F',0,7);		break;
				case 'B':	/*initialize_pin('B',7,INPUT);		set_pin_alternative_function('B',7,7);*/	initialize_pin('F',1,INPUT);		set_pin_alternative_function('F',1,7);	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch (channel_name)
			{
				case 'A':	/*initialize_pin('B',4,INPUT);		set_pin_alternative_function('B',4,7);*/	initialize_pin('F',2,INPUT);		set_pin_alternative_function('F',2,7);	break;
				case 'B':	/*initialize_pin('B',5,INPUT);		set_pin_alternative_function('B',5,7);*/	initialize_pin('F',3,INPUT);		set_pin_alternative_function('F',3,7);	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch (channel_name)
			{
				case 'A':	/*initialize_pin('B',0,INPUT);		set_pin_alternative_function('B',0,7);*/	initialize_pin('F',4,INPUT);		set_pin_alternative_function('F',4,7);	break;
				case 'B':	initialize_pin('B',1,INPUT);		set_pin_alternative_function('B',1,7);		break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch (channel_name)
			{
				case 'A':	initialize_pin('B',2,INPUT);		set_pin_alternative_function('B',2,7);		break;
				case 'B':	initialize_pin('B',3,INPUT);		set_pin_alternative_function('B',3,7);		break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch (channel_name)
			{
				case 'A':	initialize_pin('C',0,INPUT);		set_pin_alternative_function('C',0,7);		break;
				case 'B':	initialize_pin('C',1,INPUT);		set_pin_alternative_function('C',1,7);		break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch (channel_name)
			{
				case 'A':	initialize_pin('C',2,INPUT);		set_pin_alternative_function('C',2,7);		break;
				case 'B':	initialize_pin('C',3,INPUT);		set_pin_alternative_function('C',3,7);		break;
				default: break;
			}
			break;
		}
		default: break;
	}
}


void set_timer_interval(uint8_t	timer_number,char channel_name, uint16_t load_value)
{
	switch ( timer_number)
	{
		case 0:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER0_TAILR_R = load_value;	break;
				case 'B' : TIMER0_TBILR_R = load_value;	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER1_TAILR_R = load_value;	break;
				case 'B' : TIMER1_TBILR_R = load_value;	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER2_TAILR_R = load_value;	break;
				case 'B' : TIMER2_TBILR_R = load_value;	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER3_TAILR_R = load_value;	break;
				case 'B' : TIMER3_TBILR_R = load_value;	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER4_TAILR_R = load_value;	break;
				case 'B' : TIMER4_TBILR_R = load_value;	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER5_TAILR_R = load_value;	break;
				case 'B' : TIMER5_TBILR_R = load_value;	break;
				default: break;
			}
			break;
		}
		default: break;
	}
}


void set_timer_match(uint8_t	timer_number,char channel_name, uint16_t match_value)
{
	switch ( timer_number)
	{
		case 0:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER0_TAMATCHR_R = match_value;	break;
				case 'B' : TIMER0_TBMATCHR_R = match_value;	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER1_TAMATCHR_R = match_value;	break;
				case 'B' : TIMER1_TBMATCHR_R = match_value;	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER2_TAMATCHR_R = match_value;	break;
				case 'B' : TIMER2_TBMATCHR_R = match_value;	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER3_TAMATCHR_R = match_value;	break;
				case 'B' : TIMER3_TBMATCHR_R = match_value;	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER4_TAMATCHR_R = match_value;	break;
				case 'B' : TIMER4_TBMATCHR_R = match_value;	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER5_TAMATCHR_R = match_value;	break;
				case 'B' : TIMER5_TBMATCHR_R = match_value;	break;
				default: break;
			}
			break;
		}
		default: break;
	}
}

void set_timer_prescaler(uint8_t	timer_number,char channel_name, uint8_t prescaler_value)
{
	switch ( timer_number)
	{
		case 0:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER0_TAPR_R = prescaler_value;	break;
				case 'B' : TIMER0_TBPR_R = prescaler_value;	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER1_TAPR_R = prescaler_value;	break;
				case 'B' : TIMER1_TBPR_R = prescaler_value;	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER2_TAPR_R = prescaler_value;	break;
				case 'B' : TIMER2_TBPR_R = prescaler_value;	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER3_TAPR_R = prescaler_value;	break;
				case 'B' : TIMER3_TBPR_R = prescaler_value;	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER4_TAPR_R = prescaler_value;	break;
				case 'B' : TIMER4_TBPR_R = prescaler_value;	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER5_TAPR_R = prescaler_value;	break;
				case 'B' : TIMER5_TBPR_R = prescaler_value;	break;
				default: break;
			}
			break;
		}
		default: break;
	}
}


void set_timer_prescaler_match(uint8_t	timer_number,char channel_name, uint8_t prescaler_match_value)
{
	switch ( timer_number)
	{
		case 0:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER0_TAPMR_R = prescaler_match_value;	break;
				case 'B' : TIMER0_TBPMR_R = prescaler_match_value;	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER1_TAPMR_R = prescaler_match_value;	break;
				case 'B' : TIMER1_TBPMR_R = prescaler_match_value;	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER2_TAPMR_R = prescaler_match_value;	break;
				case 'B' : TIMER2_TBPMR_R = prescaler_match_value;	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER3_TAPMR_R = prescaler_match_value;	break;
				case 'B' : TIMER3_TBPMR_R = prescaler_match_value;	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER4_TAPMR_R = prescaler_match_value;	break;
				case 'B' : TIMER4_TBPMR_R = prescaler_match_value;	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch ( channel_name )
			{
				case 'A' : TIMER5_TAPMR_R = prescaler_match_value;	break;
				case 'B' : TIMER5_TBPMR_R = prescaler_match_value;	break;
				default: break;
			}
			break;
		}
		default: break;
	}
}


void up_counting(uint8_t	timer_number,char channel_name)
{
	switch ( timer_number)
	{
		case 0:
		{
			switch ( channel_name)
			{
				case 'A': TIMER0_TAMR_R |= (1<<4);	break;
				case 'B': TIMER0_TBMR_R |= (1<<4);	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch ( channel_name)
			{
				case 'A': TIMER1_TAMR_R |= (1<<4);	break;
				case 'B': TIMER1_TBMR_R |= (1<<4);	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch ( channel_name)
			{
				case 'A': TIMER2_TAMR_R |= (1<<4);	break;
				case 'B': TIMER2_TBMR_R |= (1<<4);	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch ( channel_name)
			{
				case 'A': TIMER3_TAMR_R |= (1<<4);	break;
				case 'B': TIMER3_TBMR_R |= (1<<4);	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch ( channel_name)
			{
				case 'A': TIMER4_TAMR_R |= (1<<4);	break;
				case 'B': TIMER4_TBMR_R |= (1<<4);	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch ( channel_name)
			{
				case 'A': TIMER5_TAMR_R |= (1<<4);	break;
				case 'B': TIMER5_TBMR_R |= (1<<4);	break;
				default: break;
			}
			break;
		}
		default: break;

	}
}

void down_counting(uint8_t	timer_number,char channel_name)
{
	switch ( timer_number)
	{
		case 0:
		{
			switch ( channel_name)
			{
				case 'A': TIMER0_TAMR_R &=~ (1<<4);	break;
				case 'B': TIMER0_TBMR_R &=~ (1<<4);	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch ( channel_name)
			{
				case 'A': TIMER1_TAMR_R &=~ (1<<4);	break;
				case 'B': TIMER1_TBMR_R &=~ (1<<4);	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch ( channel_name)
			{
				case 'A': TIMER2_TAMR_R &=~ (1<<4);	break;
				case 'B': TIMER2_TBMR_R &=~ (1<<4);	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch ( channel_name)
			{
				case 'A': TIMER3_TAMR_R &=~ (1<<4);	break;
				case 'B': TIMER3_TBMR_R &=~ (1<<4);	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch ( channel_name)
			{
				case 'A': TIMER4_TAMR_R &=~ (1<<4);	break;
				case 'B': TIMER4_TBMR_R &=~ (1<<4);	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch ( channel_name)
			{
				case 'A': TIMER5_TAMR_R &=~ (1<<4);	break;
				case 'B': TIMER5_TBMR_R &=~ (1<<4);	break;
				default: break;
			}
			break;
		}
		default: break;

	}
}


void	timer_init(uint8_t	timer_number,char channel_name, direction timer_direction, mode timer_mode, event capture_edge, status interrupt1_status, status interrupt2_status, uint8_t interrupt_priority)
{
	SYSCTL_RCGCTIMER_R	|= (1<< timer_number);
	while	( ! (SYSCTL_PRTIMER_R & (1<< timer_number) ) );	
	
	if ( channel_name	== 'A'  || channel_name	== 'B' )	// INDIVIDUAL
	{
			disable_timer(timer_number,channel_name);
		
			if ( interrupt1_status	== ENABLED	|| interrupt2_status == ENABLED)
					enable_timer_interrupt(timer_number,channel_name,interrupt_priority);
			
			config_half_timer(timer_number);
		
		if (timer_mode == ONE_SHOT)
		{
			set_one_shot_timer(timer_number,channel_name);
			if (interrupt1_status == ENABLED)
			{
				enable_timeout_interrupt(timer_number,channel_name);
			}
			if (interrupt2_status == ENABLED)
			{
				enable_match_interrupt(timer_number,channel_name);
			}
		}
			
		else if( timer_mode == PERIODIC)
		{
			set_periodic_timer(timer_number,channel_name);
			if (interrupt1_status == ENABLED)
			{
				enable_timeout_interrupt(timer_number,channel_name);
			}
			if (interrupt2_status == ENABLED)
			{
				enable_match_interrupt(timer_number,channel_name);
			}
		}
		
		else if( timer_mode == EDGE_COUNT)
		{
			set_edge_count(timer_number,channel_name);
			set_event(timer_number,channel_name,capture_edge);
			set_input_ccp(timer_number,channel_name);
			if (interrupt1_status == ENABLED)
			{
				enable_edge_count_interrupt(timer_number,channel_name);
			}
		}
		else if(timer_mode == EDGE_TIME)
		{
			set_edge_time(timer_number,channel_name);
			set_event(timer_number,channel_name,capture_edge);
			set_input_ccp(timer_number,channel_name);
			if (interrupt1_status == ENABLED)
			{
				enable_edge_time_interrupt(timer_number,channel_name);
			}
		}
		else if ( timer_mode == PWM)
		{
			set_PWM(timer_number,channel_name);
			set_output_ccp(timer_number,channel_name);
		}
			
		
		if (timer_direction == UP)
			up_counting(timer_number,channel_name);
		else	//down
			down_counting(timer_number,channel_name);

	}
	
		
	else			// CONCATINATED
	{
		disable_timer(timer_number,'A');
		
		if ( interrupt1_status	== ENABLED	|| interrupt2_status	== ENABLED)
				enable_timer_interrupt(timer_number,'A',interrupt_priority);
		
		if (timer_mode == RTC)
		{
			config_RTC(timer_number);
			enable_RTC_interrupt(timer_number);
		}
			
		
		else			// ONE_SHOT OR PERIODIC
		{
			config_full_timer(timer_number);
			
			if (timer_mode == ONE_SHOT)
			{
				set_one_shot_timer(timer_number,'A');
				if (interrupt1_status == ENABLED)
				{
					enable_timeout_interrupt(timer_number,'A');
				}
				if (interrupt2_status == ENABLED)
				{
					enable_match_interrupt(timer_number,'A');
				}
			}
			
		else if( timer_mode == PERIODIC)
			{
				set_periodic_timer(timer_number,'A');
				if (interrupt1_status == ENABLED)
				{
					enable_timeout_interrupt(timer_number,'A');
				}
				if (interrupt2_status == ENABLED)
				{
					enable_match_interrupt(timer_number,'A');
				}
			}
			
			if (timer_direction == UP)
				up_counting(timer_number,'A');
			else	//down
				down_counting(timer_number,'A');
		}

	}
	
}

void  run_timer(uint8_t	timer_number,char channel_name, uint32_t load_value, uint32_t match_value, uint8_t prescaler_value, uint8_t prescaler_match_value)
{
	
	if ( channel_name	== 'A'  || channel_name	== 'B' )	// INDIVIDUAL
	{
		set_timer_interval(timer_number,channel_name,load_value);
		
		if (match_value)
			set_timer_match(timer_number,channel_name,match_value);
		
		if (prescaler_value)
			set_timer_prescaler(timer_number,channel_name,prescaler_value);
		
		if (prescaler_match_value)
			set_timer_prescaler_match(timer_number,channel_name,prescaler_match_value);
		
		enable_timer(timer_number,channel_name);
	}
	
		
	else			// CONCATINATED
	{
			
			
			set_timer_interval(timer_number,'B',load_value >> 16);
			delayUs(3);			//make sure timer B is loaded
			set_timer_interval(timer_number,'A',load_value);

			
			if (match_value)
			{
				set_timer_match(timer_number,'B',match_value >> 16);
				delayUs(3);			//make sure timer B is loaded
				set_timer_match(timer_number,'A',match_value);
			}
			

		
		enable_timer(timer_number,'A');
	}

	
}



void wait_for_timeout(uint8_t	timer_number,char channel_name)
{
	switch (timer_number)
	{
		case 0:
		{
			switch ( channel_name)
			{
				case 'A': while (! (TIMER0_RIS_R	& (1<<0) ) );	TIMER0_ICR_R |= (1<<0);  break;
				case 'B':	while (! (TIMER0_RIS_R	& (1<<8) ) );	TIMER0_ICR_R |= (1<<8);  break;
				default: 	while (! (TIMER0_RIS_R	& (1<<0) ) );	TIMER0_ICR_R |= (1<<0);  break;
			}
			break;
		}
		
		case 1:
		{
			switch ( channel_name)
			{
				case 'A': while (! (TIMER1_RIS_R	& (1<<0) ) );	TIMER1_ICR_R |= (1<<0);  break;
				case 'B':	while (! (TIMER1_RIS_R	& (1<<8) ) );	TIMER1_ICR_R |= (1<<8);  break;
				default: 	while (! (TIMER1_RIS_R	& (1<<0) ) );	TIMER1_ICR_R |= (1<<0);  break;
			}
			break;
		}
		
		case 2:
		{
			switch ( channel_name)
			{
				case 'A': while (! (TIMER2_RIS_R	& (1<<0) ) );	TIMER2_ICR_R |= (1<<0);  break;
				case 'B':	while (! (TIMER2_RIS_R	& (1<<8) ) );	TIMER2_ICR_R |= (1<<8);  break;
				default: 	while (! (TIMER2_RIS_R	& (1<<0) ) );	TIMER2_ICR_R |= (1<<0);  break;
			}
			break;
		}
		
		case 3:
		{
			switch ( channel_name)
			{
				case 'A': while (! (TIMER3_RIS_R	& (1<<0) ) );	TIMER3_ICR_R |= (1<<0);  break;
				case 'B':	while (! (TIMER3_RIS_R	& (1<<8) ) );	TIMER3_ICR_R |= (1<<8);  break;
				default: 	while (! (TIMER3_RIS_R	& (1<<0) ) );	TIMER3_ICR_R |= (1<<0);  break;
			}
			break;
		}
		
		case 4:
		{
			switch ( channel_name)
			{
				case 'A': while (! (TIMER4_RIS_R	& (1<<0) ) );	TIMER4_ICR_R |= (1<<0);  break;
				case 'B':	while (! (TIMER4_RIS_R	& (1<<8) ) );	TIMER4_ICR_R |= (1<<8);  break;
				default: 	while (! (TIMER4_RIS_R	& (1<<0) ) );	TIMER4_ICR_R |= (1<<0);  break;
			}
			break;
		}
		
		case 5:
		{
			switch ( channel_name)
			{
				case 'A': while (! (TIMER5_RIS_R	& (1<<0) ) );	TIMER5_ICR_R |= (1<<0);  break;
				case 'B':	while (! (TIMER5_RIS_R	& (1<<8) ) );	TIMER5_ICR_R |= (1<<8);  break;
				default: 	while (! (TIMER5_RIS_R	& (1<<0) ) );	TIMER5_ICR_R |= (1<<0);  break;
			}
			break;
		}
		default: break;
	}
}


void wait_for_last_edge(uint8_t	timer_number,char channel_name)
{
	switch (timer_number)
	{
		case 0:
		{
			switch ( channel_name)
			{
				case 'A': while (! (TIMER0_RIS_R	& (1<<1) ) );	TIMER0_ICR_R |= (1<<1);  break;
				case 'B':	while (! (TIMER0_RIS_R	& (1<<9) ) );	TIMER0_ICR_R |= (1<<9);  break;
				default : break;
			}
			break;
		}
		
		case 1:
		{
			switch ( channel_name)
			{
				case 'A': while (! (TIMER1_RIS_R	& (1<<1) ) );	TIMER1_ICR_R |= (1<<1);  break;
				case 'B':	while (! (TIMER1_RIS_R	& (1<<9) ) );	TIMER1_ICR_R |= (1<<9);  break;
				default : break;
			}
			break;
		}
		
		case 2:
		{
			switch ( channel_name)
			{
				case 'A': while (! (TIMER2_RIS_R	& (1<<1) ) );	TIMER2_ICR_R |= (1<<1);  break;
				case 'B':	while (! (TIMER2_RIS_R	& (1<<9) ) );	TIMER2_ICR_R |= (1<<9);  break;
				default : break;
			}
			break;
		}
		
		case 3:
		{
			switch ( channel_name)
			{
				case 'A': while (! (TIMER3_RIS_R	& (1<<1) ) );	TIMER3_ICR_R |= (1<<1);  break;
				case 'B':	while (! (TIMER3_RIS_R	& (1<<9) ) );	TIMER3_ICR_R |= (1<<9);  break;
				default : break;
			}
			break;
		}
		
		case 4:
		{
			switch ( channel_name)
			{
				case 'A': while (! (TIMER4_RIS_R	& (1<<1) ) );	TIMER4_ICR_R |= (1<<1);  break;
				case 'B':	while (! (TIMER4_RIS_R	& (1<<9) ) );	TIMER4_ICR_R |= (1<<9);  break;
				default : break;
			}
			break;
		}
		
		case 5:
		{
			switch ( channel_name)
			{
				case 'A': while (! (TIMER5_RIS_R	& (1<<1) ) );	TIMER5_ICR_R |= (1<<1);  break;
				case 'B':	while (! (TIMER5_RIS_R	& (1<<9) ) );	TIMER5_ICR_R |= (1<<9);  break;
				default : break;
			}
			break;
		}
		default: break;
	}
}

void wait_for_event(uint8_t	timer_number,char channel_name)
{
	switch (timer_number)
	{
		case 0:
		{
			switch ( channel_name)
			{
				case 'A': while (! (TIMER0_RIS_R	& (1<<2) ) );	TIMER0_ICR_R |= (1<<2);  break;
				case 'B':	while (! (TIMER0_RIS_R	& (1<<10) ) );	TIMER0_ICR_R |= (1<<10);  break;
				default : break;
			}
			break;
		}
		
		case 1:
		{
			switch ( channel_name)
			{
				case 'A': while (! (TIMER1_RIS_R	& (1<<2) ) );	TIMER1_ICR_R |= (1<<2);  break;
				case 'B':	while (! (TIMER1_RIS_R	& (1<<10) ) );	TIMER1_ICR_R |= (1<<10);  break;
				default : break;
			}
			break;
		}
		
		case 2:
		{
			switch ( channel_name)
			{
				case 'A': while (! (TIMER2_RIS_R	& (1<<2) ) );	TIMER2_ICR_R |= (1<<2);  break;
				case 'B':	while (! (TIMER2_RIS_R	& (1<<10) ) );	TIMER2_ICR_R |= (1<<10);  break;
				default : break;
			}
			break;
		}
		
		case 3:
		{
			switch ( channel_name)
			{
				case 'A': while (! (TIMER3_RIS_R	& (1<<2) ) );	TIMER3_ICR_R |= (1<<2);  break;
				case 'B':	while (! (TIMER3_RIS_R	& (1<<10) ) );	TIMER3_ICR_R |= (1<<10);  break;
				default : break;
			}
			break;
		}
		
		case 4:
		{
			switch ( channel_name)
			{
				case 'A': while (! (TIMER4_RIS_R	& (1<<2) ) );	TIMER4_ICR_R |= (1<<2);  break;
				case 'B':	while (! (TIMER4_RIS_R	& (1<<10) ) );	TIMER4_ICR_R |= (1<<10);  break;
				default : break;
			}
			break;
		}
		
		case 5:
		{
			switch ( channel_name)
			{
				case 'A': while (! (TIMER5_RIS_R	& (1<<2) ) );	TIMER5_ICR_R |= (1<<2);  break;
				case 'B':	while (! (TIMER5_RIS_R	& (1<<10) ) );	TIMER5_ICR_R |= (1<<10);  break;
				default : break;
			}
			break;
		}
		default: break;
	}
}


uint32_t detect_event_time(uint8_t	timer_number,char channel_name)
{
	switch (timer_number)
	{
		case 0:
		{
			switch ( channel_name)
			{
				case 'A': return TIMER0_TAR_R;
				case 'B': return TIMER0_TBR_R;
				default : return 0xFFFFFFFF;
			}
			
		}
		
		case 1:
		{
			switch ( channel_name)
			{
				case 'A': return TIMER1_TAR_R;
				case 'B': return TIMER1_TBR_R;
				default : return 0xFFFFFFFF;
			}
			
		}
		
		case 2:
		{
			switch ( channel_name)
			{
				case 'A': return TIMER2_TAR_R;
				case 'B': return TIMER2_TBR_R;
				default : return 0xFFFFFFFF;
			}
			
		}
		
		case 3:
		{
			switch ( channel_name)
			{
				case 'A': return TIMER3_TAR_R;
				case 'B': return TIMER3_TBR_R;
				default : return 0xFFFFFFFF;
			}
			
		}
		
		case 4:
		{
			switch ( channel_name)
			{
				case 'A': return TIMER4_TAR_R;
				case 'B': return TIMER4_TBR_R;
				default : return 0xFFFFFFFF;
			}
			
		}
		
		case 5:
		{
			switch ( channel_name)
			{
				case 'A': return TIMER5_TAR_R;
				case 'B': return TIMER5_TBR_R;
				default : return 0xFFFFFFFF;
			}
			
		}
		default: return 0xFFFFFFFF;
	}
}




// 32/64 general purpose timers

void disable_wide_timer(uint8_t	wide_timer_number, char channel_name)
{
	switch ( wide_timer_number)
	{
		case 0: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER0_CTL_R &= ~(1<<0); break;
				case 'B':	WTIMER0_CTL_R &= ~(1<<8); break;
				default : WTIMER0_CTL_R &= ~(1<<0); break;
			}
			break;
		}
		case 1: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER1_CTL_R &= ~(1<<0); break;
				case 'B':	WTIMER1_CTL_R &= ~(1<<8); break;
				default : WTIMER1_CTL_R &= ~(1<<0); break;
			}
			break;
		}
		case 2: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER2_CTL_R &= ~(1<<0); break;
				case 'B':	WTIMER2_CTL_R &= ~(1<<8); break;
				default : WTIMER2_CTL_R &= ~(1<<0); break;
			}
			break;
		}
		case 3: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER3_CTL_R &= ~(1<<0); break;
				case 'B':	WTIMER3_CTL_R &= ~(1<<8); break;
				default : WTIMER3_CTL_R &= ~(1<<0); break;
			}
			break;
		}
		case 4: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER4_CTL_R &= ~(1<<0); break;
				case 'B':	WTIMER4_CTL_R &= ~(1<<8); break;
				default : WTIMER4_CTL_R &= ~(1<<0); break;
			}
			break;
		}
		case 5: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER5_CTL_R &= ~(1<<0); break;
				case 'B':	WTIMER5_CTL_R &= ~(1<<8); break;
				default : WTIMER5_CTL_R &= ~(1<<0); break;
			}
			break;
		}
		default:	break;
	}
}

void enable_wide_timer(uint8_t	wide_timer_number, char channel_name)
{
	switch ( wide_timer_number)
	{
		case 0: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER0_CTL_R |= (1<<0); break;
				case 'B':	WTIMER0_CTL_R |= (1<<8); break;
				default : WTIMER0_CTL_R |= (1<<0); break;
			}
			break;
		}
		case 1: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER1_CTL_R |= (1<<0); break;
				case 'B':	WTIMER1_CTL_R |= (1<<8); break;
				default : WTIMER1_CTL_R |= (1<<0); break;
			}
			break;
		}
		case 2: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER2_CTL_R |= (1<<0); break;
				case 'B':	WTIMER2_CTL_R |= (1<<8); break;
				default : WTIMER2_CTL_R |= (1<<0); break;
			}
			break;
		}
		case 3: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER3_CTL_R |= (1<<0); break;
				case 'B':	WTIMER3_CTL_R |= (1<<8); break;
				default : WTIMER3_CTL_R |= (1<<0); break;
			}
			break;
		}
		case 4: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER4_CTL_R |= (1<<0); break;
				case 'B':	WTIMER4_CTL_R |= (1<<8); break;
				default : WTIMER4_CTL_R |= (1<<0); break;
			}
			break;
		}
		case 5: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER5_CTL_R |= (1<<0); break;
				case 'B':	WTIMER5_CTL_R |= (1<<8); break;
				default : WTIMER5_CTL_R |= (1<<0); break;
			}
			break;
		}
		default:	break;
	}
}
void enable_wide_timer_interrupt(uint8_t	wide_timer_number,char channel_name, uint8_t interrupt_priority)
{
	switch (wide_timer_number)
	{
		case 0:
		{
			WTIMER0_ICR_R	= 0xFFF;
			switch (channel_name)
			{
				case 'A': NVIC_EN2_R	|= (1<<30);		NVIC_PRI23_R	= (NVIC_PRI23_R & 0xFF00FFFF) | ( interrupt_priority << 21);			break;
				case 'B':	NVIC_EN2_R	|= 0x80000000;		NVIC_PRI23_R	= (NVIC_PRI23_R & 0x00FFFFFF) | ( interrupt_priority << 29);			break;
				default: break;
			}
			break;
		}
		case 1:
		{
			WTIMER1_ICR_R	= 0xFFF;
			switch (channel_name)
			{
				case 'A': NVIC_EN3_R	|= (1<<0);		NVIC_PRI24_R	= (NVIC_PRI24_R & 0xFFFFFF00) | ( interrupt_priority << 5);			break;
				case 'B':	NVIC_EN3_R	|= (1<<1);		NVIC_PRI24_R	= (NVIC_PRI24_R & 0xFFFF00FF) | ( interrupt_priority << 13);		break;
				default: break;
			}
			break;
		}
		case 2:
		{
			WTIMER2_ICR_R	= 0xFFF;
			switch (channel_name)
			{
				case 'A': NVIC_EN3_R	|= (1<<2);		NVIC_PRI24_R	= (NVIC_PRI24_R & 0xFF00FFFF) | ( interrupt_priority << 21);		break;
				case 'B':	NVIC_EN3_R	|= (1<<3);		NVIC_PRI24_R	= (NVIC_PRI24_R & 0x00FFFFFF) | ( interrupt_priority << 29);		break;
				default: break;
			}
			break;
		}
		case 3:
		{
			WTIMER3_ICR_R	= 0xFFF;
			switch (channel_name)
			{
				case 'A': NVIC_EN3_R	|= (1<<4);		NVIC_PRI25_R	= (NVIC_PRI25_R & 0xFFFFFF00) | ( interrupt_priority << 5);			break;
				case 'B':	NVIC_EN3_R	|= (1<<5);		NVIC_PRI25_R	= (NVIC_PRI25_R & 0xFFFF00FF) | ( interrupt_priority << 13);			break;
				default: break;
			}
			break;
		}
		case 4:
		{
			WTIMER4_ICR_R	= 0xFFF;
			switch (channel_name)
			{
				case 'A': NVIC_EN3_R	|= (1<<6);		NVIC_PRI25_R	= (NVIC_PRI25_R & 0xFF00FFFF) | ( interrupt_priority << 21);	break;
				case 'B':	NVIC_EN3_R	|= (1<<7);		NVIC_PRI25_R	= (NVIC_PRI25_R & 0x00FFFFFF) | ( interrupt_priority << 29);	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			WTIMER5_ICR_R	= 0xFFF;
			switch (channel_name)
			{
				case 'A': NVIC_EN3_R	|= (1<<8);		NVIC_PRI26_R	= (NVIC_PRI26_R & 0xFFFFFF00) | ( interrupt_priority << 5);		break;
				case 'B':	NVIC_EN3_R	|= (1<<9);		NVIC_PRI26_R	= (NVIC_PRI26_R & 0xFFFF00FF) | ( interrupt_priority << 13);	break;
				default: break;
			}
			break;
		}
		default: break;
	}
}


void enable_wide_timeout_interrupt(uint8_t wide_timer_number,char channel_name)
{
	switch (wide_timer_number)
	{
		case 0:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER0_ICR_R	|= (1<<0);	WTIMER0_IMR_R	|= (1<<0);	break;
				case 'B':	WTIMER0_ICR_R	|= (1<<8);	WTIMER0_IMR_R	|= (1<<8);	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER1_ICR_R	|= (1<<0);	WTIMER1_IMR_R	|= (1<<0);	break;
				case 'B':	WTIMER1_ICR_R	|= (1<<8);	WTIMER1_IMR_R	|= (1<<8);	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER2_ICR_R	|= (1<<0);	WTIMER2_IMR_R	|= (1<<0);	break;
				case 'B':	WTIMER2_ICR_R	|= (1<<8);	WTIMER2_IMR_R	|= (1<<8);	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER3_ICR_R	|= (1<<0);	WTIMER3_IMR_R	|= (1<<0);	break;
				case 'B':	WTIMER3_ICR_R	|= (1<<8);	WTIMER3_IMR_R	|= (1<<8);	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER4_ICR_R	|= (1<<0);	WTIMER4_IMR_R	|= (1<<0);	break;
				case 'B':	WTIMER4_ICR_R	|= (1<<8);	WTIMER4_IMR_R	|= (1<<8);	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER5_ICR_R	|= (1<<0);	WTIMER5_IMR_R	|= (1<<0);	break;
				case 'B':	WTIMER5_ICR_R	|= (1<<8);	WTIMER5_IMR_R	|= (1<<8);	break;
				default: break;
			}
			break;
		}
		default: break;
	}
	__enable_irq();
}

void enable_wide_match_interrupt(uint8_t wide_timer_number,char channel_name)
{
	switch (wide_timer_number)
	{
		case 0:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER0_TAMR_R	|= (1<<5);  WTIMER0_ICR_R	|= (1<<4);	WTIMER0_IMR_R	|= (1<<4);	break;	
				case 'B':	WTIMER0_TBMR_R	|= (1<<5);  WTIMER0_ICR_R	|= (1<<11);	WTIMER0_IMR_R	|= (1<<11);	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER1_TAMR_R	|= (1<<5);  WTIMER1_ICR_R	|= (1<<4);	WTIMER1_IMR_R	|= (1<<4);	break;
				case 'B':	WTIMER1_TBMR_R	|= (1<<5);  WTIMER1_ICR_R	|= (1<<11);	WTIMER1_IMR_R	|= (1<<11);	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER2_TAMR_R	|= (1<<5);  WTIMER2_ICR_R	|= (1<<4);	WTIMER2_IMR_R	|= (1<<4);	break;
				case 'B':	WTIMER2_TBMR_R	|= (1<<5);  WTIMER2_ICR_R	|= (1<<11);	WTIMER2_IMR_R	|= (1<<11);	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER3_TAMR_R	|= (1<<5);  WTIMER3_ICR_R	|= (1<<4);	WTIMER3_IMR_R	|= (1<<4);	break;
				case 'B':	WTIMER3_TBMR_R	|= (1<<5);  WTIMER3_ICR_R	|= (1<<11);	WTIMER3_IMR_R	|= (1<<11);	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER4_TAMR_R	|= (1<<5);  WTIMER4_ICR_R	|= (1<<4);	WTIMER4_IMR_R	|= (1<<4);	break;
				case 'B':	WTIMER4_TBMR_R	|= (1<<5);  WTIMER4_ICR_R	|= (1<<11);	WTIMER4_IMR_R	|= (1<<11);	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER5_TAMR_R	|= (1<<5);  WTIMER5_ICR_R	|= (1<<4);	WTIMER5_IMR_R	|= (1<<4);	break;
				case 'B':	WTIMER5_TBMR_R	|= (1<<5);  WTIMER5_ICR_R	|= (1<<11);	WTIMER5_IMR_R	|= (1<<11);	break;
				default: break;
			}
			break;
		}
		default: break;
	}
	__enable_irq();
}


void enable_wide_RTC_interrupt(uint8_t wide_timer_number)
{
	switch (wide_timer_number)
	{
		case 0: WTIMER0_ICR_R |= (1<<3);	WTIMER0_IMR_R |= (1<<3);	break;
		case 1: WTIMER1_ICR_R |= (1<<3);	WTIMER1_IMR_R |= (1<<3);	break;
		case 2: WTIMER2_ICR_R |= (1<<3);	WTIMER2_IMR_R |= (1<<3);	break;
		case 3: WTIMER3_ICR_R |= (1<<3);	WTIMER3_IMR_R |= (1<<3);	break;
		case 4: WTIMER4_ICR_R |= (1<<3);	WTIMER4_IMR_R |= (1<<3);	break;
		case 5: WTIMER5_ICR_R |= (1<<3);	WTIMER5_IMR_R |= (1<<3);	break;
		default: break;
	}
}

void enable_wide_edge_count_interrupt(uint8_t wide_timer_number,char channel_name)
{
	switch (wide_timer_number)
	{
		case 0:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER0_ICR_R	|= (1<<1);	WTIMER0_IMR_R	|= (1<<1);	break;
				case 'B':	WTIMER0_ICR_R	|= (1<<9);	WTIMER0_IMR_R	|= (1<<9);	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER1_ICR_R	|= (1<<1);	WTIMER1_IMR_R	|= (1<<1);	break;
				case 'B':	WTIMER1_ICR_R	|= (1<<9);	WTIMER1_IMR_R	|= (1<<9);	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER2_ICR_R	|= (1<<1);	WTIMER2_IMR_R	|= (1<<1);	break;
				case 'B':	WTIMER2_ICR_R	|= (1<<9);	WTIMER2_IMR_R	|= (1<<9);	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER3_ICR_R	|= (1<<1);	WTIMER3_IMR_R	|= (1<<1);	break;
				case 'B':	WTIMER3_ICR_R	|= (1<<9);	WTIMER3_IMR_R	|= (1<<9);	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER4_ICR_R	|= (1<<1);	WTIMER4_IMR_R	|= (1<<1);	break;
				case 'B':	WTIMER4_ICR_R	|= (1<<9);	WTIMER4_IMR_R	|= (1<<9);	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER5_ICR_R	|= (1<<1);	WTIMER5_IMR_R	|= (1<<1);	break;
				case 'B':	WTIMER5_ICR_R	|= (1<<9);	WTIMER5_IMR_R	|= (1<<9);	break;
				default: break;
			}
			break;
		}
		default: break;
	}
	__enable_irq();
}


void enable_wide_edge_time_interrupt(uint8_t wide_timer_number,char channel_name)
{
	switch (wide_timer_number)
	{
		case 0:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER0_ICR_R	|= (1<<2);	WTIMER0_IMR_R	|= (1<<2);	break;
				case 'B':	WTIMER0_ICR_R	|= (1<<10);	WTIMER0_IMR_R	|= (1<<10);	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER1_ICR_R	|= (1<<2);	WTIMER1_IMR_R	|= (1<<2);	break;
				case 'B':	WTIMER1_ICR_R	|= (1<<10);	WTIMER1_IMR_R	|= (1<<10);	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER2_ICR_R	|= (1<<2);	WTIMER2_IMR_R	|= (1<<2);	break;
				case 'B':	WTIMER2_ICR_R	|= (1<<10);	WTIMER2_IMR_R	|= (1<<10);	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER3_ICR_R	|= (1<<2);	WTIMER3_IMR_R	|= (1<<2);	break;
				case 'B':	WTIMER3_ICR_R	|= (1<<10);	WTIMER3_IMR_R	|= (1<<10);	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER4_ICR_R	|= (1<<2);	WTIMER4_IMR_R	|= (1<<2);	break;
				case 'B':	WTIMER4_ICR_R	|= (1<<10);	WTIMER4_IMR_R	|= (1<<10);	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch (channel_name)
			{
				case 'A':	WTIMER5_ICR_R	|= (1<<2);	WTIMER5_IMR_R	|= (1<<2);	break;
				case 'B':	WTIMER5_ICR_R	|= (1<<10);	WTIMER5_IMR_R	|= (1<<10);	break;
				default: break;
			}
			break;
		}
		default: break;
	}
	__enable_irq();
}
	
void config_full_wide_timer(uint8_t wide_timer_number)
{
	switch (wide_timer_number)
	{
		case 0: WTIMER0_CFG_R	= 0x0;	break;
		case 1: WTIMER1_CFG_R	= 0x0;	break;
		case 2: WTIMER2_CFG_R	= 0x0;	break;
		case 3: WTIMER3_CFG_R	= 0x0;	break;
		case 4: WTIMER4_CFG_R	= 0x0;	break;
		case 5: WTIMER5_CFG_R	= 0x0;	break;
		default:	break;
	}
}

void config_half_wide_timer(uint8_t wide_timer_number)
{
	switch (wide_timer_number)
	{
		case 0: WTIMER0_CFG_R	= 0x4;	break;
		case 1: WTIMER1_CFG_R	= 0x4;	break;
		case 2: WTIMER2_CFG_R	= 0x4;	break;
		case 3: WTIMER3_CFG_R	= 0x4;	break;
		case 4: WTIMER4_CFG_R	= 0x4;	break;
		case 5: WTIMER5_CFG_R	= 0x4;	break;
		default:	break;
	}
}


void config_wide_RTC(uint8_t wide_timer_number)
{
	switch (wide_timer_number)
	{																																							// RTC does not stop counting even in debugging
		case 0: WTIMER0_CFG_R	= 0x1; WTIMER0_CTL_R |= (1<<4); WTIMER0_CTL_R &= ~(1<<1);	break;
		case 1: WTIMER1_CFG_R	= 0x1; WTIMER1_CTL_R |= (1<<4); WTIMER1_CTL_R &= ~(1<<1);	break;
		case 2: WTIMER2_CFG_R	= 0x1; WTIMER2_CTL_R |= (1<<4); WTIMER2_CTL_R &= ~(1<<1); break;
		case 3: WTIMER3_CFG_R	= 0x1; WTIMER3_CTL_R |= (1<<4); WTIMER3_CTL_R &= ~(1<<1);	break;
		case 4: WTIMER4_CFG_R	= 0x1; WTIMER4_CTL_R |= (1<<4); WTIMER4_CTL_R &= ~(1<<1);	break;
		case 5: WTIMER5_CFG_R	= 0x1; WTIMER5_CTL_R |= (1<<4); WTIMER5_CTL_R &= ~(1<<1);	break;
		default:	break;
	}
}

void set_one_shot_wide_timer(uint8_t wide_timer_number,char channel_name)
{
	switch ( wide_timer_number)
	{
		case 0: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER0_TAMR_R	 = ( WTIMER0_TAMR_R & 0xFFC )	| 0x001 ; break;
				case 'B':	WTIMER0_TBMR_R	 = ( WTIMER0_TBMR_R & 0xFFC )	| 0x001 ; break;
				default: break;
			}
			break;
		}
		case 1: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER1_TAMR_R	 = ( WTIMER1_TAMR_R & 0xFFC )	| 0x001 ; break;
				case 'B':	WTIMER1_TBMR_R	 = ( WTIMER1_TBMR_R & 0xFFC )	| 0x001 ; break;
				default: break;
			}
			break;
		}
		case 2: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER2_TAMR_R	 = ( WTIMER2_TAMR_R & 0xFFC )	| 0x001 ; break;
				case 'B':	WTIMER2_TBMR_R	 = ( WTIMER2_TBMR_R & 0xFFC )	| 0x001 ; break;
				default: break;
			}
			break;
		}
		case 3: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER3_TAMR_R	 = ( WTIMER3_TAMR_R & 0xFFC )	| 0x001 ; break;
				case 'B':	WTIMER3_TBMR_R	 = ( WTIMER3_TBMR_R & 0xFFC )	| 0x001 ; break;
				default: break;
			}
			break;
		}
		case 4: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER4_TAMR_R	 = ( WTIMER4_TAMR_R & 0xFFC )	| 0x001 ; break;
				case 'B':	WTIMER4_TBMR_R	 = ( WTIMER4_TBMR_R & 0xFFC )	| 0x001 ; break;
				default: break;
			}
			break;
		}
		case 5: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER5_TAMR_R	 = ( WTIMER5_TAMR_R & 0xFFC )	| 0x001 ; break;
				case 'B':	WTIMER5_TBMR_R	 = ( WTIMER5_TBMR_R & 0xFFC )	| 0x001 ; break;
				default: break;
			}
			break;
		}
		default:	break;
	}
}

void set_periodic_wide_timer(uint8_t wide_timer_number,char channel_name)
{
	switch ( wide_timer_number)
	{
		case 0: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER0_TAMR_R	 = ( WTIMER0_TAMR_R & 0xFFC )	| 0x002 ; break;
				case 'B':	WTIMER0_TBMR_R	 = ( WTIMER0_TBMR_R & 0xFFC )	| 0x002 ; break;
				default: break;
			}
			break;
		}
		case 1: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER1_TAMR_R	 = ( WTIMER1_TAMR_R & 0xFFC )	| 0x002 ; break;
				case 'B':	WTIMER1_TBMR_R	 = ( WTIMER1_TBMR_R & 0xFFC )	| 0x002 ; break;
				default: break;
			}
			break;
		}
		case 2: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER2_TAMR_R	 = ( WTIMER2_TAMR_R & 0xFFC )	| 0x002 ; break;
				case 'B':	WTIMER2_TBMR_R	 = ( WTIMER2_TBMR_R & 0xFFC )	| 0x002 ; break;
				default: break;
			}
			break;
		}
		case 3: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER3_TAMR_R	 = ( WTIMER3_TAMR_R & 0xFFC )	| 0x002 ; break;
				case 'B':	WTIMER3_TBMR_R	 = ( WTIMER3_TBMR_R & 0xFFC )	| 0x002 ; break;
				default: break;
			}
			break;
		}
		case 4: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER4_TAMR_R	 = ( WTIMER4_TAMR_R & 0xFFC )	| 0x002 ; break;
				case 'B':	WTIMER4_TBMR_R	 = ( WTIMER4_TBMR_R & 0xFFC )	| 0x002 ; break;
				default: break;
			}
			break;
		}
		case 5: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER5_TAMR_R	 = ( WTIMER5_TAMR_R & 0xFFC )	| 0x002 ; break;
				case 'B':	WTIMER5_TBMR_R	 = ( WTIMER5_TBMR_R & 0xFFC )	| 0x002 ; break;
				default: break;
			}
			break;
		}
		default:	break;
	}
}

void set_wide_edge_count(uint8_t wide_timer_number,char channel_name)
{
	switch ( wide_timer_number)
	{
		case 0: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER0_TAMR_R	 = ( WTIMER0_TAMR_R & 0xFF8 )	| 0x003 ; break;
				case 'B':	WTIMER0_TBMR_R	 = ( WTIMER0_TBMR_R & 0xFF8 )	| 0x003 ; break;
				default: break;
			}
			break;
		}
		case 1: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER1_TAMR_R	 = ( WTIMER1_TAMR_R & 0xFF8 )	| 0x003 ; break;
				case 'B':	WTIMER1_TBMR_R	 = ( WTIMER1_TBMR_R & 0xFF8 )	| 0x003 ; break;
				default: break;
			}
			break;
		}
		case 2: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER2_TAMR_R	 = ( WTIMER2_TAMR_R & 0xFF8 )	| 0x003 ; break;
				case 'B':	WTIMER2_TBMR_R	 = ( WTIMER2_TBMR_R & 0xFF8 )	| 0x003 ; break;
				default: break;
			}
			break;
		}
		case 3: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER3_TAMR_R	 = ( WTIMER3_TAMR_R & 0xFF8 )	| 0x003 ; break;
				case 'B':	WTIMER3_TBMR_R	 = ( WTIMER3_TBMR_R & 0xFF8 )	| 0x003 ; break;
				default: break;
			}
			break;
		}
		case 4: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER4_TAMR_R	 = ( WTIMER4_TAMR_R & 0xFF8 )	| 0x003 ; break;
				case 'B':	WTIMER4_TBMR_R	 = ( WTIMER4_TBMR_R & 0xFF8 )	| 0x003 ; break;
				default: break;
			}
			break;
		}
		case 5: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER5_TAMR_R	 = ( WTIMER5_TAMR_R & 0xFF8 )	| 0x003 ; break;
				case 'B':	WTIMER5_TBMR_R	 = ( WTIMER5_TBMR_R & 0xFF8 )	| 0x003 ; break;
				default: break;
			}
			break;
		}
		default:	break;
	}
}

void set_wide_edge_time(uint8_t wide_timer_number,char channel_name)
{
	switch ( wide_timer_number)
	{
		case 0: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER0_TAMR_R	 = ( WTIMER0_TAMR_R & 0xFF8 )	| 0x007 ; break;
				case 'B':	WTIMER0_TBMR_R	 = ( WTIMER0_TBMR_R & 0xFF8 )	| 0x007 ; break;
				default: break;
			}
			break;
		}
		case 1: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER1_TAMR_R	 = ( WTIMER1_TAMR_R & 0xFF8 )	| 0x007 ; break;
				case 'B':	WTIMER1_TBMR_R	 = ( WTIMER1_TBMR_R & 0xFF8 )	| 0x007 ; break;
				default: break;
			}
			break;
		}
		case 2: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER2_TAMR_R	 = ( WTIMER2_TAMR_R & 0xFF8 )	| 0x007 ; break;
				case 'B':	WTIMER2_TBMR_R	 = ( WTIMER2_TBMR_R & 0xFF8 )	| 0x007 ; break;
				default: break;
			}
			break;
		}
		case 3: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER3_TAMR_R	 = ( WTIMER3_TAMR_R & 0xFF8 )	| 0x007 ; break;
				case 'B':	WTIMER3_TBMR_R	 = ( WTIMER3_TBMR_R & 0xFF8 )	| 0x007 ; break;
				default: break;
			}
			break;
		}
		case 4: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER4_TAMR_R	 = ( WTIMER4_TAMR_R & 0xFF8 )	| 0x007 ; break;
				case 'B':	WTIMER4_TBMR_R	 = ( WTIMER4_TBMR_R & 0xFF8 )	| 0x007 ; break;
				default: break;
			}
			break;
		}
		case 5: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER5_TAMR_R	 = ( WTIMER5_TAMR_R & 0xFF8 )	| 0x007 ; break;
				case 'B':	WTIMER5_TBMR_R	 = ( WTIMER5_TBMR_R & 0xFF8 )	| 0x007 ; break;
				default: break;
			}
			break;
		}
		default:	break;
	}
}

void set_wide_PWM(uint8_t wide_timer_number,char channel_name)
{
	
	switch ( wide_timer_number)
	{
		case 0: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER0_TAMR_R	 = (WTIMER0_TAMR_R & 0xFF0) | ( 0x00A);	  WTIMER0_CTL_R	&= ~(1<<6); break;
				case 'B':	WTIMER0_TBMR_R	 = (WTIMER0_TBMR_R & 0xFF0) | ( 0x00A); 	WTIMER0_CTL_R	&= ~(1<<14); break;
				default: break;
			}
			break;
		}
		case 1: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER1_TAMR_R	 = (WTIMER1_TAMR_R & 0xFF0) | ( 0x00A); WTIMER1_CTL_R	&= ~(1<<6); break;
				case 'B':	WTIMER1_TBMR_R	 = (WTIMER1_TBMR_R & 0xFF0) | ( 0x00A); WTIMER1_CTL_R	&= ~(1<<14); break;
				default: break;
			}
			break;
		}
		case 2: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER2_TAMR_R	 = (WTIMER2_TAMR_R & 0xFF0) | ( 0x00A); WTIMER2_CTL_R	&= ~(1<<6); break;
				case 'B':	WTIMER2_TBMR_R	 = (WTIMER2_TBMR_R & 0xFF0) | ( 0x00A); WTIMER2_CTL_R	&= ~(1<<14); break;
				default: break;
			}
			break;
		}
		case 3: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER3_TAMR_R	 = (WTIMER3_TAMR_R & 0xFF0) | ( 0x00A); WTIMER3_CTL_R	&= ~(1<<6); break;
				case 'B':	WTIMER3_TBMR_R	 = (WTIMER3_TBMR_R & 0xFF0) | ( 0x00A); WTIMER3_CTL_R	&= ~(1<<14); break;
				default: break;
			}
			break;
		}
		case 4: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER4_TAMR_R	 = (WTIMER4_TAMR_R & 0xFF0) | ( 0x00A); WTIMER4_CTL_R	&= ~(1<<6); break;
				case 'B':	WTIMER4_TBMR_R	 = (WTIMER4_TBMR_R & 0xFF0) | ( 0x00A); WTIMER4_CTL_R	&= ~(1<<14); break;
				default: break;
			}
			break;
		}
		case 5: 
		{
			switch ( channel_name )
			{
				case 'A':	WTIMER5_TAMR_R	 = (WTIMER5_TAMR_R & 0xFF0) | ( 0x00A); WTIMER5_CTL_R	&= ~(1<<6); break;
				case 'B':	WTIMER5_TBMR_R	 = (WTIMER5_TBMR_R & 0xFF0) | ( 0x00A); WTIMER5_CTL_R	&= ~(1<<14); break;
				default: break;
			}
			break;
		}
		default:	break;
	}
}

void set_wide_event(uint8_t wide_timer_number,char channel_name,event capture_edge)
{
	switch (wide_timer_number)
	{
		case 0: 
		{
			switch (channel_name)
			{
				case 'A':
				{		if (capture_edge == POSITIVE_EDGE)
									WTIMER0_CTL_R	= ( WTIMER0_CTL_R & 0xFFF3) | ( 0 << 2);
						else if (capture_edge  == NEGATIVE_EDGE)
									WTIMER0_CTL_R	= ( WTIMER0_CTL_R & 0xFFF3) | ( 1 << 2);
						else if (capture_edge  == BOTH_EDGES)
									WTIMER0_CTL_R	= ( WTIMER0_CTL_R & 0xFFF3) | ( 3 << 2);
						else 					// NONE
							break;
						break;
				}
				case 'B':
				{		if (capture_edge == POSITIVE_EDGE)
									WTIMER0_CTL_R	= ( WTIMER0_CTL_R & 0xF3FF) | ( 0 << 10);
						else if (capture_edge  == NEGATIVE_EDGE)
									WTIMER0_CTL_R	= ( WTIMER0_CTL_R & 0xF3FF) | ( 1 << 10);
						else if (capture_edge  == BOTH_EDGES)
									WTIMER0_CTL_R	= ( WTIMER0_CTL_R & 0xF3FF) | ( 3 << 10);
						else 					// NONE
							break;
						break;
				}
				default: break;
			}
			break;
		}
		
		case 1: 
		{
			switch (channel_name)
			{
				case 'A':
				{		if (capture_edge == POSITIVE_EDGE)
									WTIMER1_CTL_R	= ( WTIMER1_CTL_R & 0xFFF3) | ( 0 << 2);
						else if (capture_edge  == NEGATIVE_EDGE)
									WTIMER1_CTL_R	= ( WTIMER1_CTL_R & 0xFFF3) | ( 1 << 2);
						else if (capture_edge  == BOTH_EDGES)
									WTIMER1_CTL_R	= ( WTIMER1_CTL_R & 0xFFF3) | ( 3 << 2);
						else 					// NONE
							break;
						break;
				}
				case 'B':
				{		if (capture_edge == POSITIVE_EDGE)
									WTIMER1_CTL_R	= ( WTIMER1_CTL_R & 0xF3FF) | ( 0 << 10);
						else if (capture_edge  == NEGATIVE_EDGE)
									WTIMER1_CTL_R	= ( WTIMER1_CTL_R & 0xF3FF) | ( 1 << 10);
						else if (capture_edge  == BOTH_EDGES)
									WTIMER1_CTL_R	= ( WTIMER1_CTL_R & 0xF3FF) | ( 3 << 10);
						else 					// NONE
							break;
						break;
				}
				default: break;
			}
			break;
		}
		
		case 2: 
		{
			switch (channel_name)
			{
				case 'A':
				{		if (capture_edge == POSITIVE_EDGE)
									WTIMER2_CTL_R	= ( WTIMER2_CTL_R & 0xFFF3) | ( 0 << 2);
						else if (capture_edge  == NEGATIVE_EDGE)
									WTIMER2_CTL_R	= ( WTIMER2_CTL_R & 0xFFF3) | ( 1 << 2);
						else if (capture_edge  == BOTH_EDGES)
									WTIMER2_CTL_R	= ( WTIMER2_CTL_R & 0xFFF3) | ( 3 << 2);
						else 					// NONE
							break;
						break;
				}
				case 'B':
				{		if (capture_edge == POSITIVE_EDGE)
									WTIMER2_CTL_R	= ( WTIMER2_CTL_R & 0xF3FF) | ( 0 << 10);
						else if (capture_edge  == NEGATIVE_EDGE)
									WTIMER2_CTL_R	= ( WTIMER2_CTL_R & 0xF3FF) | ( 1 << 10);
						else if (capture_edge  == BOTH_EDGES)
									WTIMER2_CTL_R	= ( WTIMER2_CTL_R & 0xF3FF) | ( 3 << 10);
						else 					// NONE
							break;
						break;
				}
				default: break;
			}
			break;
		}
		
		case 3: 
		{
			switch (channel_name)
			{
				case 'A':
				{		if (capture_edge == POSITIVE_EDGE)
									WTIMER3_CTL_R	= ( WTIMER3_CTL_R & 0xFFF3) | ( 0 << 2);
						else if (capture_edge  == NEGATIVE_EDGE)
									WTIMER3_CTL_R	= ( WTIMER3_CTL_R & 0xFFF3) | ( 1 << 2);
						else if (capture_edge  == BOTH_EDGES)
									WTIMER3_CTL_R	= ( WTIMER3_CTL_R & 0xFFF3) | ( 3 << 2);
						else 					// NONE
							break;
						break;
				}
				case 'B':
				{		if (capture_edge == POSITIVE_EDGE)
									WTIMER3_CTL_R	= ( WTIMER3_CTL_R & 0xF3FF) | ( 0 << 10);
						else if (capture_edge  == NEGATIVE_EDGE)
									WTIMER3_CTL_R	= ( WTIMER3_CTL_R & 0xF3FF) | ( 1 << 10);
						else if (capture_edge  == BOTH_EDGES)
									WTIMER3_CTL_R	= ( WTIMER3_CTL_R & 0xF3FF) | ( 3 << 10);
						else 					// NONE
							break;
						break;
				}
				default: break;
			}
			break;
		}
		
		case 4: 
		{
			switch (channel_name)
			{
				case 'A':
				{		if (capture_edge == POSITIVE_EDGE)
									WTIMER4_CTL_R	= ( WTIMER4_CTL_R & 0xFFF3) | ( 0 << 2);
						else if (capture_edge  == NEGATIVE_EDGE)
									WTIMER4_CTL_R	= ( WTIMER4_CTL_R & 0xFFF3) | ( 1 << 2);
						else if (capture_edge  == BOTH_EDGES)
									WTIMER4_CTL_R	= ( WTIMER4_CTL_R & 0xFFF3) | ( 3 << 2);
						else 					// NONE
							break;
						break;
				}
				case 'B':
				{		if (capture_edge == POSITIVE_EDGE)
									WTIMER4_CTL_R	= ( WTIMER4_CTL_R & 0xF3FF) | ( 0 << 10);
						else if (capture_edge  == NEGATIVE_EDGE)
									WTIMER4_CTL_R	= ( WTIMER4_CTL_R & 0xF3FF) | ( 1 << 10);
						else if (capture_edge  == BOTH_EDGES)
									WTIMER4_CTL_R	= ( WTIMER4_CTL_R & 0xF3FF) | ( 3 << 10);
						else 					// NONE
							break;
						break;
				}
				default: break;
			}
			break;
		}
		
		case 5: 
		{
			switch (channel_name)
			{
				case 'A':
				{		if (capture_edge == POSITIVE_EDGE)
									WTIMER5_CTL_R	= ( WTIMER5_CTL_R & 0xFFF3) | ( 0 << 2);
						else if (capture_edge  == NEGATIVE_EDGE)
									WTIMER5_CTL_R	= ( WTIMER5_CTL_R & 0xFFF3) | ( 1 << 2);
						else if (capture_edge  == BOTH_EDGES)
									WTIMER5_CTL_R	= ( WTIMER5_CTL_R & 0xFFF3) | ( 3 << 2);
						else 					// NONE
							break;
						break;
				}
				case 'B':
				{		if (capture_edge == POSITIVE_EDGE)
									WTIMER5_CTL_R	= ( WTIMER5_CTL_R & 0xF3FF) | ( 0 << 10);
						else if (capture_edge  == NEGATIVE_EDGE)
									WTIMER5_CTL_R	= ( WTIMER5_CTL_R & 0xF3FF) | ( 1 << 10);
						else if (capture_edge  == BOTH_EDGES)
									WTIMER5_CTL_R	= ( WTIMER5_CTL_R & 0xF3FF) | ( 3 << 10);
						else 					// NONE
							break;
						break;
				}
				default: break;
			}
			break;
		}
		default: break;
	}
	
}


void set_wide_output_ccp(uint8_t	wide_timer_number,char channel_name)
{
	switch (wide_timer_number)
	{
		case 0:
		{
			switch (channel_name)
			{
				case 'A':		initialize_pin('C',4,OUTPUT);		set_pin_alternative_function('C',4,7);		break;
				case 'B':		initialize_pin('C',5,OUTPUT);		set_pin_alternative_function('C',5,7);	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch (channel_name)
			{
				case 'A':		initialize_pin('C',6,OUTPUT);		set_pin_alternative_function('C',6,7);	break;
				case 'B':		initialize_pin('C',7,OUTPUT);		set_pin_alternative_function('C',7,7);	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch (channel_name)
			{
				case 'A':	initialize_pin('D',0,OUTPUT);		set_pin_alternative_function('D',0,7);	break;
				case 'B':	initialize_pin('D',1,OUTPUT);		set_pin_alternative_function('D',1,7);		break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch (channel_name)
			{
				case 'A':	initialize_pin('D',2,OUTPUT);		set_pin_alternative_function('D',2,7);		break;
				case 'B':	initialize_pin('D',3,OUTPUT);		set_pin_alternative_function('D',3,7);		break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch (channel_name)
			{
				case 'A':	initialize_pin('D',4,OUTPUT);		set_pin_alternative_function('D',4,7);		break;
				case 'B':	initialize_pin('D',5,OUTPUT);		set_pin_alternative_function('D',5,7);		break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch (channel_name)
			{
				case 'A':	initialize_pin('D',6,OUTPUT);		set_pin_alternative_function('D',6,7);		break;
				case 'B':	initialize_pin('D',7,OUTPUT);		set_pin_alternative_function('D',7,7);		break;
				default: break;
			}
			break;
		}
		default: break;
	}
}

void set_wide_input_ccp(uint8_t	wide_timer_number,char channel_name)
{
	switch (wide_timer_number)
	{
		case 0:
		{
			switch (channel_name)
			{
				case 'A':		initialize_pin('C',4,INPUT);		set_pin_alternative_function('C',4,7);		break;
				case 'B':		initialize_pin('C',5,INPUT);		set_pin_alternative_function('C',5,7);	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch (channel_name)
			{
				case 'A':		initialize_pin('C',6,INPUT);		set_pin_alternative_function('C',6,7);	break;
				case 'B':		initialize_pin('C',7,INPUT);		set_pin_alternative_function('C',7,7);	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch (channel_name)
			{
				case 'A':	initialize_pin('D',0,INPUT);		set_pin_alternative_function('D',0,7);	break;
				case 'B':	initialize_pin('D',1,INPUT);		set_pin_alternative_function('D',1,7);		break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch (channel_name)
			{
				case 'A':	initialize_pin('D',2,INPUT);		set_pin_alternative_function('D',2,7);		break;
				case 'B':	initialize_pin('D',3,INPUT);		set_pin_alternative_function('D',3,7);		break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch (channel_name)
			{
				case 'A':	initialize_pin('D',4,INPUT);		set_pin_alternative_function('D',4,7);		break;
				case 'B':	initialize_pin('D',5,INPUT);		set_pin_alternative_function('D',5,7);		break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch (channel_name)
			{
				case 'A':	initialize_pin('D',6,INPUT);		set_pin_alternative_function('D',6,7);		break;
				case 'B':	initialize_pin('D',7,INPUT);		set_pin_alternative_function('D',7,7);		break;
				default: break;
			}
			break;
		}
		default: break;
	}
}


void set_wide_timer_interval(uint8_t	wide_timer_number,char channel_name, uint32_t load_value)
{
	switch ( wide_timer_number)
	{
		case 0:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER0_TAILR_R = load_value;	break;
				case 'B' : WTIMER0_TBILR_R = load_value;	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER1_TAILR_R = load_value;	break;
				case 'B' : WTIMER1_TBILR_R = load_value;	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER2_TAILR_R = load_value;	break;
				case 'B' : WTIMER2_TBILR_R = load_value;	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER3_TAILR_R = load_value;	break;
				case 'B' : WTIMER3_TBILR_R = load_value;	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER4_TAILR_R = load_value;	break;
				case 'B' : WTIMER4_TBILR_R = load_value;	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER5_TAILR_R = load_value;	break;
				case 'B' : WTIMER5_TBILR_R = load_value;	break;
				default: break;
			}
			break;
		}
		default: break;
	}
}


void set_wide_timer_match(uint8_t	wide_timer_number,char channel_name, uint32_t match_value)
{
	switch ( wide_timer_number)
	{
		case 0:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER0_TAMATCHR_R = match_value;	break;
				case 'B' : WTIMER0_TBMATCHR_R = match_value;	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER1_TAMATCHR_R = match_value;	break;
				case 'B' : WTIMER1_TBMATCHR_R = match_value;	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER2_TAMATCHR_R = match_value;	break;
				case 'B' : WTIMER2_TBMATCHR_R = match_value;	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER3_TAMATCHR_R = match_value;	break;
				case 'B' : WTIMER3_TBMATCHR_R = match_value;	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER4_TAMATCHR_R = match_value;	break;
				case 'B' : WTIMER4_TBMATCHR_R = match_value;	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER5_TAMATCHR_R = match_value;	break;
				case 'B' : WTIMER5_TBMATCHR_R = match_value;	break;
				default: break;
			}
			break;
		}
		default: break;
	}
}

void set_wide_timer_prescaler(uint8_t	wide_timer_number,char channel_name, uint16_t prescaler_value)
{
	switch ( wide_timer_number)
	{
		case 0:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER0_TAPR_R = prescaler_value;	break;
				case 'B' : WTIMER0_TBPR_R = prescaler_value;	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER1_TAPR_R = prescaler_value;	break;
				case 'B' : WTIMER1_TBPR_R = prescaler_value;	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER2_TAPR_R = prescaler_value;	break;
				case 'B' : WTIMER2_TBPR_R = prescaler_value;	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER3_TAPR_R = prescaler_value;	break;
				case 'B' : WTIMER3_TBPR_R = prescaler_value;	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER4_TAPR_R = prescaler_value;	break;
				case 'B' : WTIMER4_TBPR_R = prescaler_value;	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER5_TAPR_R = prescaler_value;	break;
				case 'B' : WTIMER5_TBPR_R = prescaler_value;	break;
				default: break;
			}
			break;
		}
		default: break;
	}
}


void set_wide_timer_prescaler_match(uint8_t	wide_timer_number,char channel_name, uint16_t prescaler_match_value)
{
	switch ( wide_timer_number)
	{
		case 0:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER0_TAPMR_R = prescaler_match_value;	break;
				case 'B' : WTIMER0_TBPMR_R = prescaler_match_value;	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER1_TAPMR_R = prescaler_match_value;	break;
				case 'B' : WTIMER1_TBPMR_R = prescaler_match_value;	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER2_TAPMR_R = prescaler_match_value;	break;
				case 'B' : WTIMER2_TBPMR_R = prescaler_match_value;	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER3_TAPMR_R = prescaler_match_value;	break;
				case 'B' : WTIMER3_TBPMR_R = prescaler_match_value;	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER4_TAPMR_R = prescaler_match_value;	break;
				case 'B' : WTIMER4_TBPMR_R = prescaler_match_value;	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch ( channel_name )
			{
				case 'A' : WTIMER5_TAPMR_R = prescaler_match_value;	break;
				case 'B' : WTIMER5_TBPMR_R = prescaler_match_value;	break;
				default: break;
			}
			break;
		}
		default: break;
	}
}


void wide_up_counting(uint8_t	wide_timer_number,char channel_name)
{
	switch ( wide_timer_number)
	{
		case 0:
		{
			switch ( channel_name)
			{
				case 'A': WTIMER0_TAMR_R |= (1<<4);	break;
				case 'B': WTIMER0_TBMR_R |= (1<<4);	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch ( channel_name)
			{
				case 'A': WTIMER1_TAMR_R |= (1<<4);	break;
				case 'B': WTIMER1_TBMR_R |= (1<<4);	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch ( channel_name)
			{
				case 'A': WTIMER2_TAMR_R |= (1<<4);	break;
				case 'B': WTIMER2_TBMR_R |= (1<<4);	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch ( channel_name)
			{
				case 'A': WTIMER3_TAMR_R |= (1<<4);	break;
				case 'B': WTIMER3_TBMR_R |= (1<<4);	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch ( channel_name)
			{
				case 'A': WTIMER4_TAMR_R |= (1<<4);	break;
				case 'B': WTIMER4_TBMR_R |= (1<<4);	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch ( channel_name)
			{
				case 'A': WTIMER5_TAMR_R |= (1<<4);	break;
				case 'B': WTIMER5_TBMR_R |= (1<<4);	break;
				default: break;
			}
			break;
		}
		default: break;

	}
}

void wide_down_counting(uint8_t	wide_timer_number,char channel_name)
{
	switch ( wide_timer_number)
	{
		case 0:
		{
			switch ( channel_name)
			{
				case 'A': WTIMER0_TAMR_R &=~ (1<<4);	break;
				case 'B': WTIMER0_TBMR_R &=~ (1<<4);	break;
				default: break;
			}
			break;
		}
		case 1:
		{
			switch ( channel_name)
			{
				case 'A': WTIMER1_TAMR_R &=~ (1<<4);	break;
				case 'B': WTIMER1_TBMR_R &=~ (1<<4);	break;
				default: break;
			}
			break;
		}
		case 2:
		{
			switch ( channel_name)
			{
				case 'A': WTIMER2_TAMR_R &=~ (1<<4);	break;
				case 'B': WTIMER2_TBMR_R &=~ (1<<4);	break;
				default: break;
			}
			break;
		}
		case 3:
		{
			switch ( channel_name)
			{
				case 'A': WTIMER3_TAMR_R &=~ (1<<4);	break;
				case 'B': WTIMER3_TBMR_R &=~ (1<<4);	break;
				default: break;
			}
			break;
		}
		case 4:
		{
			switch ( channel_name)
			{
				case 'A': WTIMER4_TAMR_R &=~ (1<<4);	break;
				case 'B': WTIMER4_TBMR_R &=~ (1<<4);	break;
				default: break;
			}
			break;
		}
		case 5:
		{
			switch ( channel_name)
			{
				case 'A': WTIMER5_TAMR_R &=~ (1<<4);	break;
				case 'B': WTIMER5_TBMR_R &=~ (1<<4);	break;
				default: break;
			}
			break;
		}
		default: break;

	}
}


void	wide_timer_init(uint8_t	wide_timer_number,char channel_name, direction wide_timer_direction, mode wide_timer_mode, event capture_edge, status interrupt1_status, status interrupt2_status, uint8_t interrupt_priority)
{
	SYSCTL_RCGCWTIMER_R	|= (1<< wide_timer_number);	
	while	( ! (SYSCTL_PRWTIMER_R & (1<< wide_timer_number) ) );	
	
	if ( channel_name	== 'A'  || channel_name	== 'B' )	// INDIVIDUAL
	{
			disable_wide_timer(wide_timer_number,channel_name);
		
			if ( interrupt1_status	== ENABLED	|| interrupt2_status == ENABLED)
					enable_wide_timer_interrupt(wide_timer_number,channel_name,interrupt_priority);
			
			config_half_wide_timer(wide_timer_number);
		
		if (wide_timer_mode == ONE_SHOT)
		{
			set_one_shot_wide_timer(wide_timer_number,channel_name);
			if (interrupt1_status == ENABLED)
			{
				enable_wide_timeout_interrupt(wide_timer_number,channel_name);
			}
			if (interrupt2_status == ENABLED)
			{
				enable_wide_match_interrupt(wide_timer_number,channel_name);
			}
		}
			
		else if( wide_timer_mode == PERIODIC)
		{
			set_periodic_wide_timer(wide_timer_number,channel_name);
			if (interrupt1_status == ENABLED)
			{
				enable_wide_timeout_interrupt(wide_timer_number,channel_name);
			}
			if (interrupt2_status == ENABLED)
			{
				enable_wide_match_interrupt(wide_timer_number,channel_name);
			}
		}
		
		else if( wide_timer_mode == EDGE_COUNT)
		{
			set_wide_edge_count(wide_timer_number,channel_name);
			set_wide_event(wide_timer_number,channel_name,capture_edge);
			set_wide_input_ccp(wide_timer_number,channel_name);
			if (interrupt1_status == ENABLED)
			{
				enable_wide_edge_count_interrupt(wide_timer_number,channel_name);
			}
		}
		else if(wide_timer_mode == EDGE_TIME)
		{
			set_wide_edge_time(wide_timer_number,channel_name);
			set_wide_event(wide_timer_number,channel_name,capture_edge);
			set_wide_input_ccp(wide_timer_number,channel_name);
			if (interrupt1_status == ENABLED)
			{
				enable_wide_edge_time_interrupt(wide_timer_number,channel_name);
			}
		}
		else if ( wide_timer_mode == PWM)
		{
			set_wide_PWM(wide_timer_number,channel_name);
			set_wide_output_ccp(wide_timer_number,channel_name);
		}
			
		
		if (wide_timer_direction == UP)
			wide_up_counting(wide_timer_number,channel_name);
		else	//down
			wide_down_counting(wide_timer_number,channel_name);

	}
	
		
	else			// CONCATINATED
	{
		disable_wide_timer(wide_timer_number,'A');
		
		if ( interrupt1_status	== ENABLED	|| interrupt2_status	== ENABLED)
				enable_wide_timer_interrupt(wide_timer_number,'A',interrupt_priority);
		
		if (wide_timer_mode == RTC)
		{
			config_wide_RTC(wide_timer_number);
			enable_wide_RTC_interrupt(wide_timer_number);
		}
			
		
		else			// ONE_SHOT OR PERIODIC
		{
			config_full_wide_timer(wide_timer_number);
			
			if (wide_timer_mode == ONE_SHOT)
			{
				set_one_shot_wide_timer(wide_timer_number,'A');
				if (interrupt1_status == ENABLED)
				{
					enable_wide_timeout_interrupt(wide_timer_number,'A');
				}
				if (interrupt2_status == ENABLED)
				{
					enable_wide_match_interrupt(wide_timer_number,'A');
				}
			}
			
		else if( wide_timer_mode == PERIODIC)
			{
				set_periodic_wide_timer(wide_timer_number,'A');
				if (interrupt1_status == ENABLED)
				{
					enable_wide_timeout_interrupt(wide_timer_number,'A');
				}
				if (interrupt2_status == ENABLED)
				{
					enable_wide_match_interrupt(wide_timer_number,'A');
				}
			}
			
			if (wide_timer_direction == UP)
				wide_up_counting(wide_timer_number,'A');
			else	//down
				wide_down_counting(wide_timer_number,'A');
		}

	}
	
}

void  run_wide_timer(uint8_t	wide_timer_number,char channel_name, uint64_t load_value, uint64_t match_value, uint16_t prescaler_value, uint16_t prescaler_match_value)
{
	
	if ( channel_name	== 'A'  || channel_name	== 'B' )	// INDIVIDUAL
	{
		set_wide_timer_interval(wide_timer_number,channel_name,load_value);
		
		if (match_value)
			set_wide_timer_match(wide_timer_number,channel_name,match_value);
		
		if (prescaler_value)
			set_wide_timer_prescaler(wide_timer_number,channel_name,prescaler_value);
		
		if (prescaler_match_value)
			set_wide_timer_prescaler_match(wide_timer_number,channel_name,prescaler_match_value);
		
		enable_wide_timer(wide_timer_number,channel_name);
	}
	
		
	else			// CONCATINATED
	{
			
			
			set_wide_timer_interval(wide_timer_number,'B',load_value >> 32);
			delayUs(3);			//make sure timer B is loaded
			set_wide_timer_interval(wide_timer_number,'A',load_value);

			
			if (match_value)
			{
				set_wide_timer_match(wide_timer_number,'B',match_value >> 32);
				delayUs(3);			//make sure timer B is loaded
				set_wide_timer_match(wide_timer_number,'A',match_value);
			}
			

		
		enable_wide_timer(wide_timer_number,'A');
	}

	
}



void wait_for_wide_timeout(uint8_t	wide_timer_number,char channel_name)
{
	switch (wide_timer_number)
	{
		case 0:
		{
			switch ( channel_name)
			{
				case 'A': while (! (WTIMER0_RIS_R	& (1<<0) ) );	WTIMER0_ICR_R |= (1<<0);  break;
				case 'B':	while (! (WTIMER0_RIS_R	& (1<<8) ) );	WTIMER0_ICR_R |= (1<<8);  break;
				default: 	while (! (WTIMER0_RIS_R	& (1<<0) ) );	WTIMER0_ICR_R |= (1<<0);  break;
			}
			break;
		}
		
		case 1:
		{
			switch ( channel_name)
			{
				case 'A': while (! (WTIMER1_RIS_R	& (1<<0) ) );	WTIMER1_ICR_R |= (1<<0);  break;
				case 'B':	while (! (WTIMER1_RIS_R	& (1<<8) ) );	WTIMER1_ICR_R |= (1<<8);  break;
				default: 	while (! (WTIMER1_RIS_R	& (1<<0) ) );	WTIMER1_ICR_R |= (1<<0);  break;
			}
			break;
		}
		
		case 2:
		{
			switch ( channel_name)
			{
				case 'A': while (! (WTIMER2_RIS_R	& (1<<0) ) );	WTIMER2_ICR_R |= (1<<0);  break;
				case 'B':	while (! (WTIMER2_RIS_R	& (1<<8) ) );	WTIMER2_ICR_R |= (1<<8);  break;
				default: 	while (! (WTIMER2_RIS_R	& (1<<0) ) );	WTIMER2_ICR_R |= (1<<0);  break;
			}
			break;
		}
		
		case 3:
		{
			switch ( channel_name)
			{
				case 'A': while (! (WTIMER3_RIS_R	& (1<<0) ) );	WTIMER3_ICR_R |= (1<<0);  break;
				case 'B':	while (! (WTIMER3_RIS_R	& (1<<8) ) );	WTIMER3_ICR_R |= (1<<8);  break;
				default: 	while (! (WTIMER3_RIS_R	& (1<<0) ) );	WTIMER3_ICR_R |= (1<<0);  break;
			}
			break;
		}
		
		case 4:
		{
			switch ( channel_name)
			{
				case 'A': while (! (WTIMER4_RIS_R	& (1<<0) ) );	WTIMER4_ICR_R |= (1<<0);  break;
				case 'B':	while (! (WTIMER4_RIS_R	& (1<<8) ) );	WTIMER4_ICR_R |= (1<<8);  break;
				default: 	while (! (WTIMER4_RIS_R	& (1<<0) ) );	WTIMER4_ICR_R |= (1<<0);  break;
			}
			break;
		}
		
		case 5:
		{
			switch ( channel_name)
			{
				case 'A': while (! (WTIMER5_RIS_R	& (1<<0) ) );	WTIMER5_ICR_R |= (1<<0);  break;
				case 'B':	while (! (WTIMER5_RIS_R	& (1<<8) ) );	WTIMER5_ICR_R |= (1<<8);  break;
				default: 	while (! (WTIMER5_RIS_R	& (1<<0) ) );	WTIMER5_ICR_R |= (1<<0);  break;
			}
			break;
		}
		default: break;
	}
}


void wait_for_wide_last_edge(uint8_t	wide_timer_number,char channel_name)
{
	switch (wide_timer_number)
	{
		case 0:
		{
			switch ( channel_name)
			{
				case 'A': while (! (WTIMER0_RIS_R	& (1<<1) ) );	WTIMER0_ICR_R |= (1<<1);  break;
				case 'B':	while (! (WTIMER0_RIS_R	& (1<<9) ) );	WTIMER0_ICR_R |= (1<<9);  break;
				default : break;
			}
			break;
		}
		
		case 1:
		{
			switch ( channel_name)
			{
				case 'A': while (! (WTIMER1_RIS_R	& (1<<1) ) );	WTIMER1_ICR_R |= (1<<1);  break;
				case 'B':	while (! (WTIMER1_RIS_R	& (1<<9) ) );	WTIMER1_ICR_R |= (1<<9);  break;
				default : break;
			}
			break;
		}
		
		case 2:
		{
			switch ( channel_name)
			{
				case 'A': while (! (WTIMER2_RIS_R	& (1<<1) ) );	WTIMER2_ICR_R |= (1<<1);  break;
				case 'B':	while (! (WTIMER2_RIS_R	& (1<<9) ) );	WTIMER2_ICR_R |= (1<<9);  break;
				default : break;
			}
			break;
		}
		
		case 3:
		{
			switch ( channel_name)
			{
				case 'A': while (! (WTIMER3_RIS_R	& (1<<1) ) );	WTIMER3_ICR_R |= (1<<1);  break;
				case 'B':	while (! (WTIMER3_RIS_R	& (1<<9) ) );	WTIMER3_ICR_R |= (1<<9);  break;
				default : break;
			}
			break;
		}
		
		case 4:
		{
			switch ( channel_name)
			{
				case 'A': while (! (WTIMER4_RIS_R	& (1<<1) ) );	WTIMER4_ICR_R |= (1<<1);  break;
				case 'B':	while (! (WTIMER4_RIS_R	& (1<<9) ) );	WTIMER4_ICR_R |= (1<<9);  break;
				default : break;
			}
			break;
		}
		
		case 5:
		{
			switch ( channel_name)
			{
				case 'A': while (! (WTIMER5_RIS_R	& (1<<1) ) );	WTIMER5_ICR_R |= (1<<1);  break;
				case 'B':	while (! (WTIMER5_RIS_R	& (1<<9) ) );	WTIMER5_ICR_R |= (1<<9);  break;
				default : break;
			}
			break;
		}
		default: break;
	}
}

void wait_for_wide_event(uint8_t	wide_timer_number,char channel_name)
{
	switch (wide_timer_number)
	{
		case 0:
		{
			switch ( channel_name)
			{
				case 'A': while (! (WTIMER0_RIS_R	& (1<<2) ) );	WTIMER0_ICR_R |= (1<<2);  break;
				case 'B':	while (! (WTIMER0_RIS_R	& (1<<10) ) );	WTIMER0_ICR_R |= (1<<10);  break;
				default : break;
			}
			break;
		}
		
		case 1:
		{
			switch ( channel_name)
			{
				case 'A': while (! (WTIMER1_RIS_R	& (1<<2) ) );	WTIMER1_ICR_R |= (1<<2);  break;
				case 'B':	while (! (WTIMER1_RIS_R	& (1<<10) ) );	WTIMER1_ICR_R |= (1<<10);  break;
				default : break;
			}
			break;
		}
		
		case 2:
		{
			switch ( channel_name)
			{
				case 'A': while (! (WTIMER2_RIS_R	& (1<<2) ) );	WTIMER2_ICR_R |= (1<<2);  break;
				case 'B':	while (! (WTIMER2_RIS_R	& (1<<10) ) );	WTIMER2_ICR_R |= (1<<10);  break;
				default : break;
			}
			break;
		}
		
		case 3:
		{
			switch ( channel_name)
			{
				case 'A': while (! (WTIMER3_RIS_R	& (1<<2) ) );	WTIMER3_ICR_R |= (1<<2);  break;
				case 'B':	while (! (WTIMER3_RIS_R	& (1<<10) ) );	WTIMER3_ICR_R |= (1<<10);  break;
				default : break;
			}
			break;
		}
		
		case 4:
		{
			switch ( channel_name)
			{
				case 'A': while (! (WTIMER4_RIS_R	& (1<<2) ) );	WTIMER4_ICR_R |= (1<<2);  break;
				case 'B':	while (! (WTIMER4_RIS_R	& (1<<10) ) );	WTIMER4_ICR_R |= (1<<10);  break;
				default : break;
			}
			break;
		}
		
		case 5:
		{
			switch ( channel_name)
			{
				case 'A': while (! (WTIMER5_RIS_R	& (1<<2) ) );	WTIMER5_ICR_R |= (1<<2);  break;
				case 'B':	while (! (WTIMER5_RIS_R	& (1<<10) ) );	WTIMER5_ICR_R |= (1<<10);  break;
				default : break;
			}
			break;
		}
		default: break;
	}
}


uint32_t detect_wide_event_time(uint8_t	timer_number,char channel_name)
{
	switch (timer_number)
	{
		case 0:
		{
			switch ( channel_name)
			{
				case 'A': return WTIMER0_TAR_R;
				case 'B': return WTIMER0_TBR_R;
				default : return 0xFFFFFFFF;
			}
			
		}
		
		case 1:
		{
			switch ( channel_name)
			{
				case 'A': return WTIMER1_TAR_R;
				case 'B': return WTIMER1_TBR_R;
				default : return 0xFFFFFFFF;
			}
			
		}
		
		case 2:
		{
			switch ( channel_name)
			{
				case 'A': return WTIMER2_TAR_R;
				case 'B': return WTIMER2_TBR_R;
				default : return 0xFFFFFFFF;
			}
			
		}
		
		case 3:
		{
			switch ( channel_name)
			{
				case 'A': return WTIMER3_TAR_R;
				case 'B': return WTIMER3_TBR_R;
				default : return 0xFFFFFFFF;
			}
			
		}
		
		case 4:
		{
			switch ( channel_name)
			{
				case 'A': return WTIMER4_TAR_R;
				case 'B': return WTIMER4_TBR_R;
				default : return 0xFFFFFFFF;
			}
			
		}
		
		case 5:
		{
			switch ( channel_name)
			{
				case 'A': return WTIMER5_TAR_R;
				case 'B': return WTIMER5_TBR_R;
				default : return 0xFFFFFFFF;
			}
			
		}
		default: return 0xFFFFFFFF;
	}
}


