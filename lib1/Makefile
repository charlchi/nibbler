
CC = clang++
FLAGS = -std=c++11 -lncurses
NAME = lib.so
FILE = Display.cpp


all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(FILE) -shared -ldl -o $(NAME)

clean :

fclean : clean
	@rm -rf $(NAME)

re : fclean all

