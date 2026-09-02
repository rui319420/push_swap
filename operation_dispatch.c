/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_dispatch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:55:42 by rishiyam          #+#    #+#             */
/*   Updated: 2026/09/01 20:45:18 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

/* Count order: sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr. */

static void	run_swap(t_stack *a, t_stack *b, char *name, int *counts)
{
	if (!ft_strncmp(name, "sa", 3) && a->size > 1)
	{
		swap(a, 'a');
		counts[0]++;
	}
	else if (!ft_strncmp(name, "sb", 3) && b->size > 1)
	{
		swap(b, 'b');
		counts[1]++;
	}
	else if (!ft_strncmp(name, "ss", 3)
		&& (a->size > 1 || b->size > 1))
	{
		swap(a, 0);
		swap(b, 0);
		ft_printf("ss\n");
		counts[2]++;
	}
}

static void	run_forward(t_stack *a, t_stack *b, char *name, int *counts)
{
	if (!ft_strncmp(name, "ra", 3) && a->size > 1)
	{
		rotate(a, 'a');
		counts[5]++;
	}
	else if (!ft_strncmp(name, "rb", 3) && b->size > 1)
	{
		rotate(b, 'b');
		counts[6]++;
	}
	else if (!ft_strncmp(name, "rr", 3)
		&& (a->size > 1 || b->size > 1))
	{
		rotate(a, 0);
		rotate(b, 0);
		ft_printf("rr\n");
		counts[7]++;
	}
}

static void	run_reverse(t_stack *a, t_stack *b, char *name, int *counts)
{
	if (!ft_strncmp(name, "rra", 4) && a->size > 1)
	{
		reverse_rotate(a, 'a');
		counts[8]++;
	}
	else if (!ft_strncmp(name, "rrb", 4) && b->size > 1)
	{
		reverse_rotate(b, 'b');
		counts[9]++;
	}
	else if (!ft_strncmp(name, "rrr", 4)
		&& (a->size > 1 || b->size > 1))
	{
		reverse_rotate(a, 0);
		reverse_rotate(b, 0);
		ft_printf("rrr\n");
		counts[10]++;
	}
}

static void	run_push(t_stack *a, t_stack *b, char *name, int *counts)
{
	if (!ft_strncmp(name, "pa", 3) && b->size)
	{
		push(b, a, 'a');
		counts[3]++;
	}
	else if (!ft_strncmp(name, "pb", 3) && a->size)
	{
		push(a, b, 'b');
		counts[4]++;
	}
}

void	run_operation(t_stack *a, t_stack *b, char *name, int *counts)
{
	if (name[0] == 's')
		run_swap(a, b, name, counts);
	else if (name[0] == 'p')
		run_push(a, b, name, counts);
	else if (name[0] == 'r' && name[2] == '\0')
		run_forward(a, b, name, counts);
	else
		run_reverse(a, b, name, counts);
}
