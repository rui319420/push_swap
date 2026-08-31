/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:11:23 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	dst_length;
	size_t	src_length;

	i = 0;
	dst_length = 0;
	src_length = 0;
	while (dst[dst_length] != '\0' && dst_length < dsize)
		dst_length++;
	while (src[src_length] != '\0')
		src_length++;
	if (dsize <= dst_length)
		return (dsize + src_length);
	while (src[i] != '\0' && i < dsize - dst_length - 1)
	{
		dst[dst_length + i] = src[i];
		i++;
	}
	dst[dst_length + i] = '\0';
	return (dst_length + src_length);
}

// int	main(void)
// {
// 	char		dst[30] = "123456789";
// 	const char	*src;
// 	size_t		n;

// 	src = "AAAA";
// 	n = strlcat(dst, src, 6);
// 	printf("%ld	%s	%s\n", n, dst, src);
// 	return (0);
// }
