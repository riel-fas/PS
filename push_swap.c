/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:10:00 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/06 16:46:16 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **A, t_stack **B)
{
	push_first_2(A, B);
	push_nodes_to_b(A, B);
	sort_three(A);
	sort_stack_b(B);
	push_back_to_a(A, B);



}

int main(int ac, char **av)
{
	t_stack	*A;
	t_stack	*B;
	char	**splited = NULL;
	int		start_index;

	A = NULL;
	B = NULL;
	start_index = 0;
	if (ac < 2)
		return (0);
	// if (ac == 2 && !av[1][0])
		// write (2, "Error\n", 6);
	if (ac == 2)
	{
		splited = splitv2(av[1], ' ');
		//we split the command line
		if (!splited || !splited[0])
		{
			free(splited);
			return (0);
			start_index = 0;
		}
		else
		{
			splited = av;
			start_index = 1;
		}
	}
	populate_stack_A(&A, splited, start_index);
	if (stack_sort_check(A))
	{
		free_stack(&A);
		if (ac == 2)
			free_args(splited);
		return (0);
	}
	// push_swap(&A, &B);

}


