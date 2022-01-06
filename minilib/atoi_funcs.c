/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:55:37 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/10 20:11:10 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int	ft_atoi(const char *str)
{
	int		a;
	long	ret;
	int		neg;

	a = 0;
	ret = 0;
	neg = 1;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == 32)
		++a;
	if (str[a] == 43 || str[a] == 45)
	{
		if (str[a] == 45)
			neg = -1;
		++a;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		ret = ret * 10 + (str[a] - 48);
		++a;
	}
	return (ret * neg);
}

static long	is_pos(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
		nb = -nb;
	return (nb);
}

int	calc_len(long nb, int n)
{
	int		len;

	len = 1;
	if (n < 0)
		++len;
	while (nb >= 10)
	{
		nb /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ret;
	long	nb;
	int		len;
	int		i;

	nb = is_pos(n);
	len = calc_len(nb, n);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[0] = '-';
	ret[len--] = '\0';
	nb = is_pos(n);
	i = 0;
	if (n < 0)
		i = 1;
	while (len >= i)
	{
		ret[len] = nb % 10 + 48;
		nb /= 10;
		--len;
	}
	return (ret);
}
