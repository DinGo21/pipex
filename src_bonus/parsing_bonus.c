/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:41:01 by disantam          #+#    #+#             */
/*   Updated: 2023/10/16 13:44:21 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipex_parse_paths(t_pipex *pipex, char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		if (!ft_strncmp(envp[i], "PATH", 4))
			pipex -> paths = ft_split(ft_strchr(envp[i], '/'), ':');
	if (pipex -> paths == NULL)
		exit(EXIT_FAILURE);
	i = -1;
	while (pipex -> paths[++i])
	{
		pipex -> paths[i] = pipex_join(pipex -> paths[i], "/");
		if (pipex -> paths[i] == NULL)
			ft_error(pipex, NULL);
	}
}

void	pipex_parse_cmds(t_pipex *pipex, char **argv)
{
	int	i;
	int	start;

	pipex -> cmds = malloc(sizeof(char **) * (pipex -> cmd_count + 1));
	if (pipex -> cmds == NULL)
		exit(EXIT_FAILURE);
	i = -1;
	start = 2;
	if (pipex -> heredoc == 1)
		start = 3;
	while (++i < pipex -> cmd_count)
	{
		pipex -> cmds[i] = ft_split(argv[i + start], ' ');
		if (pipex -> cmds[i] == NULL)
			ft_error(pipex, NULL);
	}
	pipex -> cmds[i] = NULL;
}
