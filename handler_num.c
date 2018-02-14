/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misteir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 10:33:11 by misteir           #+#    #+#             */
/*   Updated: 2018/02/14 18:24:29 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_getbase(char *base, char flag)
{
	ft_bzero(base, 17);
	if (flag == 'o' || flag == 'O')
		ft_memcpy(base, "01234567", 8);
	else if (flag == 'x' || flag == 'p')
		ft_memcpy(base, "0123456789abcdef", 16);
	else if (flag == 'X')
		ft_memcpy(base, "0123456789ABCDEF", 16);
	else if (flag == 'b')
		ft_memcpy(base, "01", 2);
	else
		ft_memcpy(base, "0123456789", 10);
}

long long			proper_cast(t_printf *t, va_list args)
{
	if (t->mod1 == 'j')
		return ((long long)va_arg(args, intmax_t));
	else if (t->mod1 == 'z')
		return ((long long)va_arg(args, size_t));
	else if (!(t->mod2) && (t->mod1 == 'h'))
		return ((long long)((short)va_arg(args, int)));
	else if (t->mod2 == 'h')
	{
		if (t->flag == 'D')
			return ((long long)((unsigned short)va_arg(args, int)));
		return ((long long)((char)va_arg(args, int)));
	}
	else if (!(t->mod2) && (t->mod1 == 'l'))
		return ((long long)va_arg(args, long));
	else if (t->mod2 == 'l')
		return ((long long)va_arg(args, long long));
	return ((long long)va_arg(args, int));
}

unsigned long long	proper_ucast(t_printf *t, va_list args)
{
	unsigned int	n;

	if (t->mod1 == 'j')
		return ((unsigned long long)va_arg(args, intmax_t));
	else if (t->mod1 == 'z')
		return ((unsigned long long)va_arg(args, size_t));
	else if (!(t->mod2) && (t->mod1 == 'h'))
		n = (unsigned int)((unsigned short)va_arg(args, unsigned int));
	else if (t->mod2 == 'h')
		n = (unsigned int)((unsigned char)va_arg(args, unsigned int));
	else if (!(t->mod2) && (t->mod1 == 'l'))
		return ((unsigned long long)va_arg(args, unsigned long));
	else if (t->mod2 == 'l')
		return ((unsigned long long)va_arg(args, unsigned long long));
	else
		n = (unsigned int)va_arg(args, unsigned int);
	return ((unsigned long long)n);
}

void	ft_handle_num(t_buff *b, t_printf *t, va_list args)
{
	//char		base[17];
	char		*str;
	int			len;

	//ft_getbase(base, t->flag);
	t->mod1 = (t->flag < 96) ? 'l' : t->mod1;
	str = ft_lltoa(proper_cast(t, args));
	t->neg = (str[0] == '-') ? 1 : 0;
	len = ft_strlen(str) - t->neg;
	len = (t->prec == -1 && ft_atoi(str) == 0) ? 0 : len;
	ft_padding_b(b, t, len);
	bflush(b, (t->neg) ? str + 1 : str, len);
	ft_padding_a(b, t, len);
	free(str);
}

#include <stdio.h>

void            ft_displaynod(t_printf *t)
{
	printf("prec -> %d\n", t->prec);
	printf("nb -> %d\n", t->nb);
	printf("flag -> %c\n", t->flag);
	printf("zero -> %d\n", t->zero);
	printf("plus -> %d\n", t->plus);
	printf("minus -> %d\n", t->minus);
	printf("hash -> %d\n", t->hash);
	printf("space -> %d\n", t->space);
	printf("mod1 -> %c\n", t->mod1);
	printf("mod2 -> %c\n", t->mod2);
	printf("neg -> %d\n", t->neg);

}

void	ft_handle_unum(t_buff *b, t_printf *t, va_list args)
{
	char		base[17];
	char		*str;
	int			len;

	t->hash = (t->flag == 'p') ? 1 : t->hash;
	//t->flag = (t->flag == 'p') ? 'x' : t->flag;
	ft_getbase(base, t->flag);
	t->mod1 = (t->flag < 96 && t->flag != 'X' ) ? 'l' : t->mod1;
	t->mod2 = (t->flag < 96 && t->flag != 'X' ) ? 0 : t->mod2;
	t->mod1 = (t->flag == 'p' ) ? 'l' : t->mod1;


	str = ft_llutoa_base(proper_ucast(t, args), base);
	/*if (!(t->mod1))
	  str = ft_llutoa_base((unsigned int)va_arg(args, int), base);
	  else if (!(t->mod2) && (t->mod1 == 'h'))
	  str = ft_llutoa_base((unsigned short)va_arg(args, unsigned int), base);
	  else if (t->mod2 == 'h')
	  str = ft_llutoa_base(va_arg(args, unsigned int), base);
	  else if (!(t->mod2) && (t->mod1 == 'l'))
	  str = ft_llutoa_base((unsigned long)va_arg(args, unsigned long), base);
	  else if (t->mod2 == 'l')
	  str = ft_llutoa_base(va_arg(args, unsigned long long), base);
	  else if (t->mod1 == 'j')
	  str = ft_llutoa_base((unsigned long long)va_arg(args, uintmax_t), base);
	  else if (t->mod1 == 'z')
	  str = ft_llutoa_base(va_arg(args, size_t), base);
	  */
	len = ft_strlen(str);
	//printf("%s\n", str);
	//t->prec = (t->hash && t->flag == 'o' && ft_atoi(str) == 0 && str[0] == '0') ? -1 : t->prec;
	len = (t->prec == -1 && ft_atoi(str) == 0 && str[0] == '0') ? 0 : len;
	len = (t->hash && (t->flag == 'o' || t->flag == 'O') && ft_atoi(str) == 0 && str[0] == '0') ? 0 : len;
	t->hash = (!ft_charinset(t->flag, "poO") && ft_atollu(str) == 0 && str[0] == '0') ? 0 : t->hash;
	//len = (t->prec == -1 && ft_atoi(str) == 0) ? 0 : len;
	ft_padding_b(b, t, len);
	//if (t->prec != -1)
	bflush(b, str, len);
	ft_padding_a(b, t, len);
	free(str);
}

/*char	*ft_handle_unum(va_list args, t_printf *t)
  {
  char		base[16];

  ft_getbase(base, t->flag);
  if (!(t->mod1))
  return (ft_itoa_base(va_arg(args, unsigned int), base));
  else if (!(t->mod2) && (t->mod1 == 'h'))
  return (ft_itoa_base((short)va_arg(args, int), base));
  else if (t->mod2 == 'h')
  return (ft_itoa_base((signed char)va_arg(args, int), base));
  else if (!(t->mod2) && (t->mod1 == 'l'))
  return (ft_ltoa_base(va_arg(args, long), base));
  else if (t->mod2 == 'l')
  return (ft_lltoa_base(va_arg(args, long long), base));
  else if (t->mod1 == 'j')
  return (ft_lltoa_base(va_arg(args, intmax_t), base));
  else if (t->mod1 == 'z')
  return (ft_lltoa_base(va_arg(args, size_t), base));
  return (NULL);
  }*/
