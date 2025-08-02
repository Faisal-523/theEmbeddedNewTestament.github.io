#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd, ret;
    struct sockaddr_in client_addr;
    char str[255];
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket!");
        return sockfd;
    }

    //Connect to a server
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(12345);
    inet_aton("127.0.0.1", &client_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr*) &client_addr, sizeof(client_addr));
    if(ret < 0) {
        perror("Error connecting to the server!!");
        return ret;
    }

    //Send
    sprintf(str,"Hello from client!");
    ret = send(sockfd, str, strlen(str), 0);
    if(ret < 0) {
        perror("Error during send!!");
        return ret;
    }
    ret = recv(sockfd, str, sizeof(str), 0);
    if(ret < 0) {
        perror("error during receive!!");
        return ret;
    }
    printf("%s\n", str);

    //close socket
    close(sockfd);
    return 0;
}