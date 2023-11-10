/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:14:07 by disantam          #+#    #+#             */
/*   Updated: 2023/10/11 11:41:50 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_bonus.h"

static char	*gnl_restack(char *stack)
{
	int		c;
	int		c2;
	char	*nstack;

	c = 0;
	while (stack[c] != '\0' && stack[c] != '\n')
		c++;
	if (stack[c] == '\0')
		return (free(stack), NULL);
	c2 = 1;
	while (stack[c + c2] != '\0')
		c2++;
	nstack = malloc(sizeof(char) * (c2 + 1));
	if (!nstack)
		return (NULL);
	c++;
	c2 = 0;
	while (stack[c] != '\0')
		nstack[c2++] = stack[c++];
	nstack[c2] = '\0';
	free(stack);
	return (nstack);
}

static char	*gnl_line(char *stack)
{
	int		c;
	char	*line;

	c = 0;
	if (!stack[0])
		return (NULL);
	while (stack[c] != '\n' && stack[c] != '\0')
		c++;
	line = malloc(sizeof(char) * (c + 2));
	if (!line)
		return (NULL);
	c = 0;
	while (stack[c] != '\n' && stack[c] != '\0')
	{
		line[c] = stack[c];
		c++;
	}
	if (stack[c] == '\n')
		line[c++] = '\n';
	line[c] = '\0';
	return (line);
}

static char	*gnl_stacking(char *stack, char *buff)
{
	int		i;
	int		c1;
	int		c2;
	char	*str;

	c1 = ft_strlen(stack);
	c2 = ft_strlen(buff);
	str = malloc(c1 + c2 + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (i++ < c1)
		str[i] = stack[i];
	i = -1;
	while (c1 + i++ < c1 + c2)
		str[c1 + i] = buff[i];
	str[c1 + c2] = '\0';
	free(stack);
	return (str);
}

static char	*gnl_read(char *stack, int fd)
{
	int		nb;
	char	buff[BUFFER_SIZE + 1];

	if (!stack)
	{
		stack = malloc(1);
		stack[0] = '\0';
	}
	nb = 1;
	while (nb != 0 && !ft_strchr(stack, '\n'))
	{
		nb = read(fd, buff, BUFFER_SIZE);
		if (nb <= -1)
			return (free(stack), NULL);
		buff[nb] = '\0';
		stack = gnl_stacking(stack, buff);
	}
	return (stack);
}

char	*get_next_line(int fd)
{
	char		*line;	
	static char	*stack;

	stack = gnl_read(stack, fd);
	if (!stack)
		return (NULL);
	line = gnl_line(stack);
	stack = gnl_restack(stack);
	return (line);
}
