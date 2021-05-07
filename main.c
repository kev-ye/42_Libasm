/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:40:48 by kaye              #+#    #+#             */
/*   Updated: 2021/05/07 17:24:23 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int 	ft_strlen_test(char *src)
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
		printf("\033[1;31mResult of ft_strlen and strlen are not equal\033[0m\n");
		return (0);
	}
	printf("\033[1;32mft_strlen PASS\033[0m\n");
	return (1);
}

static int 	ft_strcpy_test(char *dst, char *src)
{
	char *my;
	char *rl;

	if (!dst || !src)
	{
		printf("\033[1;33mdst and src can't be NULL\033[0m\n");
		return (1);
	}
	my = ft_strcpy(dst, src);
	rl = strcpy(dst, src);
	if (strcmp(my, rl) != 0)
	{
		printf("\033[1;31mResult of ft_strcpy and strcpy are not equal\033[0m\n");
		return (0);
	}
	printf("\033[1;32mft_strcpy PASS\033[0m\n");
	return (1);
}

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
		printf("\033[1;31mResult of ft_strcmp and strcmp are not equal\033[0m\n");
		return (0);
	}
	printf("\033[1;32mft_strcmp PASS\033[0m\n");
	return (1);
}

static int 	ft_write_test(int fd1, int fd2, char *buf1, char *buf2, int nbyte)
{
	int my;
	int rl;

	errno = 0;
	my = ft_write(fd1, buf1, nbyte);
	printf("\n");
	printf("Errno value : %d", errno);
	if (errno != 0)
		perror("My :");
	printf("\n");
	errno = 0;
	rl = write(fd2, buf2, nbyte);
	printf("\n");
	printf("Errno value : %d", errno);
	if (errno != 0)
		perror("Rl :");
	printf("\n");
	if (my != rl)
	{
		printf("\033[1;31mResult of ft_write and write are not equal\033[0m\n");
		return (0);
	}
	printf("\033[1;32mft_write PASS\033[0m\n");
	return (1);
}

static int 	ft_read_test(int fd1, int fd2, char *buf1, char *buf2, int nbyte)
{
	int my;
	int rl;

	if (buf1 && buf2)
	{
		bzero(buf1, nbyte);
		bzero(buf2, nbyte);
	}
	errno = 0;
	my = ft_read(fd1, buf1, nbyte);
	buf1[nbyte] = '\0';
	printf("Errno value : %d", errno);
	if (errno != 0)
		perror("My :");
	printf("\n");
	errno = 0;
	rl = ft_read(fd2, buf2, nbyte);
	buf2[nbyte] = '\0';
	printf("Errno value : %d", errno);
	if (errno != 0)
		perror("Rl :");
	printf("\n");
	if (my != rl || ((buf1 && buf2) && strcmp(buf1, buf2) != 0))
	{
		printf("\033[1;31mResult of ft_read and read are not equal\033[0m\n");
		return (0);
	}
	printf("\033[1;32mft_read PASS\033[0m\n");
	return (1);
}

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
		printf("\033[1;31mResult of ft_strdup and strdup are not equal\033[0m\n");
		return (0);
	}
	free(my);
	free(rl);
	printf("\033[1;32mft_strdup PASS\033[0m\n");
	return (1);
}

int main(void)
{
	char dst_for_cpy[20];
	char buf_for_read1[20];
	char buf_for_read2[20];
	int fd1;
	int fd2;

	fd1 = open("./src/ft_read.s", O_RDONLY);
	fd2 = open("./src/ft_read.s", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		printf("open failed\n");
		exit(1);
	}
	printf("\033[1;36mMandatory part :\033[0m\n\n");
	printf("\033[1;35mft_strlen :\033[0m\n");
	ft_strlen_test("test");
	printf("\033[1;35mft_strcpy :\033[0m\n");
	ft_strcpy_test(dst_for_cpy, "test");
	printf("\033[1;35mft_strcmp :\033[0m\n");
	ft_strcmp_test("str1", "str2");
	printf("\033[1;35mft_write :\033[0m\n");
	ft_write_test(1, 1, "test", "test", 4);
	printf("\033[1;35mft_read :\033[0m\n");
	ft_read_test(fd1, fd2, buf_for_read1, buf_for_read2, 10);
	close(fd1);
	close(fd2);
	printf("\033[1;35mft_strdup :\033[0m\n");
	ft_strdup_test("test");
	return (0);
}