/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:11:45 by asioud            #+#    #+#             */
/*   Updated: 2023/05/12 00:05:43 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcount(const char *str, char del)
{
	size_t	i;
	size_t	wcount;

	i = 0;
	wcount = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == del))
			i++;
		if (str[i] && (str[i] != del))
			wcount++;
		while (str[i] && (str[i] != del))
			i++;
	}
	return (wcount);
}
