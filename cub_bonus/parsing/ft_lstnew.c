/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahamdan <yahamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:59:08 by werrahma          #+#    #+#             */
/*   Updated: 2023/09/04 09:58:37 by yahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_pars	*ft_lstnew(char *str)
{
	t_pars	*new;

	new = NULL;
	new = malloc(sizeof(t_pars));
	new->string = ft_strdup(str);
	new->next = NULL;
	return (new);
}
