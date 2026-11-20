/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaidbe <mohaidbe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 23:22:44 by mohaidbe          #+#    #+#             */
/*   Updated: 2026/11/19 16:28:03 by mohaidbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(va_list args, const char *c)
{
	int	i;

	i = 0;
	if (*(c + 1) == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (*(c + 1) == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (*(c + 1) == 'p')
		i = ft_putptr(va_arg(args, void *));
	else if (*(c + 1) == 'x' || *(c + 1) == 'X')
		i = ft_puthexa(va_arg(args, unsigned int), *(c + 1));
	else if (*(c + 1) == 'd' || *(c + 1) == 'i')
		i = ft_putnbr(va_arg(args, int));
	else if (*(c + 1) == 'u')
		i = ft_putunsigned(va_arg(args, unsigned int));
	else if (*(c + 1) == '%')
		i = ft_putchar(*(c + 1));
	else if (*c == '%' && *(c + 1))
	{
		i += ft_putchar(*c);
		i += ft_putchar(*(c + 1));
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		p;
	int		ret;
	va_list	args;

	if (!str || write(1, 0, 0) == -1)
		return (-1);
	i = -1;
	p = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%' && !str[i + 1])
			ret = -1;
		else if (str[i] == '%')
			ret = ft_check_format(args, &str[i++]);
		else
			ret = ft_putchar(str[i]);
		if (ret == -1)
			return (va_end(args), -1);
		p += ret;
	}
	return (va_end(args), p);
}
