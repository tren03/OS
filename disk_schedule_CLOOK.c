#include <stdlib.h>
#include <stdio.h>  // Don't forget to include this header for printf

int main() {
    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d", &initial);
    printf("Enter total disk size\n");
    scanf("%d", &size);
    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d", &move);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp;
                temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }
    
    int index;
    for (i = 0; i < n; i++) {
        if (initial < RQ[i]) {
            index = i;
            break;
        }
    }
    
    if (move == 1) {
        printf("Head moves from %d to %d\n", initial, RQ[index]);
        for (i = index; i < n; i++) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
            printf("Head moves from %d to %d\n", initial, RQ[i+1]);
        }
        for (i = 0; i < index; i++) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
            printf("Head moves from %d to %d\n", initial, RQ[i+1]);
        }
    } else {
        printf("Head moves from %d to %d\n", initial, RQ[index-1]);
        for (i = index - 1; i >= 0; i--) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
            printf("Head moves from %d to %d\n", initial, RQ[i-1]);
        }
        for (i = n - 1; i >= index; i--) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
            if(i>index)  // Only print the message if it's not the last move
                printf("Head moves from %d to %d\n", initial, RQ[i-1]);
        }
    }
    
    printf("Total head movement is %d\n", TotalHeadMoment);
    return 0;
}
