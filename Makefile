NAME = ft_malcolm

CC = gcc -Wall -Werror -Wextra

LIBFT_DIRECTORY = ./libft/

LIBFT = $(LIBFT_DIRECTORY)libft.a

LIBRARIES = $(LIBFT)

INCLUDES = -I ./includes



all : 
	clear
	$(CC) $(INCLUDES) ./main.c srcs/* ./libft/*

test : 
	./a.out 1.168.1.46  ff:bb:ff:ff:ee:1a  15.15.15.54 ff:bb:ff:ff:ee:aa

$(LIBFT) :
	@$(MAKE) -sC $(LIBFT_DIRECTORY)
clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	

fclean: clean
	@$(MAKE) -sC $(LIBFT_DIRECTORY) fclean