#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define SERVER_PORT 6001
#define MAX_CLIENT 4
int main(){
  char buffer [1024];
  int server_socket , client_socket ;
  // server_address = explicit address of server
  //client_address = client information
  struct sockaddr_in server_address , client_address ;
  //filling the server address record
  server_address.sin_family=AF_INET;  //IPv4
  server_address.sin_port=htons(SERVER_PORT);
  server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
  //server_address.sin_addr.s_addr=INADDR_ANY;
  //making socket family = AF_INET, type = SOCK_STREAM , protocol = TCP
  server_socket = socket ( AF_INET , SOCK_STREAM , IPPROTO_TCP );
  //binding socket to the server address
  bind ( server_socket , (struct sockaddr * ) & server_address ,sizeof(server_address)) ;
  //listening to incoming requests from clients with backlog of 5 clients
  listen (server_socket , MAX_CLIENT);
  int clientsize=sizeof(client_address);
  if ((client_socket = accept ( server_socket , (struct sockaddr * ) & client_address , &(clientsize)))>=0)
    printf("A connection from a client is recieved\n");
  else
    printf("Error in accepting the connection from the client\n ");
while(1) {

      bzero(buffer,1024);
      read(client_socket , buffer , 1024) ;
      FILE *pointer;
      char c;
      pointer=fopen(buffer,"r");
      bzero(buffer,1024);
      while(1){
        c=fgetc(pointer);
        if(feof(pointer))
          break;
        buffer[0]=c;
        buffer[1]='\0';

        write(client_socket , buffer , strlen(buffer));
        printf ("%s\n", buffer);
      }
      fclose(pointer);
      
    } 
    return 0;
 }