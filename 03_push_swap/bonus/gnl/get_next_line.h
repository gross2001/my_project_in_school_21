#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	"../../mandatory/ft_push_swap.h"

int		ft_strjoin(char **s1, char **s2, int line_size);
int		ft_strchr(const char *s);
int		ft_divide(char **temp, char **line);
int		ft_free(char	**pointer);
int		get_next_line(int fd, char **line, int BUFFER_SIZE);

#endif
