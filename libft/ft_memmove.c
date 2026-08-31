/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:04:47 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (d > s)
	{
		while (i < n)
		{
			d[n - 1 - i] = s[n - 1 - i];
			i++;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

// int	main(void)
// {
// 	char	dest[] = "012345678901234567890";
// 	char	ft_dest[] = "012345678901234567890";
// 	void	*ptr;
// 	void	*ft_ptr;

// 	ptr = memmove(&dest[2], &dest[0], 10);
// 	ft_ptr = ft_memmove(&ft_dest[2], &ft_dest[0], 10);
// 	printf("memmove()	%s	%p	%p\n", (char *)ptr, ptr, (void *)dest);
// 	printf("ft_memmove()	%s	%p	%p\n", (char *)ft_ptr, ft_ptr,
// 					(void *)ft_dest);
// 	return (0);
// }
