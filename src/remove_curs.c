/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_curs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:07:13 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/31 14:03:00 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_select.h"

void	inverse_selec(void)
{
	int		i;
	t_sel	*e;

	e = my_struct(NULL);
	i = -1;
	while (e->av[++i])
		e->sel[i] = ABS(e->sel[i] - 1);
}

void	all_selec(void)
{
	int		i;
	t_sel	*e;

	e = my_struct(NULL);
	i = -1;
	while (e->av[++i])
		if (e->sel[i] == 0)
			break ;
	ft_putnbr(i);
	if ((i == taille_tab(e->av) && (i = -1)) ||
			(i = -1) != -1)
		while (e->av[++i])
			e->sel[i] = 0;
	else
		while (e->av[++i])
			e->sel[i] = 1;
}

void	remove_curs(void)
{
	int		i;
	t_sel	*e;

	e = my_struct(NULL);
	i = e->cur - 1;
	e->cur = e->cur - 1;
	e->cur == -1 ? e->cur = 0 : 0;
	!taille_tab(e->av) ? ft_quit(0) : 0;
	while (e->av[++i])
	{
		ft_strdel(&(e->av[i]));
		e->av[i] = ft_strdup(e->av[i + 1]);
		e->av[i] ? e->sel[i] = e->sel[i + 1] : 0;
	}
}
