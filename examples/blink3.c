#include "contiki.h"
#include "dev/leds.h"
#include "dev/button-sensor.h"
#include <stdio.h> /* For printf() */
 
//-----------------------------------------------------------------   
PROCESS(blink_timer_process, "blink with timer example");
AUTOSTART_PROCESSES(&blink_timer_process);
//-----------------------------------------------------------------
 
 
PROCESS_THREAD(blink_timer_process, ev, data)
{   
  PROCESS_EXITHANDLER(goto exit);
  PROCESS_BEGIN();
 
  /* Initialize stuff here. */ 
 
	printf("\n++++++++++++++++++++++++++++++\n");
	printf("+    LESSON 1, EXERCISE 2    +\n");
	printf("++++++++++++++++++++++++++++++\n");
	printf("+     Blink app w/ timer     +\n");
	printf("++++++++++++++++++++++++++++++\n\n");	
	SENSORS_ACTIVATE(button_sensor);
	leds_off(LEDS_ALL);
	printf("+       All leds are off     +\n\n");   
	printf("Press the user button to start\n\n");
 
    while(1) {
	/* Do the rest of the stuff here. */
 
	static uint32_t ticks = 0;
	static uint32_t seconds = 5;
	static struct etimer et; // Define the timer
 
	PROCESS_WAIT_EVENT();  // Waiting for a event, don't care which
 
	if(ev == sensors_event) {  // If the event it's provoked by the user button, then...
           if(data == &button_sensor) {		
		etimer_set(&et, CLOCK_SECOND*seconds);  // Set the timer
		printf("+       Timer started        +\n");
           }
        }
 
	if(etimer_expired(&et)) {  // If the event it's provoked by the timer expiration, then...
		leds_toggle(LEDS_BLUE);
		if (ticks % 2 == 0) {
			printf("+ LED BLUE .............. [ON]\n");
                }
		else { 
			printf("+ LED BLUE ............. [OFF]\n");
                }
		etimer_reset(&et);
		ticks++;
                }	
	}		
	exit:
		leds_off(LEDS_ALL);
		PROCESS_END();
}
