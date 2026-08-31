/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:23:59 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/29 22:15:18 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static int	contains(t_stack *stack, int value)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		if (node->value == value)
			return (1);
		node = node->next;
	}
	return (0);
}

static int	append_value(t_stack *stack, int value)
{
	t_node	*node;
	t_node	*last;

	node = malloc(sizeof(*node));
	if (!node)
		return (0);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	if (!stack->top)
		stack->top = node;
	else
	{
		last = stack->top;
		while (last->next)
			last = last->next;
		last->next = node;
	}
	stack->size++;
	return (1);
}

static int	read_number(const char **arg, int *value)
{
	long	number;
	long	limit;
	int		sign;

	number = 0;
	sign = 1;
	if (**arg == '+' || **arg == '-')
	{
		if (**arg == '-')
			sign = -1;
		(*arg)++;
	}
	if (!ft_isdigit(**arg))
		return (0);
	limit = (long)INT_MAX + (sign < 0);
	while (ft_isdigit(**arg))
	{
		if (number > (limit - (**arg - '0')) / 10)
			return (0);
		number = number * 10 + (**arg - '0');
		(*arg)++;
	}
	*value = (int)(number * sign);
	return (1);
}

int	parse_argument(t_stack *stack, const char *arg)
{
	int	value;
	int	read_any;

	read_any = 0;
	while (*arg)
	{
		while (*arg == ' ' || (*arg >= '\t' && *arg <= '\r'))
			arg++;
		if (!*arg)
			break ;
		if (!read_number(&arg, &value) || contains(stack, value)
			|| !append_value(stack, value))
			return (0);
		read_any = 1;
		if (*arg && !(*arg == ' ' || (*arg >= '\t' && *arg <= '\r')))
			return (0);
	}
	return (read_any);
}

int	is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}
