/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:11:59 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = 0;
	while (src[s_len] != '\0')
		s_len++;
	if (dsize == 0)
		return (s_len);
	while (src[i] != '\0' && i < dsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s_len);
}

// int	main(void)
// {
// 	char	dst[] = "123456789";
// 	char	*src;
// 	size_t	n;

// 	src = "AAAAAAAAAAAAAAAAA";
// 	n = ft_strlcpy(dst, src, 7);
// 	printf("%ld	%s	%s\n", n, dst, src);
// 	return (0);
// }
