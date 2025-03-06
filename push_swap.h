/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:10:05 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/06 15:11:23 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

// Stack node structure definition
typedef struct s_stack
{
    int nbr;                // Value stored in the node
    struct s_stack *prev; // Pointer to the previous node
    struct s_stack *next; // Pointer to the next node
} t_stack;



char	**splitv2(char *s, char c);
long	atoi_v2(char *av);
void	free_stack(t_stack **stack);
void	free_args(char **args);
void	populate_stack_A(t_stack **a, char **av, int start_index);
bool	stack_sort_check(t_stack *stack);
void	sa_sb(t_stack **stack, char id);
void	ss(t_stack **a, t_stack **b);
void	ra_rb(t_stack **stack, char id);
void	rr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rra_rrb(t_stack **stack, char id);
void	push_first_2(t_stack **a, t_stack **b);





#endif
