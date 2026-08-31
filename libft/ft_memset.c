/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:05:23 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	char	str[] = "hello world";
// 	int		c;
// 	size_t	n;
// 	char	*res;
// 	char	str2[] = "hello world";
// 	char	*res2;

// 	c = 'a';
// 	n = 3;
// 	printf("memset(\"hello world\", 'a', 3)\n");
// 	printf("%s %p\n", str, str);
// 	res = (char *)memset(str, c, n);
// 	printf("%s %p\n", res, memset(str, c, n));
// 	printf("ft_memset(\"hello world\", 'a', 3)\n");
// 	printf("%s %p\n", str2, str2);
// 	res2 = (char *)ft_memset(str2, c, n);
// 	printf("%s %p\n", res2, ft_memset(str2, c, n));
// 	return (0);
// }
