/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaidbe <mohaidbe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:36:19 by mohaidbe          #+#    #+#             */
/*   Updated: 2026/11/16 12:04:44 by mohaidbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	num;
	int		i;
	int		ret;

	num = n;
	i = 0;
	if (num < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		i++;
		num = -num;
	}
	if (num >= 10)
	{
		ret = ft_putnbr(num / 10);
		if (ret == -1)
			return (-1);
		i += ret;
	}
	if (ft_putchar(num % 10 + 48) == -1)
		return (-1);
	return (i + 1);
}

int	ft_putunsigned(unsigned int n)
{
	int	i;
	int	ret;

	i = 0;
	if (n >= 10)
	{
		ret = ft_putunsigned(n / 10);
		if (ret == -1)
			return (-1);
		i += ret;
	}
	ret = ft_putchar(n % 10 + 48);
	if (ret == -1)
		return (-1);
	i += ret;
	return (i);
}
