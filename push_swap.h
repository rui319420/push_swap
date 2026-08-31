/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:25:47 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

void	free_stack(t_stack *stack);
void	put_error(void);
int		parse_argument(t_stack *stack, const char *arg);
int		is_sorted(t_stack *stack);
void	push(t_stack *from, t_stack *to, char name);
void	swap(t_stack *stack, char name);
void	rotate(t_stack *stack, char name);
void	reverse_rotate(t_stack *stack, char name);
void	sort_stack(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

#endif
