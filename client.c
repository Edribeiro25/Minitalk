/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:14:22 by eribeiro          #+#    #+#             */
/*   Updated: 2021/12/09 12:02:17 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_check;

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	send_str(int pid, char *str, size_t len)
{
	int		d;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		d = 0;
		while (d <= 7)
		{
			g_check = 0;
			if ((str[i] >> d) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			d++;
			while (g_check == 0)
				pause();
		}
		i++;
	}
}

void	arecup(int a)
{
	g_check = 1;
}

int	main(int ac, char **av)
{
	signal(SIGUSR1, &arecup);
	if (ac == 3)
		send_str(ft_atoi(av[1]), av[2], ft_strlen(av[2]));
	else
		ft_putstr("try again\n");
}
