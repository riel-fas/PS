/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:16:01 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/07 08:30:19 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculate the length of the stack
int stack_length(t_stack *stack)
{
    int count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return count;
}

// Find the last node in the stack
t_stack *find_last(t_stack *stack)
{
    if (!stack)
        return NULL;
    while (stack->next)
        stack = stack->next;
    return stack;
}

// Check if the stack is sorted
bool stack_sorted(t_stack *stack)
{
    if (!stack)
        return true;
    while (stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return false;
        stack = stack->next;
    }
    return true;
}

// Find the node with the smallest value
t_stack *find_min(t_stack *stack)
{
    long min = LONG_MAX;
    t_stack *min_node = NULL;
    while (stack)
    {
        if (stack->nbr < min)
        {
            min = stack->nbr;
            min_node = stack;
        }
        stack = stack->next;
    }
    return min_node;
}

// Find the node with the largest value
t_stack *find_max(t_stack *stack)
{
    long max = LONG_MIN;
    t_stack *max_node = NULL;
    while (stack)
    {
        if (stack->nbr > max)
        {
            max = stack->nbr;
            max_node = stack;
        }
        stack = stack->next;
    }
    return max_node;
}
