# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 07:42:05 by zessadqu          #+#    #+#              #
#    Updated: 2023/07/04 17:20:57 by zessadqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main

SRCS = Bureaucrat.cpp main.cpp AForm.cpp  RobotomyRequestForm.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp Intern.cpp

HEADERS = AForm.hpp Bureaucrat.hpp PresidentialPardonForm.hpp   RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp

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