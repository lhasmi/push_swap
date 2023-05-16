/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:01:17 by lhasmi            #+#    #+#             */
/*   Updated: 2023/05/14 23:49:44 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swaps the first two elements of stack a (does nothing if there is only one or no elements).
void swap_a(t_node **stack_a)
{
    t_node *first;
    t_node *second;

    if (*stack_a && (*stack_a)->next)
    {
        first = *stack_a;
        second = (*stack_a)->next;

        first->next = second->next;
        second->next = first;
        *stack_a = second;
        write(1, "sa\n", 3);
    }
}

void swap_b(t_node **stack_b)
{
    t_node  *first;
    t_node  *second;

    if (*stack_b && (*stack_b)->next)
    {
        first = *stack_b;
        second = (*stack_b)->next;

        first->next = second->next;
        second->next = first;
        *stack_b = second;
        write(1, "sb\n", 3);
    }
}

// Take first element at the top of b and put it at the top of a (does nothing if b is empty).
void push_a(t_node **stack_a, t_node **stack_b)
{
    t_node *node_to_move;

    if (*stack_b)
    {
        node_to_move = *stack_b;
        // Disconnect the node from stack_b
        *stack_b = (*stack_b)->next;
        node_to_move->next = NULL;
        // Set the in_stack_a flag to true
        node_to_move->in_stack_a = true;
        // Push the node to stack_a
        node_to_move->next = *stack_a;
        *stack_a = node_to_move;
        write(1, "pa\n", 3);
    }
}
// Take first element at the top of a and put it at the top of b (does nothing if a is empty).
void push_b(t_node **stack_a, t_node **stack_b)
{
    t_node *node_to_move;

    if (*stack_a)
    {
        node_to_move = *stack_a;
        // Disconnect the node from stack_a
        *stack_a = (*stack_a)->next;
        node_to_move->next = NULL;
        // Set the in_stack_a flag to false
        node_to_move->in_stack_a = false;
        // Push the node to stack_b
        node_to_move->next = *stack_b;
        *stack_b = node_to_move;
        write(1, "pb\n", 3);
    }
}

// Shifts up, First element becomes the last.
void rotate_a(t_node **stack_a)
{
    t_node *first;
    t_node *last;

    if (*stack_a && (*stack_a)->next)
    {
        first = *stack_a;
        *stack_a = (*stack_a)->next;
        first->next = NULL;

        last = *stack_a;
        while (last->next)
            last = last->next;

        last->next = first;
        write(1, "ra\n", 3);
    }
}
// Shifts up, First element becomes the last.
void rotate_b(t_node **stack_b)
{
    t_node  *first;
    t_node  *last;

    if (*stack_b && (*stack_b)->next)
    {
        first = *stack_b;
        *stack_b = (*stack_b)->next;
        first->next = NULL;
        last = *stack_b;
        while (last->next)
            last = last->next;
        last->next = first;
        write(1, "rb\n", 3);
    }
}

// Shifts down, last element becomes the first.
void reverse_rotate_a(t_node **stack_a)
{
    t_node *last;
    t_node *before_last;

    if (*stack_a && (*stack_a)->next)
    {
        before_last = *stack_a;
        while (before_last->next && before_last->next->next)
            before_last = before_last->next;
        last = before_last->next;
        before_last->next = NULL;
        last->next = *stack_a;
        *stack_a = last;
        write(1, "rra\n", 4);
    }
}

void reverse_rotate_b(t_node **stack_b)
{
    t_node *last;
    t_node *before_last;

    if (*stack_b && (*stack_b)->next)
    {
        before_last = *stack_b;
        while (before_last->next && before_last->next->next)
            before_last = before_last->next;
        last = before_last->next;
        before_last->next = NULL;
        last->next = *stack_b;
        *stack_b = last;
        write(1, "rrb\n", 4);
    }
}
