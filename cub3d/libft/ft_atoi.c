/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:58:51 by werrahma          #+#    #+#             */
/*   Updated: 2022/11/03 17:39:13 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const	char *str)
{
	unsigned long	ress;
	int				sign;
	int				a;

	ress = 0;
	sign = 1;
	a = 0;
	while ((str[a] >= 9 && str[a] <= 13) || (str[a] == 32))
		a++;
	if (str[a] == '-')
		sign = sign * (-1);
	if (str[a] == '-' || str[a] == '+')
		a++;
	while (str[a] >= '0' && str[a] <= '9')
	{
		ress = ress * 10 + str[a++] - '0';
		if (ress > __LONG_MAX__ && sign == 1)
			return (-1);
		else if (ress > __LONG_MAX__ && sign == -1)
			return (0);
	}
	return (((int)ress * sign));
}
