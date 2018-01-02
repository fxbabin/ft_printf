# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 17:49:24 by fbabin            #+#    #+#              #
#    Updated: 2017/12/20 22:18:26 by fbabin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra

_LIBS			=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
					ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
					ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
					ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
					ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
					ft_atoi.c ft_itoa.c ft_itoa_base.c ft_isalpha.c \
					ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
					ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
					ft_strnew.c ft_strdel.c ft_strclr.c ft_putstr.c \
					ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
					ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
					ft_strtrim.c ft_strsplit.c ft_putchar.c ft_putstr.c \
					ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
					ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
					ft_isspace.c ft_lstcreate.c ft_lstpushback.c \
					ft_lstpushfront.c ft_lstsize.c ft_lstlast.c ft_lstclear.c \
					ft_lstatpos.c ft_lstreverse.c ft_lstfind.c \
					ft_lstremoveif.c ft_lstmerge.c ft_lstdump.c ft_lstsort.c \
					ft_strchrindex.c ft_charinset.c ft_strjoinclr.c \
					ft_strnjoinclr.c ft_abs.c ft_swap.c ft_memalloc2.c \
					ft_ftoa.c ft_ltoa.c ft_ltoa_base.c ft_lltoa.c \
					ft_llutoa.c ft_lltoa_base.c ft_llutoa_base.c \
					ft_memdup.c ft_realloc.c ft_strreplace.c ft_split.c \
					ft_join.c ft_strmjoin.c ft_quicksort.c ft_quicksort2.c \
					ft_strquicksort.c ft_mergesort.c ft_strmergesort.c \
					ft_char2dump.c ft_int2dump.c ft_strspn.c ft_strcspn.c \
					ft_strbspn.c ft_strbcspn.c ft_atol.c ft_atoll.c \
					ft_atollu.c \

_GNLS			=	get_next_line.c \

_PRINTFS		=	init.c handlers_scp.c handlers_wc.c \
					handlers_ws.c handlers_iox.c handlers_fpb.c \
					handlers_du.c utils.c utils_2.c ft_printf.c \
					ft_printf_alt.c padding.c xtract.c \

LIBS_DIR		= libft
GNLS_DIR		= get_next_line
PRINTFS_DIR		= ft_printf
LIBS			= $(addprefix $(LIBS_DIR)/, $(_LIBS))
GNLS			= $(addprefix $(GNLS_DIR)/, $(_GNLS))
PRINTFS			= $(addprefix $(PRINTFS_DIR)/, $(_PRINTFS))
OBJS			= $(LIBS:.c=.o)
G_OBJS			= $(GNLS:.c=.o)
P_OBJS			= $(PRINTFS:.c=.o)
OBJS			+= $(G_OBJS)
OBJS			+= $(P_OBJS)

#COLORS
_CYAN=\x1b[36m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_END=\x1b[0m

all: $(NAME)

$(NAME): $(OBJS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "$(NAME) : $(_GREEN)Done$(_END)"

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I includes/

clean:
		@/bin/rm -f $(OBJS)
		@echo "clean : $(_GREEN)Done$(_END)"

fclean: clean
		@/bin/rm -f $(NAME)
		@echo "fclean : $(_GREEN)Done$(_END)"

re:
		@make fclean
		@make

.PHONY: all clean fclean re
