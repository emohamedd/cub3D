# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houattou <houattou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 11:51:02 by houattou          #+#    #+#              #
#    Updated: 2023/10/27 11:04:07 by houattou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = #-Wall -Werror -Wextra -fsanitize=address


SRCS = ./src/raycasting/draw_map.c ./src/raycasting/draw_player.c  main.c ./src/raycasting/update_player.c \
	   ./src/raycasting/draw_line.c ./src/raycasting/check_wall.c ./src/raycasting/raycasting.c \
	   ./src/raycasting/draw_Horizontal_rays.c  ./src/raycasting/draw_vertical_rays.c \
		 
OBJS = $(SRCS:.c=.o)

NAME = cub3D

GREEN = \033[0;32m
RESET = \033[0m
GLFW = $(shell brew --prefix glfw)
FRAMEWORKS = /Users/houattou/Desktop/MLX42/build/libmlx42.a -Iinclude -lglfw -L $(GLFW)/lib/ -framework Cocoa -framework OpenGL -framework IOKit -fsanitize=address
all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS)  -c $< -o $@
	@echo "$(GREEN)✅ Compiled: $<$(RESET)"

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a  $(FRAMEWORKS) -o $(NAME) 
	@echo "$(GREEN)✅  CUB3D : Compilation successful!$(RESET)"

clean:
	@make -C libft/ clean
	@rm -f $(OBJS)
	@echo "$(GREEN)✅ Cleaned up object files$(RESET)"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "$(GREEN)✅ Cleaned up $(NAME)$(RESET)"

re: fclean all