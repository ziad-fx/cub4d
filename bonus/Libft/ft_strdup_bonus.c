/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:14:52 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/27 11:46:37 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

char	*ft_strdup(char *s1)
{
	char		*tab;
	size_t		i;
	size_t		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	tab = (char *)malloc(len + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
