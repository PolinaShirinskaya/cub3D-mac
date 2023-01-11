NAME = libft.a

SRCS = 	ft_atoi.c		ft_bzero.c		ft_calloc.c \
		ft_isalnum.c	ft_isalpha.c	ft_isascii.c \
		ft_isdigit.c	ft_isprint.c	ft_itoa.c \
		ft_memchr.c		ft_memcmp.c		ft_memcpy.c \
		ft_memmove.c	ft_memset.c		ft_putchar_fd.c \
		ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr_fd.c \
		ft_split.c		ft_strchr.c		ft_strdup.c \
		ft_striteri.c	ft_strjoin.c	ft_strlcat.c \
		ft_strlcpy.c	ft_strlen.c		ft_strmapi.c \
		ft_strncmp.c	ft_strnstr.c	ft_strrchr.c \
		ft_strtrim.c	ft_substr.c		ft_tolower.c \
		ft_toupper.c	ft_strcmp.c		ft_gnl_sh.c \
		ft_lstadd_back.c ft_lstsize.c	ft_lstnew.c\
		ft_putspl_fd.c	ft_splfree.c	ft_lstclear.c \
		calloc_two_array_char.c malloc_two_array_char.c \
		size_two_array_char.c	free_two_array_char.c \
		ft_str_isdigit.c

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

LIB = ar rcs

OBJ = ${SRCS:.c=.o}

CC = gcc

all : ${NAME}

${NAME} : ${OBJ} Makefile libft.h
	${LIB} ${NAME} ${OBJ}

${OBJ} : ${SRCS} libft.h Makefile
	${CC} ${CFLAGS} ${SRCS} -c -I.

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : clean fclean all re
