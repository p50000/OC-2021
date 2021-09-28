#include <stdio.h>
#include <limits.h>
#define MAX_PROCESS 100

struct process 
{
    int arrival_time;
    int burst_time;
};

int find_minimum_arrival_time(struct process processes[], int time_left[], int n) 
{
    int min_arr_time = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (time_left[i] && processes[i].arrival_time < min_arr_time) {
            min_arr_time = processes[i].arrival_time;
        }
    }
    return min_arr_time;
}

int min(int a, int b)
{
    return a > b ? b : a;
}

void schedule_processes(struct process processes[], int n, int quantum) 
{
    int completion_time[MAX_PROCESS], turnaround_time[MAX_PROCESS], waiting_time[MAX_PROCESS];
    int time_left[MAX_PROCESS];
    for(int i = 0; i < n; ++i)
    {
        time_left[i] = processes[i].burst_time;
    }

    int current_time  = processes[0].arrival_time;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    int completed_tasks = 0;
    int actually_launched_in_iteration = 0;
    
    while (completed_tasks < n)
    {
        for (int i = 0; i < n; i++) 
        {
            if (processes[i].arrival_time > current_time || !time_left[i]) continue;
            actually_launched_in_iteration++;
            current_time += min(quantum, time_left[i]);
            time_left[i] -= min(quantum, time_left[i]);
            if (time_left[i] == 0)
            {
                completion_time[i] = current_time;
                turnaround_time[i] = current_time - processes[i].arrival_time;
                waiting_time[i] = turnaround_time[i] - processes[i].burst_time;

                total_waiting_time += waiting_time[i];
                total_turnaround_time += turnaround_time[i];
                completed_tasks++;
            }
        }

        if (completed_tasks < n && actually_launched_in_iteration == 0) {
            current_time = find_minimum_arrival_time(processes, time_left, n);
        }
        actually_launched_in_iteration = 0;
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
    schedule_processes(processes, 5, 2);
}