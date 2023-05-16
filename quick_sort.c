/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:03:49 by lhasmi            #+#    #+#             */
/*   Updated: 2023/05/08 20:16:11 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort(int arr[], int length)
{
	quicksort_recursion(arr, 0, length - 1);
}

void	quicksort_recursion(int arr[], int start, int end)
{
	int	pivot_index;

	if (start < end)
	{
		pivot_index = partition(arr, start, end);
		//this applies the swap btw both sides
		//of the pivot and between the pivot and the last element of the left side
		quicksort_recursion(arr, start, pivot_index - 1);
		//repeat the same process on the left side(3 1 2)
		quicksort_recursion(arr, pivot_index + 1, end);
		//repeat the same process on the right side(6 7 5)
	}
}

int	partition(int arr[], int start, int end)
{
	int pivot_value;
	int i; //placeholder for the elements of the left side, to be swaped with j
	int j; //moves from left to right,
			// to check if the element is smaller than the pivot

	pivot_value = arr[end]; //4
	i = start;              //3
	j = start;              //3
	while (j < end)
	{
		if (arr[j] <= pivot_value)
		//onöy incremented if 3 is smaller than 4 if not j is incremented
		{
			ft_swap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	ft_swap(&arr[i], &arr[end]);
	return (i);
}