/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:17:59 by eribeiro          #+#    #+#             */
/*   Updated: 2021/12/10 14:04:09 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

char	*lockstr(char *str, int size, char c)
{
	char	*tab;
	int		i;

	tab = (char *)malloc((size + 2) * sizeof(char));
	if (!tab)
		return (NULL);
	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			tab[i] = str[i];
			i++;
		}
	}
	tab[size] = c;
	tab[size + 1] = '\0';
	return (tab);
}

void	fillstr(char c)
{
	static char	*str;
	char		*tmp;
	int			size;
	int			i;

	tmp = str;
	if (!str)
		size = 0;
	else
		size = ft_strlen(str);
	if (c == '\0')
	{
		ft_putstr(str);
		if (str != NULL)
			free(str);
		str = NULL;
		tmp = NULL;
	}
	else
		str = lockstr(str, size, c);
	if (tmp != NULL)
		free(tmp);
}

void	reception(int bit, siginfo_t *info, void *old)
{
	static int	cc;
	static char	c;

	(void)old;
	if (bit == SIGUSR1)
		c += (1 << cc);
	cc++;
	if (cc == 8)
	{
		fillstr(c);
		c = 0;
		cc = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = &reception;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_putstr("le PID du serveur est : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
}
