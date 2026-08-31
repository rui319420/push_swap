/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:16:47 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	res;

	res = c;
	if ('A' <= c && c <= 'Z')
		res += 32;
	return (res);
}

// int	main(void)
// {
// 	int	c;
// 	int	n;

// 	c = 'A';
// 	n = '5';
// 	printf("%c	%d\n", ft_tolower(c), ft_tolower(c));
// 	printf("%c	%d\n", ft_tolower(n), ft_tolower(n));
// 	return (0);
// }
