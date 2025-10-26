/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:51:07 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/26 22:30:49 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

static int	ft_checker(int c)
{
	if (c < 0)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;
	long	checker;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		checker = res;
		res = res * 10 + (str[i] - '0');
		if (res / 10 != checker)
			return (ft_checker(sign));
		i++;
	}
	return ((int)(sign * res));
}
