/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:13:11 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	char			*str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	str = (char *)s;
	ptr = (char *)malloc(ft_strlen(str) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = f(i, str[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// char	ft_oddtoupper(unsigned int idx, char c)
// {
// 	char	res;

// 	res = c;
// 	if ((idx % 2) != 0)
// 	{
// 		if ('a' <= res && res <= 'z')
// 			res -= 32;
// 	}
// 	return (res);
// }

// int	main(void)
// {
// 	char *s = "hello world!";
// 	char *ptr = ft_strmapi(s, ft_oddtoupper);

// 	printf("%s\n", ptr);
// 	return (0);
// }
