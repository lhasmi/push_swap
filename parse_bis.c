/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:12:08 by lhasmi            #+#    #+#             */
/*   Updated: 2023/05/12 16:52:51 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_duplicate(int *array, size_t count)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (array[i] == array[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

// int get_current_index(int *array, int number)
// {
//     int index = 0;

//     while (array[index] != '\0')
//     {
//         if (array[index] == number)
//             return index;
//         index++;
//     }

//     return -1; // Return -1 if the number is not found in the array
// }

// void	get_sorted_index(t_node *head, int argc, char **argv)
// {
// 	int		*numbers;
// 	t_node	*current;
// 	int		position;
// 	int		i;

// 	numbers = (int *)malloc(sizeof(int) * (argc - 1));
// 	if (!numbers)
// 		ft_error("Error: Memory allocation error");
// 	i = 1;
// 	while (i < argc)
// 	{
// 		numbers[i - 1] = atoi(argv[i]);
// 		i++;
// 	}
// 	quicksort(numbers, argc - 1);
// 	current = head;
// 	while (current != NULL)
// 	{
// 		position = -1;
// 		i = 0;
// 		while (i < argc - 1)
// 		{
// 			if (current->value == numbers[i])
// 			{
// 				position = i;
// 				break ;
// 			}
// 			i++;
// 		}
// 		current->sorted_position = position;
// 		current = current->next;
// 	}
// 	free(numbers);
// }

// int	get_current_index(t_node *stack, int number)
// {
// 	int		index;
// 	t_node	*current;

// 	index = 0;
// 	current = stack;
// 	while (current != NULL)
// 	{
// 		if (current->value == number)
// 		{
// 			current->current_position = index;
// 			return (index);
// 		}
// 		index++;
// 		current = current->next;
// 	}
// 	return (-1); // Return -1 if the number is not found in the stack
// }

// it iterates through the linked list and updates the `sorted_position` for each node by finding its position
// in the sorted array.
// Make sure to call `update_sorted_positions` after parsing the input in your main function:
// int	main(int argc, char **argv)
// {
// 	t_node	*head;

// 	head = parse_input(argc, argv);
// 	update_sorted_positions(head, argc, argv);
// 	// ... continue with the rest of the program
// }
