.PHONY	= all clean fclean re bonus

NAME	= libasm.a
CC		= clang
CFLAGS	= -Wall -Wextra -Werror

SRCS	= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
B_SRCS	= ft_list_push_front.s

OBJSDIR	= obj
# OBJS	= $(addprefix ${OBJSDIR}/, ${SRCS:%.s=%.o})
OBJS	= $(addprefix ${OBJSDIR}/, ${B_SRCS:%.s=%.o})


all: $(NAME)

$(NAME): ${OBJSDIR} ${OBJS}
	ar rcs $(NAME) $(OBJS)

${OBJSDIR}:
	mkdir -p $@

${OBJSDIR}/%.o: %.s
	nasm -g -felf64 -o $@ $<

clean:
	rm -rf ${OBJSDIR}

fclean: clean
	rm -f ${NAME}
	rm a.out

re: fclean all


# Extra receipts
exe:
	clang $(CFLAGS) main.c -L. -lasm

bonus:
	clang $(CFLAGS) main_bonus.c -L. -lasm

diss:
	gcc -S -O0 -masm=intel -o disassembledCode.s main.c

val:
	clang -g $(CFLAGS) main.c -L. -lasm
	valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out

gdb:
	gdb -x startup.gdb a.out

