NAME = MutantStack

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS = srcs/main.cpp

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME) 
	
git: 
	@git add .
	@git commit -m "makefile"
	@git push
	clear
	
clean:
	@cd
	
fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean

reexecute: re
	./MutanStack

