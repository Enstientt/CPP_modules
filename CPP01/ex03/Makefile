# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 00:48:26 by zessadqu          #+#    #+#              #
#    Updated: 2023/04/18 21:21:27 by zessadqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = attack

CC = c++ -std=c++98

SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

HEADER =HumanB.hpp HumanA.hpp Weapon.hpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

