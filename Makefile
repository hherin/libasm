NAME	=		libasm.a
CC		=		clang
ASM		=		nasm
ASFLAG	=		-felf64
RM		=		rm -rf
SRC		=		./src/ft_strlen.s\
				./src/ft_strcpy.asm\
				./src/ft_write.s\
				./src/ft_read.s\
				./src/ft_strdup.asm\
				./src/ft_atoi_base.asm\
				./src/ft_strcmp.asm\
				./src/ft_list_size.asm\
				./src/ft_list_sort.asm\
				./src/ft_list_push_front.asm

OBJ		=		${SRC:.asm=.o}

all: 			${NAME}

${NAME}:		${OBJ}
				ar rc ${NAME} ${OBJ}
				ranlib ${NAME}

%.o:			%.asm
				${ASM} ${ASFLAG} $<

clean:
				${RM} src/*.o

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re