CC = cc
CFLAGS = #-Wall -Werror -Wextra #-fsanitize=address


SRCS = ./src/raycasting/t.c main.c
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
	
	@$(CC) $(CFLAGS) $(OBJS) $(FRAMEWORKS) -o $(NAME) 
	@echo "$(GREEN)✅  CUB3D : Compilation successful!$(RESET)"

clean:
	
	@rm -f $(OBJS)
	@echo "$(GREEN)✅ Cleaned up object files$(RESET)"

fclean: clean
	
	@rm -f $(NAME)
	@echo "$(GREEN)✅ Cleaned up $(NAME)$(RESET)"

re: fclean all