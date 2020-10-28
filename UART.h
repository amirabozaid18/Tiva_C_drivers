#ifndef UART_H
#define UART_H


#include "DIO.h"


typedef enum UART_clock_speed { NORMAL, HIGH } speed;
typedef enum word_length { FIVE, SIX, SEVEN, EIGHT} length; 
typedef enum feature_usage { USED, UNUSED} usage;
typedef enum parity_sort { EVEN, ODD} sort;


void UART_init(uint8_t UART_number);
void set_Baud_rate(uint8_t UART_number,uint32_t Baud_Rate, uint32_t system_clock, speed UART_clock_frequency);
void configure_UART(uint8_t UART_number, length data_length, usage two_stop_bits, usage parity_check, sort parity_sort);
void set_UART_interrupts(uint8_t UART_number, status reception_interrupt, status transmission_interrupt, status frame_error_interrupt , status parity_error_interrupt, status break_error_interrupt, status overrun_error_interrupt, uint8_t interrupt_priority);
void run_UART(uint8_t UART_number);
void disable_UART(uint8_t UART_number);
void UART_send_char(uint8_t UART_number, uint8_t mydata);
void UART_send_string(uint8_t UART_number, char* mystring);
void UART_send_number(uint8_t UART_number,int64_t mynumber);
uint8_t UART_receive(uint8_t UART_number);
uint8_t is_overrun_error(uint8_t UART_number);
uint8_t is_break_error(uint8_t UART_number);
uint8_t is_parity_error(uint8_t UART_number);
uint8_t is_framing_error(uint8_t UART_number);
uint8_t is_receiver_FIFO_full(uint8_t UART_number);
uint8_t is_receiver_FIFO_empty(uint8_t UART_number);
uint8_t is_transmitter_FIFO_full(uint8_t UART_number);
uint8_t is_transmitter_FIFO_empty(uint8_t UART_number);


#endif
