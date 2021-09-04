#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static int		BUFFER_SIZE = 10;
	char			*buf;
	static char		*temp = 0;
	static int		line_size = 1;

	while ((ft_strchr(temp) == 0) && (line_size != 0))
	{
		buf = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return (-1);
		line_size = read(fd, buf, BUFFER_SIZE * sizeof(char));
		if (line_size < 0)
		{
			free(buf);
			return (-1);
		}
		buf[line_size] = '\0';
		if (ft_strjoin(&temp, &buf, line_size) == -1)
			return (-1);
	}
	if (ft_divide(&temp, line) == -1)
		return (-1);
	if ((temp == 0) && (line_size == 0))
		return (0);
	return (1);
}
