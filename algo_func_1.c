/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:45:50 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/07 16:03:48 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Push the first two elements to stack B
void push_first_2(t_stack **a, t_stack **b)
{
    if (!a || !*a || !(*a)->next)
        return;
    pb(a, b);
    pb(a, b);
    if ((*b)->nbr > (*b)->next->nbr)
        sa_sb(b, 'b');
}

// Push elements from stack A to stack B
void push_nodes_to_b(t_stack **a, t_stack **b)
{
    int stack_size = stack_length(*a);

    // For larger stacks, use a chunking approach
    if (stack_size > 10)
    {
        int chunk_count;
        if (stack_size <= 100)
            chunk_count = 5;
        else
            chunk_count = 11; // More chunks for 500+ numbers

        int *sorted = stack_to_array(*a);
        if (!sorted)
            return;

        sort_array(sorted, stack_size);

        // Push in chunks, from smallest to largest
        for (int c = 0; c < chunk_count; c++)
        {
            int chunk_max = sorted[(stack_size / chunk_count) * (c + 1)];
            if (c == chunk_count - 1)
                chunk_max = sorted[stack_size - 1]; // Last chunk takes remaining numbers

            // Count how many numbers are in this chunk
            int to_push_count = 0;
            t_stack *temp = *a;
            while (temp)
            {
                if (temp->nbr <= chunk_max)
                    to_push_count++;
                temp = temp->next;
            }

            int pushed = 0;
            // Use a more efficient rotation strategy for finding chunk elements
            int total_rot = 0;
            while (pushed < to_push_count && stack_length(*a) > 3)
            {
                if ((*a)->nbr <= chunk_max)
                {
                    pb(a, b);
                    pushed++;
                    // Optimize B by keeping smaller numbers at the bottom
                    if (*b && (*b)->next && (*b)->nbr < (*b)->next->nbr && pushed > 1)
                        ra_rb(b, 'b');
                }
                else
                {
                    ra_rb(a, 'a');
                    total_rot++;
                    // If we've rotated more than half the stack, consider using reverse rotations
                    if (total_rot > stack_length(*a) / 2)
                    {
                        // Find next element in chunk
                        t_stack *temp = *a;
                        int dist = 0;
                        while (temp && temp->nbr > chunk_max)
                        {
                            dist++;
                            temp = temp->next;
                        }

                        // If it's closer to use reverse rotation, use that instead
                        if (temp && dist > stack_length(*a) / 2)
                        {
                            for (int i = 0; i < stack_length(*a) - dist; i++)
                                rra_rrb(a, 'a');
                        }
                    }
                }
            }
        }
        free(sorted);
    }
    else
    {
        // Original implementation for small stacks
        int median = find_median(*a);
        while (stack_length(*a) > 3)
        {
            if ((*a)->nbr <= median)
            {
                pb(a, b);
                if ((*b)->next && (*b)->nbr < (*b)->next->nbr)
                    sa_sb(b, 'b');
            }
            else
                ra_rb(a, 'a');
        }
    }
}
