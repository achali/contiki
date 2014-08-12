#include "contiki.h"
#include "dev/leds.h"

PROCESS(blink_process, "Blink!");
AUTOSTART_PROCESSES(&blink_process);

PROCESS_THREAD(blink_process, ev, data) {
 PROCESS_BEGIN();
 static struct t,i;
 counter = 0;
for (i=0; i++; 5)
    {
	counter++;
	leds_red(counter & 1);
	leds_green(counter & 2);
	leds_blue(counter & 4);
	etimer_set(&t, CLOCK_SECOND);
	PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&t)); 
    } 

PROCESS_END();
}
