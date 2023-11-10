/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <diego.antoniosantamaria@gmail.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:42:00 by disantam          #+#    #+#             */
/*   Updated: 2023/05/18 19:42:03 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(long i)
{
	size_t	len;

	len = 0;
	if (i <= 0)
		len++;
	while (i != 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	i;
	size_t	len;
	char	*str;

	i = n;
	len = ft_itoa_len(i);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (i == 0)
		str[0] = '0';
	if (i < 0)
	{
		str[0] = '-';
		i *= -1;
	}
	while (i > 0)
	{
		str[len--] = (i % 10) + '0';
		i /= 10;
	}
	return (str);
}
