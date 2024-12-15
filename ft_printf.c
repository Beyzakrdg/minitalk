/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekarada <bekarada@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:35:18 by bekarada          #+#    #+#             */
/*   Updated: 2024/11/12 19:52:00 by bekarada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(char c, va_list *ar, int *len)
{
	if (c == 'c')
		ft_putchar(va_arg(*ar, int), len);
	else if (c == 'p')
		ft_nbr_pointer(va_arg(*ar, void *), len);
	else if (c == 'i' || c == 'd')
		ft_integer(va_arg(*ar, int), len);
	else if (c == 's')
		ft_string(va_arg(*ar, char *), len);
	else if (c == 'x' || c == 'X')
		ft_nbr_hex(va_arg(*ar, unsigned int), c, len);
	else if (c == 'u')
		ft_unsigned_int(va_arg(*ar, unsigned int), len);
	else if (c == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;

	va_start(arg, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_check(str[i + 1], &arg, &len);
			i++;
		}
		else
		{
			ft_putchar((char)str[i], &len);
		}
		i++;
	}
	va_end(arg);
	return (len);
}
