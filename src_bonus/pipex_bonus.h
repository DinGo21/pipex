/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:29:48 by disantam          #+#    #+#             */
/*   Updated: 2023/10/16 16:04:33 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include "../gnl_bonus/gnl_bonus.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		infd;
	int		outfd;
	int		heredoc;
	int		cmd_count;
	char	**paths;
	char	***cmds;
}	t_pipex;

void	pipex_free_all(t_pipex *pipex);
void	ft_error(t_pipex *pipex, char *type);
char	*pipex_join(char *s1, char const *s2);
void	pipex_parse_cmds(t_pipex *pipex, char **argv);
void	pipex_parse_paths(t_pipex *pipex, char **envp);
void	pipex_exec(t_pipex *pipex, int n, char **envp);

#endif