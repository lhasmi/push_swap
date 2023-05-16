/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:36:38 by lailah            #+#    #+#             */
/*   Updated: 2023/05/16 10:22:27 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

void	ft_errorex(char *str, int exit_code)
{
	perror(str);
	if (exit_code == 1)
		exit(exit_code);
	else if (exit_code == 0)
		exit(EXIT_SUCCESS);
}

int	ft_openfile(char *file, int i)
{
	if (i == 0)
	{
		if (open(file, O_RDONLY, 0777) == -1)
			ft_errorex("Error: open failed", 1);
	}
	else if (i == 1)
	{
		if (open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777) == -1)
			ft_errorex("Error: open failed", 1);
	}
	else if (i == 2)
	{
		if (open(file, O_WRONLY | O_CREAT | O_APPEND, 0777) == -1)
			ft_errorex("Error: open failed", 1);
	}
	if (ft_strncmp(file, ".ber", 4) != 0)
		ft_errorex("Error: file extension is not .ber", 1);
	return (open(file, O_RDONLY, 0777));
}
