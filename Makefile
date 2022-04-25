# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 01:03:35 by ahakam            #+#    #+#              #
#    Updated: 2022/04/21 23:05:39 by ahakam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

CC=gcc

CFLAGS = -Wall -Werror -Wextra 

OBJ=ft_atoi.c\
	ft_isdigit.c\
	ft_lstadd_back_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstnew_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstdelone_bonus.c\
	oper0.c\
	oper1.c\
	push_swap_utils.c\
	push_swap.c\
	sort.c\
	sort_utils.c
	

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	
re: fclean all

clean:
	rm -f $(NAME)
	
fclean:clean