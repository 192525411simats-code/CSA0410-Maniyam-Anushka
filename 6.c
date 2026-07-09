#include <stdio.h>
#define MAX 20

int main() {
    int n, i, j;
    int bt[MAX], pr[MAX], at[MAX], rt[MAX];
    int wt[MAX], tat[MAX], completed[MAX];
    int time = 0, done = 0, idx;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter arrival time, burst time and priority for P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
        completed[i] = 0;
    }

    while (done < n) {
        idx = -1;
        int highest_priority = 9999;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && completed[i] == 0 && rt[i] > 0) {
                if (pr[i] < highest_priority) {
                    highest_priority = pr[i];
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        rt[idx]--;
        time++;

        if (rt[idx] == 0) {
            completed[idx] = 1;
            done++;
            tat[idx] = time - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            avg_wt += wt[idx];
            avg_tat += tat[idx];
        }
    }

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], pr[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);
    printf("Average Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}