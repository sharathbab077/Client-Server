#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
void main()
{
    
    int server_sockfd, client_sockfd;
    int server_len ;
    int rc ;
    unsigned client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
 
   server_sockfd = socket(AF_INET, SOCK_STREAM, 0); //TCP socket of server
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htons(INADDR_ANY); //localhost  IP for server
    server_address.sin_port = htons(5169) ; //port no.
    server_len = sizeof(server_address);
 
    rc = bind(server_sockfd, (struct sockaddr *) &server_address, server_len);
    printf("RC from bind = %d\n", rc ) ;
     rc = listen(server_sockfd, 5);
    printf("RC from listen = %d\n", rc ) ;
client_len = sizeof(client_address);

while(1) {
    client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_address, &client_len); // to accept client requests
    printf("after accept()... client_sockfd = %d\n", client_sockfd) ;
        char ch;
        printf("server waiting\n");
rc = read(client_sockfd, &ch, 1);  //accept a character from client
                if (ch=='X') break ;
        printf("REPLYING BACK\n");
	ch='Y';
        write(client_sockfd,&ch, 1); //reply back to client
close(client_sockfd); //close client socket after communication
	}
 }
