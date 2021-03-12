# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 17:29:25 by kaye              #+#    #+#              #
#    Updated: 2021/03/12 18:39:58 by kaye             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION

NA		= nasm
NAFLAG	= -f macho64

# DIRECTORIES

BUILD		:= .build
INC_DIR		:= inc
SRC_DIR		:= src
OBJ_DIR		:= $(BUILD)/obj
DIRS		:= $(OBJ_DIR)

# FILES

NAME	:= libasm.a

# MAKEFILE

$(NAME) : 

all : $(NAME)

clean :

fclean : clean

re : fclean all

.PHONY : all clean fclean re