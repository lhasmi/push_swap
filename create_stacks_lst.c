/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:39:31 by lhasmi            #+#    #+#             */
/*   Updated: 2023/05/16 10:25:58 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		ft_error("Error");
	new_node->value = value;
	new_node->sorted_position = -1;
	new_node->current_position = -1;
	new_node->in_stack_a = true;
	new_node->next = NULL;
	return (new_node);
}

void	create_stacks(t_node **stack_a, t_node **stack_b, int *numbers,
		size_t *num_count)
{
	t_indexes	index;
	int			num;
	t_node		*new_node;
	t_node		*current;

	*stack_a = NULL;
	*stack_b = NULL;
	index.n = *num_count;
	index.i = 0;
	while (index.n > 0)
	{
		num = numbers[index.i++];
		new_node = create_node(num);
		if (*stack_a == NULL)
			*stack_a = new_node;
		else
		{
			current = *stack_a;
			while (current->next != NULL)
				current = current->next;
			current->next = new_node;
		}
		index.n--;
	}
}
