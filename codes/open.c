# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>

int main() {
	int fd;
	fd = creat("file1.dat", S_IREAD | S_IWRITE);

	if (fd == -1) {
		printf("Error in opening file1.dat!\n");
	}
	else {
		printf("file1.dat opened for read/write access.\n");
		printf("file1.dat is currently empty.\n");
	}
}
