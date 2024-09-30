CC		=gcc
LIBS	=libft/libft.a minilibx/libmlx.a
CFLAGS	=-Wall -Werror -Wextra
NAME	=fdf
C_FILES	=

libft/libft.a:
	make -C libft

minilibx/libmlx.a:
	make -C minilibx

outer_clean:
	make -C libft clean
	make -C minilibx clean

outer_fclean:
	make -C libft fclean
