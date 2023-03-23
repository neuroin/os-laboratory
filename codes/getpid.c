# include <stdio.h>

int main() {
	int pid;
	pid = getpid();
	printf("Process ID: %d\n", pid);
	pid = getpid();
	printf("Parent process ID: %d\n", pid);
}
