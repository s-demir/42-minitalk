/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedemir <sedemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:59:19 by sedemir           #+#    #+#             */
/*   Updated: 2025/03/07 14:23:35 by sedemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

void	handle_bit(int sig)
{
	static int	bit = 128;
	static int	res = 0;

	if (sig == SIGUSR1)
		res += bit;
	bit /= 2;
	if (bit == 0)
	{
		if (res == 0)
			write(1, "\n", 1);
		write(1, &res, 1);
		bit = 128;
		res = 0;
	}
}

int	main(void)
{
	write(1, "PID: ", 6);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		signal (SIGUSR1, handle_bit);
		signal (SIGUSR2, handle_bit);
	}
}
