#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

int n;

int referenceString[MAX] = {0};
int frames[3] = {0};
int frameToBeFilled = 0;
int didItHit = 0;

int main()
{
	int i, j, k, l, hit = 0, miss = 0;
	printf("Please enter the number of refrences in the memory string: ");
	scanf("%d", &n);
	printf("Please start entering the reference string: \n");
	for (i = 0; i < n; i++)
	{
		printf("Reference [%d] = ", i);
		scanf("%d", &referenceString[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
		{
			didItHit = 0;
			if (frames[j] == referenceString[i])
			{
				hit++;
				printf("%d was a hit.  Frames: ", referenceString[i]);
				for (k = 0; k < 3; k++)
				{
					printf("| %d ", frames[j]);
				}
				printf(" |");
				didItHit = 1;
				break;
			}
		}
		if (didItHit != 1)
		{
			frames[frameToBeFilled] = referenceString[i];
			miss++;
			printf("%d was a miss. Frames: ", referenceString[i]);
			for (l = 0; l < 3; l++)
			{
				printf("| %d ", frames[l]);
			}
			printf(" |");
			frameToBeFilled = (frameToBeFilled + 1) % 3;
			didItHit = 0;
		}

		printf("\n");
	}
	printf("Total Hits = %d\n", hit);
	printf("Total Misses = %d\n", miss);
	printf("Hit ratio = %f\n", ((float)hit) / n);
	printf("Miss ratio = %f\n", ((float)miss) / n);
	return 0;
}