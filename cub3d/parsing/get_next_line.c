/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:21:31 by werrahma          #+#    #+#             */
/*   Updated: 2023/07/31 13:56:50 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	strlen1(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

int	search(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_read(int fd, char *p)
{
	char	*m;
	ssize_t	ret;

	ret = 1;
	m = malloc(sizeof(char) * (size_t)BUFFER_SIZE + 1);
	if (!m)
		return (NULL);
	m[0] = '\0';
	while (search(m) && ret)
	{
		ret = read(fd, m, BUFFER_SIZE);
		if (ret == -1)
			return (free(m), free(p), NULL);
		if (!ret)
		{
			free (m);
			return (p);
		}
		m[ret] = '\0';
		p = get_strjoin(p, m);
	}
	free (m);
	return (p);
}

char	*ft_free(char *p, char *line)
{
	char	*tmp;

	tmp = get_strdup(p);
	free(p);
	p = get_strdup(tmp + get_strlen(line));
	free(tmp);
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*p;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	p = ft_read (fd, p);
	if (!p)
		return (0);
	line = malloc(strlen1(p) + 1);
	while (i < strlen1(p))
	{
		line[i] = p[i];
		i++;
	}
	line[i] = '\0';
	if (get_strlen(p) > get_strlen(line))
		p = ft_free (p, line);
	else
	{
		free (p);
		p = NULL;
	}
	return (line);
}
