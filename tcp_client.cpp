// Server side C/C++ program to demonstrate Socket programming 
// Here's some include statements that might be helpful for you
#include <string> 
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <sys/socket.h> 
#include <netdb.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char const *argv[]) 
{ 
	// check to see if user input is valid
	char socket_read_buffer[1024];
	
	// TODO: Fill out the server ip and port
	std::string server_ip = "127.0.0";
	// std::string server_port = ""; -- changing to int
	int server_port = std::stoi(argv[2]);

	char buffer[256];
	int n;

	// TODO: Create a TCP socket()
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	// Helping you out by pepping the struct for connecting to the server
	// struct addrinfo hints;
	// struct addrinfo *server_addr;
	// memset(&hints, 0, sizeof(hints));
	// hints.ai_family = AF_INET;
	// hints.ai_socktype = SOCK_STREAM;
	// getaddrinfo(server_ip.c_str(), argv[2], &hints, &server_addr);

	// TODO: Connect() to the server (hint: you'll need to use server_addr)
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(server_port);
	
	// Use argv[1] as the server_ip provided on the command line!
	if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
    	perror("Invalid address/ Address not supported");
    	return -1;
	}

	if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    	perror("Error connecting");
    	return -1;
	}

	// TODO: Retreive user input
	printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);

	// TODO: Send() the user input to the server
	n = write(sockfd,buffer,strlen(buffer));

	// TODO: Recieve any messages from the server and print it here. Don't forget to make sure the string is null terminated!
	bzero(buffer,256);
    n = read(sockfd,buffer,255);
	printf("%s\n",buffer);

	// TODO: Close() the socket
	close(sockfd);

	return 0; 
} 