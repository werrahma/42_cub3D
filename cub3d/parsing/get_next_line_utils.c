/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:06:01 by werrahma          #+#    #+#             */
/*   Updated: 2023/07/31 13:55:54 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_strjoin(char *s1, char *s2)
{
	int		a;
	int		b;
	char	*m;

	a = -1;
	b = -1;
	if (!s1 && s2)
		return (get_strdup(s2));
	if (s1 && !s2)
		return (get_strdup(s1));
	m = malloc((get_strlen(s1) + get_strlen(s2)) + 1);
	if (!m)
		return (0);
	while (s1[++a])
		m[a] = s1[a];
	while (s2[++b])
		m[a + b] = s2[b];
	m[a + b] = '\0';
	free(s1);
	return (m);
}

size_t	get_strlen(char *ar)
{
	size_t	a;

	a = 0;
	while (ar[a])
		a++;
	return (a);
}

char	*get_strdup(char *s1)
{
	int		a;
	int		b;
	char	*p;

	b = get_strlen(s1);
	p = malloc(sizeof(char) * b + 1);
	if (!p)
		return (0);
	a = 0;
	while (s1[a])
	{
		p[a] = s1[a];
		a++;
	}
	p[a] = '\0';
	return (p);
}
