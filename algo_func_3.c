/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:42:35 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/07 16:02:20 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void move_both_efficiently(t_stack **a, t_stack **b, t_stack *target_a, t_stack *target_b)
{
    // Calculate rotations needed for each stack
    int rot_a = 0, rot_b = 0;
    t_stack *temp;

    // Count rotations for stack A
    temp = *a;
    while (temp && temp != target_a)
    {
        rot_a++;
        temp = temp->next;
    }
    if (rot_a > stack_length(*a) / 2)
        rot_a = -(stack_length(*a) - rot_a); // Use negative for reverse rotations

    // Count rotations for stack B
    temp = *b;
    while (temp && temp != target_b)
    {
        rot_b++;
        temp = temp->next;
    }
    if (rot_b > stack_length(*b) / 2)
        rot_b = -(stack_length(*b) - rot_b); // Use negative for reverse rotations

    // Apply rotations efficiently using combined operations when possible
    while (rot_a > 0 && rot_b > 0)
    {
        rr(a, b);
        rot_a--;
        rot_b--;
    }

    while (rot_a < 0 && rot_b < 0)
    {
        rrr(a, b);
        rot_a++;
        rot_b++;
    }

    // Finish remaining rotations
    while (rot_a > 0)
    {
        ra_rb(a, 'a');
        rot_a--;
    }
    while (rot_a < 0)
    {
        rra_rrb(a, 'a');
        rot_a++;
    }

    while (rot_b > 0)
    {
        ra_rb(b, 'b');
        rot_b--;
    }
    while (rot_b < 0)
    {
        rra_rrb(b, 'b');
        rot_b++;
    }
}

// Push elements back to stack A using the cost-based approach
void push_back_to_a(t_stack **a, t_stack **b)
{
    while (*b)
    {
        // Initialize metadata for stack A and stack B
        current_index(*a);
        current_index(*b);
        set_target_b(*a, *b);
        cost_analysis_b(*a, *b);
        set_cheapest(*b);

        // Find the cheapest node in stack B
        t_stack *cheapest = get_cheapest(*b);
        if (!cheapest)
            break;

        // Use optimized movement to position both stacks correctly
        move_both_efficiently(a, b, cheapest->target_node, cheapest);

        // Push the cheapest node from stack B to stack A
        pa(a, b);
    }
}

// Final adjustments to stack A
void final_adjustments(t_stack **a)
{
    if (!a || !*a)
        return;

    t_stack *smallest = find_min(*a); // Find the smallest node in stack A

    // Move the smallest node to the top of stack A
    move_to_top(a, smallest, 'a');
}
