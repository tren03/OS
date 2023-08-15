#include <stdio.h>

typedef struct {
    int id;           // Process Number
    int burstTime;    // Burst Time
    int waitingTime;  // Waiting Time
    int turnaroundTime; // Turn Around Time
} Process;

void sortByBurstTime(Process[], int);
void calculateTimes(Process[], int);

int main() {
    Process processes[20];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i;
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &processes[i].burstTime);
    }

    sortByBurstTime(processes, n);
    calculateTimes(processes, n);

    float avgWaitingTime = 0, avgTurnaroundTime = 0;
    
    printf("\n\t PROCESS \t BURST TIME \t WAITING TIME \t TURNAROUND TIME\n");
    for (int i = 0; i < n; i++) {
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d",
               processes[i].id, processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);
        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
    }

    printf("\nAverage Waiting Time: %.2f", avgWaitingTime / n);
    printf("\nAverage Turnaround Time: %.2f", avgTurnaroundTime / n);

    return 0;
}

void sortByBurstTime(Process arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int k = i + 1; k < n; k++) {
            if (arr[i].burstTime > arr[k].burstTime) {
                Process temp = arr[i];
                arr[i] = arr[k];
                arr[k] = temp;
            }
        }
    }
}

void calculateTimes(Process arr[], int n) {
    arr[0].waitingTime = 0;
    arr[0].turnaroundTime = arr[0].burstTime;

    for (int i = 1; i < n; i++) {
        arr[i].waitingTime = arr[i - 1].waitingTime + arr[i - 1].burstTime;
        arr[i].turnaroundTime = arr[i - 1].turnaroundTime + arr[i].burstTime;
    }
}
