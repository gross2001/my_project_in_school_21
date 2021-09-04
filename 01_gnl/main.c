#include "get_next_line.h"
#include <stdio.h>
#include <string.h>


int main()
{
        int 	fd;
	int	i;
        char*	line;
	
	line = NULL;
	i = 0;
	fd = open("text.txt", O_RDONLY);
        while (get_next_line(fd, &line) > 0)
	{
		printf("line[%i] = %s\n", i, line);
		line = NULL;
		i++;
	}

	  line = NULL;
}
