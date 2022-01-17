#include <stdio.h>

int findLRU(int time[], int n)
{
	int i, minimum = time[0], pos = 0;

	for (i = 1; i < n; ++i)
	{
		if (time[i] < minimum)
		{
			minimum = time[i];
			pos = i;
		}
	}

	return pos;
}

int main()
{
	int no_of_frames, lengthOfReferenceString, counter = 0, flag1, flag2, i, j, k, l, pos, faults = 0, miss, hit;
	int frames[30] = {0}, pages[30], time[30];
	printf("Enter number of frames: ");
	scanf("%d", &no_of_frames);
	printf("Enter length of reference string: ");
	scanf("%d", &lengthOfReferenceString);

	printf("Enter reference string: \n");

	for (i = 0; i < lengthOfReferenceString; ++i)
	{
		printf("referenceString[%d] = ", i);
		scanf("%d", &pages[i]);
	}

	for (i = 0; i < lengthOfReferenceString; ++i)
	{
		flag1 = flag2 = 0;

		for (j = 0; j < no_of_frames; ++j)
		{
			if (frames[j] == pages[i])
			{
				counter++;
				time[j] = counter;
				flag1 = flag2 = 1;
				printf("%d was a hit.  Frames: ", pages[i]);
				for (l = 0; l < no_of_frames; ++l)
				{
					printf("| %d ", frames[l]);
				}
				printf(" |");

				break;
			}
		}

		if (flag1 == 0)
		{
			for (j = 0; j < no_of_frames; ++j)
			{
				if (frames[j] == 0)
				{
					counter++;
					faults++;
					frames[j] = pages[i];
					time[j] = counter;
					flag2 = 1;
					printf("%d was a miss. Frames: ", pages[i]);
					for (k = 0; k < no_of_frames; ++k)
					{
						printf("| %d ", frames[k]);
					}
					printf(" |");
					break;
				}
			}
		}

		if (flag2 == 0)
		{
			pos = findLRU(time, no_of_frames);
			counter++;
			faults++;
			frames[pos] = pages[i];
			time[pos] = counter;
			printf("%d was a miss. Frames: ", pages[i]);
			for (j = 0; j < no_of_frames; ++j)
			{
				printf("| %d ", frames[j]);
			}
			printf(" |");
		}
		printf("\n");
	}

	miss = faults;
	hit = lengthOfReferenceString - miss;

	printf("Total Hits = %d\n", hit);
	printf("Total Misses =  %d\n", miss);
	printf("Hit ratio = %f\n", ((float)hit) / lengthOfReferenceString);
	printf("Miss ratio = %f\n", ((float)miss) / lengthOfReferenceString);
	return 0;
}