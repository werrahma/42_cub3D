/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 06:22:13 by werrahma          #+#    #+#             */
/*   Updated: 2022/11/02 10:35:34 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		a;
	char	b;
	char	*x;

	x = (char *)s;
	b = (char)c;
	a = ft_strlen(x) + 1;
	while (a != 0)
	{
		a--;
		if (x[a] == b)
			return (x + a);
	}
	return (0);
}
