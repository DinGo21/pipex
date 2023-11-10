/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:00:03 by disantam          #+#    #+#             */
/*   Updated: 2023/10/17 13:25:20 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_exec(char *args, char **envp)
{
	int		i;
	char	*cmd;
	char	**paths;
	char	**cmdargs;

	i = -1;
	while (envp[++i])
		if (!ft_strncmp(envp[i], "PATH", 4))
			paths = ft_split(ft_strchr(envp[i], '/'), ':');
	cmdargs = ft_split(args, ' ');
	if (!paths && !cmdargs)
		exit(EXIT_FAILURE);
	i = -1;
	while (paths[++i] != NULL)
		paths[i] = pipex_join(paths[i], "/");
	i = -1;
	while (paths[++i] != NULL)
	{
		cmd = ft_strjoin(paths[i], cmdargs[0]);
		execve(cmd, cmdargs, envp);
		free(cmd);
	}
	perror(cmdargs[0]);
	pipex_free(paths, cmdargs);
	exit(EXIT_FAILURE);
}

static void	pipex_parent(int *fd, int file, char *cmd, char **envp)
{
	int	status;

	waitpid(-1, &status, WNOHANG);
	if (dup2(file, STDOUT_FILENO) == -1)
		ft_error("dup");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error("dup");
	close(fd[1]);
	close(file);
	pipex_exec(cmd, envp);
	exit(EXIT_SUCCESS);
}

static void	pipex_child(int *fd, int file, char *cmd, char **envp)
{
	if (dup2(file, STDIN_FILENO) == -1)
		ft_error("dup");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error("dup");
	close(fd[0]);
	close(file);
	pipex_exec(cmd, envp);
	exit(EXIT_SUCCESS);
}

void	pipex(int file1, int file2, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) < 0)
		ft_error("pipe");
	pid = fork();
	if (pid < 0)
		ft_error("fork");
	if (pid == 0)
		pipex_child(fd, file1, argv[2], envp);
	else
		pipex_parent(fd, file2, argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		f1;
	int		f2;

	if (argc != 5)
		exit(EXIT_FAILURE);
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0)
		ft_error(argv[1]);
	if (f2 < 0)
		ft_error(argv[argc - 1]);
	i = -1;
	while (envp[++i])
		if (!ft_strncmp(envp[i], "PATH", 4))
			pipex(f1, f2, argv, envp);
	return (EXIT_SUCCESS);
}
