NAME = lib.so
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

CPP = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++11 -Wno-missing-braces
CFLAGS += -Wno-deprecated-declarations -Wno-c++11-narrowing
CFLAGS += -Wno-unused-parameter -Wno-char-subscripts
CFLAGS += -I../include -Iinclude
LDFLAGS = -shared -fPIC libglfw3.a -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(LDFLAGS) -o $(NAME) $(OBJ)

re: fclean all

%.o: %.cpp
	$(CPP) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)