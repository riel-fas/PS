/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:45:50 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/06 15:12:12 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_first_2(t_stack **A, t_stack **B)
{
	if (!A || !*A || !(*A)->next) // Ensure stack A has at least 2 nodes
		return;
	pb(A, B); // Push the first node
	pb(A, B); // Push the second node
	if ((*B)->nbr > (*B)->next->nbr)
		sa_sb(B, 'B');
}
