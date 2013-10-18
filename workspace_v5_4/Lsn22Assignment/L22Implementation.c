/*
 * L22Implementation.c
 *
 *  Created on: Oct 16, 2013
 *      Author: Andrew Tymchenko
 */

#include "moving_average.h"

/*
 * inputs: array of samples and how many samples there are
 * computes the sum of all values then divided by the number of samples to result in the average
 */
int getAverage(int array[], unsigned int arrayLength){
	int sum = 0;
	int x;
	for(x = 0; x < arrayLength; x++){
			sum += array[x];
		}
	int average = sum / arrayLength;

	return average;
}

/**
 ** inputs: new sample, array of samples, number of total samples
 ** returns: new array of samples
 ** shifts the values in the array to the left, then adds in the new sample.
 **/
void addSample(int sample, int array[], unsigned int arrayLength){
	int y;
	for(y=0; y < arrayLength-1; y++){
		array[y] = array[y+1];
	}
	array[arrayLength-1] = sample;
}

/*
 * checks all numbers in the array to see if the value is the maximum value
 */
int max(int *allNumbers, int max, int arrayLength){
	int i;
	for(i = 0; i < arrayLength; i++){
	if(*allNumbers > max){
		max = *allNumbers;
	}
	allNumbers++;
	}
	return max;
}

/*
 * checks all numbers in the array to see if the value is the minimum value
 */
int min(int *allNumbers, int min, int arrayLength){
	int i;
	for(i = 0; i < arrayLength; i++){
	if(*allNumbers < min){
		min = *allNumbers;
	}
	allNumbers++;
	}
	return min;
}

int range(int maximum, int minimum){
	return maximum - minimum;
}




