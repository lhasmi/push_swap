/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3to6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:54:24 by lhasmi            #+#    #+#             */
/*   Updated: 2023/05/14 22:21:56 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_node **stack_a)
{
    t_indexes index;

    index.pos1 = (*stack_a)->sorted_position;
    index.pos2 = (*stack_a)->next->sorted_position;
    index.pos3 = (*stack_a)->next->next->sorted_position;

    if(index.pos1 > index.pos2 && index.pos1 < index.pos3)
        swap_a(stack_a);
    else if(index.pos1 > index.pos2 && index.pos1 > index.pos3 && index.pos2 < index.pos3)
        rotate_a(stack_a);
    else if(index.pos1 < index.pos2 && index.pos1 < index.pos3 && index.pos2 > index.pos3)
    {
        swap_a(stack_a);
        rotate_a(stack_a);
    }
    else if(index.pos1 < index.pos2 && index.pos1 > index.pos3)
        reverse_rotate_a(stack_a);
    else if(index.pos1 > index.pos2 && index.pos1 > index.pos3 && index.pos2 > index.pos3)
    {
        swap_a(stack_a);
        reverse_rotate_a(stack_a);
    }
}

void reverse_sort_three(t_node **stack_a)
{
    t_indexes index;

    index.pos1 = (*stack_a)->sorted_position;
    index.pos2 = (*stack_a)->next->sorted_position;
    index.pos3 = (*stack_a)->next->next->sorted_position;

    if(index.pos1 < index.pos2 && index.pos1 > index.pos3)
        swap_a(stack_a);
    else if(index.pos1 < index.pos2 && index.pos1 < index.pos3 && index.pos2 < index.pos3)
    {
        rotate_a(stack_a);
        swap_a(stack_a);
    }
    else if(index.pos1 > index.pos2 && index.pos1 < index.pos3)
        reverse_rotate_a(stack_a);
    else if(index.pos1 > index.pos2 && index.pos1 > index.pos3 && index.pos2 < index.pos3)
    {
        reverse_rotate_a(stack_a);
        swap_a(stack_a);
    }
    else if(index.pos1 < index.pos2 && index.pos1 < index.pos3 && index.pos2 > index.pos3)
        rotate_a(stack_a);
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
    t_node	*min_node;

	min_node = find_min_node(stack_a);
	bring_to_top(stack_a, min_node);
    push_b(stack_a, stack_b);
    sort_three(stack_a);
    push_a(stack_a, stack_b);
	update_current_positions(*stack_a);
}

t_node		*find_min_node(t_node **head)
{
    t_node		*min_nd;
    t_node		*current;

	min_nd = NULL;
	current = *head;
    while (current != NULL)
    {
        if ((current->in_stack_a) && (min_nd == NULL || current->value < min_nd->value))
            min_nd = current;       
        current = current->next;
    }
    return (min_nd);
}

void	bring_to_top(t_node **stack, t_node *min_node) 
{
	t_indexes 	index;

    index.count = count_nodes(*stack);
	min_node = find_min_node(stack);
	update_current_positions(*stack);
	index.n = min_node->current_position;
    if (index.n < index.count / 2) 
	{
		index.i = 0;
        while (index.i < index.n)
		{
            rotate_a(stack);
			index.i++;
        }
    } 
	else 
	{
		index.i = 0;
        while (index.i < index.count - index.n) 
		{
            reverse_rotate_a(stack);
			index.i++;
        }
    }
}

bool	stack_is_sorted(t_node **stack)
{
	t_node		*current;

	if(!stack || !*stack)
		return (true);
	current = *stack;
	while (current->next != NULL)
    {
		if(current->value > current->next->value)
			return (false);
		current = current->next;
    }
    return (true);
}

bool	stack_is_descending(t_node **stack)
{
	t_node		*current;

	if(!stack || !*stack)
		return (true);
	current = *stack;
	while (current->next != NULL)
    {
		if(current->value < current->next->value)
			return (false);
		current = current->next;
    }
    return (true);
}

void sort_five(t_node **stack_a, t_node **stack_b)
{
    t_node	*min_node;
    int		total_nodes;

	min_node = NULL;
    total_nodes = count_nodes(*stack_a);
	while(total_nodes > 3)
	{
		min_node = find_min_node(stack_a);
		bring_to_top(stack_a, min_node);
		update_current_positions(*stack_a);
		push_b(stack_a, stack_b);
		total_nodes--;
	}
	if (total_nodes == 3 && !stack_is_sorted(stack_a))
		sort_three(stack_a);
    while (count_nodes(*stack_b) > 0)
	{
        push_a(stack_a, stack_b);
		total_nodes++;
	}
}

void sort3_push_b(t_node **stack_a, t_node **stack_b, int	total_nodes)
{
    if (total_nodes == 3 && !stack_is_sorted(stack_a))
		sort_three(stack_a);
    while (count_nodes(*stack_b) > 0)
	{
        push_a(stack_a, stack_b);
		total_nodes++;
	}
}

void sort_six_sevn(t_node **stack_a, t_node **stack_b)
{
    t_node	*min_node;
    int		total_nodes;

	min_node = NULL;
    total_nodes = count_nodes(*stack_a);
	while(total_nodes > 3)
	{
		min_node = find_min_node(stack_a);
		bring_to_top(stack_a, min_node);
		update_current_positions(*stack_a);
        if(!stack_is_sorted(stack_a))
        {
		    push_b(stack_a, stack_b);
            total_nodes--;
        }
        else
            break;
	}
    sort3_push_b(stack_a, stack_b, total_nodes);
}

	// printf("min_node inside bringtotop: %d, condition tht decides op : %zu\n", min_node->value, index.n);
	// 	printf("min_node: %d, iteration number : %d\n", min_node->value, i);
    // printf("Stack_a before pusching back:\n");
    // printf("Stack_b before pusching back:\n");
    // print_linked_list(stack_a);
    // print_linked_list(stack_b);
	// 	printf("top of stack_a:%d\n", (*stack_a)->value);

		// printf("min_node: %d, iteration number : %d\n", min_node->value, i);
		// printf("top of stack_a:%d\n", (*stack_a)->value);
	// int i = 0;
	// 	i++;
    // printf("Stack_a before pusching back:\n");
    // print_linked_list(stack_a);
    // printf("Stack_b before pusching back:\n");
    // print_linked_list(stack_b);

	// if(!stack_is_descending(stack_b) && count_nodes(*stack_b) == 3)
	// 	reverse_sort_three(stack_b);
    // else if (!stack_is_descending(stack_b) && count_nodes(*stack_b) == 2)
    //     swap_b(stack_b);
    //     printf("Stack_a after 1st if :\n");
    // print_linked_list(stack_a);
    // printf("Stack_b after 1st if:\n");
    // print_linked_list(stack_b);