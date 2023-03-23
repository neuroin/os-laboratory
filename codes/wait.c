# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

int main() {
	if (fork() == 0) {
		printf("HC: Hello from child.\n");
	}
	else {
		printf("HP: Hello from parent.\n");
		wait(NULL);
		printf("CT: Child has been terminated!\n");
	}
	
	printf("Bye!\n");
	return 0;
}
