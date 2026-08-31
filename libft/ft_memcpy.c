/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:04:11 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*b_dest;
	unsigned char	*b_src;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	b_dest = (unsigned char *)dest;
	b_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		b_dest[i] = b_src[i];
		i++;
	}
	return (b_dest);
}

// int	main(void)
// {
// 	char *dest;
// 	char *src = "hello world";
// 	printf("%p", ft_memcpy(dest, src, sizeof(src)));
// 	char dest[] = "I have a pen.";
// 	char *src = "hello world";
// 	char *res;
// 	res = (char *)memcpy(dest, src, 16);
// 	printf("%s", res);
// 	return (0);
// }
