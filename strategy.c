/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 19:08:33 by rishiyam          #+#    #+#             */
/*   Updated: 2026/09/01 21:22:07 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack *stack);
void	small_sort(t_stack *a, t_stack *b, int *counts);
void	simple_strategy(t_stack *a, t_stack *b, int *counts);
void	medium_strategy(t_stack *a, t_stack *b, int *counts);
void	complex_strategy(t_stack *a, t_stack *b, int *counts);
void	print_benchmark(int disorder, int selected, int used, int *counts);

/* Strategy ids: 0 adaptive, 1 simple, 2 medium, 3 complex. */

/* Disorder is stored as hundredths of a percent, from 0 to 10000. */
static int	compute_disorder(t_stack *stack)
{
	t_node		*first;
	t_node		*second;
	long long	mistakes;
	long long	pairs;

	mistakes = 0;
	pairs = 0;
	first = stack->top;
	while (first)
	{
		second = first->next;
		while (second)
		{
			if (first->value > second->value)
				mistakes++;
			pairs++;
			second = second->next;
		}
		first = first->next;
	}
	if (pairs == 0)
		return (0);
	return ((int)(mistakes * 10000 / pairs));
}

static int	adaptive_strategy(int disorder)
{
	if (disorder < 2000)
		return (1);
	if (disorder < 5000)
		return (2);
	return (3);
}

static void	run_selected(t_stack *a, t_stack *b, int used, int *counts)
{
	if (a->size <= 5)
		small_sort(a, b, counts);
	else if (used == 1)
		simple_strategy(a, b, counts);
	else if (used == 2)
		medium_strategy(a, b, counts);
	else
		complex_strategy(a, b, counts);
}

void	run_sort(t_stack *a, t_stack *b, int selected, int bench)
{
	int	counts[11];
	int	disorder;
	int	used;
	int	index;

	index = 0;
	while (index < 11)
		counts[index++] = 0;
	index_stack(a);
	disorder = compute_disorder(a);
	used = selected;
	if (selected == 0)
		used = adaptive_strategy(disorder);
	if (!is_sorted(a))
		run_selected(a, b, used, counts);
	if (bench)
		print_benchmark(disorder, selected, used, counts);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	run_sort(a, b, 0, 0);
}
