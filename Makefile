# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 11:51:02 by emohamed          #+#    #+#              #
#    Updated: 2023/11/13 10:08:36 by emohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


	 
CC = cc
CFLAGS = -O3

SRCS = ./mandatory/raycasting/coordination_of_player.c   main.c ./mandatory/raycasting/update_player.c \
	   ./mandatory/raycasting/render_textures.c ./mandatory/raycasting/check_wall.c ./mandatory/raycasting/raycasting.c \
	   ./mandatory/raycasting/get_vertical_intersection.c  ./mandatory/raycasting/get_horizontal_intersection.c \
	   ./mandatory/raycasting/draw_projection_wall.c   ./mandatory/raycasting/math.c \
	   ./mandatory/parsing/check_file_name.c ./mandatory/parsing/cub_utils.c ./mandatory/parsing/parsing_the_directions.c ./mandatory/parsing/free_func.c ./mandatory/parsing/key_color_range.c ./mandatory/parsing/fulling_directions.c \
	   ./mandatory/parsing/parsing_the_map.c ./mandatory/parsing/print_err.c \
	   ./mandatory/parsing/valid_map.c  ./mandatory/parsing/readfile.c ./mandatory/raycasting/txt_load.c ./mandatory/raycasting/drawing.c ./mandatory/raycasting/initialization.c \
	   ./mandatory/parsing/parsing.c \
	   


# SRCS_BONUS = ./bonus/raycasting/coordination_of_player.c   main.c ./bonus/raycasting/update_player.c \
# 	   ./bonus/raycasting/render_textures.c ./bonus/raycasting/check_wall.c ./bonus/raycasting/raycasting.c \
# 	   ./bonus/raycasting/get_vertical_intersection.c  ./bonus/raycasting/get_horizontal_intersection.c \
# 	   ./bonus/raycasting/draw_projection_wall.c   ./bonus/raycasting/math.c \
# 	   ./bonus/parsing/check_file_name.c ./bonus/parsing/cub_utils.c ./bonus/parsing/parsing_the_directions.c ./bonus/parsing/free_func.c ./bonus/parsing/key_color_range.c ./bonus/parsing/fulling_directions.c \
# 	   ./bonus/parsing/parsing_the_map.c ./bonus/parsing/print_err.c \
# 	   ./bonus/parsing/valid_map.c  ./bonus/parsing/readfile.c ./bonus/raycasting/txt_load.c ./bonus/raycasting/drawing.c ./bonus/raycasting/initialization.c \
# 	   ./bonus/parsing/parsing.c

OBJS = $(SRCS:.c=.o)

# OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = cub3D

# NAME_BONUS = cub3D_bonus

GREEN = \033[0;32m
RESET = \033[0m
GLFW = $(shell brew --prefix glfw)
FRAMEWORKS = /Users/emohamed/Desktop/MLX42/build/libmlx42.a -Iinclude -lglfw -L $(GLFW)/lib/ -framework Cocoa -framework OpenGL -framework IOKit

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS)  -c $< -o $@
	@echo "$(GREEN)✅ Compiled: $<$(RESET)"

$(NAME): $(OBJS)
	@make -C libft
	@make -C get_line
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a get_line/get_next_line.a  $(FRAMEWORKS) -o $(NAME) 
	@echo "$(GREEN)✅  CUB3D : Compilation successful!$(RESET)"

# bonus: $(OBJS_BONUS)
# 	@make -C libft
# 	@make -C get_line
# 	@$(CC) $(CFLAGS) $(OBJS_BONUS) libft/libft.a get_line/get_next_line.a  $(FRAMEWORKS) -o $(NAME_BONUS) 
# 	@echo "$(GREEN)✅  CUB3D BONUS : Compilation successful!$(RESET)"

# clean:
# 	@make -C libft/ clean
# 	@make -C get_line/ clean
# 	@rm -f $(OBJS) $(OBJS_BONUS)
# 	@echo "$(GREEN)✅ Cleaned up object files$(RESET)"

# fclean: clean
# 	@make -C libft/ fclean
# 	@make -C get_line/ fclean
# 	@rm -f $(NAME) $(NAME_BONUS)
# 	@echo "$(GREEN)✅ Cleaned up $(NAME) and $(NAME_BONUS)$(RESET)"

clean:
	@make -C libft/ clean
	@make -C get_line/ clean
	@rm -f $(OBJS)
	@echo "$(GREEN)✅ Cleaned up object files$(RESET)"

fclean: clean
	@make -C libft/ fclean
	@make -C get_line/ fclean
	@rm -f $(NAME) 
	@echo "$(GREEN)✅ Cleaned up $(NAME) and $(RESET)"

# re: fclean all bonus
re: fclean all
