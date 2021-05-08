/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:40:48 by kaye              #+#    #+#             */
/*   Updated: 2021/05/08 21:23:22 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

/*
** FT_STRLEN
*/
static int 	ft_strlen_test(const char *src)
{
	size_t my;
	size_t rl;

	if (!src)
	{
		printf("\033[1;33msrc can't be NULL\033[0m\n");
		return (1);
	}
	my = ft_strlen(src);
	rl = strlen(src);
	if (my != rl)
	{
		printf("\033[1;31m❌  Result of ft_strlen : [%zu] and strlen : [%zu] are not equal\033[0m\n", my, rl);
		return (0);
	}
	printf("\033[1;32m✅  ft_strlen PASS\033[0m\n");
	return (1);
}

static int	ft_strlen_multi_test(void)
{
	if (!ft_strlen_test(""))
		return (0);
	if (!ft_strlen_test("a simple test"))
		return (0);
	if (!ft_strlen_test("test\nwith\tsome\vno\fprintable\rcaracter"))
		return (0);
	if (!ft_strlen_test("test with end of string\0this message does not include"))
		return (0);
	printf("\n");
	return (1);
}

/*
** FT_STRCPY
*/
static int 	ft_strcpy_test(char *dst, const char *src, int size)
{
	char *my;
	char *rl;

	if (!dst || !src)
	{
		printf("\033[1;33mdst and src can't be NULL\033[0m\n");
		return (1);
	}
	bzero(dst, size);
	my = ft_strcpy(dst, src);
	bzero(dst, size);
	rl = strcpy(dst, src);
	if (strcmp(my, rl) != 0)
	{
		printf("\033[1;31m❌  Result of ft_strcpy : [%s] and strcpy : [%s] are not equal\033[0m\n", my, rl);
		return (0);
	}
	printf("\033[1;32m✅  ft_strcpy PASS\033[0m\n");
	return (1);
}

static int	ft_strcpy_multi_test(void)
{
	char dst[100];

	if (!ft_strcpy_test(dst, "", 100))
		return (0);
	if (!ft_strcpy_test(dst, "a simple test", 100))
		return (0);
	if (!ft_strcpy_test(dst, "test\nwith\tsome\vno\fprintable\rcaracter", 100))
		return (0);
	if (!ft_strcpy_test(dst, "test with end of string\0this message does not include", 100))
		return (0);
	printf("\n");
	return (1);
}

/*
** FT_STRCMP
*/
static int 	ft_strcmp_test(char *s1, char *s2)
{
	int my;
	int rl;

	if (!s1 || !s2)
	{
		printf("\033[1;33ms1 & s2 can't be NULL\033[0m\n");
		return (1);
	}
	my = ft_strcmp(s1, s2);
	rl = strcmp(s1, s2);
	if (my != rl)
	{
		printf("\033[1;31m❌  Result of ft_strcmp : [%d] and strcmp : [%d] are not equal\033[0m\n", my, rl);
		return (0);
	}
	printf("\033[1;32m✅  ft_strcmp PASS\033[0m\n");
	return (1);
}

static int	ft_strcmp_multi_test(void)
{
	if (!ft_strcmp_test("", ""))
		return (0);
	if (!ft_strcmp_test("test", ""))
		return (0);
	if (!ft_strcmp_test("", "test"))
		return (0);
	if (!ft_strcmp_test("test", "test"))
		return (0);
	if (!ft_strcmp_test("ABC", "abc"))
		return (0);
	if (!ft_strcmp_test("abb", "abc"))
		return (0);
	if (!ft_strcmp_test("no\nprintable", "no\tprintable"))
		return (0);
	if (!ft_strcmp_test("no\nprintable2", "no\0printable2"))
		return (0);
	printf("\n");
	return (1);
}

/*
** FT_WRITE
*/
static int 	ft_write_test(int fd, char *buf, int nbyte)
{
	int my;
	int rl;
	int my_errno;
	int rl_errno;

	errno = 0;
	my = ft_write(fd, buf, nbyte);
	my_errno = errno;
	printf("\n");
	errno = 0;
	rl = write(fd, buf, nbyte);
	rl_errno = errno;
	printf("\n");
	if (my != rl || my_errno != rl_errno)
	{
		printf("\033[1;31m❌  Result of ft_write : [%d] errno : [%d] and write : [%d] errno : [%d]are not equal\033[0m\n", my, my_errno, rl, rl_errno);
		return (0);
	}
	printf("\033[1;32m✅  ft_write PASS\033[0m\n");
	return (1);
}

static int	ft_write_multi_test(void)
{
	printf("\033[1;33mNormal print test :\033[0m\n");
	if (!ft_write_test(1, "test", 4))
		return (0);
	printf("\033[1;33mErrno test :\033[0m\n");
	if (!ft_write_test(-1, "test" , 0))
		return (0);
	printf("\n");
	return (1);
}

/*
** FT_READ
*/
static int 	ft_read_test(int fd1, int fd2, char *buf1, char *buf2, int nbyte)
{
	int my;
	int rl;
	int my_errno;
	int rl_errno;

	if (buf1 && buf2)
	{
		bzero(buf1, nbyte);
		bzero(buf2, nbyte);
	}
	errno = 0;
	my = ft_read(fd1, buf1, nbyte);
	buf1[nbyte] = '\0';
	my_errno = errno;
	errno = 0;
	rl = ft_read(fd2, buf2, nbyte);
	buf2[nbyte] = '\0';
	rl_errno = errno;
	if (my != rl || my_errno != rl_errno || ((buf1 && buf2) && strcmp(buf1, buf2) != 0))
	{
		printf("\033[1;31m❌  Result of ft_read : [%d] and read : [%d] are not equal\033[0m\n", my, rl);
		return (0);
	}
	printf("\033[1;32m✅  ft_read PASS\033[0m\n");
	return (1);
}

static int	ft_read_multi_test(void)
{
	char buf_for_read1[BUFF_SIZE + 1];
	char buf_for_read2[BUFF_SIZE + 1];
	int fd1;
	int fd2;

	fd1 = open("./src/ft_read.s", O_RDONLY);
	fd2 = open("./src/ft_read.s", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		printf("open failed\n");
		exit(1);
	}
	printf("\033[1;33mNormal print test :\033[0m\n");
	if (!ft_read_test(fd1, fd2, buf_for_read1, buf_for_read2, BUFF_SIZE))
		return (0);
	printf("\033[1;33mErrno test :\033[0m\n");
	if (!ft_read_test(-111, -111, buf_for_read1, buf_for_read2, 0))
		return (0);
	close(fd1);
	close(fd2);
	printf("\n");
	return (1);
}

/*
** FT_STRDUP
*/
static int 	ft_strdup_test(char *src)
{
	char *my;
	char *rl;

	if (!src)
	{
		printf("\033[1;33msrc can't be NULL\033[0m\n");
		return (1);
	}
	my = ft_strdup(src);
	rl = strdup(src);
	if (strcmp(my, rl) != 0)
	{
		free(my);
		free(rl);
		printf("\033[1;31m❌  Result of ft_strdup and strdup are not equal\033[0m\n");
		return (0);
	}
	free(my);
	free(rl);
	printf("\033[1;32m✅  ft_strdup PASS\033[0m\n");
	return (1);
}

static int	ft_strdup_multi_test(void)
{
	if (!ft_strdup_test(""))
		return (0);
	if (!ft_strdup_test("a simple test"))
		return (0);
	if (!ft_strdup_test("test\nwith\tsome\vno\fprintable\rcaracter"))
		return (0);
	if (!ft_strdup_test("test with end of string\0this message does not include"))
		return (0);
	return (1);
}

/*
** MAIN
*/
int main(void)
{
	int mandatory;
	int check;

	mandatory = 6;
	check = 0;
	printf("\033[1;36mMandatory part :\033[0m\n\n");
	printf("\033[1;35mft_strlen :\033[0m\n");
	check += ft_strlen_multi_test();
	printf("\033[1;35mft_strcpy :\033[0m\n");
	check += ft_strcpy_multi_test();
	printf("\033[1;35mft_strcmp :\033[0m\n");
	check += ft_strcmp_multi_test();
	printf("\033[1;35mft_write :\033[0m\n");
	check += ft_write_multi_test();
	printf("\033[1;35mft_read :\033[0m\n");
	check += ft_read_multi_test();
	printf("\033[1;35mft_strdup :\033[0m\n");
	check += ft_strdup_multi_test();
	if (mandatory != check)
		printf("\033[1;31m\n❌  Mandatory failed : \033[0m%d / %d\n", check, mandatory);
	else
		printf("\033[1;32m\n✅  Mandatory PASS : \033[0m%d / %d\n", check, mandatory);
	return (0);
}