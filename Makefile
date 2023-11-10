NAME = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRC = 	src/pipex.c src/tools.c\
		libft/libft.a\

SRC_BONUS = src_bonus/pipex_bonus.c src_bonus/tools_bonus.c\
			src_bonus/parsing_bonus.c gnl_bonus/gnl_bonus.c\
			libft/libft.a\
 
$(NAME) :
	make all -C libft
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(NAME)
	make clean -C libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

re : fclean all

bonus : clean
	make all -C libft
	$(CC) $(CFLAGS) $(SRC_BONUS) -o $(NAME)