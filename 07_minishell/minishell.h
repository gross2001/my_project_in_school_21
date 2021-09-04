#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_shell
{	
	char	**arg;
	int		len_arg;
	int		fd_input;
	int		fd_output;
}	t_shell;

typedef struct s_var
{
	char	**vars;
	char	**all_vars;
	char	*str;
	t_shell	*shell;
	int		len_shell;
	int		ret;
}	t_var;

t_var	g_var;

int		ft_strlen(char *str);
char	*my_join(char *s, char c);
char	*new_line(void);
int		count_char(char *str, char c);
void	exit_but(void);
void	parsing(void);
int		miss_space(void);
int		command_cd(int count);
void	freendom(void);
void	writing_var(void);
char	*ft_strjoin(char *s1, char *s2);
int		command_env(void);
char	*ft_strchr(char *str, char c);
char	*find_var_result(char *find);
int		command_unset(int count);
void	read_file(char *file);
char	*ft_itoa(int n);
int		command_export(int count);
int		command_echo(int i);
void	parsing_main(int i);
int		count_arg(void);
int		parsing_final(int i);
int		parsing_command(int count);
void	free_var(void);
int		command_open(int count);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(char *s);
char	**ft_split(char *s, char c);
void	ft_correct_path(int count);
void	ft_open_pipe(void);
void	ft_def_output(int n);
void	ft_def_input(int n);
char	*ft_add_space_for_redirect(char **str);
int		ft_check_builtin(void);
void	ft_correct_order(int count);
char	**ft_free_malloc(char **tab);
char	*find_var_result(char *str);
int		find_var(char *str, int flag);
int		count_vars(char **vars);
void	del_all(char *str);
void	del_var(char *str);
void	add_var(char *str);
void	add_all(char *str);
int		show_var(char **vars, int flag);
int		ft_atoi(char *str);
void	ft_do_one_command(void);
void	delite_vars_dop(char *ch, char *s);
int		ft_error_redirect(void);

#endif