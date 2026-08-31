/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:56:59 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getnbrlen(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n < -9 || 9 < n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*str;
	int		str_len;

	num = n;
	str_len = ft_getnbrlen(n);
	str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (str == NULL)
		return (NULL);
	str[str_len] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[--str_len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

// int	main(void)
// {
// 	printf("%s	%d\n", ft_itoa(-12345), ft_getnbrlen(-12345));
// 	printf("%s	%d\n", ft_itoa(123), ft_getnbrlen(123));
// 	printf("%s	%d\n", ft_itoa(-123), ft_getnbrlen(-123));
// 	printf("%s	%d\n", ft_itoa(0), ft_getnbrlen(0));
// 	printf("%s	%d\n", ft_itoa(INT_MAX), ft_getnbrlen(INT_MAX));
// 	printf("%s	%d\n", ft_itoa(INT_MIN), ft_getnbrlen(INT_MIN));
// 	return (0);
// }
