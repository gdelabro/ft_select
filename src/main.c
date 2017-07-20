/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 23:30:56 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/19 17:41:29 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_select.h"

void		taille_term(t_sel *e)
{
	struct winsize	win;
	int				i;

	ioctl(0, TIOCGWINSZ, &win);
	e->x = win.ws_col;
	i = -1;
	while (e->av[++i])
		!i || ft_strlen(e->av[i]) > e->t_max
			? e->t_max = ft_strlen(e->av[i]) : 0;
	e->nb_col = 1;
	while (e->nb_col * ((int)e->t_max + 1) < e->x)
		++e->nb_col;
	e->nb_col * ((int)e->t_max + 1) >= e->x
		&& e->nb_col != 1 ? --e->nb_col : 0;
}

void		init_struct(t_sel *e)
{
	int				i;
	struct winsize	win;

	i = -1;
	ioctl(0, TIOCGWINSZ, &win);
	!(e->sel = (int*)malloc(sizeof(int) * taille_tab(e->av))) ? ft_quit(0) : 0;
	while (e->av[++i])
		e->sel[i] = 0;
	e->cur = 0;
	e->x = win.ws_col;
	taille_term(e);
	ft_bzero(e->buf, 256);
}

t_sel		*my_struct(char **argv)
{
	static t_sel	*e = NULL;

	if (!e)
	{
		!(e = malloc(sizeof(*e))) ? ft_quit(0) : 0;
		e->av = cpy_tab(argv);
		init_struct(e);
	}
	return (e);
}

void		ft_select(void)
{
	int		c;
	t_sel	*e;
	int		i;

	e = my_struct(NULL);
	c = 0;
	i = -1;
	capt_sign();
	while ("YoLo")
	{
		affichage();
		c = 0;
		read(0, &c, 8);
		change_term();
		move_curs(c);
		c >= 33 && c <= 127 ? search(c) : ft_bzero(e->buf, 256);
	}
}

int			main(int ac, char **av)
{
	t_sel	*e;

	if (ac <= 1 || !isatty(STDIN_FILENO))
		return (-1);
	e = my_struct(++av);
	if (change_term() == -1)
		return (-1);
	ft_select();
	reset_term();
	return (0);
}
