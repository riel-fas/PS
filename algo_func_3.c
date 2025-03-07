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

// Push elements back to stack A using the cost-based approach
void push_back_to_a(t_stack **a, t_stack **b)
{
    while (*b)
    {
        current_index(*a);
        current_index(*b);
        set_target_b(*a, *b);
        cost_analysis_b(*a, *b);
        set_cheapest(*b);

        t_stack *cheapest = get_cheapest(*b);
        if (!cheapest)
            break;

        move_to_top(a, cheapest->target_node);
        pa(a, b);
    }
}

// Final adjustments to stack A
void final_adjustments(t_stack **a)
{
    if (!a || !*a)
        return;
    t_stack *smallest = find_min(*a);
    move_to_top(a, smallest);
}
