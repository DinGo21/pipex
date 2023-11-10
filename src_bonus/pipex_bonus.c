/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:28:56 by disantam          #+#    #+#             */
/*   Updated: 2023/10/17 13:02:26 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipex(t_pipex *pipex, int n, char **envp)
{
	int	pid;
	int	fd[2];
	int	status;

	if (pipe(fd) == -1)
		ft_error(pipex, "pipe");
	pid = fork();
	if (pid == -1)
		ft_error(pipex, "fork");
	if (pid == 0)
	{
		if (dup2(fd[1], STDOUT_FILENO) < 0)
			ft_error(pipex, "dup");
		close(fd[0]);
		pipex_exec(pipex, n, envp);
	}
	else
	{
		if (dup2(fd[0], STDIN_FILENO) < 0)
			ft_error(pipex, "dup");
		close(fd[1]);
		waitpid(-1, &status, WNOHANG);
	}
}

void	here_doc_get(t_pipex *pipex, char *limiter, int *fd)
{
	char	*res;

	close(fd[0]);
	while (1)
	{
		res = get_next_line(STDIN_FILENO);
		if (res == NULL)
			ft_error(pipex, NULL);
		if (ft_strncmp(res, limiter, ft_strlen(limiter)) == 0)
		{
			free(res);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(res, fd[1]);
		free(res);
	}
}

void	here_doc(t_pipex *pipex, char *limiter)
{
	int	pid;
	int	fd[2];
	int	status;

	if (pipe(fd) == -1)
		ft_error(pipex, "pipe");
	pid = fork();
	if (pid == -1)
		ft_error(pipex, "fork");
	if (pid == 0)
		here_doc_get(pipex, limiter, fd);
	else
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_error(pipex, "dup");
		close(fd[1]);
		waitpid(-1, &status, 0);
	}
}

void	pipex_init(t_pipex *pipex, int argc, char **argv)
{
	if (argc < 5)
		exit(EXIT_FAILURE);
	if (ft_strncmp("here_doc", argv[1], ft_strlen(argv[1])) == 0)
	{
		if (argc < 6)
			exit(EXIT_FAILURE);
		pipex -> heredoc = 1;
		pipex -> cmd_count = argc - 4;
		pipex -> outfd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (pipex -> outfd < 0)
			ft_error(pipex, argv[argc - 1]);
	}
	else
	{
		pipex -> heredoc = 0;
		pipex -> cmd_count = argc - 3;
		pipex -> infd = open(argv[1], O_RDONLY);
		pipex -> outfd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (pipex -> infd < 0)
			ft_error(pipex, argv[1]);
		if (pipex -> outfd < 0)
			ft_error(pipex, argv[argc - 1]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_pipex	px;

	pipex_init(&px, argc, argv);
	pipex_parse_cmds(&px, argv);
	pipex_parse_paths(&px, envp);
	if (px.heredoc == 1)
		here_doc(&px, argv[2]);
	else
	{
		if (dup2(px.infd, STDIN_FILENO) < 0)
			ft_error(&px, "dup");
		close(px.infd);
	}
	i = -1;
	while (++i < px.cmd_count - 1)
		pipex(&px, i, envp);
	if (dup2(px.outfd, STDOUT_FILENO) < 0)
		ft_error(&px, "dup");
	close(px.outfd);
	pipex_exec(&px, i, envp);
	pipex_free_all(&px);
	return (EXIT_SUCCESS);
}
