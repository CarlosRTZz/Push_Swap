NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INC_DIR = -I includes
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS =	main.c							\
		utils.c							\
		utils2.c						\
		check_stack.c					\
		sort.c							\
		instructions/push.c				\
		instructions/reverse_rotate.c	\
		instructions/rotate.c			\
		instructions/swap.c				\
		stack.c							\

OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.c=%.o})

LIBFT_PATH = libft
LIBFT_LIB = ${LIBFT_PATH}/libft.a
LIBFT_INC = ${LIBFT_PATH}

all: ${NAME}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} ${INC_DIR} -I ${LIBFT_INC} -c $< -o $@

${NAME}: ${OBJS}
	@make -C ${LIBFT_PATH}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} -o ${NAME}

clean:
	@make clean -C ${LIBFT_PATH}
	${RM} ${OBJS_DIR}

fclean:	clean
	@make fclean -C ${LIBFT_PATH}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re