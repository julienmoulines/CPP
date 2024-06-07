NAME = megaphone
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

all: $(NAME)

$(NAME): 
		@printf "COMPILATION EN COURS...\n"
		@$(CC) $(FLAGS) megaphone.cpp -o $(NAME)
		@sleep 0.5
		@printf "\033[F\033[K"
		@sleep 0.5
		@printf "COMPILATION Terminée !\n"

clean: 
		@$(RM) $(NAME)
		@printf "FICHIERS SUPPRIMES\n"

fclean: 
		@$(RM) $(NAME)
		@printf "FICHIERS SUPPRIMES\n"


re: clean all