/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:24:35 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/29 22:15:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	push(t_stack *from, t_stack *to, char name)
{
	t_node	*node;

	if (!from->top)
		return ;
	node = from->top;
	from->top = node->next;
	from->size--;
	node->next = to->top;
	to->top = node;
	to->size++;
	if (name == 'a')
		ft_printf("pa\n");
	else if (name == 'b')
		ft_printf("pb\n");
}

void	swap(t_stack *stack, char name)
{
	t_node	*first;

	if (stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	first->next = stack->top->next;
	stack->top->next = first;
	if (name == 'a')
		ft_printf("sa\n");
	else if (name == 'b')
		ft_printf("sb\n");
}
