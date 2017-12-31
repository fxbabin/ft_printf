/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:43:01 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/30 00:42:51 by misteir          ###   ########.fr       */
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

# define MIN_INT -2147483648
# define MAX_INT 2147483647
# define MIN_UINT -4294967295
# define MAX_UINT 4294967295
# define MIN_LONG -9223372036854775807
# define MAX_LONG 9223372036854775807

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

/*
** ---------------------------- GENERAL FUNCTIONS ------------------------------
*/

void					ft_readf(const char *fmt, t_buff *b, va_list args);
void					ft_handler(t_buff *b, const char *fmt, va_list args,
							int idx);
void					ft_xtractor(t_printf *t, const char *fmt, int len);

/*
** ---------------------------- HANDLE FUNCTIONS ------------------------------
*/

char					*ft_handle_wchar(va_list args, t_printf *t);
char					*ft_handle_wstr(va_list args, t_printf *t);
char					*ft_getwchar(wchar_t wc);

/*
** ---------------------------- UTILS FUNCTIONS ------------------------------
*/

void					bflush(t_buff *b, const char *str, int n);
int						ft_wcharlen(wchar_t wc);

#endif
