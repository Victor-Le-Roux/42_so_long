NAME = so_long

CFLAGS = -Wall -Wextra -Werror -g3 -I$(INC)
XFLAGS = -Lminilibx-linux -lmlx -lXext -lX11

INC = ./include
LIBFT = ./libft

FILES = srcs/so_long.c
OBJS = $(FILES:.c=.o)

all: $(NAME) 

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(OBJS) $(CFLAGS) $(LIBFT)/libft.a -o $(NAME) $(XFLAGS)
	@echo "Project $(NAME) is ready to run"


clean:
	@make clean -C $(LIBFT)
	@$(RM) $(OBJS) 
fclean: clean
	@make fclean -C $(LIBFT)
	@$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re 
