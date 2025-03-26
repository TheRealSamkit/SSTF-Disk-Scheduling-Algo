#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the index of the minimum distance request
int findMinDistance(int arr[], int seek[], int n, int curr_head) {
    int min = INT_MAX;
    int min_index = -1;

    for (int i = 0; i < n; i++) {
        if (seek[i] != -1) {
            int distance = abs(arr[i] - curr_head);
            if (distance < min) {
                min = distance;
                min_index = i;
            }
        }
    }
    return min_index;
}

// Function to implement SSTF disk scheduling
void sstf(int arr[], int n, int head) {
    int *seek = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        seek[i] = i;
    }
    
    printf("Disk Scheduling Sequence (SSTF):\n");

    int total_seek_time = 0;
    int curr_head = head;

    for (int i = 0; i < n; i++) {
        int index = findMinDistance(arr, seek, n, curr_head);
        if (index == -1) break;
        
        printf("%d ", arr[index]);
        total_seek_time += abs(arr[index] - curr_head);
        curr_head = arr[index];

        seek[index] = -1; // Mark this request as processed
    }

    printf("\nTotal Seek Time: %d\n", total_seek_time);
    free(seek);
}

int main() {
    // Number of disk requests
    int n;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the disk requests
    int *arr = (int *)malloc(n * sizeof(int));

    // Disk requests
    printf("Enter Requests for scheduling: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initial head position
    int head;
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // Call SSTF function
    sstf(arr, n, head);

    // Free allocated memory
    free(arr);

    return 0;
}