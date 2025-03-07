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

static t_stack	*find_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next) //Loop until the end of the stack is reached
		stack = stack->next;
	return (stack);
}

static void check_duplicates(t_stack *stack)
{
	t_stack *current;
	t_stack *runner;

	current = stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->nbr == runner->nbr)
						error_exit ();
			runner = runner->next;
		}
		current = current->next;
	}
}

static void	append_to_stack_A(t_stack **stack, int nb)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = nb;
 	if (!*stack) //if stack a is empty
	{
		*stack = node;
		node->prev = NULL;
	}
	else //if theres already nbrs in the stack a its finds the last node then set prev to it and next to null
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void populate_stack_A(t_stack **A, char **av, int start_index)
{
	long nb;
	int x;

	x = start_index;
	while (av[x])
	{
		nb = atoi_v2(av[x]);
		if (nb > INT_MAX || nb < INT_MIN) // Check for integer overflow
		{
			free_stack(A);
			error_exit ();
		}
		append_to_stack_A(A, (int)nb);
		x++;
	}
    // After populating, check for duplicates
	check_duplicates(*A);
}
