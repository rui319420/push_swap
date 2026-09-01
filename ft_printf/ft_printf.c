/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:18:35 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_fmt(const char specifier, va_list *ap)
{
	if (specifier == 'c')
		return (print_char(va_arg(*ap, int)));
	else if (specifier == 's')
		return (print_str(va_arg(*ap, char *)));
	else if (specifier == 'p')
		return (print_ptr(va_arg(*ap, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (print_nbr(va_arg(*ap, int)));
	else if (specifier == 'u')
		return (print_unbr(va_arg(*ap, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (print_hex(va_arg(*ap, unsigned int), specifier));
	else if (specifier == '%')
		return (write(1, "%%", 1));
	return (0);
}

static void	printf_char(char c, int *printed_size, int *i)
{
	ft_putchar_fd(c, 1);
	(*printed_size)++;
	(*i)++;
	return ;
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		printed_size;
	int		i;

	if (!fmt)
		return (0);
	printed_size = 0;
	i = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == '\0')
				break ;
			printed_size += check_fmt(fmt[i], &ap);
			i++;
		}
		else
			printf_char(fmt[i], &printed_size, &i);
	}
	va_end(ap);
	return (printed_size);
}

// int	main(void)
// {
// 	int	a;
// 	int	b;
// 	int	sum;

// 	a = 12;
// 	b = 31;
// 	sum = a + b;
// 	printf("%d\n", printf("%d + %d = %d\n", a, b, sum));
// 	printf("%d\n", ft_printf("%d + %d = %d\n", a, b, sum));
// 	printf("%d\n", printf("%X + %X = %X\n", a, b, sum));
// 	printf("%d\n", ft_printf("%X + %X = %X\n", a, b, sum));
// 	printf("%d\n", printf("%u + %u = %u\n", a, b, sum));
// 	printf("%d\n", ft_printf("%u + %u = %u\n", a, b, sum));
// 	printf("%d\n", printf("char %c\n", 'a'));
// 	printf("%d\n", ft_printf("char %c\n", 'a'));
// 	printf("%d\n", printf("hello\n"));
// 	printf("%d\n", ft_printf("hello\n"));
// 	printf("%d\n", printf("%s world\n", "hello"));
// 	printf("%d\n", ft_printf("%s world\n", "hello"));
// 	printf("%d\n", printf("%s world\n", "hello"));
// 	printf("%d\n", ft_printf("%s world\n", "hello"));
// 	char *s = NULL;
// 	printf("%d\n", printf("%s %s\n", "hello", s));
// 	printf("%d\n", ft_printf("%s %s\n", "hello", s));
// 	printf("%d\n", printf("%%\n"));
// 	printf("%d\n", ft_printf("%%\n"));
// 	char *str = "hello";

// 	printf("%d\n", printf("%p\n", str));
// 	printf("%d\n", ft_printf("%p\n", str));
// 	printf("%d\n", printf("%p\n", NULL));
// 	printf("%d\n", ft_printf("%p\n", NULL));
// 	close(1);
// 	int ret = printf("%d\n", printf("%s", "hello"));
// 	int ret2 = printf("%d\n", ft_printf("%s", "hello"));
// 	ft_putnbr_fd(ret, 2);
// 	ft_putnbr_fd(ret2, 2);
// 	return (0);
// }
