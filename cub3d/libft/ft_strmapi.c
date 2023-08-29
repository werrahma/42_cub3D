/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 08:48:20 by werrahma          #+#    #+#             */
/*   Updated: 2022/11/03 14:07:53 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*m;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	m = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!m)
		return (NULL);
	while (i < ft_strlen(s))
	{
		m[i] = (*f)(i, s[i]);
		i++;
	}
	m[i] = '\0';
	return (m);
}
