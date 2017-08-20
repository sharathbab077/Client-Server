# Client-Server

SERVER
1.Server should create socket and bind its IP address and port no. used to service client.
2.Server should also call listen() and decide no. of requests can be queued.
3.Server now should wait for client to connect to it.
4.Once any client send connect request, server should accept the request and assign a new sockfd and allow access communication.
5.Now if another client sends request to server, it should accept its request and assign a new sockfd. (We implement dynamic array of sockfd so it can create new sockfd to each client connecting to server).
6.Once client terminates, Server should deallocate sockfd assign to it and still keep running to service other clients. (i.e. Server socket should not close when one client socket closes).

CLIENT

1.Create client socket (In each client machine).
2.All clients should follow same socket type used by server,i.e. Connection oriented socket if protocol used is TCP and connection less if UDP protocol.(Meaning socket type of server and clients to be same).
3.Client programs (all individual client independently) should store server IP address in sin_addr.s_addr structure variable.
4.The port no. of server and port no. of each client should be same.(as each application is categorised based on port no.,hence application server is selects requests from client based on port no.)
5.Version of IP protocol (protocol family) must be same between server & clients. (Else steps to be taken to match).
6.Each client can now call connect() with its sockfd and object of sockaddr_in (structure which holds server IP and port no.). 
7.After server access, each client socket is closed.
