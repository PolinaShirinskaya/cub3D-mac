UNAME_S			=	$(shell uname -s)

NAME			=	cub3D

CC				=	gcc

LIBFT			=	./libft/libft.a

ifeq ($(UNAME_S), Linux)
	CFLAGS		= 	-Wall -Wextra -Werror -D LINUX -I./include -I../mlx_linux
	LINKLIB		=	-L libft/ -lft -lm -L../mlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
else
	CFLAGS		=	-Wall -Wextra -Werror -I./include -g -ggdb3
	LINKLIB		=	-L libft/ -lft -framework OpenGL -framework AppKit -lm -lmlx
endif

HEADER_DIR		=	includes

HEADER_MAIN		=	cub3d.h
HEADER_DEFS		=	defines.h
HEADER_ERROR	=	error_mess.h
HEADER_KEYS		=	keycodes.h


HEADER			=	$(addprefix $(HEADER_DIR)/,$(HEADER_MAIN))
HEADER			+=	$(addprefix $(HEADER_DIR)/,$(HEADER_DEFS))
HEADER			+=	$(addprefix $(HEADER_DIR)/,$(HEADER_ERROR))
HEADER			+=	$(addprefix $(HEADER_DIR)/,$(HEADER_KEYS))


SRCS_DIR		=	srcs
SRCS_LIST		=	main.c \
					cub3d.c \
					keys_1.c \
					keys_2.c \
					rendering_1.c \
					rendering_2.c \
					end_program.c \
					init.c \
					parse_file_to_tokens.c \
					tokens_utils.c \
					tokens.c \
					parse_textures.c \
					parse_textures_wall.c \
					parse_textures_floor_ceil.c \
					parse_map_1.c \
					parse_map_2.c \
					utils.c

SRCS			=	$(addprefix $(SRCS_DIR)/,$(SRCS_LIST))

OBJS_DIR		=	objs
OBJS			=	$(addprefix $(OBJS_DIR)/,$(SRCS_LIST:.c=.o))

NORMAL			=	\033[0m
RED				=	\033[1;31m
GREEN			=	\033[1;32m
YELLOW			=	\033[1;33m
BLUE			=	\033[1;34m
CYAN			=	\033[1;36m
WHITE			=	\033[1;37m


all : $(OBJS_DIR) $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(HEADER) Makefile
	@$(CC) $(OBJS) $(CFLAGS) -o $@ $(LINKLIB)
	@echo "$(GREEN)Project succesfully compiled$(NORMAL)"

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) -O3 -c $< -o $@ -I./$(HEADER_DIR)
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(OBJS_DIR) :
	@mkdir -p objs
	@echo "$(CYAN)Creating directory for objects file:$(WHITE) $(GREEN)[Done]$(NORMAL)"

$(LIBFT) : ./libft/Makefile ./libft/libft.h ./libft/*.c
	@make -C ./libft
	@echo "$(CYAN)'libft' was compiled$(NORMAL)"

clean :
	@make clean -C ./libft
	@rm -rf $(OBJS_DIR)
	@echo "$(YELLOW)Removing objects files$(WHITE) --> *.o --> $(GREEN)[Done]$(NORMAL)"

fclean : clean
	@make fclean -C ./libft
	@rm -rf $(NAME)
	@echo "$(YELLOW)Removing perfoming file$(WHITE) --> $(NAME) --> $(GREEN)[Done]$(NORMAL)"

re : fclean all

.PHONY: all clean fclean re bonus