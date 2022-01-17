#include<stdio.h>
#define MAX 100

void main()
{
    int number_of_processes, number_of_resources, i, j, k, allocation_matrix[MAX][MAX], max[MAX][MAX], available[MAX];
    int finished_status[MAX],safe_sequence[MAX], ind=0, need[MAX][MAX];
    printf("Enter number of processes: ");
    scanf("%d",&number_of_processes);
    printf("Enter the number of Resources: ");
    scanf("%d",&number_of_resources);
    printf("Enter the Values of Allocation Matrix: \n");
    for(i=0;i<number_of_processes;i++)
    {
        for(j=0;j<number_of_resources;j++)
        {
            printf("Enter value at position [%d,%d] :",i+1,j+1);
            scanf("%d",&allocation_matrix[i][j]);
        }
    }
    printf("Enter the Values of Max Matrix: \n");
    for(i=0;i<number_of_processes;i++)
    {
        for(j=0;j<number_of_resources;j++)
        {
            printf("Enter value at position [%d,%d] :",i+1,j+1);
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the values in available: \n");
    for(j=0;j<number_of_resources;j++)
    {
        printf("Enter value at position [%d] :",j+1);
        scanf("%d",&available[j]);
    }
    for(k=0;k<number_of_processes;k++)
    {
        finished_status[k]=0;
    }
    for(i=0;i<number_of_processes;i++)
    {
        for(j=0;j<number_of_resources;j++)
        {
            need[i][j] = max[i][j] - allocation_matrix[i][j];
        }
    }
    int y=0;
    for(k=0;k<number_of_processes;k++)    
    {
        for(i=0;i<number_of_processes;i++)
        {
            if(finished_status[i]==0)     
            {
                int flag = 0;
                for(j=0;j<number_of_resources;j++)
                {
                    if(need[i][j] > available[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    safe_sequence[ind++] = i;
                    for(y=0;y<number_of_resources;y++)
                    {
                        available[y] = available[y] + allocation_matrix[i][y];
                    }
                    finished_status[i]=1;
                }
            }
        }
    }
    printf("The safe sequence is: \n");
    for(i=0;i<number_of_processes-1;i++)
    {
        printf(" P%d ->", safe_sequence[i]);
    }
    printf(" P%d", safe_sequence[number_of_processes-1]);
}
