#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


int main () {
    int sockfd, clientfd;
    const char* resp = "hello from server";
    char buffer[1000];
    struct sockaddr_in addr;
    int addrlen = sizeof(addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == 0) {
        printf("Error creating socket!!");
        exit(EXIT_FAILURE);
    }


    addr.sin_family = AF_INET;
    inet_aton("127.0.0.1", &addr.sin_addr);
    addr.sin_port = htons(12345);

    if(bind(sockfd, (struct sockaddr *)&addr, (socklen_t)addrlen) < 0) {
        printf("Error binding the socket");
        exit(EXIT_FAILURE);
    }

    if(listen(sockfd, 3) < 0) {
        printf("Error listening!");
        exit(EXIT_FAILURE);
    }

    clientfd = accept(sockfd, (struct sockaddr*)&addr, (socklen_t *)&addrlen);
    if(clientfd < 0) {
        printf("Error with accept!");
        exit(EXIT_FAILURE);
    }

    send(clientfd, resp, strlen(resp), 0);

    recv(clientfd, buffer, sizeof(buffer), 0);
    printf("Received from client: %s\n", buffer);

    close(sockfd);
    close(clientfd);


    return 0;
}