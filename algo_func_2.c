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

// Sort a stack of three elements
void sort_three(t_stack **a)
{
    if (!a || !*a || !(*a)->next || !(*a)->next->next)
        return;
    t_stack *first = *a;
    t_stack *second = first->next;
    t_stack *third = second->next;

    if (first->nbr < second->nbr && second->nbr < third->nbr)
        return;
    if (first->nbr < second->nbr && second->nbr > third->nbr && first->nbr < third->nbr)
    {
        rra_rrb(a, 'a');
        sa_sb(a, 'a');
    }
    else if (first->nbr > second->nbr && second->nbr < third->nbr && first->nbr < third->nbr)
    {
        sa_sb(a, 'a');
    }
    else if (first->nbr > second->nbr && second->nbr < third->nbr && first->nbr > third->nbr)
    {
        rra_rrb(a, 'a');
    }
    else if (first->nbr > second->nbr && second->nbr > third->nbr)
    {
        sa_sb(a, 'a');
        rra_rrb(a, 'a');
    }
}
