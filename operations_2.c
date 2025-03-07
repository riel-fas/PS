/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:49:07 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/06 14:54:49 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap stack A or B
void sa_sb(t_stack **stack, char id)
{
    if (!stack || !*stack || !(*stack)->next)
        return;
    t_stack *first = *stack;
    t_stack *second = first->next;
    first->next = second->next;
    second->next = first;
    second->prev = NULL;
    first->prev = second;
    if (first->next)
        first->next->prev = first;
    *stack = second;

    if (id == 'a')
        write(1, "sa\n", 3);
    else if (id == 'b')
        write(1, "sb\n", 3);
}

// Push from stack A to stack B or vice versa
void pa(t_stack **a, t_stack **b)
{
    if (!b || !*b)
        return;
    t_stack *top_b = *b;
    *b = top_b->next;
    if (*b)
        (*b)->prev = NULL;
    top_b->next = *a;
    if (*a)
        (*a)->prev = top_b;
    *a = top_b;
    write(1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b)
{
    if (!a || !*a)
        return;
    t_stack *top_a = *a;
    *a = top_a->next;
    if (*a)
        (*a)->prev = NULL;
    top_a->next = *b;
    if (*b)
        (*b)->prev = top_a;
    *b = top_a;
    write(1, "pb\n", 3);
}
