/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:32:41 by disantam          #+#    #+#             */
/*   Updated: 2023/10/03 14:09:25 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split_malloc(char const *s, char c)
{
	int		i;
	int		j;
	int		count;
	char	**split;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		j = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i > j)
			count++;
	}
	split = malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	return (split);
}

static char	**ft_split_free(char **split, int words)
{
	int	i;

	i = 0;
	while (i < words && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	**ft_split_func(char **split, const char *s, char c)
{
	int	i;
	int	j;
	int	split_i;

	i = 0;
	split_i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		j = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i > j)
		{
			split[split_i] = malloc(sizeof(char) * (i - j + 1));
			if (!split[split_i])
				return (ft_split_free(split, split_i));
			ft_strlcpy(split[split_i++], s + j, i - j + 1);
		}
	}
	split[split_i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = ft_split_malloc(s, c);
	if (!split)
		return (NULL);
	return (ft_split_func(split, s, c));
}
