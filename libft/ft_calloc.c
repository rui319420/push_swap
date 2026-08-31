/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:53:23 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*p;
	size_t			total;
	size_t			i;

	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	p = (unsigned char *)ptr;
	i = 0;
	while (i < (nmemb * size))
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}

// int	main(void)
// {
// 	char	*buffer;
// 	int		i;

// 	buffer = (char *)calloc(40, sizeof(char));
// 	if (buffer == NULL)
// 		return (1);
// 	i = 0;
// 	while (i < 40)
// 	{
// 		printf("index[%d]: %d\n", i, buffer[i]);
// 		i++;
// 	}
// 	return (0);
// }
