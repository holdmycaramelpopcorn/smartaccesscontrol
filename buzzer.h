/* Buzzer control functions
 * Buzzer connected to DAC - P0.25 AOUT
 */
 #include <lpc214x.h>
#define EMPTYBUZZER 500
#define TIMEBUZZER 1000


void startBuzzer(int intensity) {
	PINSEL1 |= (2 << 18);			// Selected option 2 of P0.25 - AOUT
	
	if(intensity > 1023)			// If intensity is more than maximum, set it to maximum
		intensity = 1023;
	if(intensity < 200)			// If intensity is lower than audible, set it to minimum
		intensity = 200;
	
	DACR = (1 << 16) | (intensity << 6); 	// Ring the buzzer with the given intensity	
}


void stopBuzzer() {
	DACR = (0 << 6);			// Resets value of DACR to 0
}