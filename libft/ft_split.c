/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:08:23 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if ((i == 0 || str[i - 1] == c) && str[i] != c)
			count++;
		i++;
	}
	return (count);
}

static void	ft_freearray(char **array, int i)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

static char	**ft_makearray(char *str, char c, char **array, int words)
{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (str[j] && str[j] == c)
			j++;
		word_len = 0;
		while (str[j + word_len] && str[j + word_len] != c)
			word_len++;
		array[i] = ft_substr(str, j, word_len);
		if (!array[i])
		{
			ft_freearray(array, i - 1);
			return (NULL);
		}
		j += word_len;
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*str;
	int		word_count;

	str = (char *)s;
	word_count = ft_countwords(str, c);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (array == NULL)
		return (NULL);
	array = ft_makearray(str, c, array, word_count);
	return (array);
}

// int	main(void)
// {
// 	char	*s;
// 	char	c;
// 	char	**array;
// 	int		i;
// 	int		j;

// 	s = "I like 42Tokyo. how about you?";
// 	c = ' ';
// 	array = ft_split(s, c);
// 	i = 0;
// 	while (array[i] != NULL)
// 	{
// 		printf("array[%d]: %s\n", i, array[i]);
// 		i++;
// 	}
// 	j = 0;
// 	while (array[j] != NULL)
// 	{
// 		free(array[j]);
// 		j++;
// 	}
// 	free(array);
// 	return (0);
// }
