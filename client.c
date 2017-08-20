

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
 
void main()
{
    printf("This is the client program\n");
     int sockfd;
    int len, rc ;
    struct sockaddr_in address;
    int result;
    char ch = 'A',exitstatus;
 
    sockfd = socket(PF_INET, SOCK_STREAM, 0); //TCP socket for client
    if (sockfd == -1) {
        perror("Socket create failed.\n") ;
        return -1 ;
    }
     
    //Name the socket as agreed with server.
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("192.168.30.135");  // Server IP address
    address.sin_port = htons(5169);  //port no.
    len = sizeof(address);
 	result = connect(sockfd, (struct sockaddr *)&address, len); //connect to server
    if(result == -1)
    {
        perror("Error has occurred");
        exit(-1);
    }
printf("Enter a character to send to server\n");
	scanf("%c",&ch); //send a character to server
        rc = write(sockfd, &ch, 1); //write character to server
        if (rc == -1) exit(0);
        read(sockfd, &ch, 1); //read a character from server
        printf("Char from server = %c\n", ch);
		write(sockfd,&exitstatus,1);
     close(sockfd); //close socket after communication
exit(0);
}
