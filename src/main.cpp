/* MBED RTOS Blinky
 * Flash some simple LEDs using the RTOS
 * Thread version
 */

#include <mbed.h>

DigitalOut   red(LED1,1); /* initialise to 1 = off */
DigitalOut green(LED2,1); /* initialise to 1 = off */
DigitalOut  blue(LED3,1); /* initialise to 1 = off */

void flash_red(void)
{
	while(true) {
		red = !red;
		wait(0.3);
	}
}

void flash_green(void)
{
	while(true) {
		green = !green;
		wait(0.3);
	}
}

void flash_blue(void)
{
	while(true) {
		blue = !blue;
		wait(0.3);
	}
}

int main(void)
{
	Thread blink1, blink2, blink3;
	blink1.start(flash_red);
	blink2.start(flash_green);
	blink3.start(flash_blue);

	blink1.join();
}

