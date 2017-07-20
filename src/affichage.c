/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 23:36:30 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/31 16:42:47 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_select.h"

void	search(int c)
{
	int		i;
	t_sel	*e;

	e = my_struct(NULL);
	i = -1;
	if (ft_strlen(e->buf) == 254)
		ft_bzero(e->buf, 256);
	while (e->buf[++i])
		;
	if (c != 127)
		e->buf[i] = c;
	else if (ft_strlen(e->buf))
		e->buf[i - 1] = 0;
	i = -1;
	while (c != 127 && ft_strlen(e->buf) && e->av[++i])
	{
		if (ft_strstr(e->av[i], e->buf))
		{
			e->cur = i;
			break ;
		}
	}
}

void	space(char *str, size_t len)
{
	while (len-- > ft_strlen(str))
		ft_putchar_fd(' ', 0);
	ft_putstr_fd(" ", 0);
}

int		ft_mode(char *str)
{
	struct stat	st;

	lstat(str, &st);
	if (S_ISDIR(st.st_mode))
		return (1);
	if (S_ISREG(st.st_mode))
		return (2);
	return (0);
}

void	ft_color(int i)
{
	int		mode;
	t_sel	e;

	e = *my_struct(NULL);
	mode = ft_mode(e.av[i]);
	mode == 1 && !e.sel[i] ? ft_putstr_fd(CYAN, 0) : 0;
	mode == 2 && !e.sel[i] ? ft_putstr_fd("\033[37m", 0) : 0;
	mode == 0 && !e.sel[i] ? ft_putstr_fd(RED, 0) : 0;
	e.sel[i] ? ft_putstr_fd("\033[30m", 0) : 0;
	mode == 1 && e.sel[i] ? ft_putstr_fd("\033[46m", 0) : 0;
	mode == 2 && e.sel[i] ? ft_putstr_fd("\033[47m", 0) : 0;
	mode == 0 && e.sel[i] ? ft_putstr_fd("\033[41m", 0) : 0;
	i == e.cur ? ft_putstr_fd("\033[4m", 0) : 0;
}

void	affichage(void)
{
	int		i;
	t_sel	*e;

	i = -1;
	e = my_struct(NULL);
	taille_term(e);
	ft_putstr_fd("\033[H\033[J", 0);
	header();
	while (e->av[++i])
	{
		ft_color(i);
		ft_putstr_fd(e->av[i], 0);
		ft_putstr_fd(NONE, 0);
		space(e->av[i], e->t_max);
		(i + 1) % e->nb_col == 0 || !e->av[i + 1] ? ft_putendl_fd("", 0) : 0;
	}
	if (ft_strcmp("", e->buf))
	{
		ft_putstr_fd(YELLOW"recherche"NONE": ", 0);
		ft_putendl_fd(e->buf, 0);
	}
}
