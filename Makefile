NAME 		= fractol
SRC_DIR		= src
OBJ_DIR		= obj
LIBFT		= incs/libft/libft.a

SRCS		= $(addprefix $(SRC_DIR)/, draw.c init.c events.c \
				utils.c julia.c mandel.c) \
			$(addprefix $(SRC_DIR)/, main.c)
OBJ			= $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

LINK		= -Lincs/mlx -lmlx -Lincs/libft -lft -framework OpenGL -framework AppKit
INCS		= -I incs -I incs/mlx -I incs/libft/incs
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f

$(OBJ_DIR)/%.o :	$(SRC_DIR)/%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C incs/libft
			@$(CC) $(OBJ) $(LINK) -o $(NAME)
clean:
			$(RM) $(OBJ)
			$(RM) -r $(OBJ_DIR)
			@make clean -C incs/libft

fclean:		clean
			$(RM) $(NAME)
			@make fclean -C incs/libft

re:			fclean all

.PHONY:		all clean fclean re