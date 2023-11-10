/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <diego.antoniosantamaria@gmail.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:32:57 by disantam          #+#    #+#             */
/*   Updated: 2023/04/25 16:32:58 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dststr;
	char	*srcstr;

	if (dst == 0 && src == 0)
		return (NULL);
	i = 0;
	dststr = dst;
	srcstr = (char *)src;
	while (i < n)
	{
		dststr[i] = srcstr[i];
		i++;
	}
	return (dststr);
}

// int main ()
// {
// 	char str[] = "Hola Mundo";
// 	char str1[] = "Hola Diegopapu";

// 	printf("%s", ft_memcpy(str, str1, 11));
// 	return (0);
// }