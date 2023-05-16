/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:04:28 by lhasmi            #+#    #+#             */
/*   Updated: 2023/05/15 22:53:50 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <ctype.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct s_node
{
	int				value;
	int				sorted_position;
	int				current_position;
	bool			in_stack_a;
	struct s_node	*next;
}					t_node;

typedef struct s_indexes
{
	size_t	n; 
	size_t	i;
	int		ix;
	size_t	j;
	size_t	index;
	size_t	count;
	size_t	range;
	int		pos1;
	int		pos2;
	int		pos3;
}					t_indexes;

typedef struct s_stack
{
	t_node			*head;
	int				position;
	int				size;
}					t_stack;

int calculate_cutoff(t_node **stack_a);
void		sort3_push_b(t_node **stack_a, t_node **stack_b, int	total_nodes);
t_node		*find_max_node(t_node **head);
void		find_range_numbers(t_node **stack, int range, t_node **range_nodes);
void		bringmax_to_top(t_node **stack, t_node *max_node);
void				bring_to_top(t_node **stack, t_node *min_node);
t_node				*find_min_node(t_node **head);
void				ft_free_lst(t_node *head);
void				free_stacks(t_node **stack_a, t_node **stack_b);
void				free_all(t_node **stack_a, t_node **stack_b, int *numbers);
int					count_nodes(t_node *head);
void				sort_small_stack(t_node **stack_a, t_node **stack_b);
void				update_current_positions(t_node *head);
void				update_sorted_positions(t_node *head, int *numbers, int argc, char *argv[]);
void				print_linked_list(t_node **head);
bool				stack_is_descending(t_node **stack);
bool				stack_is_sorted(t_node **stack);

// create_stacks_lst.c//
t_node				*create_node(int value);
void				create_stacks(t_node **stack_a, t_node **stack_b, int *numbers, size_t *num_count);
void				free_stacks(t_node **stack_a, t_node **stack_b);

//parse_bis.c//
bool				is_duplicate(int *array, size_t count);
// void				get_sorted_index(t_node *head, int argc, char **argv);
// int				get_current_index(t_node *stack, int number);
// int				get_current_index(int *array, int number);

//parse_input_ll.c//
int					*parse_input(size_t argc, char **argv, size_t *num_count);
size_t				count_numbers(size_t argc, char **argv);
int					*allocate_numbers(size_t count);
void 				fill_numbers(size_t argc, char **argv, int *numbers);
void 				check_duplicates(int *numbers, size_t count);


//stack_ops.c//
void				swap_a(t_node **stack_a);
void				swap_b(t_node **stack_b);
// Take first element at the top of b and put it at the top of a (does nothing if b is empty).
void				push_a(t_node **stack_a, t_node **stack_b);
// Take first element at the top of a and put it at the top of b (does nothing if a is empty).
void				push_b(t_node **stack_a, t_node **stack_b);
// Shifts up, First element becomes the last.
void				rotate_a(t_node **stack_a);
void				rotate_b(t_node **stack_b);
// Shifts down, last element becomes the first.
void 				reverse_rotate_a(t_node **stack_a);
void				reverse_rotate_b(t_node **stack_b);

//quick_sort.c//
void				quicksort(int arr[], int length);
void				quicksort_recursion(int arr[], int start, int end);
int					partition(int arr[], int start, int end);

void				sort_three(t_node **stack_a);
void				reverse_sort_three(t_node **stack_a);
void				sort_four(t_node **stack_a, t_node **stack_b);
void		sort_five(t_node **stack_a, t_node **stack_b);
void		sort_six_sevn(t_node **stack_a, t_node **stack_b);
void		sort_stack(t_node **stack_a, t_node **stack_b);
void	push_chunk(t_node **stack_a, t_node **stack_b);
int		count_rotations(t_node *stack, int x);
// This function sorts stack_a and stack_b by pushing elements from stack_b back to stack_a.
void	sort_stack(t_node **stack_a, t_node **stack_b);
#endif