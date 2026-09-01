/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:21:35 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(void *p)
{
	int				count;
	unsigned long	address;

	if (p == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count = 2;
	address = (unsigned long)p;
	count += print_hex(address, 'x');
	return (count);
}
