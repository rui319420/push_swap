/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:42:17 by rishiyam          #+#    #+#             */
/*   Updated: 2026/09/01 20:31:06 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*other;

	node = stack->top;
	while (node)
	{
		node->index = 0;
		other = stack->top;
		while (other)
		{
			if (other->value < node->value)
				node->index++;
			other = other->next;
		}
		node = node->next;
	}
}
