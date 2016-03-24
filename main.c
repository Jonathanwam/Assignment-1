#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double getAvg(int array[], int intervals){
	double avg = 0.0;
	
	for(int i = 0; i < intervals; i++){
		avg += array[i];
	}
	
	avg /= intervals;
	return avg;
}

double getStd(int array[], int intervals){
	double std = 0.0;
	for(int i = 0; i < intervals; i++){
		std += (array[i] * array[i]);
	}
	int bottom = intervals * intervals;
	std /= bottom;
	std = sqrt(std);
	return std;
}

int main() {
	int intervals, numRands, r, w;
	
	// user prompts
	printf("Input number of intervals to divide the range 0 to RAND_MAX by: ");
	scanf("%i", &intervals);
	printf("Input number of random numbers to generate: ");
	scanf("%i", &numRands);
	
	// slot for each interval
	int array[intervals];
	for(int i = 0; i < intervals; i++) array[i] = 0;
	
	// generate random numbers and increment count for intervals the random numbers fall in	
	for(int i = 0; i < numRands; i++){
		r = rand();
		w = ( (float) r / (float) RAND_MAX) * intervals;
		array[w]++; 
	}

	
	double myAvg = getAvg(array, intervals);
	double stdDev = getStd(array, intervals);
	
	printf("The average numbers per interval: %.2lf\n", myAvg);
	printf("The standard deviation of all intervals used: %.2lf\n", stdDev);
	return 0;
}
