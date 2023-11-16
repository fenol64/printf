NAME = libftprintf.a

SRCS = ft_printf.c printf_utils.c
OBJS = $(SRCS:.c=.o)

COMPILER = cc -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	@ $(COMPILER) -c -I . $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	@ ar rc $(NAME) $(OBJS)
	@ echo "compiling...\ncompile complete!"

re: fclean $(NAME)

exec: re
	@ $(COMPILER) main.c libftprintf.a -o exec
	@ clear
	@ ./exec

clean:
	@ rm -rf $(OBJS)
	@ echo "deleted all .o files."

fclean: clean
	@ rm -rf $(NAME)
	@ echo "deleted $(NAME) lib successfully"

aclean: fclean
	@ rm -rf exec
	@ echo "deleted exec successfully"

.PHONY: all clean fclean re exec

