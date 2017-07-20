/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 21:32:28 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/31 15:19:38 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_select.h"

void	header(void)
{
	ft_putstr_fd(GREEN, 0);
	ft_putendl_fd("              __     __      __             ", 0);
	ft_putendl_fd("   ____ _____/ /__  / /___ _/ /_  _________ ", 0);
	ft_putendl_fd("  / __ `/ __  / _ \\/ / __ `/ __ \\/ ___/ __ \\", 0);
	ft_putendl_fd(" / /_/ / /_/ /  __/ / /_/ / /_/ / /  / /_/ /", 0);
	ft_putendl_fd(" \\__, /\\__,_/\\___/_/\\__,_/_.___/_/   \\____/ ", 0);
	ft_putendl_fd("/____/                                      ", 0);
	ft_putstr_fd(NONE, 0);
}

int		change_term(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO | ICANON);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &term);
	return (0);
}

void	reset_term(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= (ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &term);
}
