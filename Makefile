# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: made-alm <made-alm@student.42porto.co      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 19:56:15 by made-alm          #+#    #+#              #
#    Updated: 2023/03/14 20:52:49 by made-alm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBC = ar rc
RM = rm -rf

SRCS = ft_print_c.c\
	ft_print_di.c\
	ft_print_p.c\
	ft_print_s.c\
	ft_print_u.c\
	ft_print_xx.c\
	ft_printf.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re .c .o
