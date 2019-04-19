#include<stdio.h>
struct process
{
      char process_name;
      int arrival_time, burst_time, completion_time, waiting_time, turnaround_time, priority_of_process;
      int status;
}
process_queue[10];
int maxval;
void Arrival_Time_Sorting()
{
      struct process temp;
      int a, b;
      for(a = 0; a < maxval - 1; a++)
      {
            for(b = a + 1; b < maxval; b++)
            {
                  if(process_queue[a].arrival_time > process_queue[b].arrival_time)
                  {
                        temp = process_queue[a];
                        process_queue[a] = process_queue[b];
                        process_queue[b] = temp;
                  }
            }
      }
}
int main()
{
      int a, time = 0, burst_time = 0, largest;
      char c;
      float wait_time = 0, turnaround_time = 0, average_waiting_time, average_turnaround_time;
      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &maxval);
      for(a = 0, c = 'A'; a < maxval; a++, c++)
      {
            process_queue[a].process_name = c;
            printf("\nEnter Details For Process[%C]:\n", process_queue[a].process_name);
            printf("Enter Arrival Time:\t");
            scanf("%d", &process_queue[a].arrival_time );
            printf("Enter Burst Time:\t");
            scanf("%d", &process_queue[a].burst_time);
            printf("Enter Priority of process:\t");
            scanf("%d", &process_queue[a].priority_of_process);
            process_queue[a].status = 0;
            burst_time = burst_time + process_queue[a].burst_time;
      }
      Arrival_Time_Sorting();
      process_queue[9].priority_of_process = -9999;
      printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");
      for(time = process_queue[0].arrival_time; time < burst_time;)
      {
            largest = 9;
            for(a = 0; a< maxval; a++)
            {
                  if(process_queue[a].arrival_time <= time && process_queue[a].status != 1 && process_queue[a].priority_of_process > process_queue[largest].priority_of_process)
                  {
                        largest = a;
                  }
            }
            time = time + process_queue[largest].burst_time;
            process_queue[largest].completion_time = time;
            process_queue[largest].waiting_time = process_queue[largest].completion_time - process_queue[largest].arrival_time - process_queue[largest].burst_time;
            process_queue[largest].turnaround_time = process_queue[largest].completion_time - process_queue[largest].arrival_time;
            process_queue[largest].status = 1;
            wait_time = wait_time + process_queue[largest].waiting_time;
            turnaround_time = turnaround_time + process_queue[largest].turnaround_time;
            printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d", process_queue[largest].process_name, process_queue[largest].arrival_time, process_queue[largest].burst_time, process_queue[largest].priority_of_process, process_queue[largest].waiting_time);
      }
      average_waiting_time = wait_time / maxval;
      average_turnaround_time = turnaround_time / maxval;
      printf("\n\nAverage waiting time:\t%f\n", average_waiting_time);
      printf("Average Turnaround Time:\t%f\n", average_turnaround_time);
}
