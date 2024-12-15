/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekarada <bekarada@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:29:04 by bekarada          #+#    #+#             */
/*   Updated: 2024/11/12 19:17:07 by bekarada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *len);
void	ft_string(char *str, int *len);
void	ft_integer(int nbr, int *len);
void	ft_nbr_hex(unsigned int nbr, char c, int *len);
void	ft_unsigned_int(unsigned int nbr, int *len);
void	ft_nbr_pointer(void *nbr, int *len);

#endif