/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:27:35 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/29 22:15:34 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	rotate(t_stack *stack, char name)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
	if (name == 'a')
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}
