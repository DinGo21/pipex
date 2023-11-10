/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:07:10 by disantam          #+#    #+#             */
/*   Updated: 2023/11/10 12:11:51 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	pipex_free(char **paths, char **cmdargs)
{
	int	i;

	i = 0;
	while (paths[i] != NULL)
		free(paths[i++]);
	free(paths);
	i = 0;
	while (cmdargs[i] != NULL)
		free(cmdargs[i++]);
	free(cmdargs);
}

void	ft_error(char *type)
{
	perror(type);
	exit(EXIT_FAILURE);
}
