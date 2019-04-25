#include <stdio.h>
#include<windows.h>
#include <string.h>

int process[4][2] = {{0, 20}, {5, 36}, {13, 19}, {17, 42}};	//Arrival and Burst times respectively
float priority[4] = {0.0};	// Array to calculate and store priorities of the processes initialized to '0'
int bursts[4] = {20, 36, 19, 42};	// Copy of burst times used to print at the end

int updatePriority();	// Declaration of the function used to calculate the priorities
	
	int p, q, i, y, z;
	int sequence[4] = {0};
	
	int next = 0;
	for(i=0; i<4; i++) {
		next = updatePriority();	//Calling function to calculate priorities and return the process id of highest priority
		sequence[i] = next;
		//printf("%d\t", sequence[i]);
		currenTime += process[next][burst];		//Updating the current execution time by burst time
		completion[next] = currenTime;
		process[next][burst] = 0;
		priority[next] = 0;
	}
