/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cupatham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:58:14 by cupatham          #+#    #+#             */
/*   Updated: 2022/04/22 06:23:08 by cupatham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			step;
	size_t			index;
	unsigned char	*dest;
	unsigned char	*source;

	if (dst == NULL && src == NULL)
		return (NULL);
	step = +1;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dst > src)
	{
		step = -1;
		dest = (unsigned char *)(dst + len - 1);
		source = (unsigned char *)(src + len - 1);
	}
	index = 0;
	while (index < len)
	{
		*dest = *source;
		dest += step;
		source += step;
		index++;
	}
	return (dst);
}
