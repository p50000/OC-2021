#include <stdio.h>
#include <limits.h>
#define MAX_PROCESS 100

struct process 
{
    int arrival_time;
    int burst_time;
};

void schedule_processes(struct process processes[], int n) 
{
    int completion_time[MAX_PROCESS], turnaround_time[MAX_PROCESS], waiting_time[MAX_PROCESS];
    int is_complete[MAX_PROCESS];
    for(int i = 0; i < MAX_PROCESS; ++i)
    {
        is_complete[i] = 0;
    }

    int current_time  = processes[0].arrival_time;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    while (1)
    {
        int shortest_job = -1;
        int min_burst_time = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (!is_complete[j] && min_burst_time > processes[j].burst_time && processes[j].arrival_time <= current_time) 
            {
                min_burst_time = processes[j].burst_time;
                shortest_job = j;
            }
        }
        if (shortest_job == -1) break;

        if (current_time < processes[shortest_job].arrival_time) 
        {
            current_time = processes[shortest_job].arrival_time;
        }

        current_time += processes[shortest_job].burst_time;
        completion_time[shortest_job] = current_time;
        turnaround_time[shortest_job] = current_time - processes[shortest_job].arrival_time;
        waiting_time[shortest_job] = turnaround_time[shortest_job] - processes[shortest_job].burst_time;

        total_waiting_time += waiting_time[shortest_job];
        total_turnaround_time += turnaround_time[shortest_job];

        is_complete[shortest_job] = 1;
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
    struct process processes[] = {{0, 2}, {0, 1}, {1, 4}};
    schedule_processes(processes, 3);
}