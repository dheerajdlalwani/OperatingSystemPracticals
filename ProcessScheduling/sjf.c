#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int n;
float averageTurnAroundTime, averageWaitTime;

struct process
{
	int burst_time;
	int turnaround_time;
	int waiting_time;
	int number;
};

struct process listOfProcesses[MAX];

void getProcesses()
{
	int i;
	for (i = 0; i < n; i++)
	{
		listOfProcesses[i].number = i;
		printf("Please enter P%d burst time: ", i);
		scanf("%d", &listOfProcesses[i].burst_time);
		getchar();
	}
}

void calculateTurnAroundTime()
{
	int i = 0;
	float sum = 0;
	for (i = 0; i < n; i++)
	{
		sum = sum + listOfProcesses[i].burst_time;
		listOfProcesses[i].turnaround_time = sum;
	}
	sum = 0;
	for (i = 0; i < n; i++)
	{
		sum = sum + listOfProcesses[i].turnaround_time;
	}
	averageTurnAroundTime = sum / n;
}

void calculateWaitingTime()
{
	int i = 0;
	float sum = 0;
	for (i = 0; i < n; i++)
	{
		listOfProcesses[i].waiting_time = sum;
		sum = sum + listOfProcesses[i].burst_time;
	}
	sum = 0;
	for (i = 0; i < n; i++)
	{
		sum = sum + listOfProcesses[i].waiting_time;
	}
	averageWaitTime = sum / n;
}

void printTable()
{
	int i = 0;
	printf("\n-----------------------------------------------------\n");
	printf("| %3s | %10s | %12s | %15s |\n", "Pid", "Burst Time", "Waiting Time", "Turnaround Time");
	printf("|-----|------------|--------------|-----------------|\n");
	for (i = 0; i < n; i++)
	{
		printf("| P%d  | %10d | %12d | %15d |\n", listOfProcesses[i].number, listOfProcesses[i].burst_time, listOfProcesses[i].waiting_time, listOfProcesses[i].turnaround_time);
	}
	printf("-----------------------------------------------------\n");
	printf("\nAverage Waiting Time = %g units.\n", averageWaitTime);
	printf("\nAverage Turnaround Time = %g units.\n", averageTurnAroundTime);
}

void sjf()
{
	struct process temp;
	int pos, cpos;
	for (pos = 0; pos <= n - 2; pos++)
	{
		for (cpos = pos + 1; cpos <= n - 1; cpos++)
		{
			if (listOfProcesses[pos].burst_time > listOfProcesses[cpos].burst_time)
			{
				temp = listOfProcesses[pos];
				listOfProcesses[pos] = listOfProcesses[cpos];
				listOfProcesses[cpos] = temp;
			}
		}
	}
}

int main()
{
	printf("This is the start of program.\n");
	printf("Please enter the number of processes: ");
	scanf("%d", &n);
	getProcesses();
	sjf();
	calculateTurnAroundTime();
	calculateWaitingTime();
	printTable();
	return 0;
}