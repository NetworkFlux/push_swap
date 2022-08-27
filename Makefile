# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 12:06:04 by npinheir          #+#    #+#              #
#    Updated: 2022/08/27 17:26:02 by npinheir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
NAME2 = push_swap

CFLAGS = -Wall -Wextra -Werror

PUSHSWAPFD = push_swap/
CHECKERFD = checker/
COMMONFD = common/

SRCSFD = src/
PUSHSWAP_SRC = main.c \
			   big_sort.c \
			   big_sort_2.c \
			   sorts_3.c \
			   fucking_norm.c
CHECKER_SRC = main.c \
			  check_utils.c \
			  get_next_line.c
COMMON_SRC = check_sort.c \
			 cmds.c \
			 cmds_2.c \
			 cmds_3.c \
			 error.c \
			 free.c \
			 init_stack.c \
			 utils.c
OBJSFD = objs/
PUSHSWAP_OBJS = $(addprefix $(OBJSFD)$(PUSHSWAPFD), $(PUSHSWAP_SRC:.c=.o))
CHECKER_OBJS = $(addprefix $(OBJSFD)$(CHECKERFD), $(CHECKER_SRC:.c=.o))
COMMON_OBJS = $(addprefix $(OBJSFD)$(COMMONFD), $(COMMON_SRC:.c=.o))

HDRSFD = include/
HDR = checker.h common.h push_swap.h 
HDRS = $(addprefix $(HDRSFD), $(HDR))

HDR_INC = -I./include
LIBFT_HDR = -I./libft/include/
LIB_BINARY = -L./libft -lft
LIBFT = libft/libft.a

RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m

all: check_libft project $(HDRS) $(NAME) $(NAME2)
	@echo "Project ready"

check_libft:
	@echo "Checking dependencies..."
	@make -C libft

project:
	@echo "Checking project..."

$(OBJSFD):
	@mkdir $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(OBJSFD)$(PUSHSWAPFD): $(OBJSFD)
	@mkdir $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(OBJSFD)$(CHECKERFD): $(OBJSFD)
	@mkdir $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(OBJSFD)$(COMMONFD): $(OBJSFD)
	@mkdir $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(NAME): $(OBJSFD)$(CHECKERFD) $(CHECKER_OBJS) $(OBJSFD)$(COMMONFD) $(COMMON_OBJS) $(LIBFT) $(HDRS)
	@gcc $(CFLAGS) $(LIB_BINARY) $(CHECKER_OBJS) $(COMMON_OBJS) -o $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ executable"

$(NAME2): $(OBJSFD)$(PUSHSWAPFD) $(PUSHSWAP_OBJS) $(OBJSFD)$(COMMONFD) $(COMMON_OBJS) $(LIBFT) $(HDRS)
	@gcc $(CFLAGS) $(LIB_BINARY) $(PUSHSWAP_OBJS) $(COMMON_OBJS) -o $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ executable"

$(OBJSFD)$(PUSHSWAPFD)%.o: $(SRCSFD)$(PUSHSWAPFD)%.c $(HDRS) $(LIBFT)
	@gcc $(CFLAGS) $(HDR_INC) $(LIBFT_HDR) -o $@ -c $<
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ object"

$(OBJSFD)$(CHECKERFD)%.o: $(SRCSFD)$(CHECKERFD)%.c $(HDRS) $(LIBFT)
	@gcc $(CFLAGS) $(HDR_INC) $(LIBFT_HDR) -o $@ -c $<
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ object"

$(OBJSFD)$(COMMONFD)%.o: $(SRCSFD)$(COMMONFD)%.c $(HDRS) $(LIBFT)
	@gcc $(CFLAGS) $(HDR_INC) $(LIBFT_HDR) -o $@ -c $<
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ object"

clean:
	@/bin/rm -rf $(OBJSFD)
	@echo "\t[ $(RED)✗$(NONE) ] $(OBJSFD) directory"
	@make -C ./libft clean

fclean: clean
	@/bin/rm -f $(NAME) $(NAME2)
	@echo "\t[ $(RED)✗$(NONE) ] $(NAME) executable"
	@echo "\t[ $(RED)✗$(NONE) ] $(NAME2) executable"
	@make -C ./libft fclean

re: fclean all

.PHONY: check_libft project all clean fclean re