/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:09:02 by werrahma          #+#    #+#             */
/*   Updated: 2022/11/03 19:28:11 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			a;
	unsigned char	*s;
	unsigned char	*d;

	a = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if ((s == NULL) && (d == NULL))
		return (NULL);
	if (d > s)
		while (len--)
			d[len] = s[len];
	else if (d < s)
	{
		while (a < len)
		{
			d[a] = s[a];
			a++;
		}
	}
	return (dst);
}
