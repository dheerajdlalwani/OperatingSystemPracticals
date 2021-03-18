#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct section
{
	int memory;
	bool occupiedStatus;
	char process[5];
	struct section *next;
};

struct memory
{
	int sectionCount;
	struct section *start;
	struct section *end;
};

struct section *sectionStart,
    *sectionEnd, *sectionNext, *sectionNew, *sectionPrevious;

struct memory *memInfo;

void initializeMemory()
{
	printf("Initializing memory...\n");
	memInfo = (struct memory *)malloc(sizeof(struct memory));
	memInfo->sectionCount = 0;
	memInfo->start = NULL;
	memInfo->end = NULL;
}

void inputMemoryStatus()
{
	bool ongoing = true;
	char yesNo;
	printf("This will take input of the current memory status.\n");

	do
	{
		if (memInfo->start == NULL)
		{
			// struct section *sectionStart;
			sectionNew = (struct section *)malloc(sizeof(struct section));
			printf("Please enter Process name (Enter free if the memory block is free) : ");
			scanf("%s", sectionNew->process);
			getchar();
			printf("Please enter %s memory : ", sectionNew->process);
			scanf("%d", &sectionNew->memory);
			getchar();
			if (strcmp(sectionNew->process, "free") == 0)
			{
				sectionNew->occupiedStatus = false;
			}
			else
			{
				sectionNew->occupiedStatus = true;
			}
			printf("Debug: Printing contents of sectionStart: %d | %s\n", sectionNew->memory, sectionNew->process);
			printf("Do you want to add next section [Y/n] : ");
			scanf("%c", &yesNo);
			if (tolower(yesNo) == 'n')
			{
				ongoing = false;
				sectionNew->next = NULL;
				memInfo->start = sectionNew;
				memInfo->end = sectionNew;
				break;
			}
			else
			{
				memInfo->start = sectionNew;
				memInfo->end = sectionNew;
				continue;
			}
		}
		else
		{
			sectionNew = (struct section *)malloc(sizeof(struct section));
			printf("Please enter Process name (Enter free if the memory block is free) : ");
			scanf("%s", sectionNew->process);
			getchar();
			printf("Please enter %s memory : ", sectionNew->process);
			scanf("%d", &sectionNew->memory);
			getchar();
			if (strcmp(sectionNew->process, "free") == 0)
			{
				sectionNew->occupiedStatus = false;
			}
			else
			{
				sectionNew->occupiedStatus = true;
			}
			printf("Debug: Printing contents of sectionNew: %d | %s\n", sectionNew->memory, sectionNew->process);
			printf("Do you want to add next section [Y/n] : ");
			scanf("%c", &yesNo);
			if (tolower(yesNo) == 'n')
			{
				ongoing = false;
				sectionNew->next = NULL;
				memInfo->end->next = sectionNew;
				memInfo->end = sectionNew;
				break;
			}
			else
			{
				sectionNew->next = NULL;
				memInfo->end->next = sectionNew;
				memInfo->end = sectionNew;
				continue;
			}
		}
	} while (ongoing);
}

void inputNewProcess()
{
	sectionNew = (struct section *)malloc(sizeof(struct section));
	if (sectionNew != NULL)
	{
		printf("Please enter Process name : ");
		scanf("%s", sectionNew->process);
		getchar();
		printf("Please enter %s memory : ", sectionNew->process);
		scanf("%d", &sectionNew->memory);
		getchar();
		sectionNew->occupiedStatus = true;
		sectionNew->next = NULL;
		printf("Debug: Printing contents of sectionNew: %d | %s\n", sectionNew->memory, sectionNew->process);
	}
	else
	{
		printf("Insufficient memory, exiting .... \n");
	}
}

void printMemoryStatus()
{
	char status[3];
	printf("This will print the status of the memory.\n");
	printf("|  %8s  |  %7s  |  %7s  |\n", "Section", "Memory", "Status");
	sectionNext = memInfo->start;
	while (sectionNext != NULL)
	{
		if (sectionNext->occupiedStatus == 0)
		{
			strcpy(status, "F");
		}
		else
		{
			strcpy(status, "NF");
		}
		printf("|  %8s  |  %7d  |  %7s  |\n", sectionNext->process, sectionNext->memory, status);
		sectionNext = sectionNext->next;
	}
	printf("=============================================\n");
}

bool insertBestFit()
{
	// TODO
	printf("This will insert the new process in the memory, using best fit.\n");
	return false;
}

void insertFirstFit()
{
	// DOING
	printf("This will insert the new process in the memory, using first fit.\n");
	sectionPrevious = NULL;
	sectionNext = memInfo->start;
	while (sectionNext != NULL)
	{
		if (sectionNext->occupiedStatus == 0 && sectionNext->memory >= sectionNew->memory)
		{
			break;
		}
		sectionPrevious = sectionNext;
		sectionNext = sectionNext->next;
	}
	if (sectionPrevious == NULL && sectionNext->occupiedStatus == 0 && sectionNext->memory > sectionNew->memory)
	{
		sectionNew->next = memInfo->start;
		memInfo->start->memory = memInfo->start->memory - sectionNew->memory;
		memInfo->start = sectionNew;
		printf("Debug: on Line 189\n");
	}
	else if (sectionPrevious == NULL && sectionNext->occupiedStatus == 0 && sectionNext->memory == sectionNew->memory)
	{
		sectionNew->next = memInfo->start->next;
		memInfo->start = sectionNew;
		printf("Debug: on Line 195\n");
	}
	else if (sectionPrevious != NULL && sectionNext->occupiedStatus == 0 && sectionNext->memory > sectionNew->memory)
	{
		sectionNew->next = sectionPrevious->next;
		sectionNext->memory = sectionNext->memory - sectionNew->memory;
		sectionPrevious->next = sectionNew;
		printf("Debug: on Line 202\n");
	}
	else if (sectionPrevious != NULL && sectionNext->occupiedStatus == 0 && sectionNext->memory == sectionNew->memory)
	{
		sectionNew->next = sectionPrevious->next->next;
		sectionPrevious->next = sectionNew;
		printf("Debug: on Line 208\n");
	}
	else
	{
		printf("No sufficient memory slot available. Exiting...\n");
	}
	printMemoryStatus();
}

bool insertWorstFit()
{
	// TODO
	printf("This will insert the new process in the memory, using worst fit.\n");
	return false;
}

int menu()
{
	int choice;
	printf("1) Insert With Best Fit\n");
	printf("2) Insert With First Fit\n");
	printf("3) Insert With Worst Fit\n");
	printf("4) Exit\n");
	printf("Please enter your choice: ");
	scanf("%d", &choice);
	return choice;
}

int main()
{
	int choice;
	initializeMemory();
	printf("Welcome to memory simulation system.\n\n");
	inputMemoryStatus();
	printMemoryStatus();
	inputNewProcess();
	do
	{
		choice = menu();
		if (choice == 1)
		{
			insertBestFit();
		}
		else if (choice == 2)
		{
			insertFirstFit();
		}
		else if (choice == 3)
		{
			insertWorstFit();
		}
		else
		{
			exit(0);
		}
	} while (choice <= 4 && choice >= 1);

	return 0;
}