# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 21:07:24 by npinheir          #+#    #+#              #
#    Updated: 2022/08/27 17:24:37 by npinheir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = srcs/

SRC_NAMES		=	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c \
					ft_split.c ft_strlcat.c ft_strncmp.c ft_substr.c \
					ft_isalpha.c ft_memcpy.c ft_putendl_fd.c \
					ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_tolower.c \
					ft_bzero.c ft_isascii.c ft_memccpy.c ft_memmove.c \
					ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
					ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c \
					ft_memset.c ft_putstr_fd.c ft_strjoin.c ft_strmapi.c \
					ft_strtrim.c ft_atoi.c ft_strcmp.c
					
SRCS = $(addprefix $(SRC_DIR), $(SRC_NAMES))
OBJ_DIR = objs/
OBJ_NAMES = $(SRC_NAMES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_NAMES))

HDR_NAMES = libft.h
HDR_DIR = include/
HDRS = $(addprefix $(HDR_DIR),$(HDR_NAMES))

HDR_INC = $(addprefix -I./, $(HDR_DIR))

RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m

all: $(NAME) $(HDRS)

$(NAME): $(OBJ_DIR) $(OBJS) $(HDRS)
	@ar rc $@ $(OBJS)
	@ranlib $@
	@echo "\t[ $(GREEN)✔$(NONE) ] libft/libft.a library"

$(OBJ_DIR):
	@mkdir $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDRS)
	@$(CC) $(CFLAGS) $(HDR_INC) -c $< -o $@

clean:
	@rm -Rf $(OBJ_DIR)
	@echo "\t[ $(RED)✗$(NONE) ] libft/$(OBJ_DIR) directory"

fclean: clean
	@rm -f $(NAME)
	@echo "\t[ $(RED)✗$(NONE) ] libft/$(NAME) library"

re: fclean all

.PHONY: all clean fclean re project