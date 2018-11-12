/* MBED RTOS Blinky
 * Flash some simple LEDs using the RTOS
 * Thread version
 */

#include <mbed.h>

DigitalOut   red(LED1,1); /* initialise to 1 = off */
DigitalOut green(LED2,1); /* initialise to 1 = off */
DigitalOut  blue(LED3,1); /* initialise to 1 = off */

enum { ON, OFF};
void flash_red(void)
{
	while(true) {
		red = ON;
		wait(0.3);
		red = OFF;
		wait(0.6);
	}
}

void flash_green(void)
{
	wait(0.3);
	while(true) {
		green = ON;
		wait(0.3);
		green = OFF;
		wait(0.6);
	}
}

void flash_blue(void)
{
	wait(0.6);
	while(true) {
		blue = ON;
		wait(0.3);
		blue = OFF;
		wait(0.6);
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

