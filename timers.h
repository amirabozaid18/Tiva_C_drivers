#ifndef	TIMERS_H
#define TIMERS_H

#include "DIO.h"

typedef enum	count_direction { UP, DOWN} direction;
typedef enum	working_mode { ONE_SHOT, PERIODIC, RTC, EDGE_COUNT, EDGE_TIME, PWM } mode;
typedef	enum	capture_event	{ POSITIVE_EDGE, NEGATIVE_EDGE, BOTH_EDGES, NONE} event;	


// 16/32 general purpose timers
void disable_timer(uint8_t	timer_number, char channel_name);
void enable_timer(uint8_t	timer_number, char channel_name);
void enable_timer_interrupt(uint8_t	timer_number,char channel_name, uint8_t interrupt_priority);
void enable_timeout_interrupt(uint8_t timer_number,char channel_name);
void enable_match_interrupt(uint8_t timer_number,char channel_name);
void enable_RTC_interrupt(uint8_t timer_number);
void enable_edge_count_interrupt(uint8_t timer_number,char channel_name);
void enable_edge_time_interrupt(uint8_t timer_number,char channel_name);
void config_full_timer(uint8_t timer_number);
void config_half_timer(uint8_t timer_number);
void config_RTC(uint8_t timer_number);
void set_one_shot_timer(uint8_t timer_number,char channel_name);
void set_periodic_timer(uint8_t timer_number,char channel_name);
void set_edge_count(uint8_t timer_number,char channel_name);
void set_edge_time(uint8_t timer_number,char channel_name);
void set_PWM(uint8_t timer_number,char channel_name);
void set_event(uint8_t timer_number,char channel_name,event capture_edge);
void set_output_ccp(uint8_t	timer_number,char channel_name);
void set_input_ccp(uint8_t	timer_number,char channel_name);
void set_timer_interval(uint8_t	timer_number,char channel_name, uint16_t load_value);
void set_timer_match(uint8_t	timer_number,char channel_name, uint16_t match_value);
void set_timer_prescaler(uint8_t	timer_number,char channel_name, uint8_t prescaler_value);
void set_timer_prescaler_match(uint8_t	timer_number,char channel_name, uint8_t prescaler_match_value);
void up_counting(uint8_t	timer_number,char channel_name);
void down_counting(uint8_t	timer_number,char channel_name);
void timer_init(uint8_t	timer_number,char channel_name, direction timer_direction, mode timer_mode, event capture_edge, status interrupt1_status, status interrupt2_status, uint8_t interrupt_priority);
void run_timer(uint8_t	timer_number,char channel_name, uint32_t load_value, uint32_t match_value, uint8_t prescaler_value, uint8_t prescaler_match_value);
void wait_for_timeout(uint8_t	timer_number,char channel_name);
void wait_for_last_edge(uint8_t	timer_number,char channel_name);
void wait_for_event(uint8_t	timer_number,char channel_name);
uint32_t detect_event_time(uint8_t	timer_number,char channel_name);



// 32/64 general purpose timers

void disable_wide_timer(uint8_t	wide_timer_number, char channel_name);
void enable_wide_timer(uint8_t	wide_timer_number, char channel_name);
void enable_wide_timer_interrupt(uint8_t	wide_timer_number,char channel_name, uint8_t interrupt_priority);
void enable_wide_timeout_interrupt(uint8_t wide_timer_number,char channel_name);
void enable_wide_match_interrupt(uint8_t wide_timer_number,char channel_name);
void enable_wide_RTC_interrupt(uint8_t wide_timer_number);
void enable_wide_edge_count_interrupt(uint8_t wide_timer_number,char channel_name);
void enable_wide_edge_time_interrupt(uint8_t wide_timer_number,char channel_name);
void config_full_wide_timer(uint8_t wide_timer_number);
void config_half_wide_timer(uint8_t wide_timer_number);
void config_wide_RTC(uint8_t wide_timer_number);
void set_one_shot_wide_timer(uint8_t wide_timer_number,char channel_name);
void set_periodic_wide_timer(uint8_t wide_timer_number,char channel_name);
void set_wide_edge_count(uint8_t wide_timer_number,char channel_name);
void set_wide_edge_time(uint8_t wide_timer_number,char channel_name);
void set_wide_PWM(uint8_t wide_timer_number,char channel_name);
void set_wide_event(uint8_t wide_timer_number,char channel_name,event capture_edge);
void set_wide_output_ccp(uint8_t	wide_timer_number,char channel_name);
void set_wide_input_ccp(uint8_t	wide_timer_number,char channel_name);
void set_wide_timer_interval(uint8_t	wide_timer_number,char channel_name, uint32_t load_value);
void set_wide_timer_match(uint8_t	wide_timer_number,char channel_name, uint32_t match_value);
void set_wide_timer_prescaler(uint8_t	wide_timer_number,char channel_name, uint16_t prescaler_value);
void set_wide_timer_prescaler_match(uint8_t	wide_timer_number,char channel_name, uint16_t prescaler_match_value);
void wide_up_counting(uint8_t	wide_timer_number,char channel_name);
void wide_down_counting(uint8_t	wide_timer_number,char channel_name);
void wide_timer_init(uint8_t	wide_timer_number,char channel_name, direction wide_timer_direction, mode wide_timer_mode, event capture_edge, status interrupt1_status, status interrupt2_status, uint8_t interrupt_priority);
void run_wide_timer(uint8_t	wide_timer_number,char channel_name, uint64_t load_value, uint64_t match_value, uint16_t prescaler_value, uint16_t prescaler_match_value);
void wait_for_wide_timeout(uint8_t	wide_timer_number,char channel_name);
void wait_for_wide_last_edge(uint8_t	wide_timer_number,char channel_name);
void wait_for_wide_event(uint8_t	wide_timer_number,char channel_name);
uint32_t detect_wide_event_time(uint8_t	timer_number,char channel_name);


#endif
