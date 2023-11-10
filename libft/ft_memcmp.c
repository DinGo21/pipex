/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <diego.antoniosantamaria@gmail.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:07:51 by disantam          #+#    #+#             */
/*   Updated: 2023/04/21 19:07:53 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (ptr1[i] != ptr2[i])
			return ((unsigned char)ptr1[i] - (unsigned char)ptr2[i]);
		i++;
	}
	if (i < n && ptr1[i] != ptr2[i])
		return ((unsigned char)ptr1[i] - (unsigned char)ptr2[i]);
	return (0);
}

// int main()
// {
// 	unsigned char str1[] = "atoms\0\0\0\0";
// 	unsigned char str2[] = "atoms\0abc";

// 	printf("%d", ft_memcmp(str1, str2, 8));
// 	return (0);
// }