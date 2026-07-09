#include <stdio.h>
#define MAX 20

int main() {
    int n, i, idx;
    int bt[MAX], at[MAX], wt[MAX], tat[MAX], completed[MAX];
    int time = 0, done = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        completed[i] = 0;
    }

    while (done < n) {
        idx = -1;
        int shortest = 9999;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && completed[i] == 0) {
                if (bt[i] < shortest) {
                    shortest = bt[i];
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        wt[idx] = time - at[idx];
        time += bt[idx];
        tat[idx] = wt[idx] + bt[idx];
        completed[idx] = 1;
        done++;

        avg_wt += wt[idx];
        avg_tat += tat[idx];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);
    printf("Average Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}