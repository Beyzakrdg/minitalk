/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekarada <bekarada@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:57:17 by bekarada          #+#    #+#             */
/*   Updated: 2024/11/12 19:27:24 by bekarada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_integer(int nbr, int *len)
{
	if (nbr == -2147483648)
		ft_string("-2147483648", len);
	else if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr = nbr * -1;
		ft_integer(nbr, len);
	}
	else if (nbr == 0)
		ft_putchar('0', len);
	else
	{
		if (nbr > 9)
		{
			ft_integer(nbr / 10, len);
			ft_integer(nbr % 10, len);
		}
		else
		{
			nbr += '0';
			write(1, &nbr, 1);
			*len += 1;
		}
	}
}

void	ft_nbr_hex(unsigned int nbr, char c, int *len)
{
	char	*hex_digits;
	char	new_hex[25];
	int		i;

	i = 0;
	if (c == 'x')
		hex_digits = "0123456789abcdef";
	else if (c == 'X')
		hex_digits = "0123456789ABCDEF";
	if (nbr == 0)
		ft_putchar('0', len);
	else
	{
		while (nbr != 0)
		{
			new_hex[i] = hex_digits[nbr % 16];
			nbr = nbr / 16;
			i++;
		}
		new_hex[i] = '\0';
		i--;
		while (i >= 0)
			ft_putchar(new_hex[i--], len);
	}
}

void	ft_unsigned_int(unsigned int nbr, int *len)
{
	if (nbr >= 10)
		ft_unsigned_int(nbr / 10, len);
	ft_putchar((nbr % 10) + '0', len);
}

void	ft_nbr_pointer(void *nbr, int *len)
{
	char			*new_digits;
	char			new_pointer[20];
	unsigned long	address;
	int				i;

	i = 0;
	address = (unsigned long)nbr;
	new_digits = "0123456789abcdef";
	if (address == '\0')
		ft_string("(nil)", len);
	else if (address == 0)
		ft_putchar('0', len);
	else
	{
		write(1, "0x", 2);
		*len += 2;
		while (address != 0)
		{
			new_pointer[i++] = new_digits[address % 16];
			address = address / 16;
		}
		new_pointer[i--] = '\0';
		while (i >= 0)
			ft_putchar(new_pointer[i--], len);
	}
}
