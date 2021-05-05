# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 17:29:25 by kaye              #+#    #+#              #
#    Updated: 2021/05/05 16:50:21 by kaye             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION

NA		= nasm
NAFLAG	= -f macho64
CC		= clang
CFLAG	= -Wall -Wextra -Werror -fsanitize=address
IFLAG	= -I./inc

# DIRECTORIES

BUILD		:= .build
INC_DIR		:= inc
SRC_DIR		:= src
OBJ_DIR		:= $(BUILD)/obj
DIR			:= $(OBJ_DIR)

# FILES

NAME		:= libasm.a
MAIN		:= main_test_exec
MAIN_SRC	:= main.c
SRC			:= ft_strlen.s \
			   ft_strcpy.s \
			   ft_strcmp.s \
			   ft_write.s \
			   ft_read.s \
			   ft_strdup.s
OBJ			:= $(SRC:%.s=$(OBJ_DIR)/%.o)

# COLORS

DEFAULT_COLOR	= \033[0m
BLACK_COLOR		= \033[1;30m
RED_COLOR		= \033[1;31m
GREEN_COLOR		= \033[1;32m
YELLOW_COLOR	= \033[1;33m
BLUE_COLOR		= \033[1;34m
MAGENTA_COLOR 	= \033[1;35m
CYAN_COLOR 		= \033[1;36m
WHITE_COLOR 	= \033[1;107m

# MAKEFILE

$(NAME): $(OBJ)
	@echo "Creating $(RED_COLOR) $@ $(DEFAULT_COLOR)..."
	@ar -rcs $@ $^
	@echo "$(GREEN_COLOR)Compilation $(YELLOW_COLOR)of $(RED_COLOR)$@ $(BLUE_COLOR)done$(DEFAULT_COLOR)"

$(MAIN): $(NAME)
	@echo "Creating $(RED_COLOR) $@ $(DEFAULT_COLOR)..."
	@$(CC) $(CFLAG) $(IFLAG) $(MAIN_SRC) $(NAME) -o $@
	@echo "$(GREEN_COLOR)Compilation $(YELLOW_COLOR)of $(RED_COLOR)$@ $(BLUE_COLOR)done$(DEFAULT_COLOR)"

all: $(NAME)

test: $(MAIN)

clean:
	rm -Rf $(BUILD)

fclean: clean
	rm -Rf $(NAME)
	rm -Rf $(MAIN)

re: fclean all

$(BUILD):
	@echo "Creating $(RED_COLOR)$@ $(DEFAULT_COLOR)..."
	@mkdir $@ $(DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s | $(BUILD)
	@echo "Compiling $(CYAN_COLOR)$< $(DEFAULT_COLOR)..."
	$(NA) $(NAFLAG) $< -o $@

.PHONY : all clean fclean re