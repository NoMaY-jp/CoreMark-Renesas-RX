#ifndef PORTME_HELPER_H
#define PORTME_HELPER_H

#define RX_MCU_RUN_CLK   32000000UL
#define RX_MCU_TIMER_CLK 32000000UL

void hardware_start(void);
void charput(char output_char);
void sci_charput(char output_char);
void serial_charput(char output_char);
unsigned long timer_gettick(void);

#endif /* PORTME_HELPER_H */
