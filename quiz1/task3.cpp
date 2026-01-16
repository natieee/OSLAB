#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    int n = 6;
    int p[6] = {0, 1, 2, 3, 4, 5};
    float bt[6] = {99.99, 107.9, 143.77, 20.24, 50.55, 66.66};
    float wt[6], tat[6];
    int i, k;
    float wtavg = 0, tatavg = 0;
    float temp_bt;
    int temp_p;

    // Sort by burst time (Shortest Job First)
    for(i = 0; i < n; i++)
        for(k = i + 1; k < n; k++)
            if(bt[i] > bt[k])
            {
                temp_bt = bt[i];
                bt[i] = bt[k];
                bt[k] = temp_bt;
                
                temp_p = p[i];
                p[i] = p[k];
                p[k] = temp_p;
            }
     
    // Calculate Waiting Time and Turnaround Time
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0]; 
    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    
    cout << "\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n";
    for(i = 0; i < n; i++)
        cout << "\t P" << p[i] << " \t\t " << fixed << setprecision(2) << setw(8)
        << bt[i] << " \t " << setw(8) << wt[i] << " \t " << setw(8) << tat[i] << "\n";
    
    cout << "\n\nAverage Waiting Time -- " << fixed << setprecision(2) << wtavg/n;
    cout << "\nAverage Turnaround Time -- " << tatavg/n;
    
    return 0;
}
