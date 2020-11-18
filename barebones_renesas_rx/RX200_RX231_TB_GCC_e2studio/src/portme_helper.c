#include "portme_helper.h"
#include "r_smc_entry.h"

U_CONFIG_SCI1_UART_SEND_IMPL();

void hardware_start(void)
{
    /* Start the UART and the counter */
    R_Config_SCI1_Start();
    R_Config_MTU1_Start();
    R_Config_MTU2_Start();
}

void sci_charput(char output_char)
{
    /* Write the character out via the UART */ 
    U_Config_SCI1_UART_Send_UWT((uint8_t *)&output_char, 1);
}

void serial_charput(char output_char)
{
    /* Write the character out to terminal and the Debug Console */ 
    sci_charput(output_char);
#ifndef DISABLE_DEBUG_CONSOLE
    charput(output_char);
#endif

    /* Add carriage return for easy reading in Hyper Terminal, Tera Term */
    if(output_char == '\n')
    {
        sci_charput('\r');
    }
}

unsigned long timer_gettick(void)
{
    unsigned long cycles;

    /* Stop the lower 16-bit counter (it makes also the upper 16-bit counter stop) */
    R_Config_MTU2_Stop();

    /* Combine two 16-bit counters to form 32-bit counter value */
    cycles =  ((unsigned long)(MTU2.TCNT) &  0xffff); 
    cycles |= ((unsigned long)(MTU1.TCNT) << 16);

    /* Resume the lower 16-bit counter (it makes also the upper 16-bit counter resume) */
    R_Config_MTU2_Start();

    return cycles;
}

#if defined(__GNUC__)

void abort(void);

/* Maybe not called but necessary for linking without various undefined errors. */
void abort(void)
{
    for (;;) {}
}

#endif
