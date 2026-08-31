/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:17:23 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	res;

	res = c;
	if ('a' <= c && c <= 'z')
		res -= 32;
	return (res);
}

// int	main(void)
// {
// 	int	c;
// 	int	n;

// 	c = 'a';
// 	n = '5';
// 	printf("%c	%d\n", ft_toupper(c), ft_toupper(c));
// 	printf("%c	%d\n", ft_toupper(n), ft_toupper(n));
// 	return (0);
// }
