# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 17:49:24 by fbabin            #+#    #+#              #
#    Updated: 2019/07/06 14:36:36 by fbabin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra

_SRCS			=	ft_printf.c padding.c xtract.c handler_wc.c \
					handler_ws.c handler_num.c handler_fnk.c utils.c utils2.c \
					utils3.c

SRCS_DIR		=	srcs
SRCS			=	$(addprefix $(SRCS_DIR)/, $(_SRCS))
OBJS			=	$(SRCS:.c=.o)
RM				=	/bin/rm

#Color
_GREEN=\x1b[32m
_END=\x1b[0m

all: $(NAME)

$(NAME): $(OBJS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "$(NAME) : $(_GREEN)Done$(_END)"

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ -I includes/

clean:
	@$(RM) -f $(OBJS)
	@echo "clean : $(_GREEN)Done$(_END)"

fclean: clean
	@$(RM) -f $(NAME)
	@echo "fclean : $(_GREEN)Done$(_END)"

re:
	@make fclean
	@make

.PHONY: all clean fclean re
