/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:29:49 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/06 16:38:55 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void sort_three(t_stack **a)
// {
//     if (!a || !*a || !(*a)->next || !(*a)->next->next)
//         return; // Ensure stack A has exactly 3 nodes

//     t_stack *first = *a;
//     t_stack *second = first->next;
//     t_stack *third = second->next;

//     // Case 1: [1, 2, 3] (already sorted)
//     if (first->nbr < second->nbr && second->nbr < third->nbr)
//         return;
//     // Case 2: [1, 3, 2] → Swap the last two elements
//     if (first->nbr < second->nbr && second->nbr > third->nbr && first->nbr < third->nbr)
//     {
//         rra_rrb(a, 'a'); // Reverse rotate to bring the last element to the top
//         sa_sb(a, 'a');   // Swap the first two elements
//         return;
//     }
//     // Case 3: [2, 1, 3] → Swap the first two elements
//     if (first->nbr > second->nbr && second->nbr < third->nbr && first->nbr < third->nbr)
//     {
//         sa_sb(a, 'a');
//         return;
//     }
//     // Case 4: [2, 3, 1] → Rotate to bring the smallest element to the top
//     if (first->nbr > second->nbr && second->nbr < third->nbr && first->nbr > third->nbr)
//     {
//         rra_rrb(a, 'a');
//         return;
//     }
//     // Case 5: [3, 1, 2] → Rotate to bring the smallest element to the top
//     if (first->nbr > second->nbr && second->nbr < third->nbr && first->nbr > third->nbr)
//     {
//         ra_rb(a, 'a');
//         return;
//     }
//     // Case 6: [3, 2, 1] → Swap the first two elements and then rotate
//     if (first->nbr > second->nbr && second->nbr > third->nbr)
//     {
//         sa_sb(a, 'a');
//         rra_rrb(a, 'a');
//         return;
//     }
// }




void sort_three(t_stack **a)
{
    if (!a || !*a || !(*a)->next || !(*a)->next->next)
        return; // Ensure stack A has exactly 3 nodes

    t_stack *first = *a;
    t_stack *second = first->next;
    t_stack *third = second->next;

    // Case 1: [1, 2, 3] (already sorted)
    if (first->nbr < second->nbr && second->nbr < third->nbr)
        return;

    // Case 2: [1, 3, 2] → Swap the last two elements
    if (first->nbr < second->nbr && second->nbr > third->nbr && first->nbr < third->nbr)
    {
        rra_rrb(a, 'a'); // Reverse rotate to bring the last element to the top
        sa_sb(a, 'a');   // Swap the first two elements
        return;
    }

    // Case 3: [2, 1, 3] → Swap the first two elements
    if (first->nbr > second->nbr && second->nbr < third->nbr && first->nbr < third->nbr)
    {
        sa_sb(a, 'a');
        return;
    }

    // Case 4: [2, 3, 1] → Rotate to bring the smallest element to the top
    if (first->nbr > second->nbr && second->nbr < third->nbr && first->nbr > third->nbr)
    {
        rra_rrb(a, 'a');
        return;
    }

    // Case 5: [3, 1, 2] → Rotate to bring the smallest element to the top
    if (first->nbr > second->nbr && second->nbr < third->nbr && first->nbr > third->nbr)
    {
        ra_rb(a, 'a');
        return;
    }

    // Case 6: [3, 2, 1] → Swap the first two elements and then rotate
    if (first->nbr > second->nbr && second->nbr > third->nbr)
    {
        sa_sb(a, 'a');
        rra_rrb(a, 'a');
        return;
    }
}

t_stack *find_largest(t_stack *stack)
{
	if (!stack)
	return NULL;

    t_stack *largest = stack;
    t_stack *current = stack;

    while (current)
    {
		if (current->nbr > largest->nbr)
            largest = current;
			current = current->next;
    }

    return largest;
}

void move_to_top(t_stack **stack, t_stack *target)
{
	if (!stack || !*stack || !target)
	return;

    // Calculate the number of rotations needed to bring the target to the top
    int moves_up = 0;
    t_stack *current = *stack;
    while (current && current != target)
    {
		moves_up++;
        current = current->next;
    }

    int stack_size = stack_length(*stack);
    int moves_down = stack_size - moves_up;

    // Move in the most efficient direction
    if (moves_up <= moves_down)
    {
		for (int i = 0; i < moves_up; i++)
		ra_rb(stack, '\0'); // Rotate forward
    }
    else
    {
		for (int i = 0; i < moves_down; i++)
		rra_rrb(stack, '\0'); // Rotate backward
    }
}

void sort_stack_b(t_stack **b)
{
	if (!b || !*b || !(*b)->next)
		return; // Nothing to do if stack B is empty or has only one node

	t_stack *largest = find_largest(*b); // Find the largest node in stack B

	// Move the largest node to the top of stack B
	move_to_top(b, largest);
}

