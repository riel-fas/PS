/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:49:04 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/06 14:53:45 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra_rrb(t_stack **stack, char id)
{
    t_stack	*last;
    t_stack	*second_last;

    if (!stack || !*stack || !(*stack)->next)
        return;

    last = *stack;
    while (last->next)
        last = last->next;
    second_last = last->prev;
    second_last->next = NULL;
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;

    // Print operation based on id parameter
    if (id == 'a')
        write(1, "rra\n", 4);
    else if (id == 'b')
        write(1, "rrb\n", 4);
}

void rrr(t_stack **a, t_stack **b)
{
    // Perform reverse rotate operations without printing
    rra_rrb(a, '\0');
    rra_rrb(b, '\0');
    write(1, "rrr\n", 4);
}
