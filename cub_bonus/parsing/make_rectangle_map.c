/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rectangle_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:31:41 by werrahma          #+#    #+#             */
/*   Updated: 2023/09/01 18:46:05 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*create_str(int len)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(len + 1);
	while (i < len)
	{
		str[i] = '1';
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	get_longwidth(char **map, int len)
{
	size_t	width;
	int		i;

	i = 0;
	width = ft_strlen(map[0]);
	while (map[i])
	{
		if (i < len && width < ft_strlen(map[i + 1]))
			width = ft_strlen(map[i + 1]);
		i++;
	}
	return (width);
}

char	**rectagle_map(char **map)
{
	int		i;
	size_t	width;
	int		len;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	len = height_map(map);
	width = get_longwidth(map, len);
	while (map[i])
	{
		if (ft_strlen(map[i]) < width)
		{
			tmp1 = map[i];
			tmp2 = create_str(width - ft_strlen(map[i]));
			map[i] = ft_strjoin(map[i], tmp2);
			free (tmp1);
			free (tmp2);
		}
		i++;
	}
	return (map);
}
