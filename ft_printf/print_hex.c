/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:20:23 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_base(char specifier)
{
	if (specifier == 'x')
		return ("0123456789abcdef");
	else if (specifier == 'X')
		return ("0123456789ABCDEF");
	return (NULL);
}

int	print_hex(unsigned long n, char specifier)
{
	int		count;
	char	*base;

	count = 0;
	base = get_base(specifier);
	if (n > 15)
		count += print_hex(n / 16, specifier);
	write(1, &base[n % 16], 1);
	count++;
	return (count);
}
