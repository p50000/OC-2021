#include <stdio.h>
#define MAX_PROCESS 100

struct process 
{
    int arrival_time;
    int burst_time;
};

void schedule_processes(struct process processes[], int n) 
{
    int completion_time[MAX_PROCESS], turnaround_time[MAX_PROCESS], waiting_time[MAX_PROCESS];
    int current_time  = processes[0].arrival_time;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    for (int i = 0; i < n; i++) 
    {
        if(current_time < processes[i].arrival_time) 
        {
            current_time = processes[i].arrival_time;
        }

        current_time += processes[i].burst_time;
        completion_time[i] = current_time;
        turnaround_time[i] = current_time - processes[i].arrival_time;
        waiting_time[i] = turnaround_time[i] - processes[i].burst_time;

        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    printf("P#\tAT\tBT\tCT\tTAT\tWT\n\n");
    for (int i = 0; i < n; i++) 
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, 
                processes[i].arrival_time, processes[i].burst_time, completion_time[i], turnaround_time[i], waiting_time[i]);
    }

    printf("\n\nAverage turn around time = %f\nAvarage waiting time = %f\n", (double)total_turnaround_time / n, (double)total_waiting_time / n);
}

int main()
{
    struct process processes[] = {{4, 1}, {6, 4}, {10, 2}, {10, 3}, {13, 4}};
    schedule_processes(processes, 5);
}