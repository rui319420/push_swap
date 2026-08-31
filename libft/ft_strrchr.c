/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:14:59 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*last_c;
	unsigned char	target;
	char			*str;
	int				i;

	last_c = NULL;
	target = (unsigned char)c;
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] == target)
			last_c = &str[i];
		i++;
	}
	if (target == '\0')
		return (&str[i]);
	return (last_c);
}

// int	main(void)
// {
// 	char	*s;
// 	int		c;

// 	s = "abcabcabc";
// 	c = 'a';
// 	printf("%s\n", ft_strrchr(s, c));
// 	return (0);
// }
