/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaidbe <mohaidbe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:34:37 by mohaidbe          #+#    #+#             */
/*   Updated: 2026/11/23 18:16:19 by mohaidbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexalower(unsigned long n)
{
	char	*hex;
	int		i;
	int		r;

	i = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
	{
		r = ft_hexalower(n / 16);
		if (r == -1)
			return (-1);
		i += r;
	}
	r = ft_putchar(hex[n % 16]);
	if (r == -1)
		return (-1);
	i += r;
	return (i);
}

int	ft_putptr(void *ptr)
{
	int	i;
	int	res;

	if (!ptr)
	{
		i = ft_putstr("(nil)");
		return (i);
	}
	i = ft_putstr("0x");
	if (i == -1)
		return (-1);
	res = ft_hexalower((unsigned long)ptr);
	if (res == -1)
		return (-1);
	i += res;
	return (i);
}
