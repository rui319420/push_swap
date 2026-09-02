/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:26:59 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/29 22:15:32 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	reverse_rotate(t_stack *stack, char name)
{
	t_node	*before_last;
	t_node	*last;

	if (stack->size < 2)
		return ;
	before_last = stack->top;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
	if (name == 'a')
		ft_printf("rra\n");
	else if (name == 'b')
		ft_printf("rrb\n");
}
