# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 12:51:42 by eribeiro          #+#    #+#              #
#    Updated: 2021/12/09 13:17:09 by eribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

NAME2 = client

HEADER =  minitalk.h 

CC = gcc 

FLAGS = -Wall -Wextra -Werror
 
SRCS    =       server.c\
                ressource.c\

SRCSC	=		client.c\
				ressource.c\

OBJECTS  =  ${SRCS:.c=.o}

OBJECTS2  =  ${SRCSC:.c=.o}

all: $(NAME2) $(NAME)

$(NAME):$(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(HEADER) -g -o $(NAME)

$(NAME2):$(OBJECTS2) 
	$(CC) $(FLAGS) $(OBJECTS2) $(HEADER) -o $(NAME2)

clean:
	/bin/rm -f $(OBJECTS) $(OBJECTS2)

fclean: clean
	/bin/rm -f $(NAME) $(NAME2)

re: fclean all

.PHONY:                 all fclean clean re bonus
