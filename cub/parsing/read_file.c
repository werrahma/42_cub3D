/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:24:07 by werrahma          #+#    #+#             */
/*   Updated: 2023/09/01 17:13:53 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

char	*switch_nline(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	return (str);
}

void	create_list(t_pars **list, char *n_file)
{
	char	*str;
	int		fd;

	str = NULL;
	fd = open(n_file, O_RDONLY);
	if (fd == -1)
	{
		write(2, "open failed\n", 12);
		exit(1);
	}
	str = switch_nline(get_next_line(fd));
	while (str)
	{
		ft_lstadd_back(list, ft_lstnew(str));
		free(str);
		str = switch_nline(get_next_line(fd));
	}
	if (!*list)
	{
		write(2, "file .cub is empty\n", 19);
		exit(1);
	}
}
