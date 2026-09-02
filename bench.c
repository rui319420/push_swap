/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 20:23:08 by rishiyam          #+#    #+#             */
/*   Updated: 2026/09/01 21:51:37 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	*strategy_name(int strategy);
char	*complexity_name(int strategy);
void	print_operation_counts(int *counts);

static int	total_operations(int *counts)
{
	int	total;
	int	index;

	total = 0;
	index = 0;
	while (index < 11)
		total += counts[index++];
	return (total);
}

static void	print_disorder(int disorder)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(disorder / 100, 2);
	ft_putchar_fd('.', 2);
	if (disorder % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(disorder % 100, 2);
	ft_putstr_fd("%\n", 2);
}

void	print_benchmark(int disorder, int selected, int used, int *counts)
{
	print_disorder(disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strategy_name(selected), 2);
	ft_putstr_fd(" / ", 2);
	ft_putendl_fd(complexity_name(used), 2);
	ft_putstr_fd("[bench] total operations: ", 2);
	ft_putnbr_fd(total_operations(counts), 2);
	ft_putchar_fd('\n', 2);
	print_operation_counts(counts);
}
