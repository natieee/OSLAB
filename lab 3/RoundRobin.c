#include<stdio.h>

int main()
{
    int p[20], bt[20], rem_bt[20], wt[20], tat[20];
    int i, n, time_quantum, t = 0, done;
    float wtavg = 0, tatavg = 0;

    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        p[i] = i;
        printf("Enter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];  
        wt[i] = 0;
        tat[i] = 0;
    }

    printf("Enter Time Quantum -- ");
    scanf("%d", &time_quantum);

    do
    {
        done = 1;
        for(i = 0; i < n; i++)
        {
            if(rem_bt[i] > 0)
            {
                done = 0;

                if(rem_bt[i] > time_quantum)
                {
                    t += time_quantum;
                    rem_bt[i] -= time_quantum;
                }
                else
                {
                    t += rem_bt[i];
                    tat[i] = t;    
                    wt[i] = tat[i] - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
    } while(!done);

    for(i = 0; i < n; i++)
    {
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for(i = 0; i < n; i++)
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time -- %f", wtavg / n);
    printf("\nAverage Turnaround Time -- %f", tatavg / n);

    return 0;
}