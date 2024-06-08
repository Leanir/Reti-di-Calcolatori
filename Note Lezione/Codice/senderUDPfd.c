// da usare con receiverUDPfd.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int sockfd, n;
    struct sockaddr_in remote_address;
    char sendline[1000], recline[1000];

    socklen_t len = sizeof(struct sockaddr_in);

    if (argc != 3)
    {
        printf("Errore! Inserisci ip e port\n");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        printf("Errore nell'apertura socket\n");
        return -1;
    }

    memset(&remote_address, 0, len);
    remote_address.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &(remote_address.sin_addr));
    remote_address.sin_port = htons(atoi(argv[2]));

    while (fgets(sendline, 1000, stdin) != NULL)
    {
        sendto(
            sockfd, sendline, strlen(sendline), 0,
            (struct sockaddr *)&remote_address, len);

        recvfrom(
            sockfd, recline, 999, 0,
            (struct sockaddr *)&remote_address, &len);

        recline[n] = 0; // terminatore stringa, va bene anche al posto di \0

        printf(
            "IP = %s, P = %d, msg = %s",
            inet_ntoa(remote_address.sin_addr),
            ntohs(remote_address.sin_port),
            recline);

        if (strcmp(recline, "fine\n") == 0)
            break;
    }

    close(sockfd);

    return 0;
}