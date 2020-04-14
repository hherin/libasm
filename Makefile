NAME	=		libasm.a
CC		=		gcc
ASM		=		nasm
ASFLAG	=		-fmacho64
RM		=		rm -rf
SRC		=		./src/ft_strlen.asm\
				./src/ft_strcpy.asm\
				./src/ft_write.asm\
				./src/ft_read.asm\
				./src/ft_strdup.asm\
				./src/ft_strcmp.asm
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