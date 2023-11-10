/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <diego.antoniosantamaria@gmail.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:44:28 by disantam          #+#    #+#             */
/*   Updated: 2023/04/21 16:44:30 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	if (!(i < size))
		return (i + ft_strlen(src));
	else
	{
		while (i < size - 1 && src[j])
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (i - j + ft_strlen(src));
}

// int main() {
// 	char s1[11] = "hola";
// 	char s2[5] = "mano";

// 	printf("%lu\n", ft_strlcat(s1, s2, 8));
// 	printf("%s", s1);

// 	return 0;
// }
