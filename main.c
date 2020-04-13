/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 14:35:24 by heleneherin       #+#    #+#             */
/*   Updated: 2020/04/13 11:01:28 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern size_t ft_strlen(char *s);
extern char *ft_strcpy(char *dest, char *src);
extern int ft_strcmp(const char *s1, const char *s2);

int main(void)
{
	char s[] = "salut";
	char s2[] = "biquette";
	char s3[] = "";

	printf("---STRLEN---\n");
	printf("HOME %zu\n", ft_strlen(s2));
	printf("FUNC %lu\n", strlen(s2));
	printf("HOME %zu\n", ft_strlen(s));
	printf("FUNC %lu\n", strlen(s));
	printf("HOME %zu\n", ft_strlen(s3));
	printf("FUNC %lu\n", strlen(s3));

	printf("\n---STRCPY---\n");
	char *s4= malloc(sizeof(char) * 10);
	char *s5=malloc(sizeof(char) * 1);
	printf("HOME %s/%s\n", ft_strcpy(s4, s), s);
	printf("FUNC %s/%s\n", strcpy(s4, s), s);
	printf("HOME %s/%s\n", ft_strcpy(s5, s2), s2);
	printf("FUNC %s/%s\n", strcpy(s5, s2), s2);
	free(s4);
	free(s5);

	printf("\n---STRCMP---\n");
	char *a = "a";
	char *b = "";
	char *c = "b";
	printf("HOME %d\n", ft_strcmp(a, b));
	printf("FUNC %d\n", strcmp(a, b));
	printf("HOME %d\n", ft_strcmp(a, c));
	printf("FUNC %d\n", strcmp(a, c));
	printf("HOME %d\n", ft_strcmp(c, b));
	printf("FUNC %d\n", strcmp(c, b));
	return (0);
}