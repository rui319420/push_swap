/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:23:23 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/29 22:15:15 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;

	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;
	i = 1;
	while (i < argc && parse_argument(&a, argv[i]))
		i++;
	if (i != argc)
	{
		free_stack(&a);
		put_error();
		return (1);
	}
	if (!is_sorted(&a))
		sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
