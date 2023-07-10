# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 03:24:07 by otaraki           #+#    #+#              #
#    Updated: 2023/07/10 09:55:27 by otaraki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = includes/philo.h
LIBFT = libft/libft.a

CC := cc

CFLAGS :=  -Wall -Wextra -Werror

SRCS := Manda/philo.c Manda/utils.c Manda/dinner.c\
Manda/pattern.c\

OBJ := $(SRCS:.c=.o)

RM := rm -rf

m := MakefileAutoPush


all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	$(CC) $(OBJ) -o $(NAME) $(LIBFT)

%.o : %.c $(HEADER) 
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C libft
	$(RM) $(OBJ)

fclean : clean
	make  fclean -C libft
	$(RM) $(NAME)

re : fclean all

git :
	git add .
	git status
	git commit -m "$(m)"
	git push

.PHONY : all clean fclean re git