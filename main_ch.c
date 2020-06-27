#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <assert.h>
#include <fcntl.h>

int				ft_strlen(const char *s1);
ssize_t 		ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t 		ft_read(int fildes, const void *buf, size_t nbyte);
int				ft_strcmp(const char *str, const char *str2);
char			*ft_strcpy(char * dst, const char * src);
char			*ft_strdup(const char *s1);

void	introduce_test(char *str)
{
	setbuf(stdout, NULL);
	char stars[] = "*********************************************************"\
					"**********************";
	if (!str)
	{
		printf("problem with introduce_test\n");
		exit(1);
	}
	printf("\n\033[32;m%s\n\tTESTS FOR: %s\n%s\n\033[0m", stars, str, stars);
}

void	end_test(void)
{
	char stars[] = "------------";
	printf("\033[32;m\n%s\n|  [ OK ]  |\n", stars);
	printf("%s\n\n\n\033[0m", stars);
}

void	ko_test(void)
{
	char stars[] = "------------";
	printf("\033[31;m\n%s\n|  [ KO ]  |\n", stars);
	printf("%s\n\n\n\033[0m", stars);
}

int get_number_char_written(int fd)
{
	char	buf;
	int		i;

	i = 0;
	while (read(fd, &buf, 1) != 0)
		i++;
	return (i);
}

int	main(int argc __attribute__((unused)), char *av[] __attribute__((unused)))
{
	char	buf[5] = "hey!\n";
	char	str_copy[100] = {'\0'};

	char	*str;
	char 	*str1;
	char 	*str2;
	char 	*str3;
	char	*str_empty;

	int		res_real;
	int		res;
	int		errno_copy;
	int		fd1;
	int		fd2;

	if((fd1 = open("./dummy_file1", O_CREAT | O_RDWR | O_TRUNC, 0644)) == -1 \
	|| (fd2 = open("./dummy_file2", O_CREAT | O_RDWR | O_TRUNC, 0644)) == -1)
	{
		printf("failed to Open dummy_file1\n");
		exit(1);
	}
	str = strdup("A.");
	str1= strdup("B.");
	str2 = strdup("Charmstr");
	str3 = strdup("D.");
	str_empty = strdup("");
	if (!str || !str1 || !str2 || !str3)
	{
		printf("malloc failure\n");
		return (0);
	}

/*
**	test for ft_strlen()
*/
	introduce_test("ft_strlen()");
	//assert(ft_strlen(NULL) == 0);
	//printf("input: [NULL], output = 0\n");
	assert(ft_strlen("") == 0);
	printf("input: [""], output = 0\n");
	assert(ft_strlen(str2) == (int)strlen(str2));
	printf("input: [%s], output = %d\n", str2, ft_strlen(str2));
	assert(ft_strlen(str) == (int)strlen(str));
	printf("input: [%s], output = %d\n", str, ft_strlen(str));
	end_test();
/*
**	test for ft_strcpy()
*/
	introduce_test("ft_strcpy()");
	assert(strcmp(ft_strcpy(str3, str1), str1) == 0);
	printf("note: dest_string array is 100 wide\n");
	assert(strcmp(ft_strcpy(str_copy, str2), str2) == 0);
	printf("copy of [%s] in str_copy:\n        [%s]\n", str2, str_copy);
	assert(strcmp(ft_strcpy(str_copy, str1), str1) == 0);
	printf("copy of [%s] in str_copy:\n        [%s]\n", str1, str_copy);
	assert(strcmp(ft_strcpy(str_copy, str2), str2) == 0);
	printf("copy of [%s] in str_copy:\n        [%s]\n", str2, str_copy);
	end_test();

/*
**	test for ft_strcmp()
*/
	introduce_test("ft_strcmp()");
	assert(strcmp("", "") == ft_strcmp("", ""));
	printf("compare: [%s] and [%s], OK\n", "", "");
	assert(strcmp(str, "") == ft_strcmp(str, ""));
	printf("compare: [%s] and [%s], OK\n", str, "");
	assert(strcmp(str, str) == ft_strcmp(str, str));
	printf("compare: [%s] and [%s], OK\n", str, str);
	assert(strcmp(str, str2) == ft_strcmp(str, str2));
	printf("compare: [%s] and [%s], OK\n", str, str2);
	end_test();

/*
**	test for ft_write()
*/
	introduce_test("ft_write()");
	printf("test 1:\n");
	res = ft_write(-1, buf, 5);
	errno_copy = errno;
	res_real = write(-1, buf, 5);
	assert(res_real == res);
	assert(errno_copy == errno);
	printf("ft_write: errno is [%d], and ft_write result is [%d]\n", errno_copy, res);
	printf("   write: errno is [%d], and    write result is [%d]\n", errno, res_real);
	lseek(fd1, 0, SEEK_SET);
	lseek(fd2, 0, SEEK_SET);
	assert(res_real == res);
	assert(errno_copy == errno);
	assert(get_number_char_written(fd1) == get_number_char_written(fd2));
	errno = 0;


	printf("\ntest 2:\n");
	res = ft_write(fd1, NULL, 5);
	errno_copy = errno;
	res_real = write(fd2, NULL, 5);
	assert(res_real == res);
	assert(errno_copy == errno);
	printf("ft_write: errno is [%d], and ft_write result is [%d]\n", errno_copy, res);
	printf("   write: errno is [%d], and    write result is [%d]\n", errno, res_real);
	lseek(fd1, 0, SEEK_SET);
	lseek(fd2, 0, SEEK_SET);
	assert(res_real == res);
	assert(errno_copy == errno);
	assert(get_number_char_written(fd1) == get_number_char_written(fd2));
	errno = 0;

	printf("\ntest 3:\n");
	res = ft_write(-1, NULL, 5);
	errno_copy = errno;
	res_real = write(-1, NULL, 5);
	assert(res_real == res);
	assert(errno_copy == errno);
	printf("ft_write: errno is [%d], and ft_write result is [%d]\n", errno_copy, res);
	printf("   write: errno is [%d], and    write result is [%d]\n", errno, res_real);
	lseek(fd1, 0, SEEK_SET);
	lseek(fd2, 0, SEEK_SET);
	assert(res_real == res);
	assert(errno_copy == errno);
	assert(get_number_char_written(fd1) == get_number_char_written(fd2));
	errno = 0;

	printf("\ntest 4:\n");
	res = ft_write(fd1, buf, 1);
	errno_copy = errno;
	res_real = write(fd2, buf, 1);
	printf("ft_write: errno is [%d], and ft_write result is [%d]\n", errno_copy, res);
	printf("   write: errno is [%d], and    write result is [%d]\n", errno, res_real);
	lseek(fd1, 0, SEEK_SET);
	lseek(fd2, 0, SEEK_SET);
	assert(res_real == res);
	assert(errno_copy == errno);
	assert(get_number_char_written(fd1) == get_number_char_written(fd2));
	errno = 0;

	printf("\ntest 5:\n");
	res = ft_write(fd1, buf, 5);
	errno_copy = errno;
	res_real = write(fd2, buf, 5);
	printf("ft_write: errno is [%d], and ft_write result is [%d]\n", errno_copy, res);
	printf("   write: errno is [%d], and    write result is [%d]\n", errno, res_real);
	lseek(fd1, 0, SEEK_SET);
	lseek(fd2, 0, SEEK_SET);
	assert(res_real == res);
	assert(errno_copy == errno);
	assert(get_number_char_written(fd1) == get_number_char_written(fd2));
	errno = 0;

	end_test();

/*
**	test for ft_read()
*/
	introduce_test("ft_read()");

	printf("test 0:\n reading 0 characters from dummy_file1\n");
	lseek(fd1, 0, SEEK_SET);
	res = ft_read(fd1, buf, 0);
	errno_copy = errno;
	lseek(fd1, 0, SEEK_SET);
	res_real = read(fd1, buf, 0);
	printf("errno is [%d], and ft_read result is [%d]\n", errno_copy, res);
	printf("errno is [%d], and    read result is [%d]\n", errno, res_real);
	assert(errno_copy == errno);
	assert(res == res_real);
	printf("OK\n\n");
	errno = 0;

	printf("test 1:\n reading 1 character from dummy_file1\n");
	lseek(fd1, 0, SEEK_SET);
	res = ft_read(fd1, buf, 1);
	errno_copy = errno;
	lseek(fd1, 0, SEEK_SET);
	res_real = read(fd1, buf, 1);
	printf("errno is [%d], and ft_read result is [%d]\n", errno_copy, res);
	printf("errno is [%d], and    read result is [%d]\n", errno, res_real);
	assert(errno_copy == errno);
	assert(res == res_real);
	printf("OK\n\n");
	errno = 0;

	printf("test2:\n reading 4 characters from dummy_file1\n");
	lseek(fd1, 0, SEEK_SET);
	res = ft_read(fd1, buf, 4);
	errno_copy = errno;
	lseek(fd1, 0, SEEK_SET);
	res_real = read(fd1, buf, 4);
	printf("errno is [%d], and ft_read result is [%d]\n", errno_copy, res);
	printf("errno is [%d], and    read result is [%d]\n", errno, res_real);
	assert(errno_copy == errno);
	assert(res == res_real);
	printf("OK\n\n");
	errno = 0;

	printf("test3:\n reading 5 characters from dummy_file1, but negative fd\n");
	lseek(fd1, 0, SEEK_SET);
	res = ft_read(-1, buf, 5);
	errno_copy = errno;
	lseek(fd1, 0, SEEK_SET);
	res_real = read(-1, buf, 5);
	printf("errno is [%d], and ft_read result is [%d]\n", errno_copy, res);
	printf("errno is [%d], and    read result is [%d]\n", errno, res_real);
	assert(errno_copy == errno);
	assert(res == res_real);
	printf("OK\n\n");
	errno = 0;

	printf("test4:\n reading 5 characters from dummy_file1, but NULL buffer\n");
	lseek(fd1, 0, SEEK_SET);
	res = ft_read(fd1, NULL, 5);
	errno_copy = errno;
	lseek(fd1, 0, SEEK_SET);
	res_real = read(fd1, NULL, 5);
	printf("errno is [%d], and ft_read result is [%d]\n", errno_copy, res);
	printf("errno is [%d], and    read result is [%d]\n", errno, res_real);
	assert(errno_copy == errno);
	assert(res == res_real);
	printf("OK\n\n");
	errno = 0;

	end_test();

/*
**	test for ft_strdup()
*/
	introduce_test("ft_strdup()");
	free(str3);
	free(str_empty);
	if (!(str3 = ft_strdup(str1)) || !(str_empty = ft_strdup("")))
	{
		printf("malloc_failure in ft_strdup\n");
		exit(1);
	}
	printf("free str_empty, then dup [%s], result: [%s]\n", "", str_empty);
	assert(strcmp(str_empty, "") == 0);
	printf("free str3, then dup [%s], result: [%s]\n", str1, str3);
	assert(strcmp(str3, str1) == 0);
	end_test();

/*
**	close files, delete dummy_files (used in tests for ft_write and ft_read)
**	and test for leaks...
*/
	close(fd1);
	close(fd2);
	system("rm dummy_file1");
	system("rm dummy_file2");
	free(str);
	free(str1);
	free(str2);
	free(str3);
	free(str_empty);
	introduce_test("LEAKS");
	sprintf(str_copy, "leaks %d", getpid());
	res = system(str_copy);
	if (!res)
		end_test();
	else
		ko_test();
	return (0);
}
