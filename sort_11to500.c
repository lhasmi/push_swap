/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_11to500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:00:49 by lhasmi            #+#    #+#             */
/*   Updated: 2023/05/15 22:43:37 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int calculate_cutoff(t_node **stack_a) 
{
    int     number_of_nodes;
    int     cutoff;
    
    number_of_nodes = count_nodes(*stack_a);
    cutoff = 1;
    while (number_of_nodes > 0) 
	{
        cutoff++;
        number_of_nodes /= 2;
    }
    return (cutoff * 24 / 10);
}

void	push_chunk(t_node **stack_a, t_node **stack_b)
{
    int    cutoff;
    int    i;

	i = 0;
	// cutoff = ft_sqrt(count_nodes(*stack_a)) * 14 / 10;
	cutoff = calculate_cutoff(stack_a);
	while (*stack_a != NULL)
	{
        // current_node = *stack_a;
		if ((*stack_a)->sorted_position <= i)
		{
            // printf("current_node: %d, iteration number : %d\n", current_node->value, i);
			push_b(stack_a, stack_b);
            // update_current_positions(*stack_a);
            rotate_b(stack_b);
			i++;
            // printf("current_node: %d, iteration number : %d\n", current_node->value, i);
		}
		else if ((*stack_a)->sorted_position <= i + cutoff)
		{
            // printf("Stack_a after 2nd if :\n");
            // printf("current_node: %d, iteration number : %d\n", current_node->value, i);
			push_b(stack_a, stack_b);
			i++;
		}
		else
        {
            // printf("current_node: %d, iteration number : %d\n", current_node->value, i);
            rotate_a(stack_a);
            // update_current_positions(*stack_a);
            // bring_to_top(stack_a, current_node);
            // i++;
        }
	}
}
int	count_rotations(t_node *stack, int x)
{
	t_indexes    index;

	index.ix = 0;
	while (stack && stack->sorted_position != x)
	{
		stack = stack->next;
		index.ix++;
	}
	return (index.ix);
}

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int	rb_count;
	int	rrb_count;
    int	count;

    count = count_nodes(*stack_b);
	while (count - 1 >= 0)
	{
		rb_count = count_rotations(*stack_b, count - 1);
		rrb_count = (count) - rb_count;
		if (rb_count <= rrb_count)
		{
			while ((*stack_b)->sorted_position != count - 1)
				rotate_b(stack_b);
			push_a(stack_a, stack_b);
			count--;
		}
		else
		{
			while ((*stack_b)->sorted_position != count - 1)
				reverse_rotate_b(stack_b);
			push_a(stack_a, stack_b);
			count--;
		}
	}
}

    // if (count == 3 && !stack_is_sorted(stack_a))
	// 	sort_three(stack_a);
    // else if (count == 2 && !stack_is_sorted(stack_a))
    //     swap_a(stack_a);
    // while (*stack_b != NULL)
    // {
    //     push_a(stack_a, stack_b);
    //     update_current_positions(*stack_a);
    // }
            // print_linked_list(stack_a);
            // printf("Stack_b after 2nd if:\n");

            // printf("Stack_a after else:\n");
            // print_linked_list(stack_a);
            // printf("Stack_b after else:\n");

// t_node		*find_max_node(t_node **head)
// {
//     t_node		*max_nd;
//     t_node		*current;

// 	max_nd = NULL;
// 	current = *head;
//     while (current != NULL)
//     {
//         if (!(current->in_stack_a) && (max_nd == NULL || current->value > max_nd->value))
//             max_nd = current;       
//         current = current->next;
//     }
//     return (max_nd);
// }

// void find_cutoff_numbers(t_node **stack, int cutoff, t_node **cutoff_nodes)
// {
//     t_node		*current;
//     int count = 0;

//     current = *stack;
//     while (current != NULL && count < cutoff)
//     {
//         if (current->in_stack_a && (current->sorted_position <= cutoff))
//         {
//             cutoff_nodes[count] = current;
//             count++;
//         }
//         current = current->next;
//     }
// }

// void	bringmax_to_top(t_node **stack, t_node *max_node) 
// {
// 	t_indexes 	index;

//     index.count = count_nodes(*stack);
// 	max_node = find_max_node(stack);
// 	update_current_positions(*stack);
// 	index.n = max_node->current_position;
//     if (index.n < index.count / 2) 
// 	{
// 		index.i = 0;
//         while (index.i < index.n)
// 		{
//             rotate_a(stack);
//             update_current_positions(*stack);
// 			index.i++;
//         }
//     } 
// 	else 
// 	{
// 		index.i = 0;
//         while (index.i < index.count - index.n) 
// 		{
//             reverse_rotate_a(stack);
//             update_current_positions(*stack);
// 			index.i++;
//         }
//     }
// }

// void bring_cutoff_to_top(t_node **stack, t_node **cutoff_nodes, size_t cutoff)
// {
//     t_indexes 	index;

//     index.count = count_nodes(*stack);
// 	index.j = 0;
//     while (index.j < cutoff)
//     {
//         t_node *node = cutoff_nodes[index.j];
// 		update_current_positions(*stack);
//         index.n = node->current_position;
//         if (index.n < index.count / 2) 
//         {
//             index.i = 0;
//             while (index.i < index.n)
//             {
//                 rotate_a(stack);
//                 update_current_positions(*stack);
//                 index.i++;
//             }
//         } 
//         else 
//         {
//             index.i = 0;
//             while (index.i < index.count - index.n) 
//             {
//                 reverse_rotate_a(stack);
//                 update_current_positions(*stack);
//                 index.i++;
//             }
//         }
// 		index.j++;
//     }
// }
            // print_linked_list(stack_b);