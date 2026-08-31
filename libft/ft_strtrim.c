/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:15:35 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str1;
	size_t	start;
	size_t	end;

	str1 = (char *)s1;
	if (!str1 || !set)
		return (NULL);
	start = 0;
	while (str1[start] && ft_strchr(set, str1[start]))
		start++;
	end = ft_strlen(str1);
	while (end > start && ft_strchr(set, str1[end - 1]))
		end--;
	return (ft_substr(str1, start, end - start));
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*set;
// 	char	*ptr;

// 	s1 = "abcabcabc";
// 	set = "ac";
// 	ptr = ft_strtrim(s1, set);
// 	printf("%s", ptr);
// 	return (0);
// }
