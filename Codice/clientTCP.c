#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    // %% 1. socket
    int sockfd, n;
    struct sockaddr_in
        local_addr,
        remote_addr;
    char sendline[1000], remoteline[1000];

    if (argc < 3)
    {
        printf("Errore! Inserisci IP e port\n");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0); // ? sockstream è per tcp

    if (sockfd < 0)
    {
        printf("Errore nell'apertura di socket\n");
        return -1;
    }

    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = inet_addr(argv[1]); // setting indirizzo IP, modo alternativo con accesso diretto a struct
    remote_addr.sin_port = htons(atoi(argv[2]));

    // %% 4. connect
    connect(
        sockfd,
        (struct sockaddr *)&remote_addr,
        sizeof(remote_addr));

    // %% 5 & 6. send e recv
    while (fgets(sendline, 999, stdin) != NULL)
    {
        send(
            sockfd,
            sendline,
            strlen(sendline),
            0);

        n = recv(sockfd, recvline, 999, 0);
        recvline[n] = 0;

        printf("IP %s, P %d, msg %s\n",
               inet_ntoa(remote_addr.sin_addr),
               ntohs(remote_addr.sin_port),
               recvline);

        if (stcmp(recvline, "fine\n") == 0)
        {
            printf("Fine\n");
            break;
        }
    }

    // %% 7. close
    close(sockfd);

    return 0;
}