/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 09:21:20 by werrahma          #+#    #+#             */
/*   Updated: 2022/11/03 16:34:42 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_return(long a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
	if (a < 0)
		i++;
	while (a)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

static	char	*fill(int a, char *m, int nb)
{
	while (a)
	{
		m[nb--] = a % 10 + '0';
		a = a / 10;
	}
	return (m);
}

char	*ft_itoa(int n)
{
	char	*m;
	int		sign;
	int		nb;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb = ft_return(n);
	if (n < 0)
	{
		n = n * -1;
		sign = 1;
	}
	m = malloc(nb + 1);
	if (!m)
		return (NULL);
	m[nb] = '\0';
	if (sign == 1)
		m[0] = '-';
	nb--;
	if (n == 0)
		m[0] = '0';
	return (fill(n, m, nb));
}
