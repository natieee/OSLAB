#include<iostream>

using namespace std;

int main()
{
    int n = 10;
    int bt[10] = {9, 8, 7, 8, 7, 8, 2, 1, 2, 5};
    int at[10] = {0, 4, 2, 1, 3, 6, 7, 8, 4, 5};
    int ct[10], tat[10], wt[10], i;
    float wtavg = 0, tatavg = 0;
    
    // Sort processes by arrival time (Bubble Sort)
    int temp_bt, temp_at, temp_p;
    int p[10];
    for(i = 0; i < n; i++) p[i] = i;
    
    for(i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(at[p[j]] > at[p[j+1]])
            {
                temp_p = p[j];
                p[j] = p[j+1];
                p[j+1] = temp_p;
            }
        }
    }
    
    // Calculate Completion Time
    ct[p[0]] = at[p[0]] + bt[p[0]];
    for(i = 1; i < n; i++)
    {
        if(at[p[i]] > ct[p[i-1]])
            ct[p[i]] = at[p[i]] + bt[p[i]];
        else
            ct[p[i]] = ct[p[i-1]] + bt[p[i]];
    }
    
    // Calculate Turnaround Time and Waiting Time
    for(i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    
    cout << "\n\t PROCESS \tARRIVAL TIME \tBURST TIME \t WAITING TIME\t TURNAROUND TIME" << endl;
    for(i = 0; i < n; i++)
        cout << "\n\t P" << i << "\t\t" << at[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i];
    
    cout << "\n\nAverage Waiting Time -- " << wtavg/n;
    cout << "\nAverage Turnaround Time -- " << tatavg/n;

    return 0;
}
