#include <stdio.h>

void implementFirstFit(int blockSizes[], int numBlocks, int processSizes[], int numProcesses) {
    int allocation[numProcesses]; // Store the block id of allocated blocks for processes
    int isOccupied[numBlocks]; // Track whether a block is occupied

    // Initialize allocation indexes to -1 (no allocation)
    for (int i = 0; i < numProcesses; i++) {
        allocation[i] = -1;
    }

    // Initialize occupied status of blocks to 0 (unoccupied)
    for (int i = 0; i < numBlocks; i++) {
        isOccupied[i] = 0;
    }

    // Assign each process to an available block
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numBlocks; j++) {
            if (!isOccupied[j] && blockSizes[j] >= processSizes[i]) {
                allocation[i] = j;
                isOccupied[j] = 1;
                break;
            }
        }
    }

    // Print allocation results
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d \t\t\t %d \t\t\t", i + 1, processSizes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int blockSizes[] = {30, 5, 10};
    int processSizes[] = {10, 6, 9};
    int numBlocks = sizeof(blockSizes) / sizeof(blockSizes[0]);
    int numProcesses = sizeof(processSizes) / sizeof(processSizes[0]);

    implementFirstFit(blockSizes, numBlocks, processSizes, numProcesses);

    return 0;
}
