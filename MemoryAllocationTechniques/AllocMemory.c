#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

struct section
{
	int memory;
	bool occupiedStatus;
	char process[3];
	struct section *next;
};

struct section *sectionStart, *sectionEnd, *sectionNext, *kaamKaSection;

void inputMemoryStatus()
{
	bool ongoing = true;
	char yesNo;
	printf("This will take input of the current memory status.\n");

	do
	{
		if (sectionStart == NULL)
		{
			struct section *sectionStart;
			sectionStart = (struct section *)malloc(sizeof(struct section));
			printf("Please enter Process name (Enter f if the memory block is free) : ");
			scanf("%s", sectionStart->process);
			getchar();
			printf("Please enter %s memory : ", sectionStart->process);
			scanf("%d", &sectionStart->memory);
			getchar();
			if (sectionStart->process == "f")
			{
				sectionStart->occupiedStatus = false;
			}
			else
			{
				sectionStart->occupiedStatus = true;
			}
			printf("Do you want to add next section [Y/n] : ");
			scanf("%c", &yesNo);
			if (tolower(yesNo) == 'n')
			{
				ongoing = false;
				sectionStart->next = NULL;
				sectionEnd = sectionStart;
				break;
			}
			else
			{
				continue;
			}
		}
		else
		{
			sectionNext = (struct section *)malloc(sizeof(struct section));
			printf("Please enter Process name: ");
			scanf("%s", sectionNext->process);
			printf("Please enter memory needed for %s: ", sectionNext->process);
			scanf("%d", &sectionNext->memory);
			sectionNext->occupiedStatus = true;
			sectionNext->next = NULL;
			sectionEnd->next = sectionNext;
			printf("Do you want to add next section [Y/n] : ");
			yesNo = fgetc(stdin);
			if (tolower(yesNo) == 'n')
			{
				ongoing = false;
				sectionNext->next = NULL;
				sectionEnd = sectionNext;
				break;
			}
			else
			{
				continue;
			}
		}
	} while (ongoing);
}

bool inputNewProcess()
{
	// TODO
	printf("This will take input of the new process.\n");
	return false;
}

bool insertBestFit()
{
	// TODO
	printf("This will insert the new process in the memory, using best fit.\n");
	return false;
}

bool insertFirstFit()
{
	// TODO
	printf("This will insert the new process in the memory, using first fit.\n");
	return false;
}

bool insertWorstFit()
{
	// TODO
	printf("This will insert the new process in the memory, using worst fit.\n");
	return false;
}

void printMemoryStatus()
{
	// TODO
	printf("This will print the status of the memory.\n");
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
	printf("Welcome to memory simulation system.\n\n");
	inputMemoryStatus();
	printMemoryStatus();
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