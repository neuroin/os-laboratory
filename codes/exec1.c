# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("PID of exec1.c = %d\n", getpid());
	char *args[] = {"Hello", "C", "Programming", NULL};

	execv("./exec2", args);
	printf("Back to exec1.c\n");

	return 0;
}
