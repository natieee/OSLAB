#include <iostream>
#include <iomanip>

int main() {
    double bt[20], rem_bt[20], wt[20], tat[20];
    int i, n = 6, quantum = 25;
    double time = 0.0;
    double wtavg = 0.0, tatavg = 0.0;

    /* Hardcoded burst times */
    bt[0] = 99.99; bt[1] = 107.9; bt[2] = 143.77;
    bt[3] = 20.24; bt[4] = 50.55; bt[5] = 66.66;

    for (i = 0; i < n; i++){
        rem_bt[i] = bt[i];
        wt[i] = 0.0;
    }

    /*Gantt segments*/
    int seg_proc[1000];
    double seg_start[1000], seg_end[1000];
    int seg_cnt = 0;

    int done;
    do {
        done = 1;
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 1e-9) {
                done = 0;
                double delta = (rem_bt[i] > quantum) ? quantum : rem_bt[i];
                double start = time;
                time += delta;
                rem_bt[i] -= delta;

                seg_proc[seg_cnt] = i;
                seg_start[seg_cnt] = start;
                seg_end[seg_cnt] = time;
                seg_cnt++;

                if (rem_bt[i] <= 1e-9) {
                    wt[i] = time - bt[i];
                }
            }
        }
    } while (!done);
    
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    std::cout << "\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n";
    for (i = 0; i < n; i++)
        std::cout << "\t P" << i << " \t\t " << std::fixed << std::setprecision(2) << std::setw(8)
        << bt[i] << " \t " << std::setw(8) << wt[i] << " \t " << std::setw(8) << tat[i] << "\n";

    std::cout << "\nGANTT CHART:\n";
    std::cout << "Gantt Chart:\n";
    int colw = 8;
    for(int j = 0; j < seg_cnt; j++) {
        char lbl[16];
        snprintf(lbl, sizeof(lbl), "P%d", seg_proc[j]+1);
        std::cout << "|" << std::left << std::setw(6) << lbl;
    }

    std::cout << "|\n";
    std::cout << "\nAverage Waiting Time -- " << wtavg / n << "\n";
    std::cout << "\nAverage Turnaround Time -- " << tatavg / n << "\n\n";

    std::cout << "\n\n";

    return 0;
}