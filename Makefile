# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamchur <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 17:33:54 by hamchur           #+#    #+#              #
#    Updated: 2022/02/20 17:08:02 by hamchur          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS	=	utils/ft_putstr_fd.c\
				utils/ft_split.c \
				utils/ft_strlen.c \
				utils/ft_strjoin.c \
				utils/ft_strnstr.c \
				utils/ft_putchar_fd.c \
				sources/pipex.c \
				sources/errors.c \
				sources/pipex_utilities.c

HEADER	=	includes/pipex.h

OBJ		=	$(SRCS:%.c=%.o)

СС		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o 	:	%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all	clean fclean re
