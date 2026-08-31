/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:55:11 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("isascii('r'):		%d\n", isascii('\t'));
// 	printf("ft_isascii('r'):	%d\n", ft_isascii('\t'));
// 	printf("isascii('7'):		%d\n", isascii('7'));
// 	printf("ft_isascii('7'):	%d\n", ft_isascii('7'));
// 	write(1, "\n", 1);
// 	return (0);
// }
