#include <stdio.h>

typedef struct Process {
    int id;           // Process Number
    int burstTime;    // Burst Time
    int arrivalTime;  // Arrival Time
    float turnaroundTime; // Turn Around Time
    float waitingTime;   // Waiting Time
} Process;

void sortByArrivalTime(Process[], int);
void calculateTimes(Process[], int);

int main() {
    int numProcesses, i;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);
    
    Process processes[numProcesses];
    
    for (i = 0; i < numProcesses; i++) {
        processes[i].id = i;
        printf("Enter the data for Process %d\n", processes[i].id);
        printf("Enter Burst Time: ");
        scanf("%d", &(processes[i].burstTime));
        printf("Enter Arrival Time: ");
        scanf("%d", &(processes[i].arrivalTime));
    }
    
    sortByArrivalTime(processes, numProcesses);
    
    printf("Process\tBurst Time\tArrival Time\tTurn Around Time\tWaiting Time\n");
    calculateTimes(processes, numProcesses);
    
    float avgTurnaroundTime = 0, avgWaitingTime = 0;
    for (i = 0; i < numProcesses; i++) {
        avgTurnaroundTime += processes[i].turnaroundTime;
        avgWaitingTime += processes[i].waitingTime;
        printf("%5d\t%10d\t%12d\t%15.3f\t%12.3f\n",
               processes[i].id, processes[i].burstTime, processes[i].arrivalTime,
               processes[i].turnaroundTime, processes[i].waitingTime);
    }
    
    printf("Average Turn Around Time: %.3f\nAverage Waiting Time: %.3f\n",
           avgTurnaroundTime / numProcesses, avgWaitingTime / numProcesses);
    
    return 0;
}

void sortByArrivalTime(Process arr[], int n) {
    int i, j;
    Process temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i].arrivalTime > arr[j].arrivalTime) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void calculateTimes(Process arr[], int n) {
    int temp = 0;
    for (int i = 0; i < n; i++) {
        temp += arr[i].burstTime;
        arr[i].turnaroundTime = temp - arr[i].arrivalTime;
        arr[i].waitingTime = arr[i].turnaroundTime - arr[i].burstTime;
    }
