/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coste_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:50:15 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/07 16:13:01 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculate the index and median position for each node


void move_to_top(t_stack **stack, t_stack *target, char stack_name)
{
    while (*stack != target)
    {
        if (target->above_median)
        {
            if (stack_name == 'a')
                ra_rb(stack, 'a');
            else if (stack_name == 'b')
                ra_rb(stack, 'b');
        }
        else
        {
            if (stack_name == 'a')
                rra_rrb(stack, 'a');
            else if (stack_name == 'b')
                rra_rrb(stack, 'b');
        }
    }
}

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
    long best_match_value;

    while (b)
    {
        best_match_value = LONG_MAX;
        target_node = NULL; // Initialize target_node to NULL for each b element
        current_a = a;

        while (current_a)
        {
            // Find closest larger number in A
            if (current_a->nbr > b->nbr && current_a->nbr < best_match_value)
            {
                best_match_value = current_a->nbr;
                target_node = current_a;
            }
            current_a = current_a->next;
        }

        // If no larger number found, target the minimum
        if (target_node == NULL)
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
            b->push_cost = len_b - b->index; // Cost to rotate backward
        if (b->target_node->above_median)
            b->push_cost += b->target_node->index; // Cost to rotate forward in A
        else
            b->push_cost += len_a - b->target_node->index; // Cost to rotate backward in A
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
void move_both_stacks(t_stack **a, t_stack **b, t_stack *target_a, t_stack *target_b)
{
    // Move both stacks together when possible
    while (*a != target_a && *b != target_b && target_a->above_median && target_b->above_median)
    {
        // Use combined operation
        rr(a, b);
    }

    while (*a != target_a && *b != target_b && !target_a->above_median && !target_b->above_median)
    {
        // Use combined operation
        rrr(a, b);
    }

    // Complete individual rotations
    move_to_top(a, target_a, 'a');
    move_to_top(b, target_b, 'b');
}
