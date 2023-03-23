# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int main() {
	int pid, pid1, pid2;

	pid = fork();
	if (pid == 0) {
		sleep(3);
		printf("Child[1] -> pid = %d and ppid = %d\n", getpid(), getppid());
	}
	else {
		pid1 = fork();
		if (pid1 == 0) {
			printf("Child[2] -> pid = %d and ppid = %d\n", getpid(), getppid());
		}
		else {
			pid2 = fork();
			if (pid2 == 0) {
				printf("Child[3] -> pid = %d and ppid = %d\n", getpid(), getppid());
			}
			else {
				sleep(3);
				printf("Parent -> pid = %d\n", getpid());
			}
		}
	}
	return 0;
}
