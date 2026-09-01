/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:26:23 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/31 17:23:40 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MEDIUM_MAX_SIZE 100
#define MEDIUM_DISORDER_LIMIT 40
#define MEDIUM_RANGE_FACTOR 14
#define COMPLEX_RANGE_FACTOR 18

int	stack_disorder_percentage(t_stack *stack);

static int	chunk_range(int size, int factor)
{
	int	root;

	root = 1;
	while ((root + 1) * (root + 1) <= size)
		root++;
	return (root * factor / 10);
}

static int	max_position(t_stack *stack)
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
			max_position = position;
			max_index = node->index;
		}
		position++;
		node = node->next;
	}
	return (max_position);
}

static void	push_chunks(t_stack *a, t_stack *b, int range)
{
	int	pushed;

	pushed = 0;
	while (a->size)
	{
		if (a->top->index <= pushed)
		{
			push(a, b, 'b');
			rotate(b, 'b');
			pushed++;
		}
		else if (a->top->index <= pushed + range)
		{
			push(a, b, 'b');
			pushed++;
		}
		else
			rotate(a, 'a');
	}
}

static void	restore_stack(t_stack *a, t_stack *b)
{
	int	position;

	while (b->size)
	{
		position = max_position(b);
		if (position <= b->size / 2)
			while (position-- > 0)
				rotate(b, 'b');
		else
			while (position++ < b->size)
				reverse_rotate(b, 'b');
		push(b, a, 'a');
	}
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	disorder;
	int	factor;

	disorder = stack_disorder_percentage(a);
	if (a->size <= MEDIUM_MAX_SIZE || disorder <= MEDIUM_DISORDER_LIMIT)
		factor = MEDIUM_RANGE_FACTOR;
	else
		factor = COMPLEX_RANGE_FACTOR;
	push_chunks(a, b, chunk_range(a->size, factor));
	restore_stack(a, b);
}
