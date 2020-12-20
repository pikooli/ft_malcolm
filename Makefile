NAME = ft_malcolm

CC = gcc

LIBFT_DIRECTORY = ./libft/

LIBFT = $(LIBFT_DIRECTORY)libft.a

LIBRARIES = $(LIBFT)

INCLUDES = -I ./includes



all : $(LIBFT)
	$(CC) $(LIBRARIES) $(INCLUDES) ./main.c srcs/*

$(LIBFT) :
	@$(MAKE) -sC $(LIBFT_DIRECTORY)
clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	

fclean: clean
	@$(MAKE) -sC $(LIBFT_DIRECTORY) fclean