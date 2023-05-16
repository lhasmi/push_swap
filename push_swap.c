/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainsmall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:54:09 by lhasmi            #+#    #+#             */
/*   Updated: 2023/05/15 22:40:29 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool is_sorted(int *array, size_t count)
{
    size_t i;

	i = 1;
	while (i < count)
    {
        if (array[i] < array[i - 1])
            return (false);
		i++;
    }
    return (true);
}

void	update_sorted_positions(t_node *head, int *numbers, int argc, char *argv[])
{
	t_node		*current;
	t_stack		stack;
	t_indexes	index;
	size_t		num_count;

	num_count = count_numbers(argc, argv);
	quicksort(numbers, (int)num_count);
	current = head;
	while (current != NULL)
	{
		stack.position = -1;
		index.i = 0;
		while (index.i < num_count)
		{
			if (current->value == numbers[index.i])
			{
				stack.position = index.i;
				break ;
			}
			index.i++;
		}
		current->sorted_position = stack.position;
		current = current->next;
	}
}

void update_current_positions(t_node *head) 
{
    t_node 	*current;
    int 	position;
	
	current = head;
    position = 0;
    while (current != NULL) 
	{
        current->current_position = position++;
        current = current->next;
    }
}

void	print_linked_list(t_node **head)
{
	t_node	*current;

	current = *head;
	printf("Linked list contents:\n");
	while (current != NULL)
	{
		printf("Value: %d, Current position: %d, Sorted position: %d\n",
				current->value,
				current->current_position,
				current->sorted_position);
		current = current->next;
	}
}

int		count_nodes(t_node *head) 
{
    t_node		*current;
	t_indexes	index;

	current = head;
	index.count = 0;
    while(current != NULL)
    {
        index.count++;
        current = current->next;
    }
    return (index.count);
}

void	sort_small_stack(t_node **stack_a, t_node **stack_b)
{
    t_indexes	index;

	index.count = count_nodes(*stack_a);
    if (index.count == 2 && (*stack_a)->value > (*stack_a)->next->value)
        swap_a(stack_a);
    else if (index.count == 3)
        sort_three(stack_a);
    else if (index.count == 4)
        sort_four(stack_a, stack_b);
    else if (index.count == 5)
        sort_five(stack_a, stack_b);
    else if (index.count > 5 && index.count <= 11)
        sort_six_sevn(stack_a, stack_b);
    else if (index.count > 11)
    {
        push_chunk(stack_a, stack_b);
        sort_stack(stack_a, stack_b);
    }
}

// void    myleaksfunc(void)
// {
//     system("leaks push_swap");
// }

int main(int argc, char **argv)
{
    int     *numbers;
    size_t  num_count;
    t_node  *stack_a;
    t_node  *stack_b;

    num_count = 0;
    if (argc == 1)
        return (0);
    numbers = parse_input(argc, argv, &num_count);
    if (is_sorted(numbers, num_count))
    {
        free(numbers);
        return (0);
    }
    create_stacks(&stack_a, &stack_b, numbers, &num_count);
    update_current_positions(stack_a);
    update_sorted_positions(stack_a, numbers, argc, argv);

    // Example calls to the new functions
	sort_small_stack(&stack_a, &stack_b);
    // printf("///////Stack_a:////////\n");
    // print_linked_list(&stack_a);
    // atexit(myleaksfunc);
    // printf("///////Stack_b:////////\n");
    // print_linked_list(&stack_b);
	//free all
    free_all(&stack_a, &stack_b, numbers);
    return (0);
}

	// printf("Stack_a before sorting:\n");
    // print_linked_list(&stack_a);
	// printf("Stack_b before sorting:\n");
    // print_linked_list(&stack_b);
	// printf("Sorting...\n");
	// printf("Stack_a:\n");
    // print_linked_list(&stack_a);
	// printf("Stack_b:\n");
    // print_linked_list(&stack_b);