# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 12:19:31 by amaitre           #+#    #+#              #
#    Updated: 2016/01/22 09:36:04 by amaitre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit
SRC		=	src/resolve.c \
			src/check_form.c \
			src/creat_list.c \
			src/fillit.c \
			src/funct_return.c \
			src/map.c \
			src/swap.c \
			src/select_letter.c \
			src/width_height.c \
			src/move_piece.c
SRCO	=	$(SRC:.c=.o)
HEADERS	=	header
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

re: fclean all

%.o: %.c
	@echo "\033[32mFILLIT:\033[0m [Compilation:\033[33m $@\033[0m]"
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(HEADERS)

$(NAME): $(SRCO)
	@make -C libft/
	@$(CC)  $(CFLAGS) -o $@ libft/libft.a $^
	@echo "[\033[32m--------------------------\033[0m]"
	@echo "[\033[36m------ OK - FILLIT -------\033[0m]"
	@echo "[\033[32m--------------------------\033[0m]"

clean:
	@echo "\033[32mFILLIT:\033[0m [\033[31mSuppression des .o\033[0m]"
	@make clean -C libft/
	@rm -f $(SRCO)

fclean:
	@echo "\033[32mFILLIT:\033[0m [\033[31mSuppression des .o\033[0m]"
	@rm -f $(SRCO)
	@echo "\033[32mFILLIT:\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@make fclean -C libft/
	@rm -f $(NAME)

.PHONY: re clean fclean all
