NAME = lib1.so
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

CPP = clang++
CPPFLAGS ?= -Wall -Wextra -Werror -std=c++11
CPPFLAGS += -I../include
LDFLAGS = -shared -fPIC -lncurses

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(LDFLAGS) -o $(NAME) $(OBJ)

re: fclean all

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)