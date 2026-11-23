/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaidbe <mohaidbe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:53:10 by mohaidbe          #+#    #+#             */
/*   Updated: 2026/11/22 14:13:18 by mohaidbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	res;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		res = ft_putchar(str[i]);
		if (res == -1)
			return (-1);
		i++;
	}
	return (i);
}
