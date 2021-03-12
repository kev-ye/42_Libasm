# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 17:29:25 by kaye              #+#    #+#              #
#    Updated: 2021/03/11 17:29:28 by kaye             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION



# DIRECTORIES

BUILD	:= .build
SRC		:= src

# FILES

NAME	:= libasm.a


$(NAME) : 

all : $(NAME)

clean :

fclean : clean

re : fclean all

.PHONY : all clean fclean re