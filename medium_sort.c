/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 19:54:28 by rishiyam          #+#    #+#             */
/*   Updated: 2026/09/01 21:40:52 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_operation(t_stack *a, t_stack *b, char *name, int *counts);

static int	chunk_range(int size)
{
	int	root;

	root = 1;
	while ((root + 1) * (root + 1) <= size)
		root++;
	return (root * 14 / 10);
}

static int	maximum_position(t_stack *stack)
{
	t_node	*node;
	int		position;
	int		max_position;
	int		max_index;

	node = stack->top;
	position = 0;
	max_position = 0;
	max_index = node->index;
	while (node)
	{
		if (node->index > max_index)
		{
			max_index = node->index;
			max_position = position;
		}
		position++;
		node = node->next;
	}
	return (max_position);
}

static void	push_chunks(t_stack *a, t_stack *b, int range, int *counts)
{
	int	pushed;

	pushed = 0;
	while (a->size)
	{
		if (a->top->index <= pushed)
		{
			run_operation(a, b, "pb", counts);
			run_operation(a, b, "rb", counts);
			pushed++;
		}
		else if (a->top->index <= pushed + range)
		{
			run_operation(a, b, "pb", counts);
			pushed++;
		}
		else
			run_operation(a, b, "ra", counts);
	}
}

static void	restore_stack(t_stack *a, t_stack *b, int *counts)
{
	int	position;

	while (b->size)
	{
		position = maximum_position(b);
		if (position <= b->size / 2)
			while (position-- > 0)
				run_operation(a, b, "rb", counts);
		else
			while (position++ < b->size)
				run_operation(a, b, "rrb", counts);
		run_operation(a, b, "pa", counts);
	}
}

void	medium_strategy(t_stack *a, t_stack *b, int *counts)
{
	push_chunks(a, b, chunk_range(a->size), counts);
	restore_stack(a, b, counts);
}
