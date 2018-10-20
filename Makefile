#NAME	=	ft_printf
NAME	=	libftprintf.a

TEMP	=	tmp
SRC_D	=	src

SOURCES	= 	format_flags_reader.c \
			ft_printf.c \
			flags_optimizer.c \
			string_printer1.c \
			postprocessor1.c \
			number_helper.c \
			number_printer.c \
			unicode.c

OBJS 	= 	$(addprefix $(TEMP)/,$(SOURCES:.c=.o))
SRCS 	= 	$(addprefix $(SRC_D)/,$(SOURCES:.c=.o))

all: $(NAME)

$(TEMP)/%.o : $(SRC_D)/%.c
	@mkdir -p $(TEMP)
	gcc -Wall -Wextra -Werror -c $< -o $@

$(NAME): libft $(OBJS)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS) libft/*.o
	@ranlib $(NAME)

.PHONY: libft
libft:
	@make -C libft

clean:
	echo $(OBJS)
	@rm -rf $(OBJS)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all
