#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>  // For close()
#include <stdbool.h>

int main() {
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFD < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    struct sockaddr_in address;  // Correct structure for IPv4 sockets
    memset(&address, 0, sizeof(address)); // Zero out the structure

    address.sin_family = AF_INET;
    address.sin_port = htons(2000);  // Port of the server

    char* ip = "127.0.0.1"; // IP Address of Google
    if (inet_pton(AF_INET, ip, &address.sin_addr) <= 0) {
        perror("Invalid IP address");
        close(socketFD);
        return EXIT_FAILURE;
    }

    int result = connect(socketFD, (struct sockaddr*)&address, sizeof(address));
    if(result !=0){
      perror("Connection failed");
      return EXIT_FAILURE;
    }

    printf("Connection was successful\n");

    char* message = NULL;
    size_t messageSize = 0;
    while(true){
        ssize_t charCount = getline(&message, &messageSize,stdin);
        if(charCount > 0){
            if(strcmp(message,"exit")==0) break;

            ssize_t amountSent = send(socketFD,message,strlen(message),0);
        }
        
    }

    char buffer[1024];

    recv(socketFD,buffer,1024,0);
    printf("%s\n",buffer);

    close(socketFD);
    return 0;
}
