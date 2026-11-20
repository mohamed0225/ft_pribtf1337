/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaidbe <mohaidbe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:53:10 by mohaidbe          #+#    #+#             */
/*   Updated: 2026/11/12 19:15:31 by mohaidbe         ###   ########.fr       */
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
	int	j;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	j = 0;
	while (str[i])
	{
		j += ft_putchar(str[i]);
		i++;
	}
	return (j);
}
