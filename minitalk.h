/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:19:18 by eribeiro          #+#    #+#             */
/*   Updated: 2021/12/09 10:47:48 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include<signal.h>
# include<unistd.h>
# include<stdlib.h>

int	ft_putstr(char *s);
int	ft_putchar(char s);
int	ft_atoi(const char *str);
int	ft_putnbr(int n);
int	ft_strlen(const char *str);

#endif
