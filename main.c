#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

//Read whole text
int main()
{
	int	fd = open("bestjoke.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	close(fd);
}


// //Call gnl just 3 times;
// int main()
// {
// 	int	fd = open("bestjoke.txt", O_RDONLY);
// 	char *line;
// 	int count = 0;

// 	while (count < 3)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		count++;
// 	}

// 	close(fd);
// }

