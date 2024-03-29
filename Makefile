# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yitoh <yitoh@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/19 10:52:21 by yitoh         #+#    #+#                  #
#    Updated: 2023/05/10 11:26:00 by yitoh         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = cc
SRC = fdf.c parsing_fdf.c draw.c find_points.c hook_fdf.c get_color.c color_init.c\
		rotation_equation.c parsing_utils_fdf.c
# OBJ = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ_DIR = ./obj/
CFLAG = -Wall -Wextra -Werror #-g -fsanitize=address
NAME = fdf
MLX_DIR = ./MLX42/build
MLX = $(MLX_DIR)/libmlx42.a
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(LIBFT)
	@$(CC) $(CFLAG) $^ -Iinclude -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -o $@

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(CFLAG) $< -o $@
	
# %.o: %.c
# 	@$(CC) -c $(CFLAG) $< -o $@

$(MLX):
	@$(MAKE) -C $(MLX_DIR)
	@cp $(MLX) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all
