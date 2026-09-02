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
#include "libft/libft.h"

void	run_sort(t_stack *a, t_stack *b, int strategy, int bench);

static void	initialize_stacks(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
}

static int	same_option(char *argument, char *option)
{
	return (ft_strncmp(argument, option, ft_strlen(option) + 1) == 0);
}

static int	selector_value(char *argument)
{
	if (same_option(argument, "--adaptive"))
		return (0);
	if (same_option(argument, "--simple"))
		return (1);
	if (same_option(argument, "--medium"))
		return (2);
	if (same_option(argument, "--complex"))
		return (3);
	return (-1);
}

static int	parse_input(int argc, char **argv, t_stack *a, int *options)
{
	int	i;
	int	selector;

	i = 1;
	while (i < argc)
	{
		selector = selector_value(argv[i]);
		if (selector >= 0)
		{
			if (options[0] >= 0)
				return (0);
			options[0] = selector;
		}
		else if (same_option(argv[i], "--bench"))
		{
			if (options[1])
				return (0);
			options[1] = 1;
		}
		else if (!parse_argument(a, argv[i]))
			return (0);
		i++;
	}
	return (a->size > 0);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		options[2];

	if (argc == 1)
		return (0);
	initialize_stacks(&a, &b);
	options[0] = -1;
	options[1] = 0;
	if (!parse_input(argc, argv, &a, options))
	{
		free_stack(&a);
		put_error();
		return (1);
	}
	if (options[0] < 0)
		options[0] = 0;
	run_sort(&a, &b, options[0], options[1]);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
