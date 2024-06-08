#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int sockfd, n;

    struct sockaddr_in6
        local_addr,
        remote_addr;

    socklen_t len = sizeof(struct sockaddr_in6);

    char
        ipv6_addr[46],
        msg[1000];

    if (argc != 2)
    {
        printf("Errore! Inserisci numero port\n");
        return -1;
    }

    sockfd = socket(AF_INET6, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        printf("Errore nell'apertura di socket\n");
        return -1;
    }

    memset(&local_address, 0, len);
    local_addr.sin6_family = AF_INET6;
    local_addr.sin6_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *)&local_addr, len) < 0)
    {
        printf("Errore nella bind\n");
        return -1;
    }

    for (;;)
    {
        recvfrom(
            sockfd, msg, 999, 0,
            (struct sockaddr *)&remote_address, &len);
        msg[n] = 0;

        sendto(
            sockfd, msg, strlen(msg), 0,
            (struct sockaddr *)&remote_address, &len);

        inet_ntop(AF_INET6, &(remote_addr.sin6_addr), ipv6_addr, INET6_ADDRSTRLEN);
        printf(
            "IP = %s, P = %d, msg = %s",
            ipv6_addr,
            ntohs(remote_address.sin_port),
            msg);

        if (strcmp(msg, "fine\n") == 0)
            break;
    }

    printf("Fine comunicazione\n");
    close(sockfd);

    return 0;
}