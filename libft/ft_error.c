/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:39:26 by lailah            #+#    #+#             */
/*   Updated: 2023/05/08 20:16:52 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

// void ft_error(char *str, int exit_code)
// {
//     perror(str);
//     if (exit_code == 1)
//         exit(exit_code);
//     else if (exit_code == 0)
//         exit(EXIT_SUCCESS);
// }
