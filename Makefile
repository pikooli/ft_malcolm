NAME = ft_malcolm

CC = gcc 

INCLUDES = -I ./includes

CFLAGS = -Wall -Werror -Wextra $(INCLUDES)

SRC = \
	ft_check_arg.c\
	ft_compare.c\
	ft_error.c\
	ft_getipaddress.c\
	ft_loop.c\
	ft_mim.c\
	ft_print.c\
	ft_recv.c\
	ft_send.c\
	ft_sigint.c\
	main.c

SRCS =  $(addprefix ./srcs/,$(SRC))

LIBFT = \
	ft_atoi.c\
	ft_is_int.c\
	ft_isnum.c\
	ft_lstdelone_bonus.c\
	ft_memcmp.c\
	ft_putnbr.c\
	ft_split.c\
	ft_strlen.c\
	ft_toupper.c\
	ft_atoi_base.c\
	ft_isalnum.c\
	ft_isprefix.c\
	ft_lstiter_bonus.c\
	ft_memcpy.c\
	ft_putnbr_fd.c\
	ft_strchr.c\
	ft_strmapi.c\
	ft_validnumber.c\
	ft_base_10.c\
	ft_isalpha.c\
	ft_isprint.c\
	ft_lstlast_bonus.c\
	ft_memmove.c\
	ft_putstr.c\
	ft_strcmp.c\
	ft_strncmp.c\
	ft_zemalloc.c\
	ft_bzero.c\
	ft_isascii.c\
	ft_isspace.c\
	ft_lstmap_bonus.c\
	ft_memset.c\
	ft_putstr_fd.c\
	ft_strcpy.c\
	ft_strnstr.c\
	ft_calloc.c\
	ft_isbase_16.c\
	ft_itoa.c\
	ft_lstnew_bonus.c\
	ft_printf.c\
	ft_putstrendl.c\
	ft_strdup.c\
	ft_strrchr.c\
	ft_conversion.c\
	ft_isdigit.c\
	ft_lstadd_back_bonus.c\
	ft_lstsize_bonus.c\
	ft_putchar_fd.c\
	ft_putstrnb.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_free_split.c\
	ft_ishexa.c\
	ft_lstadd_front_bonus.c\
	ft_memccpy.c\
	ft_putcolor.c\
	ft_randnumb.c\
	ft_strlcat.c\
	ft_substr.c\
	ft_free_tab.c\
	ft_islower.c\
	ft_lstclear_bonus.c\
	ft_memchr.c\
	ft_putendl_fd.c\
	ft_shuffle_array.c\
	ft_strlcpy.c\
	ft_tolower.c

LIBFTS = $(addprefix ./srcs/libft/,$(LIBFT))

LIBFTOBJS = ${LIBFTS:.c=.o}

OBJS   = ${SRCS:.c=.o}

.c.o	: ${CC} $(MLX)  ${CFLAGS} -c $< -o ${<:.c=.o}

all : $(OBJS) $(LIBFTOBJS)
		$(CC) $(INCLUDES) ${OBJS} ${LIBFTOBJS} -o ${NAME}

$(NAME) : $(OBJS) $(LIBFTOBJS)
		$(CC) $(INCLUDES) ${OBJS} ${LIBFTOBJS} -o ${NAME}

arp :
	ping -c 1 192.168.1.38
	@echo "\033[32m"
	arp -a | grep "192.168.1.38" 
	@echo "\033[0m"
	sleep 2
	sudo arp -d 192.168.1.38
	ping -c 1 192.168.1.38
	@echo "\033[32m"
	arp -a | grep "192.168.1.38" 
	@echo "\033[0m"

arptest : 
	./ft_malcolm 192.168.1.46  14:7d:da:9a:97:f9  192.168.1.38 00:1e:73:78:ff:0d

fake : 
	./ft_malcolm toto  tata titi tutu 
	./ft_malcolm 192.168.1.46  14:7d:da:9a:97:f9  192.168.1.38 
	./ft_malcolm 192.168.1.46  14:7d:da:9a:97:  192.168.1.38 00:1e:73:78:ff:0d
	./ft_malcolm 192.168.1.46  14:7d:da:9a:97:f9  192.168.1.38 00:1e:73:78:ff:

$(LIBFT) :
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@rm $(NAME)
	
fclean: clean
	@rm -rf $(OBJS) $(LIBFTOBJS)
	@rm -rf $(NAME)