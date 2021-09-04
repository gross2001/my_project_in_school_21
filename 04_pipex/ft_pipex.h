#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<sys/wait.h>

int	ft_check_data(int argc);
int	ft_run_child(char *argv1, char *argv2, int p[]);
int	ft_run_parrent(char *argv3, char *argv4, int p[]);

#endif
