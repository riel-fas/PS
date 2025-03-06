/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:19:28 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/06 16:39:28 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack *tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void free_args(char **args)
{
	int i = 0;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

bool stack_sort_check(t_stack *stack)
{
    if (!stack || !stack->next)
        return true; // Empty or single-node stack is sorted
    while (stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return false;
        stack = stack->next;
    }
    return true;
}

int	stack_length(t_stack *stack)
{
	int x;

	x = 0;
	while (stack)//fixed???
	{
		x++;
		stack = stack->next;
	}
	return (x);
}
