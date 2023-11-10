/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <diego.antoniosantamaria@gmail.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:52:37 by disantam          #+#    #+#             */
/*   Updated: 2023/04/21 17:52:39 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *)(s + i));
	while (--i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
	}
	return (NULL);
}

// int	main()
// {
// 	char str[] = "pepe y cparlos";

// 	printf("%s", strrchr(str, 'c'));
// 	return 0;
// }
