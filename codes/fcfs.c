# include <stdio.h>

struct process {
	int burst, wait;
} p[20] = {0, 0};

int main() {
	int n, i, totalwait = 0, totalturn = 0;
	
	printf("Enter the no. of process:\n");
	scanf("%d", &n);

	for (i = 0; i < n; i++){
		printf("Enter the burst time (in secs) for process #%-3d: ", i + 1);
		scanf("%d", &p[i].burst);
	}

	printf("\nProcess\t\tWaiting Time\tTurn Around Time");
	printf("\n\t\t(in secs)\t(in ms)");
	for (i = 0; i < n; i++) {
		printf("\nProcess #%-12d%-15d%-15d", i + 1, p[i].wait, p[i].wait+p[i].burst);
		p[i+1].wait = p[i].wait + p[i].burst;
		totalwait = totalwait + p[i].wait;
		totalturn = totalturn + p[i].wait + p[i].burst;
	}

	printf("\n\nAVERAGE\n");
	printf("Waiting time: %.2f ms\n", totalwait/(float)n);
	printf("Turn Around Time: %.2f ms\n", totalturn/(float)n);

	return 0;
}
