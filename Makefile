# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkristi <rkristi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 10:07:50 by rkristi           #+#    #+#              #
#    Updated: 2021/08/17 05:36:19 by rkristi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

SRCS	= main.c\
			phil.c\
			spawn.c\
			sups.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f

FLAGS	= -Wall -Werror -Wextra


.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} header.h
			${CC} ${OBJS} -o philo

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re