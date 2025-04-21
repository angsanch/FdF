CC		=gcc
LIBS	=libft/libft.a minilibx/build/libmlx42.a
LINKS	=-ldl -lglfw -pthread -lm
CFLAGS	=-Wall -Werror -Wextra -Iinclude
NAME	=fdf
C_FILES	=src/main.c \
			src/parsing/map.c \
			src/parsing/map_apply.c \
			src/tools/node.c \
			src/tools/web.c \
			src/engine/engine_tools.c \
			src/engine/hook_internals.c \
			src/engine/hooks.c \
			src/engine/hooks2.c \
			src/engine/graphic/background.c \
			src/engine/graphic/lines.c \

libft/libft.a:
	make -C libft

minilibx/build/libmlx42.a:
	cmake minilibx -B minilibx/build && make -C minilibx/build -j4

outer_clean:
	make -C libft clean
	make -C minilibx/build clean

outer_fclean:
	make -C libft fclean
