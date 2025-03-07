/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_in_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:53:15 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/07 12:53:18 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Append a node to the stack
static void append_node(t_stack **stack, int n)
{
    t_stack *node = malloc(sizeof(t_stack));
    if (!node)
        return;
    node->nbr = n;
    node->next = NULL;
    node->prev = find_last(*stack);
    if (!*stack)
        *stack = node;
    else
        find_last(*stack)->next = node;
}

// Initialize stack A
void populate_stack_a(t_stack **a, char **av, int start_index)
{
    long n;
    int i = start_index;
    while (av[i])
    {
        n = atoi_v2(av[i]);
        if (n > INT_MAX || n < INT_MIN)
            free_errors(a);
        if (error_duplicate(*a, (int)n))
            free_errors(a);
        append_node(a, (int)n);
        i++;
    }
}
