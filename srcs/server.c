#include "main.h"


int main(int ac, char **av)
{
    char server_message[256] = "You have reached the server!";
    struct sockaddr client_addr;
    socklen_t size;
	// create the server socket
	int server_socket; 
	server_socket = socket(AF_INET, SOCK_STREAM, 0); 
	printf("network fd = %d\n", server_socket);
    
	//define the server address
	struct sockaddr_in server_address;

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	//bind the socket to our specified IP and port
    int bind_return = bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    
	// check for error with the connection 
	if (bind_return == -1) {
		perror("There was an error making the bind of the server\n");
		return 0;
	}
	
	listen(server_socket, 5);

    int client_socket;
    client_socket = accept(server_socket, &client_addr, &size);
    printf("the client data are %d\n",client_addr.sa_family ); 
    printf("the client sa_data are %s\n",client_addr.sa_data ); 
    // send the message
    send(client_socket, server_message, sizeof(server_message), 0);

    // close the socket
    close(server_socket);
	return 0;
} 
