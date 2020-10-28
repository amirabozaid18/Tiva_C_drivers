#ifndef ADC_H
#define ADC_H


#include "tm4c123gh6pm.h"
#include "stdint.h"


typedef enum clock_status { CONNECTED, DISCONNECTED} clock;
typedef enum seqencer_initiation { ONCE, ALWAYS} initiation;
typedef enum interrupt_state {ON , OFF} state;


void initialize_analog_pin(char port_name, uint8_t pin_number);
void ADC_pin_init(uint8_t input_number, clock ADC0_clock, clock ADC1_clock);
void set_sequencers_priorities(uint8_t ADC_number, uint8_t sequencer0_priority, uint8_t sequencer1_priority, uint8_t sequencer2_priority, uint8_t sequencer3_priority);
void sequencer0_init(uint8_t ADC_number,initiation sequencer_initiation,uint8_t samples_number, state sequence_interrupt, uint8_t interrupt_priority, uint8_t first_input, uint8_t second_input, uint8_t third_input, uint8_t fourth_input, uint8_t fifth_input, uint8_t sixth_input, uint8_t seventh_input, uint8_t eighth_input);
void sequencer1_init(uint8_t ADC_number,initiation sequencer_initiation,uint8_t samples_number, state sequence_interrupt, uint8_t interrupt_priority, uint8_t first_input, uint8_t second_input, uint8_t third_input, uint8_t fourth_input);
void sequencer2_init(uint8_t ADC_number,initiation sequencer_initiation,uint8_t samples_number, state sequence_interrupt, uint8_t interrupt_priority, uint8_t first_input, uint8_t second_input, uint8_t third_input, uint8_t fourth_input);
void sequencer3_init(uint8_t ADC_number,initiation sequencer_initiation, state sequence_interrupt, uint8_t interrupt_priority, uint8_t sequencer_input);
void run_sequencer(uint8_t ADC_number,uint8_t sequencer_number);
void disable_sequencer(uint8_t ADC_number,uint8_t sequencer_number);
void enable_sequencer(uint8_t ADC_number,uint8_t sequencer_number);
uint16_t conversion_result(uint8_t ADC_number, uint8_t sequencer_number);
uint8_t is_FIFO_full(uint8_t ADC_number, uint8_t sequencer_number);
uint8_t is_FIFO_empty(uint8_t ADC_number, uint8_t sequencer_number);
uint8_t next_entry_to_be_read(uint8_t ADC_number, uint8_t sequencer_number);
uint8_t next_entry_to_be_written(uint8_t ADC_number, uint8_t sequencer_number);
void enable_ADC_interrupt(uint8_t ADC_number,uint8_t sequencer_number,uint8_t interrupt_priority);
void synchronize_ADC_modules(uint8_t first_module_sequecner_number, uint8_t first_module_lag_multiplier, uint8_t second_module_sequecner_number, uint8_t second_module_lag_multiplier);
void set_differntial_pair(uint8_t ADC_number, uint8_t sequencer_number, uint8_t positive_sample_index,uint8_t negative_sample_index);
uint8_t is_ADC_busy(uint8_t ADC_number);
void set_averaging_rate(uint8_t ADC_number,uint8_t average_rate);


#endif
