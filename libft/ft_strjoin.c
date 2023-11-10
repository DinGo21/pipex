/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:27:10 by disantam          #+#    #+#             */
/*   Updated: 2023/08/18 12:52:14 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	c1;
	size_t	c2;
	char	*str;

	c1 = ft_strlen(s1);
	c2 = ft_strlen(s2);
	str = malloc(c1 + c2 + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < c1)
		str[i] = s1[i];
	i = -1;
	while (c1 + ++i < c1 + c2)
		str[c1 + i] = s2[i];
	str[c1 + c2] = '\0';
	return (str);
}

// int main()
// {
// 	char st1[] = "where is my ";
// 	char st2[] = "malloc ???";

// 	printf("%s", ft_strjoin(st1, st2));
// 	return 0;
// }