/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 19:37:12 by rishiyam          #+#    #+#             */
/*   Updated: 2026/09/01 21:35:09 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_operation(t_stack *a, t_stack *b, char *name, int *counts);

static int	minimum_position(t_stack *stack)
{
	t_node	*node;
	int		position;
	int		min_position;
	int		min_index;

	node = stack->top;
	position = 0;
	min_position = 0;
	min_index = node->index;
	while (node)
	{
		if (node->index < min_index)
		{
			min_index = node->index;
			min_position = position;
		}
		position++;
		node = node->next;
	}
	return (min_position);
}

static void	sort_three(t_stack *a, t_stack *b, int *counts)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	if (first > second && first > third)
		run_operation(a, b, "ra", counts);
	else if (second > first && second > third)
		run_operation(a, b, "rra", counts);
	if (a->top->index > a->top->next->index)
		run_operation(a, b, "sa", counts);
}

static void	sort_five(t_stack *a, t_stack *b, int *counts)
{
	int	position;

	while (a->size > 3)
	{
		position = minimum_position(a);
		if (position <= a->size / 2)
			while (position-- > 0)
				run_operation(a, b, "ra", counts);
		else
			while (position++ < a->size)
				run_operation(a, b, "rra", counts);
		run_operation(a, b, "pb", counts);
	}
	sort_three(a, b, counts);
	while (b->size)
		run_operation(a, b, "pa", counts);
}

void	small_sort(t_stack *a, t_stack *b, int *counts)
{
	if (a->size == 2)
		run_operation(a, b, "sa", counts);
	else if (a->size == 3)
		sort_three(a, b, counts);
	else
		sort_five(a, b, counts);
}
