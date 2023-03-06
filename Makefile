NAME = libftptintf.a
LIBC = ar rc
RM = rm -rf

SRCS = ft_print_c.c\
	ft_print_di.c\
	ft_print_p.c\
	ft_print_s.c\
	ft_print_u.c\
	ft_print_xX.c\
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