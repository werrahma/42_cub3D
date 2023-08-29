/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:16:00 by werrahma          #+#    #+#             */
/*   Updated: 2022/10/28 11:18:07 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			a;
	unsigned char	*b;

	a = 0;
	b = (unsigned char *)s;
	while (a < n)
	{
		if (b[a] == (unsigned char)c)
			return (b + a);
		a++;
	}
	return (NULL);
}
