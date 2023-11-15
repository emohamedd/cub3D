# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houattou <houattou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 11:51:02 by emohamed          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2023/11/14 18:35:32 by houattou         ###   ########.fr        #
=======
#    Updated: 2023/11/14 22:49:28 by emohamed         ###   ########.fr        #
>>>>>>> 2d794348263f8612d4e6df21f2402a7b31f791c8
#                                                                              #
# **************************************************************************** #


	 
CC = cc
CFLAGS =  -O3 #-fsanitize=address -g


SRCS = ./mandatory/raycasting/coordination_of_player.c   main.c ./mandatory/raycasting/update_player.c \
	   ./mandatory/raycasting/render_textures.c ./mandatory/raycasting/check_wall.c ./mandatory/raycasting/raycasting.c \
	   ./mandatory/raycasting/get_vertical_intersection.c  ./mandatory/raycasting/get_horizontal_intersection.c \
	   ./mandatory/raycasting/drawing_bonus.c   ./mandatory/raycasting/math.c \
	   ./mandatory/parsing/check_file_name.c ./mandatory/parsing/cub_utils.c ./mandatory/parsing/parsing_the_directions.c ./mandatory/parsing/free_func.c ./mandatory/parsing/key_color_range.c ./mandatory/parsing/fulling_directions.c \
	   ./mandatory/parsing/parsing_the_map.c ./mandatory/parsing/print_err.c ./mandatory/parsing/parsing_the_directions_utils.c ./mandatory/parsing/readfile_utils.c \
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
YELLOW = \033[0;33m
RESET = \033[0m
GLFW = $(shell brew --prefix glfw)
FRAMEWORKS = /Users/houattou/Desktop/MLX42/build/libmlx42.a -Iinclude -lglfw -L $(GLFW)/lib/ -framework Cocoa -framework OpenGL -framework IOKit

all: $(NAME) display_banner

%.o: %.c
	@$(CC) $(CFLAGS)  -c $< -o $@
	@echo "$(GREEN)✅ Compiled: $<$(RESET)"

$(NAME): $(OBJS)
	@make -C libft
	@make -C get_line
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a get_line/get_next_line.a  $(FRAMEWORKS) -o $(NAME) 
	@echo "$(GREEN)✅  CUB3D : Compilation successful!$(RESET)"

display_banner:
	@echo "$(GREEN)\$(RESET)" 
	@echo "$(GREEN)		.d8888b.  888     888 888888b.     .d8888b.  8888888b.$(RESET)" 
	@echo "$(GREEN)		d88P  Y88b 888     888 888  \"88b   d88P  Y88b 888   Y88b$(RESET)" 
	@echo "$(GREEN)		888    888 888     888 888  .88P        .d88P 888    888$(RESET)" 
	@echo "$(GREEN)		888        888     888 8888888K.       8888\"  888    888$(RESET)" 
	@echo "$(GREEN)		888        888     888 888  \"Y88 b      \"Y8b. 888    888$(RESET)" 
	@echo "$(GREEN)		888    888 888     888 888    888  888    888 888    888$(RESET)" 
	@echo "$(GREEN)		Y88b  d88P Y88b. .d88P 888   d88P  Y88b  d88P 888  .d88P$(RESET)" 
	@echo "$(GREEN)		  Y8888P     Y88888P    8888888P      Y8888P   8888888P$(RESET)"
	@echo "$(YELLOW)						By emohamed && houattou$(RESET)"

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
