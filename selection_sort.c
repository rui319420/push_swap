/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:28:11 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/29 22:15:42 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define SIMPLE_MAX_SIZE 5

static void	set_indexes(t_stack *a)
{
	t_node	*node;
	t_node	*other;

	node = a->top;
	while (node)
	{
		node->index = 0;
		other = a->top;
		while (other)
		{
			if (other->value < node->value)
				node->index++;
			other = other->next;
		}
		node = node->next;
	}
}

static void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	if (first > second && first > third)
		rotate(a, 'a');
	else if (second > first && second > third)
		reverse_rotate(a, 'a');
	if (a->top->index > a->top->next->index)
		swap(a, 'a');
}

static int	min_position(t_stack *a)
{
	t_node	*node;
	int		position;
	int		min;
	int		min_pos;

	node = a->top;
	position = 0;
	min = node->index;
	min_pos = 0;
	while (node)
	{
		if (node->index < min)
		{
			min = node->index;
			min_pos = position;
		}
		position++;
		node = node->next;
	}
	return (min_pos);
}

static void	sort_simple(t_stack *a, t_stack *b)
{
	int	position;

	while (a->size > 3)
	{
		position = min_position(a);
		if (position <= a->size / 2)
			while (position--)
				rotate(a, 'a');
		else
			while (position++ < a->size)
				reverse_rotate(a, 'a');
		push(a, b, 'b');
	}
	sort_three(a);
	while (b->size)
		push(b, a, 'a');
}

void	sort_stack(t_stack *a, t_stack *b)
{
	set_indexes(a);
	if (a->size == 2)
		swap(a, 'a');
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= SIMPLE_MAX_SIZE)
		sort_simple(a, b);
	else
		radix_sort(a, b);
}
