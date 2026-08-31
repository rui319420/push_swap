/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:09:35 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*ptr;
	size_t	i;
	size_t	len;

	str = (char *)s;
	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*ptr;

// 	str = "hello";
// 	printf("%s	%p\n", str, str);
// 	ptr = ft_strdup(str);
// 	printf("%s	%p\n", ptr, ptr);
// 	return (0);
// }
