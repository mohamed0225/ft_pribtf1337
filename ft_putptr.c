/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaidbe <mohaidbe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:34:37 by mohaidbe          #+#    #+#             */
/*   Updated: 2026/11/13 14:36:16 by mohaidbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexalower(unsigned long n)
{
	char	*hex;
	int		i;

	i = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		i += ft_hexalower(n / 16);
	i += ft_putchar(hex[n % 16]);
	return (i);
}

int	ft_putptr(void *ptr)
{
	int	i;

	if (!ptr)
		return (write(1, "(nil)", 5));
	i = write(1, "0x", 2);
	i += ft_hexalower((unsigned long)ptr);
	return (i);
}
