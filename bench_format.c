/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 20:34:51 by rishiyam          #+#    #+#             */
/*   Updated: 2026/09/01 21:55:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

/* Strategy ids: 0 adaptive, 1 simple, 2 medium, 3 complex. */

char	*strategy_name(int strategy)
{
	if (strategy == 0)
		return ("Adaptive");
	if (strategy == 1)
		return ("Simple");
	if (strategy == 2)
		return ("Medium");
	return ("Complex");
}

char	*complexity_name(int strategy)
{
	if (strategy == 1)
		return ("O(n^2)");
	if (strategy == 2)
		return ("O(n sqrt(n))");
	return ("O(n log(n))");
}

static void	print_count(char *name, int count)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(count, 2);
	ft_putchar_fd('\n', 2);
}

/* Count order matches operation_dispatch.c. */
void	print_operation_counts(int *counts)
{
	print_count("sa", counts[0]);
	print_count("sb", counts[1]);
	print_count("ss", counts[2]);
	print_count("pa", counts[3]);
	print_count("pb", counts[4]);
	print_count("ra", counts[5]);
	print_count("rb", counts[6]);
	print_count("rr", counts[7]);
	print_count("rra", counts[8]);
	print_count("rrb", counts[9]);
	print_count("rrr", counts[10]);
}
