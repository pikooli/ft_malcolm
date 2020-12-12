#include "main.h"


int main(int ac, char **av)
{
	// create a socket
	int network_socket; 
	network_socket = socket(AF_INET, SOCK_STREAM, 0); 
	printf("network fd = %d\n", network_socket);
	//specify an address for the socket
	struct sockaddr_in server_address;

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	// check for error with the connection 
	if (connection_status == -1) {
		perror("There was an error making a connection to the remote socket\n");
		return 0;
	}
	
	// receive datra from server
	char server_response[256];

	recv(network_socket, &server_response, sizeof(server_response), 0);

	// printf out the server's response
	printf("The server sent the data %s\n", server_response);

	// and then close the socket
	close(network_socket);
	return 0;
} 
