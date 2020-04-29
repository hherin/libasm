/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 14:35:24 by heleneherin       #+#    #+#             */
/*   Updated: 2020/04/29 09:41:48 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
extern size_t ft_strlen(char *s);
extern char *ft_strcpy(char *dest, char *src);
extern int ft_strcmp(char *s1, char *s2);
extern ssize_t ft_write(int fd, void *buf, size_t size);
extern ssize_t ft_read(int fd, void *buf, size_t nbyte);
extern char *ft_strdup(const char *s1);
extern int	ft_atoi_base(char *str, char *base);

int main(void)
{
	char *s = "salut";
	char *s2 = "biquette";
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
	// printf("	HOME %zu\n", ft_write(1, s, 2));
	// printf("	func %zu\n", write(1, s, 2));

	// printf("	HOME %zu\n", ft_write(1, s, 3));
	// printf("	func %zu\n", write(1, s, 3));

	// printf("	HOME %zu\n", ft_write(1, s, 0));
	// printf("	func %zu\n", write(1, s, 0));

	// printf("	HOME %zd - errno %d\n", ft_write(-1, s, 3), errno);
	// printf("	func %zd - errno %d\n", write(-1, s, 3), errno);

	// printf("	HOME %zd - errno %d\n", ft_write(1, NULL, 5), errno);
	// printf("	func %zd - errno %d\n", write(1, NULL, 5), errno);

	// printf("	HOME %zd - errno %d\n", ft_write(-1, NULL, 5), errno);
	// printf("	func %zd - errno %d\n", write(-1, NULL, 5), errno);

	// printf("	HOME %zd - errno %d\n", ft_write(1, NULL, -1), errno);
	// printf("	func %zd - errno %d\n", write(1, NULL, -1), errno);

	printf("\n---READ---\n");
	char buf[100];
	char buf2[100];
	printf("	HOME %zu\n", ft_read(1, buf, 3));
	printf("outhome %s\n", buf);
	printf("	func %zu\n", read(1, buf2, 3));
	printf("outfunc %s\n", buf);

	// printf("\n---STRDUP---\n");
	// printf("HOME %s\n", ft_strdup("salut"));
	// printf("HOME %s\n", ft_strdup("salut ca va"));
	// printf("HOME %s\n", ft_strdup(""));

	// printf("\n---ATOI_BASE---\n");
	// printf("Base 10 : %d\n", ft_atoi_base("123", "0123456789"));
	// printf("Base 2 : %d\n", ft_atoi_base("1111011", "01"));
	// printf("Base 16 : %d\n", ft_atoi_base("7B", "0123456789ABCDEF"));
	// printf("EMPTY %d\n", ft_atoi_base("", "01"));

	return (0);
}