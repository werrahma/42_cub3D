/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:53:37 by werrahma          #+#    #+#             */
/*   Updated: 2022/10/28 17:25:21 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			a;
	unsigned char	*b;
	unsigned char	*c;

	a = 0;
	b = (unsigned char *)s1;
	c = (unsigned char *)s2;
	while (a < n)
	{
		if (b[a] != c[a])
			return (b[a] - c[a]);
		a++;
	}
	return (0);
}
