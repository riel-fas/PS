/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:42:35 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/06 16:46:25 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_smallest(t_stack *stack)
{
		if (!stack)
		return NULL;

		t_stack *smallest = stack;
		t_stack *current = stack;

		while (current)
		{
			if (current->nbr < smallest->nbr)
			smallest = current;
			current = current->next;
		}

		return smallest;
}

t_stack *find_best_insert_position(t_stack *a, int nbr)
{
	t_stack *current = a;
    t_stack *best_pos = NULL;
    t_stack *smallest = find_smallest(a);

    if (!current)
	return NULL;

    // If the number to insert is smaller than the smallest in A,
    // return the smallest as the position (we'll rotate to it)
    if (nbr < smallest->nbr)
	return smallest;

    // Otherwise, find the position where nbr should be inserted
    while (current)
    {
		if (current->nbr > nbr &&
            (current->prev == NULL || current->prev->nbr < nbr))
			{
				best_pos = current;
				break;
			}
			current = current->next;
		}

		// If no position found (nbr is larger than all elements),
		// return the smallest element so we can rotate to put the largest at the end
		if (!best_pos)
        return smallest;

		return best_pos;
}



// void	move_to_top(t_stack **stack, t_stack *target)
// {
//     if (!stack || !*stack || !target)
//         return;

//     // Calculate the number of rotations needed to bring the target to the top
//     int moves_up = 0;
//     t_stack *current = *stack;
//     while (current && current != target)
//     {
//         moves_up++;
//         current = current->next;
//     }

//     int stack_size = stack_length(*stack);
//     int moves_down = stack_size - moves_up;

//     // Move in the most efficient direction
//     if (moves_up <= moves_down)
//     {
//         for (int i = 0; i < moves_up; i++)
//             ra_rb(stack, '\0'); // Rotate forward
//     }
//     else
//     {
//         for (int i = 0; i < moves_down; i++)
//             rra_rrb(stack, '\0'); // Rotate backward
//     }
// }


void push_back_to_a(t_stack **a, t_stack **b)
	{
		while (*b) // Continue until stack B is empty
		{
			t_stack *target = find_best_insert_position(*a, (*b)->nbr);

			if (target) // If a position was found
				move_to_top(a, target); // Move the target node to the top of stack A

			pa(a, b); // Push the top node of stack B to stack A
		}
	}


void final_adjustments(t_stack **a)
{
    if (!a || !*a)
        return; // Nothing to do if stack A is empty

    t_stack *smallest = find_smallest(*a); // Find the smallest node in stack A

    // Move the smallest node to the top of stack A
    move_to_top(a, smallest);
}
