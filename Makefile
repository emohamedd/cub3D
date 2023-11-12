# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houattou <houattou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 11:51:02 by emohamed          #+#    #+#              #
#    Updated: 2023/11/12 17:34:24 by houattou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


	 
CC = cc
CFLAGS = -O3

SRCS = ./mandatory/raycasting/draw_map.c ./mandatory/raycasting/draw_player.c  main.c ./mandatory/raycasting/update_player.c \
	   ./mandatory/raycasting/draw_line.c ./mandatory/raycasting/check_wall.c ./mandatory/raycasting/raycasting.c \
	   ./mandatory/raycasting/get_vertical_intersection.c  ./mandatory/raycasting/get_horizontal_intersection.c \
	   ./mandatory/raycasting/draw_projection_wall.c   ./mandatory/raycasting/math.c \
	   ./mandatory/parsing/check_file_name.c ./mandatory/parsing/cub_utils.c ./mandatory/parsing/parsing_the_directions.c ./mandatory/parsing/free_func.c ./mandatory/parsing/key_color_range.c ./mandatory/parsing/fulling_directions.c \
	   ./mandatory/parsing/parsing_the_map.c ./mandatory/parsing/print_err.c \
	   ./mandatory/parsing/valid_map.c  ./mandatory/parsing/readfile.c ./mandatory/raycasting/txt_load.c ./mandatory/raycasting/drawing.c ./mandatory/raycasting/initialization.c \
	   ./mandatory/parsing/parsing.c \
	   


		 
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