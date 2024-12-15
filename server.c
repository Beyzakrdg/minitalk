/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekarada <bekarada@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:15:55 by bekarada          #+#    #+#             */
/*   Updated: 2024/12/15 10:49:52 by bekarada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	put_signal(int s)
{
	static char		c = 0;
	static int		i = 128;

	if (s == SIGUSR1)
		c += i;
	i /= 2;
	if (i == 0)
	{
		write(1, &c, 1);
		c = 0;
		i = 128;
	}
}

int main(void)
{
	ft_printf("%d", getpid());
	signal(SIGUSR1, put_signal);
	signal(SIGUSR2, put_signal);
	while(1)
		pause();
	return (0);	
}