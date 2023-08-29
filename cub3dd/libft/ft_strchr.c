/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:49:37 by werrahma          #+#    #+#             */
/*   Updated: 2022/10/28 11:33:41 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		a;
	char	*x;
	char	y;

	a = 0;
	x = (char *)s;
	y = (char)c;
	while (x[a] != '\0' || y == '\0')
	{
		if (x[a] != y)
			a++;
		else
			return (x + a);
	}
	return (NULL);
}
