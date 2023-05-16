/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_ll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:58:14 by lhasmi            #+#    #+#             */
/*   Updated: 2023/05/12 19:30:41 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//- Run  with non numeric parameters. The program must display "Error".OK
// - Run with a duplicate numeric parameter.  must display "Error".OK
// - Run push_swap with only numeric parameters including one greater
// than MAXINT. The program must display "Error".OK
//- No parameters. The program must not display anything and give the prompt back.
//  Run the following command "$>./push_swap 42". The program
// should display nothing (0 instruction).
// - Run the following command "$>./push_swap 0 1 2 3". The
// program should display nothing (0 instruction).
// - Run the following command "$>./push_swap 0 1 2 3 4 5 6 7 8
// 9". The program should display nothing (0 instruction).

// Run ```$>ARG="2 1 0"; ./push_swap $ARG | ./checker_OS $ARG ```
// Check that the checker program displays "OK" and that the size of the list of instructions
// from push_swap is 2 OR 3.

// 1. Save the input sequence you want to sort in a variable named "ARG",
//    ARG="2 1 0"
// 2. Run your push_swap program with the input sequence and pipe its output to the checker program:
//    ./push_swap $ARG | ./checker $ARG
// 3. The checker program will display "OK" if the sequence was sorted correctly,
// or "KO" otherwise. It will also display the number of operations performed by your push_swap program.
// 4. You can also use the "-v" flag to display the details of each operation performed by your push_swap program:
//    ./push_swap $ARG | ./checker -v $ARG
//This will display each operation along with the state of the stacks after each operation.


size_t	count_numbers(size_t argc, char **argv)
{
	t_indexes	index;
	char 		**split_numbers;

	index.count = 0;
	index.n = 1;
	while (index.n < argc)
	{
		split_numbers = ft_split(argv[index.n], ' ');
		if (!split_numbers)
			ft_error("Error: Memory allocation error");
		index.i = 0;
		while (split_numbers[index.i])
		{
			if (ft_isnumber(split_numbers[index.i]))
				index.count++;
			index.i++;
		}
		free_argv(split_numbers);
		index.n++;
	}
	return (index.count);
}

int	*allocate_numbers(size_t count)
{
	int *numbers = (int *)malloc(sizeof(int) * (count + 1));
	if (!numbers)
		ft_error("Error: Memory allocation error");
	return (numbers);
}

void fill_numbers(size_t argc, char **argv, int *numbers)
{
	t_indexes	index;
	char 		**split_numbers; 

	index.n = 1;
	index.index = 0;
	while (index.n < argc)
	{
		split_numbers = ft_split(argv[index.n], ' ');
		if (!split_numbers)
			ft_error("Error: Memory allocation error");
		index.i = 0;
		while (split_numbers[index.i])
		{
			if (ft_isnumber(split_numbers[index.i]) && ft_isint(split_numbers[index.i]))
				numbers[index.index++] = ft_atoi(split_numbers[index.i]);
			else if (!ft_isnumber(split_numbers[index.i]))
				ft_error("Wrong input");
			index.i++;
		}
		free_argv(split_numbers);
		index.n++;
	}
	numbers[index.index] = 0;
}

void check_duplicates(int *numbers, size_t count)
{
	if (is_duplicate(numbers, count))
		ft_error("Duplicate input");
}

int	*parse_input(size_t argc, char **argv, size_t *num_count)
{
	int		*numbers;

	*num_count = count_numbers(argc, argv);
	numbers = allocate_numbers(*num_count);
	fill_numbers(argc, argv, numbers);
	check_duplicates(numbers, *num_count);

	return (numbers);
}
