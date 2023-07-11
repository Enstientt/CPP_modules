NAME = main

SRCS =  Whatever.cpp main.cpp

HEADERS = Whatever.hpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror #-std=c++98

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