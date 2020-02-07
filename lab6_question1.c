#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#define SERVER_PORT 6001
int main(){
   int client_socket;
   char buffer [1024];
   //making the server address record with a recognized server IP and port
   struct sockaddr_in server;
   server.sin_family=AF_INET;
   server.sin_port=htons(SERVER_PORT);
   server.sin_addr.s_addr=inet_addr("127.0.0.1");
   //making socket family = AF_INET, type = SOCK_STREAM , protocol = TCP
   client_socket = socket ( AF_INET , SOCK_STREAM , IPPROTO_TCP );
   //connecting to the server
   if (connect ( client_socket , (struct sockaddr * ) &server , sizeof(server))==0)
      printf("Client is connected to the server!\n");
   else
      printf("Error in connecting to the server\n");


   while(1) {

      bzero (buffer ,1024);
      fgets(buffer, 1024,stdin);
      write(client_socket , buffer , strlen(buffer) - 1);
      printf("msg is sent to the server!\n");
      FILE *fp;
      fp = fopen("client_cpy.txt","w");
       //bzero (buffer ,256);
       //fgets(buffer, 256,stdin);
      //bzero (buffer ,256);
      while(1){
        //bzero (buffer ,256);
        read(client_socket , buffer , 1024);
        printf("can read in Client\n");
        //puts(buffer);
        if(buffer[0] == '\0')
          break;
        fputs(buffer, fp);
        printf("fput ok in Client\n");
      }
      fclose(fp);     
}
return 0; }