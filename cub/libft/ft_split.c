/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:51:21 by werrahma          #+#    #+#             */
/*   Updated: 2022/11/03 21:41:29 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_countr(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == '\0')
			count++;
		if (s[i] != c && s[i + 1] == c)
			count++;
		i++;
	}
	return (count);
}

static int	the_free(char **m, int b)
{
	while (b > 0)
	{
		free(m[--b]);
	}
	free(m);
	return (-1);
}

static int	split(const char *s, char **m, char c, int count)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			m[count] = ft_substr(s, start, i - start);
			if (!m[count])
				return (the_free(m, count));
			count++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**m;

	if (!s)
		return (NULL);
	m = malloc(sizeof(char *) * (word_countr(s, c) + 1));
	if (!m)
		return (NULL);
	count = split(s, m, c, 0);
	if (count == -1)
		return (NULL);
	m[count] = NULL;
	return (m);
}
