/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 23:20:33 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/31 15:11:50 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <sys/ipc.h>
# include <termios.h>
# include <termcap.h>
# include "libft/libft.h"

# define NONE			"\033[0m"
# define BOLD			"\033[1m"
# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define RED_BOLD		"\033[31;1m"
# define GREEN			"\033[32;1m"
# define BROWN			"\033[33m"
# define YELLOW			"\033[33;1m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36;1m"
# define GRAY			"\033[37m"
# define DEV_C			"\033[43;34m"
# define DEV_B			"\033[46;34m"
# define ABS(x) ((x) < 0 ? - (x) : (x))

typedef struct termios	t_termios;

typedef struct			s_sel
{
	char		**av;
	int			*sel;
	int			cur;
	int			x;
	int			nb_col;
	char		buf[256];
	size_t		t_max;
}						t_sel;

void					affichage(void);
void					remove_curs(void);
void					reset_term(void);
void					move_down(void);
void					move_up(void);
void					move_right(void);
void					move_left(void);
void					search(int c);
void					capt_sign(void);
void					taille_term(t_sel *e);
t_sel					*my_struct(char **argv);
void					ft_quit(int mode);
void					ft_select(void);
void					inverse_selec(void);
void					all_selec(void);
void					header(void);
void					init_struct(t_sel *e);
void					move_curs(int c);
int						change_term(void);

#endif
