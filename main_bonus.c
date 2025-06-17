#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd1 = open("bestjoke.txt", O_RDONLY);
	int fd2 = open("2ndbestjoke.txt", O_RDONLY);
	char *a = get_next_line(fd1);
	char *b = get_next_line(fd2);
	char *a2 = get_next_line(fd1);
	char *b2 = get_next_line(fd2);
	char *b3 = get_next_line(fd2);
	char *a3 = get_next_line(fd1);

	printf("%s%s%s%s%s%s", a, b, a2, b2, a3, b3);
	free (a);
	free (b);
	free (a2);
	free (b2);
	free (a3);
	free (b3);

	close (fd1);
	close (fd2);

	return 0;
}
