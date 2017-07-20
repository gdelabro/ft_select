/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_curs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 22:25:10 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/31 15:59:20 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_select.h"

void	move_right(void)
{
	t_sel	*e;

	e = my_struct(NULL);
	if (e->cur == taille_tab(e->av) - 1)
		e->cur = 0;
	else
		++e->cur;
}

void	move_left(void)
{
	t_sel	*e;

	e = my_struct(NULL);
	if (!e->cur)
		e->cur = taille_tab(e->av) - 1;
	else
		--e->cur;
}

void	move_up(void)
{
	t_sel	*e;

	e = my_struct(NULL);
	if (e->cur / e->nb_col)
		e->cur -= e->nb_col;
	else
		while (e->cur + e->nb_col < taille_tab(e->av))
			e->cur += e->nb_col;
}

void	move_down(void)
{
	t_sel	*e;

	e = my_struct(NULL);
	if (e->cur + e->nb_col <= taille_tab(e->av) - 1)
		e->cur += e->nb_col;
	else
		e->cur = e->cur % e->nb_col;
}

void	move_curs(int c)
{
	t_sel *e;

	e = my_struct(NULL);
	c == 32 ? e->sel[e->cur] = ABS(e->sel[e->cur] - 1) : 0;
	c == 32 ? move_right() : 0;
	c == 4414235 ? move_right() : 0;
	c == 4479771 ? move_left() : 0;
	c == 4283163 ? move_up() : 0;
	c == 4348699 ? move_down() : 0;
	c == 27 ? ft_quit(0) : 0;
	c == 10 ? ft_quit(1) : 0;
	(c == 127 && !ft_strlen(e->buf)) || c == 2117294875 ? remove_curs() : 0;
	c == 19 ? inverse_selec() : 0;
	c == 1 ? all_selec() : 0;
}
