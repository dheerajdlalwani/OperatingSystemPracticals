#include <stdio.h>
#include <math.h>
#define MAX 100

struct track
{
    int number;
    int visited;
};

struct track queue[MAX];

int number_of_tracks;

int get_closest_track_index(int current_track)
{
    int i;
    int closest;
    closest = 0;
    for(i = 0; i < number_of_tracks; i++)
    {
        if(queue[i].visited == 0)
        {
            if (abs(current_track - queue[i].number) > abs(current_track - queue[closest].number) )
            {
                closest = i;
            }
        }
    }
    for(i = 0; i < number_of_tracks; i++)
    {
        if(queue[i].visited == 0)
        {
        if (abs(current_track - queue[i].number) <= abs(current_track - queue[closest].number) )
            {
                closest = i;
            }
        }
    }
    return closest;
}

int main()
{
    int total_head_movement = 0, current_head, start_head, i, counter, next_closest;
    struct track next_node;
    printf("\nPlease enter number of tracks: ");
    scanf("%d", &number_of_tracks);
    printf("\nPlease enter the tracks: \n\n");
    for (i = 0; i < number_of_tracks; i++)
    {
        printf("Track [%d] = ", i);
        scanf("%d", &queue[i].number);
        queue[i].visited = 0;
    }
    printf("\nStart: --> ");
    for (i = 0; i < number_of_tracks; i++)
    {
        printf("%d --> ", queue[i].number);
    }
    printf(":End\n\n");
    printf("Please enter initial head position: ");
    scanf("%d", &start_head);
    printf("\nStarting at Track: %d\n\n", start_head);
    counter = number_of_tracks;
    printf("The following will be the order according to SSTF: \n");
    printf("\nStart: --> ");
    total_head_movement = 0;
    current_head = start_head;
    do
    {
        printf("%d --> ", current_head);
        if(queue[get_closest_track_index(current_head)].visited == 1)
        {
            break;
        }
        else
        {
            next_node = queue[get_closest_track_index(current_head)];
            queue[get_closest_track_index(current_head)].visited = 1;       
            next_closest = next_node.number;
            total_head_movement += abs(current_head - next_closest);
            current_head = next_closest;
            counter--;
        }
    }
    while(counter >= 0);
    printf(":End\n\n");
    printf("Total head movement = %d\n\n", total_head_movement);
    printf("Average head movement = %f\n\n", (float)total_head_movement/(float)number_of_tracks);
}