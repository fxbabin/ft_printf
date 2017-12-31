/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misteir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:54:08 by misteir           #+#    #+#             */
/*   Updated: 2017/12/31 01:27:40 by misteir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

# define READ_SIZE 10

char	*ft_get_stdout(int *pfd, int *save)
{
	char	*rslt;
	char	*tmp;
	char	buff[READ_SIZE + 1];

	fflush(stdout);
	rslt = ft_strnew(0);
	close(pfd[1]);
	close(1);
	bzero(buff, READ_SIZE + 1);
	while (read(pfd[0], buff, READ_SIZE) > 0)
	{
		tmp = rslt;
		rslt = ft_strjoin(tmp, buff);
		free(tmp);
		bzero(buff, READ_SIZE + 1);
	}
	close(pfd[0]);
	dup2(*save, 1);
	close(*save);
	return (rslt);
}

void	ft_connect_stdout(int *pfd, int *save)
{
	*save = dup(1);
	if (pipe(pfd) == -1)
		exit(1);
	if (dup2(pfd[1], 1) == -1)
		exit(1);
}

void	init(int *r1, int (*pfd)[2], int *sa)
{
	*r1 = 0;
	ft_connect_stdout((int*)pfd, sa);
}

void	ft_compare(int r1, int r2, char *s1, char *s2)
{
	if (ft_strcmp(s1, s2))
	{
		write(1, "X", 1);
		return ;
	}
	if (r1 != r2)
	{
		write(1, "R", 1);
		return ;
	}
	write(1, ".", 1);
}

int		main(void)
{
	int		pfd[2];
	int		save_stdout;
	int		r1;
	int		r2;
	char	*s1;
	char	*s2;

	write(1, "[b] : ", 6);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("\n");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("\n");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("test");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("test");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("test\n");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("test\n");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("1234");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("1234");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	write(1, "\n", 1);
	write(1, "[%] : ", 6);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%%");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%%");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%5%");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%-5%");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%-5%");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%-5%");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%.0%");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%.0%");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%%", "test");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%%", "test");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%   %", "test");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%   %", "test");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	write(1, "\n", 1);
	write(1, "[c] : ", 6);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("[%c]", 'a');
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("[%c]", 'a');
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("[%.2c]", NULL);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("[%.2c]", NULL);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("[%.c]", 'a');
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("[%.c]", 'a');
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("[%c]", 42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("[%c]", 42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("[%5c]", 42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("[%5c]", 42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("[%-5c]", 42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("[%-5c]", 42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("@moulitest: %c", 0);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("@moulitest: %c", 0);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%2c", 0);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%2c", 0);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("null %c and text", 0);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("null %c and text", 0);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("% c", 0);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("% c", 0);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%c%c", '4', '2');
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%c%c", '4', '2');
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
	' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
	'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
	'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
	'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
	'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
	'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
	't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
	' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
	'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
	'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
	'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
	'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
	'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
	't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	write(1, "\n", 1);
	write(1, "[s] : ", 6);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%s", "abc");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%s", "abc");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%s", "this is a string");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%s", "this is a string");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%s ", "this is a string");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%s ", "this is a string");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("this is a %s", "string");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("this is a %s", "string");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%s is a string", "this");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%s is a string", "this");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("Line Feed %s", "\n");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("Line Feed %s", "\n");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%10s is a string", "this");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%10s is a string", "this");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%.2s is a string", "this");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%.2s is a string", "this");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%5.2s is a string", "this");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%5.2s is a string", "this");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%10s is a string", "");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%10s is a string", "");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%.2s is a string", "");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%.2s is a string", "");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%5.2s is a string", "");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%5.2s is a string", "");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%-10s is a string", "this");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%-10s is a string", "this");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%-.2s is a string", "this");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%-.2s is a string", "this");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%-5.2s is a string", "this");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%-5.2s is a string", "this");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%-10s is a string", "");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%-10s is a string", "");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%-.2s is a string", "");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%-.2s is a string", "");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%-5.2s is a string", "");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%-5.2s is a string", "");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%s %s", "this", "is");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%s %s", "this", "is");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%s %s %s", "this", "is", "a");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%s %s %s", "this", "is", "a");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%s %s %s %s", "this", "is", "a", "multi");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%s %s %s %s", "this", "is", "a", "multi");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%s %s %s %s string. gg!", "this", "is", "a", "multi", "string");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%s %s %s %s string. gg!", "this", "is", "a", "multi", "string");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%s%s%s%s%s", "this", "is", "a", "multi", "string");
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%s%s%s%s%s", "this", "is", "a", "multi", "string");
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("@moulitest: %s", NULL);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("@moulitest: %s", NULL);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	write(1, "\n", 1);

	write(1, "[d] : ", 6);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%d", 1);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%d", 1);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("the %d", 1);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("the %d", 1);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%d is one", 1);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%d is one", 1);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%d", -1);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%d", -1);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%d", 4242);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%d", 4242);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%d", -4242);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%d", -4242);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%d", 2147483647);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%d", 2147483647);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%d", 2147483648);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%d", 2147483648);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%d", -2147483648);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%d", -2147483648);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%d", -2147483649);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%d", -2147483649);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("% d", 42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("% d", 42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("% d", -42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("% d", -42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%+d", 42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%+d", 42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%+d", -42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%+d", -42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%+d", 0);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%+d", 0);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%+d", 4242424242424242424242);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%+d", 4242424242424242424242);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("% +d", 42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("% +d", 42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("% +d", -42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("% +d", -42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%+ d", 42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%+ d", 42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%+ d", -42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%+ d", -42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%  +d", 42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%  +d", 42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%  +d", -42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%  +d", -42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%+  d", 42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%+  d", 42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%+  d", -42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%+  d", -42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("% ++d", 42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("% ++d", 42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("% ++d", -42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("% ++d", -42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%++ d", 42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%++ d", 42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%++ d", -42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%++ d", -42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%0d", -42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%0d", -42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%00d", -42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%00d", -42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%5d", 42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%5d", 42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%05d", 42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%05d", 42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%0+5d", 42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%0+5d", 42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%++ d", -42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%++ d", -42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%5d", -42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%5d", -42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%05d", -42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%05d", -42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%0+5d", -42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%0+5d", -42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%-5d", 42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%-5d", 42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%-05d", 42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%-05d", 42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%-5d", -42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%-5d", -42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%-05d", -42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%-05d", -42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%hd", 32767);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%hd", 32767);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%hd", -32768);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%hd", -32768);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%hd", 32768);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%hd", 32768);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%hd", -32769);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%hd", -32769);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%hhd", 127);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%hhd", 127);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%hhd", 128);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%hhd", 128);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%hhd", -128);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%hhd", -128);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%hhd", -129);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%hhd", -129);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%ld", 2147483647);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%ld", 2147483647);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%ld", 2147483648);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%ld", 2147483648);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%ld", -2147483648);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%ld", -2147483648);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%ld", -2147483649);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%ld", -2147483649);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%lld", 9223372036854775807);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%lld", 9223372036854775807);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%lld", -9223372036854775808);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%lld", -9223372036854775808);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%jd", 9223372036854775807);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%jd", 9223372036854775807);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%jd", 9223372036854775808);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%jd", 9223372036854775808);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%zd", 4294967295);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%zd", 4294967295);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%zd", 4294967296);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%zd", 4294967296);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%zd", -0);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%zd", -0);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%zd", -1);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%zd", -1);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%d", 1);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%d", 1);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%d %d", 1, -2);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%d %d", 1, -2);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%d %d %d", 1, -2, 33);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%d %d %d", 1, -2, 33);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%d %d %d %d", 1, -2, 33, 42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%d %d %d %d", 1, -2, 33, 42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%d %d %d %d gg!", 1, -2, 33, 42, 0);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%d %d %d %d gg!", 1, -2, 33, 42, 0);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%4.15d", 42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%4.15d", 42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%.2d", 4242);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%.2d", 4242);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%.10d", 4242);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%.10d", 4242);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%10.5d", 4242);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%10.5d", 4242);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%-10.5d", 4242);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%-10.5d", 4242);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("% 10.5d", 4242);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("% 10.5d", 4242);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%+10.5d", 4242);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%+10.5d", 4242);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%-+10.5d", 4242);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%-+10.5d", 4242);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%03.2d", 0);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%03.2d", 0);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%03.2d", 1);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%03.2d", 1);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("%03.2d", -1);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("%03.2d", -1);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("@moulitest: %.10d", -42);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("@moulitest: %.10d", -42);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("@moulitest: %.d %.0d", 42, 43);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("@moulitest: %.d %.0d", 42, 43);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("@moulitest: %.d %.0d", 0, 0);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("@moulitest: %.d %.0d", 0, 0);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	init(&r1, &pfd, &save_stdout);
	r1 = ft_printf("@moulitest: %5.d %5.0d", 0, 0);
	s1 = ft_get_stdout(pfd, &save_stdout);
	init(&r2, &pfd, &save_stdout);
	r2 = printf("@moulitest: %5.d %5.0d", 0, 0);
	s2 = ft_get_stdout(pfd, &save_stdout);
	ft_compare(r1, r2, s1, s2);
	write(1, "\n", 1);
	//printf("%10s is a string\n", "this");
	//ft_printf("[%s]", "abc"); 
	//printf("[%s]\n", "abc"); 
	return (0);
}

