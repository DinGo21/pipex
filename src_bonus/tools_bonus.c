/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:29:17 by disantam          #+#    #+#             */
/*   Updated: 2023/10/16 16:03:59 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipex_free_all(t_pipex *pipex)
{
	int	i;
	int	j;

	if (pipex -> paths != NULL)
	{
		i = 0;
		while (pipex -> paths[i] != NULL)
			free(pipex -> paths[i++]);
		free(pipex -> paths);
	}
	if (pipex -> cmds != NULL)
	{
		i = 0;
		while (pipex -> cmds[i] != NULL)
		{
			j = 0;
			while (pipex -> cmds[i][j])
				free(pipex -> cmds[i][j++]);
			free(pipex -> cmds[i++]);
		}
		free(pipex -> cmds);
	}
}

void	ft_error(t_pipex *pipex, char *type)
{
	if (type != NULL)
		perror(type);
	pipex_free_all(pipex);
	exit(EXIT_FAILURE);
}

char	*pipex_join(char *s1, char const *s2)
{
	int		i;
	int		c1;
	int		c2;
	char	*str;

	c1 = ft_strlen(s1);
	c2 = ft_strlen(s2);
	str = malloc(c1 + c2 + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (i++ < c1)
		str[i] = s1[i];
	i = -1;
	while (c1 + i++ < c1 + c2)
		str[c1 + i] = s2[i];
	str[c1 + c2] = '\0';
	free(s1);
	return (str);
}

void	pipex_exec(t_pipex *pipex, int n, char **envp)
{
	int		i;
	char	*cmd;

	i = -1;
	while (pipex -> paths[++i] != NULL)
	{
		cmd = ft_strjoin(pipex -> paths[i], pipex -> cmds[n][0]);
		if (!cmd)
			ft_error(pipex, NULL);
		execve(cmd, pipex -> cmds[n], envp);
		free(cmd);
	}
	ft_error(pipex, pipex -> cmds[n][0]);
}
