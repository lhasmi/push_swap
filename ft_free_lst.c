/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:12:22 by lhasmi            #+#    #+#             */
/*   Updated: 2023/05/16 10:28:32 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_lst(t_node *head)
{
	t_node	*current;
	t_node	*temp;

	current = head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

void	free_stacks(t_node **stack_a, t_node **stack_b)
{
	ft_free_lst(*stack_a);
	ft_free_lst(*stack_b);
	*stack_a = NULL;
	*stack_b = NULL;
}

void	free_all(t_node **stack_a, t_node **stack_b, int *numbers)
{
	free(numbers);
	ft_free_lst(*stack_a);
	ft_free_lst(*stack_b);
}
