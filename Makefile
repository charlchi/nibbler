

# https://www.glfw.org/docs/latest/compile_guide.html
# cmake -DBUILD_SHARED_LIBS=ON .

# install:

NAME = test
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

CPP = clang++
CPPFLAGS ?= -Wall -Wextra -Werror -std=c++11
CPPFLAGS += -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) -o $(NAME) $(OBJ)

re: fclean all

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)