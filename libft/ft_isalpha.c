/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:54:35 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("isalpha('r'):		%d\n", isalpha('r'));
// 	printf("ft_isalpha('r'):	%d\n", ft_isalpha('r'));
// 	printf("isalpha('7'):		%d\n", isalpha('7'));
// 	printf("ft_isalpha('7'):	%d\n", ft_isalpha('7'));
// 	write(1, "\n", 1);
// }
