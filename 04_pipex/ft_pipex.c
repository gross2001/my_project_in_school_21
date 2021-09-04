#include "ft_pipex.h"

int	ft_check_data(int argc)
{
	if (argc != 5)
	{
		write(1, "Incorrect number of arguments\n", 30);
		exit(0);
	}
	return (0);
}

int	ft_run_child(char *argv1, char *argv2, int p[])
{
	char	*command[4];
	char	*envp[1];
	int		fd;

	fd = open(argv1, O_RDONLY);
	if (fd < 0)
	{
		perror(argv1);
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDIN_FILENO) == -1 || dup2(p[1], STDOUT_FILENO) == -1 )
		exit(EXIT_FAILURE);
	close(p[0]);
	close(fd);
	close(p[1]);
	command[0] = "/bin/zsh";
	command[1] = "-c";
	command[2] = argv2;
	command[3] = (char *) 0;
	envp[0] = (char *) 0;
	execve(command[0], command, envp);
	exit(EXIT_FAILURE);
}

int	ft_run_parrent(char *argv3, char *argv4, int p[])
{
	char	*command[4];
	char	*envp[1];
	int		fd;

	fd = open(argv4, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd < 0)
	{
		perror(argv4);
		exit(EXIT_FAILURE);
	}
	if (dup2(p[0], STDIN_FILENO) == -1 || dup2(fd, STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(p[1]);
	close(p[0]);
	close(fd);
	command[0] = "/bin/zsh";
	command[1] = "-c";
	command[2] = argv3;
	command[3] = (char *) 0;
	envp[0] = (char *) 0;
	execve(command[0], command, envp);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	pid_t	result_of_fork;
	int		p[2];
	int		status;

	ft_check_data(argc);
	if (pipe(p) < 0)
		exit (EXIT_FAILURE);
	result_of_fork = fork();
	if (result_of_fork == -1)
		exit (EXIT_FAILURE);
	if (result_of_fork == 0)
		ft_run_child(argv[1], argv[2], p);
	if (result_of_fork > 0)
	{
		wait(&status);
		ft_run_parrent(argv[3], argv[4], p);
	}
}
