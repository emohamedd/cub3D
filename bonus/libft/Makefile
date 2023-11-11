CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRC = ft_isalpha.c ft_strlen.c ft_isprint.c ft_isdigit.c ft_isascii.c ft_isalnum.c ft_memmove.c ft_bzero.c ft_memcpy.c \
        ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_tolower.c ft_toupper.c ft_strrchr.c \
        ft_memchr.c ft_calloc.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c\
        ft_striteri.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	   ar rcs $(NAME) $(OBJ)
    
clean :
		rm -f $(OBJ)

fclean  :
		rm -f $(OBJ) $(NAME)
    
re: fclean all

.PHONY : clean fclean re 