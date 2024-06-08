#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int sockfd, n;
    struct sockaddr_in local_address, remote_address;
    socklen_t len = sizeof(struct sockaddr_in);
    char msg[1000];

    if (argc != 2)
    {
        printf("Errore! Inserisci numero port\n");
        return -1;
    }

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        printf("Errore nell'apertura di socket\n");
        return -1;
    }

    memset(&local_address, 0, len);
    local_address.sin_family = AF_INET;
    local_address.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *)&local_address, len) < 0)
    {
        printf("Errore! Inserisci un numero diverso di port\n");
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

        printf(
            "IP = %s, P = %d, msg = %s",
            inet_ntoa(remote_address.sin_addr),
            ntohs(remote_address.sin_port),
            msg);

        if (strcmp(msg, "fine\n") == 0)
            break;
    }

    printf("Fine comunicazione\n");
    close(sockfd);

    return 0;
}