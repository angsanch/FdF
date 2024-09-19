CC		=gcc
LIBS	=libft/libft.a
CFLAGS	=-Wall -Werror -Wextra
NAME	=fdf
C_FILES	=

libft/libft.a:
	make -C libft

outer_clean:
	make -C libft clean

outer_fclean:
	make -C libft fclean
