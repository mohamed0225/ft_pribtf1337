/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaidbe <mohaidbe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:37:18 by mohaidbe          #+#    #+#             */
/*   Updated: 2026/11/16 12:27:03 by mohaidbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexaupper(unsigned int n)
{
	char	*hex;
	int		i;
	int		ret;

	i = 0;
	hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		ret = ft_hexaupper(n / 16);
		if (ret == -1)
			return (-1);
		i += ret;
	}
	ret = ft_putchar(hex[n % 16]);
	if (ret == -1)
		return (-1);
	i += ret;
	return (i);
}

static int	ft_hexalower(unsigned int n)
{
	char	*hex;
	int		i;
	int		ret;

	i = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
	{
		ret = ft_hexalower(n / 16);
		if (ret == -1)
			return (-1);
		i += ret;
	}
	ret = ft_putchar(hex[n % 16]);
	if (ret == -1)
		return (-1);
	i += ret;
	return (i);
}

int	ft_puthexa(unsigned int n, char c)
{
	int	i;

	i = 0;
	if (c == 'X')
		i = ft_hexaupper(n);
	if (c == 'x')
		i = ft_hexalower(n);
	return (i);
}
