#include <stdio.h>

int main() {
    int total_frames, window_size;
    int i = 1, j, ack;

    printf("Enter total number of frames to send: ");
    scanf("%d", &total_frames);

    printf("Enter window size: ");
    scanf("%d", &window_size);

    printf("\n--- Selective Repeat ARQ Simulation ---\n");

    while (i <= total_frames) {
        printf("\nSending frames: ");
        for (j = i; j < i + window_size && j <= total_frames; j++)
          {
            printf("%d ", j);
          }
        for (j = i; j < i + window_size && j <= total_frames; j++) {
            printf("\nDid you receive ACK for frame %d? (1 = Yes, 0 = No): ", j);
            scanf("%d", &ack);

            if (ack == 0) {
                printf("Resending frame %d...\n", j);
                printf("Frame %d received successfully now.\n", j);
            } else {
                printf("Frame %d acknowledged successfully.\n", j);
            }
        }
        i = i + window_size;
    }

    printf("\nAll frames sent and acknowledged successfully.\n");
    return 0;
}
