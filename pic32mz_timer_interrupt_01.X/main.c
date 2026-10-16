/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.
 *******************************************************************************/

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "definitions.h"


static volatile unsigned int timerTicks = 0;


/* Timer 2 interrupt callback
   TMR2 is configured to interrupt every 100 ms */
static void TMR2_EventHandler(uint32_t status, uintptr_t context)
{
    (void)status;
    (void)context;

    timerTicks++;

    /* 5 interrupts x 100 ms = 500 ms */
    if (timerTicks >= 5)
    {
        LATHINV = (1u << 0);
        timerTicks = 0;
    }
}


int main(void)
{
    SYS_Initialize(NULL);

    /* RH0 is connected to LED1 */
    TRISHCLR = (1u << 0);
    LATHCLR = (1u << 0);

    /* Register the Timer 2 callback */
    TMR2_CallbackRegister(TMR2_EventHandler, (uintptr_t)NULL);

    /* Start Timer 2 */
    TMR2_Start();

    while (true)
    {
        /*
         * Main loop is intentionally empty.
         * Timer 2 handles the LED timing through interrupts.
         */
    }

    return EXIT_FAILURE;
}


/*******************************************************************************
 End of File
*/