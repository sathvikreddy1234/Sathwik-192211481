#include <stdio.h>

int main() {
    int num_processes = 3;
    int burst_times[] = {10, 15, 25};
    int waiting_times[num_processes], turnaround_times[num_processes];

    // Initialize the waiting time for the first process to 0
    waiting_times[0] = 0;

    // Calculate waiting and turnaround times for each process
    for (int i = 1; i < num_processes; i++) {
        waiting_times[i] = waiting_times[i-1] + burst_times[i-1];
    }

    for (int i = 0; i < num_processes; i++) {
        turnaround_times[i] = waiting_times[i] + burst_times[i];
    }

    // Calculate the average waiting and turnaround times
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    for (int i = 0; i < num_processes; i++) {
        avg_waiting_time += waiting_times[i];
        avg_turnaround_time += turnaround_times[i];
    }
    avg_waiting_time /= num_processes;
    avg_turnaround_time /= num_processes;

    // Print the results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, burst_times[i], waiting_times[i], turnaround_times[i]);
    }
    printf("Average Waiting Time: %f\n", avg_waiting_time);
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);

    return 0;
}
