#include <stdio.h>

int main() {
    int incomingStream[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int totalPageFaults = 0;
    int numFrames = 3;
    int currentIndex, frameIndex, search, numPages;

    numPages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    printf(" Incoming Page \t Frame 1 \t Frame 2 \t Frame 3 \n");

    int frames[numFrames]; // Array to hold the frames

    // Initialize frames with -1 to indicate empty frames
    for (currentIndex = 0; currentIndex < numFrames; currentIndex++) {
        frames[currentIndex] = -1;
    }

    // Iterate through the incoming pages
    for (currentIndex = 0; currentIndex < numPages; currentIndex++) {
        search = 0;

        // Search for the page in the frames
        for (frameIndex = 0; frameIndex < numFrames; frameIndex++) {
            if (incomingStream[currentIndex] == frames[frameIndex]) {
                search++;
                totalPageFaults--; // Decrement if page is found in frame
            }
        }

        totalPageFaults++;

        // If there are empty frames or the page is not found in any frame
        if ((totalPageFaults <= numFrames) && (search == 0)) {
            frames[currentIndex] = incomingStream[currentIndex];
        } else if (search == 0) {
            // Replace page in the frame with the least recently used page
            frames[(totalPageFaults - 1) % numFrames] = incomingStream[currentIndex];
        }

        // Print the current state
        printf("%d\t\t\t", incomingStream[currentIndex]);
        for (frameIndex = 0; frameIndex < numFrames; frameIndex++) {
            if (frames[frameIndex] != -1) {
                printf(" %d\t\t\t", frames[frameIndex]);
            } else {
                printf(" - \t\t\t");
            }
        }
        printf("\n");
    }

    printf("Total Page Faults:\t%d\n", totalPageFaults);
    return 0;
}
