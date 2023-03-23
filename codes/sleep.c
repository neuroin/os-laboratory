# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int main(void) {
	int pid, status, exitch;

	if ((pid = fork()) == -1) {
		perror("Error!");
		exit(0);
	}

	if (pid == 0) {
		sleep(1);
		printf("Child process.\n");
		exit(0);
	}
	else {
		printf("Parent process.\n");
		
		if ((exitch = wait(&status)) == -1) {
			perror("During wait()");
			exit(0);
		}

		printf("Parent existing.\n");
		exit(0);
	}
}
