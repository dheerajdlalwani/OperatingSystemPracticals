#include <stdio.h>
#include <math.h>

#define MAX 100

int main()
{
    int number_of_tracks, total_head_movement = 0, at_head, tracks[MAX], i, on_track;

    printf("Please enter number of tracks: ");
    scanf("%d", &number_of_tracks);

    printf("Please enter the tracks: \n");
    for (i = 0; i < number_of_tracks; i++)
    {
        printf("Track [%d] = ", i);
        scanf("%d", &tracks[i]);
    }

    printf("Please enter initial head position: ");
    scanf("%d", &at_head);

    printf("The  following will be the order for FCFS: \n");

    for (i = 0; i < number_of_tracks; i++)
    {
        on_track = tracks[i];
        total_head_movement = total_head_movement + abs(on_track - at_head);
        printf("%d --> %d = %d\n", at_head, on_track, abs(on_track - at_head));
        at_head = on_track;
    }

    printf("Total head movement = %d\n", total_head_movement);
    printf("Average head movement = %f", (float)total_head_movement / number_of_tracks);

    return 0;
}