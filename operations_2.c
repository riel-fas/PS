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

void sa_sb(t_stack **stack, char id)
{
    t_stack	*first;
    t_stack	*second;

    if (!stack || !*stack || !(*stack)->next)
        return;

    first = *stack;
    second = first->next;
    //swapping next
    first->next = second->next;
    second->next = first;
    //swapping prev
    second->prev = NULL;
    first->prev = second;
    //if there is more than 2 nodes
    if (first->next)
        first->next->prev = first;
    *stack = second; //updating the head

    // Print operation based on id parameter
    if (id == 'a')
        write(1, "sa\n", 3);
    else if (id == 'b')
        write(1, "sb\n", 3);
}

void ss(t_stack **a, t_stack **b)
{
    sa_sb(a, '\0');
    sa_sb(b, '\0');
    write(1, "ss\n", 3);
}

void ra_rb(t_stack **stack, char id)
{
    t_stack	*first;
    t_stack	*last;

    if (!stack || !*stack || !(*stack)->next)
        return;

    first = *stack;
    last = first;
    while (last->next)
        last = last->next;
    //make the last node the head of linked list
    *stack = first->next;
    (*stack)->prev = NULL;
    //attach the first node to the end of linked list
    first->next = NULL;
    last->next = first;
    first->prev = last;

    // Print operation based on id parameter
    if (id == 'a')
        write(1, "ra\n", 3);
    else if (id == 'b')
        write(1, "rb\n", 3);
}

void rr(t_stack **a, t_stack **b)
{
    // Perform rotate operations without printing
    ra_rb(a, '\0');
    ra_rb(b, '\0');
    write(1, "rr\n", 3);
}

void pa(t_stack **a, t_stack **b)
{
    t_stack	*top_b;

    if (!b || !*b)
        return;
    top_b = *b;
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
    t_stack *top_a;

    if (!a || !*a)
        return;

    top_a = *a;
    *a = top_a->next;
    if (*a)
        (*a)->prev = NULL;

    top_a->next = *b;
    if (*b)
        (*b)->prev = top_a;

    *b = top_a;

    write(1, "pb\n", 3);
}
