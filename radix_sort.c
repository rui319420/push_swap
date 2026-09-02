/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 20:07:45 by rishiyam          #+#    #+#             */
/*   Updated: 2026/09/01 21:44:16 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_operation(t_stack *a, t_stack *b, char *name, int *counts);

static int	required_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

void	complex_strategy(t_stack *a, t_stack *b, int *counts)
{
	int	bit;
	int	remaining;
	int	size;

	bit = 0;
	size = a->size;
	while (bit < required_bits(size))
	{
		remaining = size;
		while (remaining-- > 0)
		{
			if ((a->top->index >> bit) & 1)
				run_operation(a, b, "ra", counts);
			else
				run_operation(a, b, "pb", counts);
		}
		while (b->size)
			run_operation(a, b, "pa", counts);
		bit++;
	}
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	counts[11];
	int	index;

	index = 0;
	while (index < 11)
		counts[index++] = 0;
	complex_strategy(a, b, counts);
}
