NAME	=		libasm.a
CC		=		gcc
ASM		=		nasm
ASFLAG	=		-f elf64
RM		=		rm -rf
SRC		=		./src/ft_strlen.s\
				./src/ft_strcpy.s\
				./src/ft_write.s\
				./src/ft_read.s\
				./src/ft_strdup.s\
				./src/ft_atoi_base.s\
				./src/ft_strcmp.s\
				./src/ft_list_size.s\
				./src/ft_list_sort.s\
				./src/ft_list_push_front.s

OBJ		=		${SRC:.s=.o}

all: 			${NAME}

${NAME}:		${OBJ}
				ar rc ${NAME} ${OBJ}
				ranlib ${NAME}

%.o:			%.s
				${ASM} ${ASFLAG} $<

clean:
				${RM} src/*.o *.o 

fclean:			clean
				${RM} ${NAME} a.out

re:				fclean all

.PHONY:			all clean fclean re