all : 
	gcc srcs/main.c srcs/Utils/ft_strdup.c srcs/Utils/getIpAddress.c srcs/Utils/ft_strcmp.c  test.c -I include

client : 
	gcc srcs/client.c -I include -o client

server : 
	gcc srcs/server.c -I include -o server 
