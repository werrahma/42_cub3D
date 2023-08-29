/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:00:18 by werrahma          #+#    #+#             */
/*   Updated: 2023/07/31 13:17:30 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <string.h>

void	ft_lstadd_back(t_pars **lst, t_pars *new)
{
	t_pars	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = new;
	new->next = NULL;
	*lst = tmp;
}
