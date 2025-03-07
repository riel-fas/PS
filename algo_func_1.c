/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:45:50 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/06 16:29:39 by riel-fas         ###   ########.fr       */
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
