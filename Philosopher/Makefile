NAME := philo

SRC := mandatory/main.c  func/utils1.c  func/utils2.c  func/actions.c \

GCC := gcc -Werror -Wextra -Wall  #-fsanitize=thread

all : $(NAME)

$(NAME) : $(SRC)
		@$(GCC) $(SRC) -o $(NAME)

clean :
	@echo "Cleaning up..."

fclean :
	@echo "Cleaning up..."
	@rm -f $(NAME)

re : fclean all

	