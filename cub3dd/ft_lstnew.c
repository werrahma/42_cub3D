/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:59:08 by werrahma          #+#    #+#             */
/*   Updated: 2023/07/31 13:30:04 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_pars	*ft_lstnew(char *str)
{
	t_pars	*new;

	new = NULL;
	new = malloc(sizeof(t_pars));
	new->string = ft_strdup(str);
	new->next = NULL;
	return (new);
}
