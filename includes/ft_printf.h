/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:43:01 by fbabin            #+#    #+#             */
/*   Updated: 2018/04/18 00:13:33 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** --------------------------------- INCLUDES ---------------------------------
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <locale.h>
# include "libft.h"

/*
** --------------------------------- DEFINES ---------------------------------
*/

# define BUFF_SIZE	128
# define RED		0xE71010
# define LRED		0xF3664D
# define GREEN		0x219A25
# define LGREEN		0x55DA59
# define YELLOW		0xFFFB00
# define LYELLOW	0xFBF978
# define BLUE		0x224DFC
# define LBLUE		0x8099FE
# define MAGENTA	0xFF54F7
# define LMAGENTA	0xFFB6FC
# define CYAN		0x2EFCFF
# define LCYAN		0x97FEFF
# define EOC		0xFFFFFF
# define RESET		-1

/*
** ------------------------------- STRUCTURES ----------------------------------
*/

typedef struct			s_buff
{
	char				buff[BUFF_SIZE + 1];
	int					len;
	int					pos;
	int					err;
	int					fd;
	char				*str;
	char				sprintf;
	int					err_len;
}						t_buff;

typedef struct			s_printf
{
	int					prec;
	int					nb;
	char				flag;
	char				zero;
	char				plus;
	char				minus;
	char				hash;
	char				space;
	char				mod1;
	char				mod2;
	char				neg;
}						t_printf;

/*
** ----------------------------------------------------------------------------
** ---------------------------------- SOURCES ---------------------------------
** ----------------------------------------------------------------------------
*/

/*
** ---------------------------- PRINTF FUNCTIONS -------------------------------
*/

int						ft_printf(const char *restrict format, ...);
int						ft_sprintf(char **str, const char *restrict format,
							...);
int						ft_dprintf(int fd, const char *restrict format, ...);
int						ft_vfprintf(int fd, const char *restrict format,
							va_list args);

/*
** ---------------------------- GENERAL FUNCTIONS ------------------------------
*/

void					ft_readf(const char *fmt, t_buff *b, va_list args);
void					ft_handler(t_buff *b, t_printf *t, va_list args);
int						ft_xtractor(t_printf *t, const char *fmt, va_list args);

/*
** ---------------------------- HANDLE FUNCTIONS ------------------------------
*/

void					ft_getwchar(t_buff *b, wchar_t wc, int len);
void					ft_handle_num(t_buff *b, t_printf *t, va_list args);
void					ft_handle_unum(t_buff *b, t_printf *t, va_list args);
void					ft_handle_wchar(t_buff *b, t_printf *t, va_list args);
void					ft_handle_wstr(t_buff *b, t_printf *t, va_list args);
void					ft_handle_n(t_buff *b, t_printf *t, va_list args);
void					ft_handle_colors(t_buff *b, t_printf *t, va_list args);
void					ft_handle_other(t_buff *b, t_printf *t, char flag);
void					ft_handle_float(t_buff *b, t_printf *t, va_list args);
void					add_spaces(t_buff *b, t_printf *t, int len);
void					ft_padding_b(t_buff *b, t_printf *t, int len);
void					ft_padding_a(t_buff *b, t_printf *t, int len);

/*
** ---------------------------- UTILS FUNCTIONS ------------------------------
*/

void					bflush(t_buff *b, const char *str, int n);
int						ft_wcharlen(wchar_t wc);

#endif
