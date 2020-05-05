/*
 * CarProto.c
 *
 * Created: 22.04.2020 18:13:29
 * Author : Yauheni
 */ 
  
#include <avr/io.h>
#include <util/delay.h>
#include "avr-uart/uart.h"

int main(void)
{
	uart0_init(UART_BAUD_SELECT(115200, F_CPU));
	uart1_init(UART_BAUD_SELECT(115200, F_CPU));
	
	while(1) {
		_delay_ms(10);
		uint16_t c = uart1_getc();
		
		if (c == UART_NO_DATA) {
			continue;
		}
		
		uart0_putc(c & 0xff);
	}
}
