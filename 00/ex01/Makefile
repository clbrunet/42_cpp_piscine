NAME = phonebook

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = contact.cpp		\
	   phonebook.cpp	\
	   main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
