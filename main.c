/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 14:35:24 by heleneherin       #+#    #+#             */
/*   Updated: 2020/04/14 14:57:00 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

extern size_t ft_strlen(char *s);
extern char *ft_strcpy(char *dest, char *src);
extern int ft_strcmp(char *s1, char *s2);
extern size_t ft_write(int fd, void *buf, size_t size);
ssize_t ft_read(int fd, void *buf, size_t nbyte);
char *ft_strdup(const char *s1);

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
	// char *s4= malloc(sizeof(char) * 10);
	// char *s5=malloc(sizeof(char) * 1);
	// printf("HOME %s/%s\n", ft_strcpy(s4, s), s);
	// printf("func %s/%s\n", strcpy(s4, s), s);
	// printf("HOME %s/%s\n", ft_strcpy(s5, s2), s2);
	// printf("func %s/%s\n", strcpy(s5, s2), s2);
	// free(s4);
	// free(s5);

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

	// printf("\n---READ---\n");
	// char buf[100];
	// char buf2[100];
	// printf("	HOME %zu\n", ft_read(1, buf, 3));
	// printf("outhome %s\n", buf);
	// printf("	func %zu\n", read(1, buf2, 3));
	// printf("outfunc %s\n", buf);

	printf("\n---STRDUP---\n");
	printf("HOME %s\n", ft_strdup("salut"));
	printf("HOME %s\n", ft_strdup("salut ca va"));
	printf("HOME %s\n", ft_strdup(""));

	return (0);
}