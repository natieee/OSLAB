#include<stdio.h>

int main()
{
    int p[20], bt[20], pr[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;

    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        p[i] = i;
        printf("Enter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
        printf("Enter Priority for Process %d (lower number = higher priority) -- ", i);
        scanf("%d", &pr[i]);
    }

    for(i = 0; i < n; i++)
        for(k = i + 1; k < n; k++)
            if(pr[i] > pr[k])
            {
                temp = pr[i];
                pr[i] = pr[k];
                pr[k] = temp;

                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }

    wt[0] = 0;
    wtavg = 0;
    tat[0] = bt[0];
    tatavg = tat[0];

    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\n\t PROCESS \tPRIORITY \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for(i = 0; i < n; i++)
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d \t\t %d", p[i], pr[i], bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time -- %f", wtavg / n);
    printf("\nAverage Turnaround Time -- %f", tatavg / n);

    return 0;
}

