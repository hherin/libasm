/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 14:35:24 by heleneherin       #+#    #+#             */
/*   Updated: 2020/05/17 11:36:44 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>


extern size_t ft_strlen(char *s);
extern char *ft_strcpy(char *dest, char *src);
extern int ft_strcmp(char *s1, char *s2);
extern ssize_t ft_write(int fd, void *buf, size_t size);
extern ssize_t ft_read(int fd, void *buf, size_t nbyte);
extern char *ft_strdup(const char *s1);
extern int	ft_atoi_base(char *str, char *base);

typedef struct s_list
{
	char *data;
	struct s_list *next;
} t_list;

void print_list(t_list **begin_list)
{
	t_list *link;

	link = *begin_list;
	printf("[%s]", link->data);
	while (link->next)
	{
		link = link->next;
		printf(" -> [%s]", link->data);
	}
	printf("\n");
}

void ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);
void ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_swap(char **s1, char **s2);

int main(void)
{
	// char *s = "salut";
	// char *s2 = "biquette";
	// char *s3 = "";

	// printf("---STRLEN---\n");
	// printf("HOME %zu\n", ft_strlen(s2));
	// printf("func %lu\n", strlen(s2));
	// printf("HOME %zu\n", ft_strlen(s));
	// printf("func %lu\n", strlen(s));
	// printf("HOME %zu\n", ft_strlen(s3));
	// printf("func %lu\n", strlen(s3));

	// printf("\n---STRCPY---\n");
	// char s4[10];
	// char s5[10];
	// printf("HOME %s/%s\n", ft_strcpy(s4, s), s);
	// printf("func %s/%s\n", strcpy(s4, s), s);
	// printf("HOME %s/%s\n", ft_strcpy(s5, s2), s2);
	// printf("func %s/%s\n", strcpy(s5, s2), s2);

	// printf("\n---STRCMP---\n");
	// char *a = "act";
	// char *b = "acde";
	// char *c = "";
	// printf("HOME %d\n", ft_strcmp(a, b));
	// printf("func %d\n", strcmp(a, b));
	// printf("HOME %d\n", ft_strcmp(c, b));
	// printf("func %d\n", strcmp(c, b));
	// printf("HOME %d\n", ft_strcmp(a, c));
	// printf("func %d\n", strcmp(a, c));
	// printf("HOME %d\n", ft_strcmp(s2, s));
	// printf("func %d\n", strcmp(s2, s));

	// printf("\n---WRITE---\n");
	//printf("	HOME %zu\n", ft_write(1, s, 2));
	 //printf("	func %zu\n", write(1, s, 2));

	// printf("	HOME %zu\n", ft_write(1, s, 3));
	//printf("	func %zu\n", write(1, s, 3));

	// printf("	HOME %zu\n", ft_write(1, s, 0));
	// printf("	func %zu\n", write(1, s, 0));

	 //printf("	HOME %zd - errno %d\n", ft_write(-1, s, 3), errno);
	// printf("	func %zd - errno %d\n", write(-1, s, 3), errno);

	// printf("	HOME %zd - errno %d\n", ft_write(1, NULL, 5), errno);
	// printf("	func %zd - errno %d\n", write(1, NULL, 5), errno);

	// printf("	HOME %zd - errno %d\n", ft_write(-1, NULL, 5), errno);
	// printf("	func %zd - errno %d\n", write(-1, NULL, 5), errno);

	// printf("	HOME %zd - errno %d\n", ft_write(1, NULL, -1), errno);
	// printf("	func %zd - errno %d\n", write(1, NULL, -1), errno);

	// printf("\n---READ---\n");
	// char buf[100];
	// char buf2[100];
	// int fd1 = open("./src/ft_strlen.asm", O_RDONLY);
	// int nb = ft_read(-1, buf, 3);
	// printf("HOME : ret %zd / %s | erno %d\n", ft_read(-1, buf, 3), buf, errno);
	//  printf("FUNC : ret %zd / %s | erno %d\n", read(-1, buf2, 3), buf2, errno);
	// char buf3[3] = "\0";
	// char buf4[3] = "\0";
	 //int fd1 = open("./src/ft_strlen.asm", O_RDONLY);
	// printf("	HOME %zu\n%s\n", ft_read(fd1, buf3, 3), buf3);
	// printf("	func %zu\n%s\n", read(fd1, buf3, 3), buf3);
	// printf("	HOME %zu\n", ft_read(1, buf3, 3));
	// printf("outhome %s\n", buf3);
	// printf("	func %zu\n", read(1, buf4, 3));
	// printf("outfunc %s\n", buf4);

	// printf("\n---STRDUP---\n");
	// char *test1;
	// char *test2;
	 //char *dup = NULL;
	 //printf("avant %d / %s / %d\n", errno, ft_strdup(dup), errno);
	 //printf("avant %d / %s / %d\n", errno, strdup(dup), errno);
	 //printf("HOME %s %p\n", test1 = ft_strdup("salut"), &test1);
	// printf("func %s %p\n", test2 = strdup("salut"), &test2);
	 //printf("1 ");
	 //free(test1);
	// printf("2\n");
	// free(test2);
	 //printf("HOME %s\n", ft_strdup("salut ca va"));
	// printf("HOME %s\n", ft_strdup(""));

	// printf("\n---ATOI_BASE---\n");
	// printf("Base 10 : %d\n", ft_atoi_base("123", "0123456789"));
	// printf("Base 2 : %d\n", ft_atoi_base("1111011", "01"));
	// printf("Base 16 : %d\n", ft_atoi_base("7B", "0123456789ABCDEF"));
	// printf("EMPTY %d\n", ft_atoi_base("", "01"));

	 //printf("\n---LIST_PUSH_FRONT---\n");
	// t_list *elem = malloc(sizeof(t_list));
	// elem->data = ft_strdup("hello");
	// elem->next = NULL;
	 //print_list(&elem);
	// ft_list_push_front(&elem, "hello");
	// print_list(&elem);
	// ft_list_push_front(&elem, "bien");
	// print_list(&elem);

	// printf("\n---LIST_SIZE---\n");
	// t_list	*elem;
	// elem = malloc(sizeof(t_list));
	// elem = NULL;
	 //ft_list_push_front(&elem, "hey");
	 //ft_list_push_front(&elem, "comment");
	 //ft_list_push_front(&elem, "cava");
	// printf("size 1 = %d\n", ft_list_size(elem));
	// ft_list_push_front(&elem, "yoyo");
	// ft_list_push_front(&elem, "yoyo");
	// printf("size 2 = %d\n", ft_list_size(elem));

	// printf("\n---LIST_SORT---\n");
	// t_list *new = malloc(sizeof(t_list));
	// new->data = strdup("5");
	// new->next = malloc(sizeof(t_list));
	// new->next->data = strdup("1");
	// new->next->next = malloc(sizeof(t_list));
	// new->next->next->data = strdup("3");
	// new->next->next->next = malloc(sizeof(t_list));
	// new->next->next->next->data = strdup("2");
	// new->next->next->next->next = malloc(sizeof(t_list));
	// new->next->next->next->next->data = strdup("4");
	// new->next->next->next->next->next = NULL;
	// print_list(&new);
	// ft_list_sort(&new, &ft_strcmp);
	// print_list(&new);
	// t_list *nul = NULL;
	// ft_list_sort(&nul, &ft_strcmp);


	return (0);
}