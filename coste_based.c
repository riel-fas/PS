/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coste_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:50:15 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/07 13:08:28 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculate the index and median position for each node
void current_index(t_stack *stack)
{
    int i = 0;
    int median = stack_length(stack) / 2;

    while (stack)
    {
        stack->index = i;
        stack->above_median = (i <= median);
        stack = stack->next;
        i++;
    }
}

// Find the target node in stack A for each node in stack B
void set_target_b(t_stack *a, t_stack *b)
{
    t_stack *current_a;
    t_stack *target_node;
    long best_match_index;

    while (b)
    {
        best_match_index = LONG_MAX;
        current_a = a;
        while (current_a)
        {
            if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
            {
                best_match_index = current_a->nbr;
                target_node = current_a;
            }
            current_a = current_a->next;
        }
        if (best_match_index == LONG_MAX)
            b->target_node = find_min(a);
        else
            b->target_node = target_node;
        b = b->next;
    }
}

// Calculate the push cost for each node in stack B
void cost_analysis_b(t_stack *a, t_stack *b)
{
    int len_a = stack_length(a);
    int len_b = stack_length(b);

    while (b)
    {
        b->push_cost = b->index;
        if (!b->above_median)
            b->push_cost = len_b - b->index;
        if (b->target_node->above_median)
            b->push_cost += b->target_node->index;
        else
            b->push_cost += len_a - b->target_node->index;
        b = b->next;
    }
}

// Set the cheapest node in stack B
void set_cheapest(t_stack *stack)
{
    long cheapest_value = LONG_MAX;
    t_stack *cheapest_node = NULL;

    while (stack)
    {
        if (stack->push_cost < cheapest_value)
        {
            cheapest_value = stack->push_cost;
            cheapest_node = stack;
        }
        stack = stack->next;
    }
    if (cheapest_node)
        cheapest_node->cheapest = true;
}

// Retrieve the cheapest node in stack B
t_stack *get_cheapest(t_stack *stack)
{
    while (stack)
    {
        if (stack->cheapest)
            return stack;
        stack = stack->next;
    }
    return NULL;
}

// Move the target node to the top of the stack
void move_to_top(t_stack **stack, t_stack *target)
{
    while (*stack != target)
    {
        if (target->above_median)
            ra_rb(stack, 'a');
        else
            rra_rrb(stack, 'a');
    }
}
