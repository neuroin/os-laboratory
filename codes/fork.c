# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void main() {
	int pid, pid1, pid2;
	pid = fork();
	
	if (pid == -1) {
		printf("Error in process creation!\n");
	}
	else if (pid == 0) {
		pid1 = getpid();
		printf("The child process ID is %d\n", pid1);
	}
	else {
		pid2 = getpid();
		printf("The parent process ID is %d\n", pid2);
	}
}
