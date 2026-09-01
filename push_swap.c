/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:25:11 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/29 22:15:21 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	put_error(void)
{
	ft_putendl_fd("Error", 2);
}

void	free_stack(t_stack *stack)
{
	t_node	*next;

	while (stack->top)
	{
		next = stack->top->next;
		free(stack->top);
		stack->top = next;
	}
	stack->size = 0;
}

int	stack_disorder_percentage(t_stack *stack)
{
	t_node	*left;
	t_node	*right;
	long	inversions;
	long	pairs;

	inversions = 0;
	left = stack->top;
	while (left)
	{
		right = left->next;
		while (right)
		{
			if (left->index > right->index)
				inversions++;
			right = right->next;
		}
		left = left->next;
	}
	pairs = (long)stack->size * (stack->size - 1) / 2;
	return ((int)(inversions * 100 / pairs));
}
