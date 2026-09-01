/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:22:47 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unbr(unsigned int nbr)
{
	int		count;
	char	c;

	count = 0;
	if (nbr > 9)
		count += print_unbr(nbr / 10);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}
