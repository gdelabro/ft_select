/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:36:12 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/31 15:17:04 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_select.h"

void	sign(int s)
{
	reset_term();
	if (s == SIGWINCH)
	{
		affichage();
		change_term();
	}
	else
		exit(s);
	change_term();
}

void	ft_quit(int mode)
{
	t_sel	*e;
	int		i;

	e = my_struct(NULL);
	if (mode == 1)
	{
		i = -1;
		while (e->av[++i])
			if (e->sel[i])
			{
				ft_putstr(e->av[i]);
				ft_putstr(" ");
			}
		reset_term();
		exit(0);
	}
	reset_term();
	if (mode == 0)
		exit(0);
}

void	capt_sign(void)
{
	signal(SIGINT, &sign);
	signal(SIGKILL, &sign);
	signal(SIGWINCH, &sign);
	signal(SIGTERM, &sign);
	signal(SIGQUIT, &sign);
	signal(SIGABRT, &sign);
	signal(SIGHUP, &sign);
}
