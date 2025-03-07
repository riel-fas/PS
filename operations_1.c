/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:49:04 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/07 16:03:00 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotate stack A or B
void ra_rb(t_stack **stack, char id)
{
    if (!stack || !*stack || !(*stack)->next)
        return;
    t_stack *first = *stack;
    t_stack *last = find_last(*stack);
    *stack = first->next;
    (*stack)->prev = NULL;
    first->next = NULL;
    last->next = first;
    first->prev = last;

    if (id == 'a')
        write(1, "ra\n", 3);
    else if (id == 'b')
        write(1, "rb\n", 3);
}

// Reverse rotate stack A or B
void rra_rrb(t_stack **stack, char id)
{
    if (!stack || !*stack || !(*stack)->next)
        return;
    t_stack *last = find_last(*stack);
    t_stack *second_last = last->prev;
    second_last->next = NULL;
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;

    if (id == 'a')
        write(1, "rra\n", 4);
    else if (id == 'b')
        write(1, "rrb\n", 4);
}

void rr(t_stack **a, t_stack **b)
{
    ra_rb(a, 'c'); // Use 'c' to not print individual operations
    ra_rb(b, 'c');
    write(1, "rr\n", 3);
}

void rrr(t_stack **a, t_stack **b)
{
    rra_rrb(a, 'c'); // Use 'c' to not print individual operations
    rra_rrb(b, 'c');
    write(1, "rrr\n", 4);
}
