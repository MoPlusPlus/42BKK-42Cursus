/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cupatham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:56:40 by cupatham          #+#    #+#             */
/*   Updated: 2022/04/22 06:22:25 by cupatham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_len(int n)
{
	size_t	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_build_str(size_t len, char *str, int n, int neg)
{
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	int		neg;
	size_t	len;
	char	*str;

	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = ft_get_len(n) + neg;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	ft_build_str(len, str, n, neg);
	return (str);
}
