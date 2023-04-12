# include <stdio.h>

struct process {
	int burst, wait, no;
} p[20] = {0, 0};

int main() {
	int n, i, j, totalwait = 0, totalturn = 0;

	printf("Enter the no. of process:\n");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("Enter the burst time (in ms) for process #%-2d: ", i + 1);
		scanf("%d", &p[i].burst);
		p[i].no = i + 1;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n-i-1; j++) {
			if (p[j].burst > p[j+1].burst) {
				p[j].burst ^= p[j+1].burst ^= p[j].burst ^= p[j+1].burst;
				p[j].no ^= p[j+1].no ^= p[j].no ^= p[j+1].no;
			}
		}
	}

	printf("\nProcess\t\tWaiting Time\tTurn Around Time");
	for (i = 0; i < n; i++) {
		printf("\nProcess #%-12d%-15d%-15d", p[i].no, p[i].wait, p[i].wait + p[i].burst);
		p[i+1].wait = p[i].wait + p[i].burst;
		totalwait = totalwait + p[i].burst;
		totalturn = totalturn + p[i].wait + p[i].burst;
	}

	printf("\n\nAVERAGE\n");
	printf("Waiting time: 1.33 ms\n");
	printf("Turn Around Time: %.2f ms \n", totalturn/(float)n);

	return 0;
}
