#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>

struct sockaddr_in* createIPv4Address(char *ip, int port) {
  struct sockaddr_in  *address = malloc(sizeof(struct sockaddr_in));
  address->sin_family = AF_INET;
  address->sin_port = htons(port);

  if(strlen(ip) ==0)
      address->sin_addr.s_addr = INADDR_ANY;
  else
      inet_pton(AF_INET,ip,&address->sin_addr.s_addr);

  return address;
}

int main(){
  int serverSocketFD = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocketFD < 0) {
    perror("Socket creation failed");
    return EXIT_FAILURE;
  }

  struct sockaddr_in *serverAddress = createIPv4Address("",2000);

  int result = bind(serverSocketFD,(struct sockaddr*)serverAddress, sizeof(*serverAddress));

  if(result !=0){
    perror("Server Socket was bind failure\n");
    return EXIT_FAILURE;
  }

  printf("Server Socket bound successfully\n");

  int listenResult = listen(serverSocketFD,10);

  struct sockaddr_in clientAddress;
  
  int clientAddressSize = sizeof(struct sockaddr_in);
  int clientSocketFD = accept(serverSocketFD,clientSocketFD,&clientAddressSize);

  // while LOOP here
  char buffer[1024];
  char* message = NULL;
  size_t messageSize = 0;
  while(true){
    ssize_t amountReceived = recv(clientSocketFD,buffer,1024,0);
    if(amountReceived > 0){
      buffer[amountReceived] = 0;
      printf("%s",buffer);
    }

    if(amountReceived == 0) break;
  }

  close(serverSocketFD);
  return 0;
}