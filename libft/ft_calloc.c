/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lailah <lailah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:46:41 by lhasmi            #+#    #+#             */
/*   Updated: 2022/05/20 13:55:00 by lailah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;

	if ((count >= SIZE_MAX) || (size >= SIZE_MAX))
		return (NULL);
	s = malloc(count * size);
	if (s == (NULL))
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}
