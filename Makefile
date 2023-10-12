# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 11:16:03 by emohamed          #+#    #+#              #
#    Updated: 2023/10/12 08:37:03 by emohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address


SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

NAME = cub3D

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