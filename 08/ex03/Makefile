NAME = mindopen

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = IncrementPointer.cpp	\
	   DecrementPointer.cpp	\
	   IncrementByte.cpp	\
	   DecrementByte.cpp	\
	   OutputByte.cpp		\
	   InputByte.cpp		\
	   OpenBracket.cpp		\
	   CloseBracket.cpp		\
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
