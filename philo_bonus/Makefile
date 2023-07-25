# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 02:11:03 by otaraki           #+#    #+#              #
#    Updated: 2023/07/25 03:51:18 by otaraki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

HEADER = philo_bonus.h

CC := cc

CFLAGS :=  -Wall -Wextra -Werror 

SRCS := philo_bonus.c utils_bonus.c ft_atoi.c time.c sema_dinner.c actions.c\

OBJ := $(SRCS:.c=.o)

RM := rm -rf

m := MakefileAutoPush


all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o  $(NAME)

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