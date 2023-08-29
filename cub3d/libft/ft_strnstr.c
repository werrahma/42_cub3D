/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:42:47 by werrahma          #+#    #+#             */
/*   Updated: 2022/11/02 21:53:43 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;
	char	*x;
	char	*z;

	x = (char *)haystack;
	z = (char *)needle;
	a = 0;
	if (!haystack && len == 0)
		return (NULL);
	if (z[0] == '\0')
		return (&x[a]);
	while (x[a] && a < len)
	{
		b = 0;
		while ((x[a + b] == z[b]) && a + b < len)
		{
			if (z[b + 1] == '\0')
				return (&x[a]);
			b++;
		}
		a++;
	}
	return (0);
}
