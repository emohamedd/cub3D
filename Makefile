# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houattou <houattou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 11:51:02 by emohamed          #+#    #+#              #
#    Updated: 2023/11/10 22:16:35 by houattou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	 
CC = cc
CFLAGS = -O3

SRCS = ./src/raycasting/draw_map.c ./src/raycasting/draw_player.c  main.c ./src/raycasting/update_player.c \
	   ./src/raycasting/draw_line.c ./src/raycasting/check_wall.c ./src/raycasting/raycasting.c \
	   ./src/raycasting/draw_Horizontal_rays.c  ./src/raycasting/draw_vertical_rays.c \
	   ./src/raycasting/draw_projection_wall.c \
	   ./src/parsing/check_file_name.c ./src/parsing/cub_utils.c ./src/parsing/parsing_the_directions.c ./src/parsing/key_color_range.c ./src/parsing/fulling_directions.c \
	   ./src/parsing/parsing_the_map.c ./src/parsing/print_err.c \
	   ./src/parsing/valid_map.c  ./src/parsing/readfile.c ./src/raycasting/txt_load.c ./src/raycasting/drawing.c ./src/raycasting/initialization.c \
	   ./src/parsing/parsing.c \
	   


		 
OBJS = $(SRCS:.c=.o)

NAME = cub3D

GREEN = \033[0;32m
RESET = \033[0m
GLFW = $(shell brew --prefix glfw)
FRAMEWORKS = /Users/houattou/Desktop/MLX42/build/libmlx42.a -Iinclude -lglfw -L $(GLFW)/lib/ -framework Cocoa -framework OpenGL -framework IOKit
all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS)  -c $< -o $@
	@echo "$(GREEN)✅ Compiled: $<$(RESET)"

$(NAME): $(OBJS)
	@make -C libft
	@make -C get_line
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a get_line/get_next_line.a  $(FRAMEWORKS) -o $(NAME) 
	@echo "$(GREEN)✅  CUB3D : Compilation successful!$(RESET)"

clean:
	@make -C libft/ clean
	@make -C get_line/ clean
	@rm -f $(OBJS)
	@echo "$(GREEN)✅ Cleaned up object files$(RESET)"

fclean: clean
	@make -C libft/ fclean
	@make -C get_line/ fclean
	@rm -f $(NAME)
	@echo "$(GREEN)✅ Cleaned up $(NAME)$(RESET)"

re: fclean all