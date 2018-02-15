/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:43:01 by fbabin            #+#    #+#             */
/*   Updated: 2018/02/16 00:24:15 by fbabin           ###   ########.fr       */
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

# define BUFF_SIZE 128

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define EOC "\x1b[0m"

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
int						ft_fprintf(int fd, const char *restrict format, ...);
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
