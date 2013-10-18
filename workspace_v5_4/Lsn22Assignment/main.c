#include <msp430.h> 
#include "moving_average.h"

/*
 * main.c
 */
#define N_AVG_SAMPLES 2

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    int Maximum;
    int Minimum;
    int range;
    int numbers[] = {45, 42, 41, 40, 43, 45, 46, 47, 49, 45};
    int tempArray[N_AVG_SAMPLES];
    //sets limits of max and min so they can be changed
    Maximum = -256;
    Minimum = 255;
    int	i, x = 0;
    int average;
    // initializes the temp array so the average is 0
    for(i = 0; i <= N_AVG_SAMPLES; i++){
    	x++;
    	tempArray[i] = 0;
    	i = x;
    }

    //calculates the size of the array
    int sizeOfNumbersArray = sizeof(numbers)/sizeof(int);

    //computes the average for each number set
    for(i = 0; i <= sizeOfNumbersArray; i++){
    	average = getAverage(tempArray, N_AVG_SAMPLES);
	   addSample(numbers[i],tempArray, N_AVG_SAMPLES);
    }
}
