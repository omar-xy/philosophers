# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 03:24:07 by otaraki           #+#    #+#              #
#    Updated: 2023/08/05 01:03:02 by otaraki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = includes/philo.h

CC := cc

CFLAGS :=  -Wall -Wextra -Werror 

SRCS := Manda/philo.c Manda/utils.c Manda/dinner.c Manda/ft_atoi.c\
Manda/error.c Manda/pattern.c\

OBJ := $(SRCS:.c=.o)

RM := rm -rf

m := MakefileAutoPush


all : $(NAME)

$(NAME) : $(OBJ)
	$(CC)  $(OBJ) -o  $(NAME)

%.o : %.c $(HEADER) 
	$(CC) $(CFLAGS) -c $<  -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

git :
	git add .
	git status
	git commit -m "$(m)"
	git push

.PHONY : all clean fclean re git