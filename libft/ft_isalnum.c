/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:53:59 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') || ('a' <= c
			&& c <= 'z'))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("isalnum('r'):		%d\n", isalnum('r'));
// 	printf("ft_isalnum('r'):	%d\n", ft_isalnum('r'));
// 	printf("isalnum('7'):		%d\n", isalnum('7'));
// 	printf("ft_isalnum('7'):	%d\n", ft_isalnum('7'));
// 	write(1, "\n", 1);
// 	return (0);
// }
