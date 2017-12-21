/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:43:01 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/19 16:05:20 by fbabin           ###   ########.fr       */
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
	char				z;
}						t_printf;

/*
** ----------------------------------------------------------------------------
** ---------------------------------- SOURCES ---------------------------------
** ----------------------------------------------------------------------------
*/

/*
** ---------------------------- PRINTF FUNCTIONS -------------------------------
*/

int						ft_vfprintf(int fd, const char *restrict format,
							va_list ap);
int						ft_printf(const char *restrict format, ...);
int						ft_fprintf(int fd, const char *restrict format, ...);
int						ft_sprintf(char **str, const char *restrict format,
							...);

/*
** ---------------------------- GENERAL FUNCTIONS ------------------------------
*/

int						ft_read_bis(char *str, int *len);
char					*ft_readf(const char *fmt, va_list args, char *buff,
							int *len);
char					*ft_handler_bis(char *tm, t_printf *t, int *len);
char					*ft_hdl_bis(char *tm, t_printf *t);
int						ft_charinset(char c, const char *charset);
char					*ft_charargs(t_printf *t, va_list args);
t_printf				*ft_xtractor(char *str, int len);
char					*ft_handler(char *buff, char *tmp, va_list args,
							int *len);
/*
** ---------------------------- HANDLE FUNCTIONS ------------------------------
*/

char					*ft_handle_colors(char *str, int *len);
char					*ft_handle_float(va_list args, t_printf *t);
char					*ft_handle_str(va_list args, t_printf *t);
char					*ft_handle_percent(va_list args, t_printf *t);
char					*ft_handlep(va_list args, t_printf *t);
char					*ft_handle_b(va_list args, t_printf *t);
char					*ft_handle_char(va_list args, t_printf *t);
char					*ft_handle_wchar(va_list args, t_printf *t);
char					*ft_handleint(va_list args, t_printf *t);
char					*ft_handle_int(va_list args, t_printf *t);
char					*ft_handleoctal(va_list args, t_printf *t);
char					*ft_handle_octal(va_list args, t_printf *t);
char					*ft_handlehex(va_list args, t_printf *t);
char					*ft_handle_hex(va_list args, t_printf *t);
char					*ft_handleuint(va_list args, t_printf *t);
char					*ft_handle_uint(va_list args, t_printf *t);
char					*ft_getwchar(wchar_t wc);
char					*ft_handle_wstr(va_list args, t_printf *t);

/*
** ---------------------------- UTILS FUNCTIONS ------------------------------
*/

void					ft_dfree(void *s, void *t);
t_printf				*ft_plst_init(void);
int						ft_wcharlen(wchar_t wc);
char					*ft_rep(char *str, char old, char fresh);
int						ft_backsearch(char *str, int len);

#endif
