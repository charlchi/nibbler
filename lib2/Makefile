NAME = lib.so
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

CPP = clang++
CPPFLAGS ?= -Wall -Wextra -Werror -std=c++11 -Wno-missing-braces
CPPFLAGS += -Wno-deprecated-declarations -Wno-c++11-narrowing
CPPFLAGS += -Wno-unused-parameter -Wno-char-subscripts
CPPFLAGS += -I../include -Itigr.h
LDFLAGS = -shared -fPIC -framework OpenGL -framework Cocoa

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