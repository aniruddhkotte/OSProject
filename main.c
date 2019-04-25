#include <stdio.h>
#include<windows.h>
#include <string.h>

int process[4][2] = {{0, 20}, {5, 36}, {13, 19}, {17, 42}};	//Arrival and Burst times respectively
float priority[4] = {0.0};	// Array to calculate and store priorities of the processes initialized to '0'
int bursts[4] = {20, 36, 19, 42};	// Copy of burst times used to print at the end
int waiting[4] = {0};	// Waiting times of the processes initialized to '0'
int turnAround[4] = {0};	// Same as above
int completion[4] = {0};	// Same as above
const arrival =0, burst =1;	// Used to refer to the corresponding values in the 'process' array
int currenTime = 0;

COORD coord = {0, 0};	// Variable used to postition the cursor on the consol

int updatePriority();	// Declaration of the function used to calculate the priorities
void main() {
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
	
	int turnAroundSum = 0;
	int waitingSum = 0;
	for(i=0; i<4; i++) {
		turnAround[i] = completion[i] - process[i][arrival];
		turnAroundSum += turnAround[i];
		waitingSum += waiting[i];
	}
	
	float waitingAvg = waitingSum/4.0;
	float turnAroundAvg = turnAroundSum/4.0;
}

/*Calculates the priorities of each process based on
the waiting time and burst time of the corresponding processes*/
int updatePriority() {
	int x;
	for(x=0; x<4; x++) {
		if(process[x][burst] != 0 && process[x][arrival] <= currenTime) {
			waiting[x] = currenTime-process[x][arrival];
			priority[x] += 1 + (waiting[x]/process[x][burst]);
		}
	}
	
	int high = 0;
	for (x=0; x<4; x++) {
		if(priority[x]>high) {
			high = x;
		}
	}
	return high;
	
	printf("---------------------------------------------------------------------------------------------");
	z = 1;
	cursorPos(8, z);
	printf("Process");
	cursorPos(22, z);
	printf("Arrival Time");
	cursorPos(40, z);
	printf("Burst Time");
	cursorPos(55, z);
	printf("Turnaround Time");
	cursorPos(75, z);
	printf("Waiting Time");
	z += 1;
	cursorPos(0, z);
	printf("---------------------------------------------------------------------------------------------");
}

//Function to position the cursor on the consol
void cursorPos (int x, int y) {
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
