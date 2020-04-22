#include <lpc214x.h>
#define STEPS 50


void open() {
	IO1DIR |= 0xF0000000;						// Set P1.28 to P1.31 as output
	int step_count = STEPS;
	
	while(1) {
		int i, to_shift = 1;		
		for(i = 0; i < 4 && --step_count; i++) {
			IO1CLR = 0xF0000000;				// Clear all concerned pin values
			IO1SET = to_shift << 28;			// Sets appropriate direction pin
			to_shift *= 2;
		}
		
		if(!(--step_count))
			break;
	}
	
	IO1CLR = 0xF0000000;						// Resets all concerned pins
}

void close() {
	IO1DIR |= 0xF0000000;						// Set P1.28 to P01.31 as output
	int step_count = STEPS;
	
	while(1) {
		int i, to_shift = 8;		
		for(i = 0; i < 4 && --step_count; i++) {
			IO1CLR = 0xF0000000;				// Clear all concerned pin values
			IO1SET = to_shift << 28;			// Sets appropriate direction pin
			to_shift /= 2;
		}
		
		if(!(--step_count))
			break;
	}
	
	IO1CLR = 0xF0000000;						// Resets all concerned pins
}