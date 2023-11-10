/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:22:56 by disantam          #+#    #+#             */
/*   Updated: 2023/09/19 16:45:12 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	c;
	char	*str;

	c = ft_strlen(s1) + 1;
	str = malloc(c);
	if (!str)
		return (NULL);
	i = 0;
	while (i < c)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}

// int main()
// {
// 	char string[] = "Hola Mundo";

// 	printf("%s", ft_strdup(string));
// 	return (0);
// }