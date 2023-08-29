/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:28:31 by werrahma          #+#    #+#             */
/*   Updated: 2022/11/02 10:57:59 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;
	size_t	i;

	i = 0;
	if (dstsize == 0 && !dst)
		return (ft_strlen(src));
	if (dstsize && dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	a = ft_strlen(src);
	b = ft_strlen(dst);
	if (dstsize > 0)
	{
		while (src[i] != 0 && b + i < dstsize -1)
		{
			dst[b + i] = src[i];
			i++;
		}
		dst[b + i] = '\0';
		return (a + b);
	}
	return (a + dstsize);
}
