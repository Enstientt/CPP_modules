# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 15:52:39 by zessadqu          #+#    #+#              #
#    Updated: 2023/05/02 11:56:04 by zessadqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animal

SRCS = Cat.cpp Dog.cpp main.cpp Animal.cpp Brain.cpp

HEADERS = Animal.hpp Cat.hpp Dog.hpp Brain.hpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all