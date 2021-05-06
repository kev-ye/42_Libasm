/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:40:48 by kaye              #+#    #+#             */
/*   Updated: 2021/05/06 23:25:50 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>

int main(void)
{

	// ft_strlen
	// char *sl1;
	// char *sl2;
	// char *sl3;
	// char *sl1r;
	// char *sl2r;
	// char *sl3r;

	// sl1 = "Hello world";
	// sl2 = "H";
	// sl3 = "";
	// sl1r = "Hello world";
	// sl2r = "H";
	// sl3r = "";

	// printf("\033[0;36mft_strlen :\033[0m\n\n");
	// printf("%-20s (11) -> len : [\033[0;32m%zu\033[0m] | [\033[0;32mft_strlen\033[0m]\n", "sl1  : [hello word]", ft_strlen(sl1));
	// printf("%-20s (11) -> len : [\033[0;33m%zu\033[0m] | [\033[0;33mstrlen\033[0m]\n", "sl1r : [hello word]", strlen(sl1r));
	// printf("%-20s (1)  -> len : [\033[0;32m%zu\033[0m]  | [\033[0;32mft_strlen\033[0m]\n", "sl2  : [H]", ft_strlen(sl2));
	// printf("%-20s (1)  -> len : [\033[0;33m%zu\033[0m]  | [\033[0;33mstrlen\033[0m]\n", "sl2r : [H]", strlen(sl2r));
	// printf("%-20s (0)  -> len : [\033[0;32m%zu\033[0m]  | [\033[0;32mft_strlen\033[0m]\n", "sl3  : []", ft_strlen(sl3));
	// printf("%-20s (0)  -> len : [\033[0;33m%zu\033[0m]  | [\033[0;33mstrlen\033[0m]\n", "sl3r : []", strlen(sl3r));

	// // ft_strcpy
	// char dst[20];
	// char dstr[20];
	// char *ret;
	// char *retr;
	// char *src;
	// char *srcr;

	// src = "hello world";
	// srcr = "hello world";
	// ret = ft_strcpy(dst, src);
	// printf("\033[0;36m\nft_strcpy :\033[0m\n\n");
	// printf("dst  [20bytes] - src  [hello world] -> dst  : \033[0;32m%s\033[0m src  : [\033[0;32m%s\033[0m] | return : [\033[0;32m%s\033[0m] | \033[0;32mft_strcpy\033[0m\n", dst, src, ret);
	// retr = strcpy(dstr, srcr);
	// printf("dstr [20bytes] - srcr [hello world] -> dstr : \033[0;33m%s\033[0m srcr : [\033[0;33m%s\033[0m] | return : [\033[0;33m%s\033[0m] | \033[0;33mstrcpy\033[0\n", dstr, srcr, retr);	

	// // ft_strcmp
	// printf("\033[0;36m\nft_strcmp :\033[0m\n\n");
	// char *s1 = "abc";
	// char *s2 = "abb";
	// int resu;
	// int resu2;

	// resu = ft_strcmp(s1, s2);
	// resu2 = ft_strcmp(s2, s1);
	// printf("resu s1 - s2 : %d\n", resu);
	// printf("resu2 s2 - s1 : %d\n", resu2);
	// printf("s1 : %s\n", s1);
	// printf("s2 : %s\n", s2);

	// ft_write
	// int w1;
	// int w2;
	// int w3;
	// int w1r;
	// int w2r;
	// int w3r;

	// printf("\033[0;36m\nft_write :\033[0m\n\n");
	// printf("fd [1] - buf [Hello world] - nbytes [11]\n");
    // w1 = ft_write(1, "Hello world", 11);
	// printf(" -> return value : [\033[0;32m%d\033[0m] | \033[0;32mft_write\033[0m\n", w1);
	// w1r = write(1, "Hello world", 11);
	// printf(" -> return value : [\033[0;33m%d\033[0m] | \033[0;33mwrite\033[0m\n", w1r);
	// printf("\n");
	// printf("fd [1] - buf [Hello world] - nbytes [1]\n");
	// w2 = write(1, "Hello world", 1);
	// printf(" -> return value : [\033[0;32m%d\033[0m] | \033[0;32mft_write\033[0m\n", w2);
	// w2r = ft_write(1, "Hello world", 1);
	// printf(" -> return value : [\033[0;33m%d\033[0m] | \033[0;33mwrite\033[0m\n", w2r);
	// printf("\n");
	// printf("fd [1] - buf [Hello world] - nbytes [0]\n");
	// w3 = ft_write(1, "Hello world", 0);
	// printf(" -> return value : [\033[0;32m%d\033[0m] | \033[0;32mft_write\033[0m\n", w3);
	// w3r = write(1, "Hello world", 0);
	// printf(" -> return value : [\033[0;33m%d\033[0m] | \033[0;33mwrite\033[0m\n", w3r);
	// printf("\n");

	// int fd;
	// errno = 0;
	// fd = open("", O_RDONLY);
	// printf("open :\nerrno : %d - return : %d\n", errno, fd);
	// if (errno != 0)
	// 	perror("");

	
	// int wte;
	// errno = 0;
	// wte = ft_write(1, "hello", -1);
	// printf("\nmy write :\nerrno : %d - return : %d\n", errno, wte);
	// if (errno != 0)
	// 	perror("");


	// int wte2;
	// errno = 0;
	// wte2 = write(1, "hello", -1);
	// printf("\nreal write :\nerrno : %d - return : %d\n", errno, wte2);
	// if (errno != 0)
	// 	perror("");

	// ft_read
	// int r1;
	// int fd1;
	// char buf1[1024];
	// int r1r;
	// int fd1r;
	// char buf1r[1024];

	// fd1 = open("./src/ft_read.s", O_RDONLY);
	// fd1r = open("./src/ft_read.s", O_RDONLY);
	// if (fd1 == -1 || fd1r == -1)
	// {
	// 	printf("open error\n");
	// 	exit(1);
	// }
	// printf("\033[0;36m\nft_read :\033[0m\n\n");
	// r1 = ft_read(fd1, buf1, 10);
	// printf("file content (first 10 caracter) -> [\033[0;32m%s\033[0m] | return : [\033[0;32m%d\033[0m] | [\033[0;32mft_read\033[0m]\n", buf1, r1);
	// r1r = read(fd1r, buf1r, 10);
	// printf("file content (first 10 caracter) -> [\033[0;33m%s\033[0m] | return : [\033[0;33m%d\033[0m] | [\033[0;33mread\033[0m]\n", buf1r, r1r);
	// close(fd1);
	// close(fd1r);

	// int fd2;
	// errno = 0;
	// fd2 = open("", O_RDONLY);
	// printf("open :\nerrno : %d - return : %d\n", errno, fd2);
	// if (errno != 0)
	// 	perror("");

	
	// int rd;
	// errno = 0;
	// rd = ft_read(-1, "hello", 1);
	// printf("\nmy read :\nerrno : %d - return : %d\n", errno, rd);
	// if (errno != 0)
	// 	perror("");


	// int rd2;
	// errno = 0;
	// rd2 = read(-1, "hello", 1);
	// printf("\nreal read :\nerrno : %d - return : %d\n", errno, rd2);
	// if (errno != 0)
	// 	perror("");

	// char *s;

	// s = ft_strdup("test");
	// printf("%s\n", s);
	// free(s);

	char *s;

	s = ft_strdup("test");
	printf("%s\n", s);
	free(s);

	return (0);
}