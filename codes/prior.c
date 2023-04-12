# include <stdio.h>

float awt, avg_tat, avg_wt;
int p[30], bt[30], tot_tat = 0, pr[30], wt[30], n, tot_wt = 0, tat[30], PR_wt = 0, PR_tat = 0;

int sort();
int swap(int *a, int *b);
int WT_TAT(int *a, int *b);

void main() {
	printf("\nEnter the no. of processes:\n");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("Enter burst time of process[%d]:", i+1);
		scanf("%d", &bt[i]);
		printf("Enter priority of process[%d]:", i+1);
		scanf("%d", &pr[i]);
		p[i] = i;
	}

	sort();
	WT_TAT(&PR_tat, &PR_wt);
	printf("\n\nTotal Turn Around Time: %dms", PR_tat);
	printf("\nAverage Turn Around Time: %dms", PR_tat/n);
	printf("\nTotal Waiting Timee: %dms", PR_wt);
	printf("\nAverage Waiting Time: %dms\n", PR_wt/n);
}

int sort() {
	int t, i, j, t2, t1;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (pr[i] > pr[j]) {
				swap(&bt[j], &bt[i]);
				swap(&p[j], &p[i]);
				swap(&pr[j], &pr[i]);
			}
		}
	}
	return 0;
}

int swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
	return 0;
}

int WT_TAT(int *a, int *b) {
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			tat[i] = bt[i];
		}
		else {
			tat[i] = tat[i-1] + bt[i];
			tot_tat = tot_tat + tat[i];
		}
	}
	*a = tot_tat;
	wt[0] = 0;

	for (int i = 1; i < n; i++) {
		wt[i] = wt[i-1] + bt[i-1];
		tot_wt = tot_wt + wt[i];
	}
	*b = tot_wt;

	printf("\nProcess ID\tBurst Time\tPriority\tTurn Around Time\tWaiting Time");
	for (int i = 0; i < n; i++) {
		printf("\nProcess [%d]\t\t%d\t\t%d\t\t%d\t\t%d", p[i]+1, bt[i], pr[i], tat[i], wt[i]);
	}
	return 0;
}
