/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:56:23 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("isprint('r'):		%d\n", isprint('\t'));
// 	printf("ft_isprint('r'):	%d\n", ft_isprint('\t'));
// 	printf("isprint('7'):		%d\n", isprint('7'));
// 	printf("ft_isprint('7'):	%d\n", ft_isprint('7'));
// 	write(1, "\n", 1);
// 	return (0);
// }
