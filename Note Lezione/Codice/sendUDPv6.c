#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int socketFileDescriptor, n;
    struct sockaddr_in6 remote_addr;
    socklen_t len = sizeof(struct sockaddr_in6);
    char
        sendline[1000],
        recline[1000],
        ipv6_addr[INET6_ADDRSTRLEN];

    if (argc != 3)
    {
        printf("Errore! Inserisci ip e port\n");
        return -1;
    }

    socketFileDescriptor = socket(AF_INET6, SOCK_DGRAM, 0);
    if (socketFileDescriptor < 0)
    {
        printf("Errore nell'apertura di socket\n");
        return -1;
    }

    memset(&remote_addr, 0, len);
    remote_addr.sin6_family = AF_INET6;
    inet_pton(AF_INET6, argv[1], &(remote_addr.sin6_addr));
    remote_addr.sin6_port = htons(atoi(argv[2]));

    while (fgets(sendline, 1000, stdin) != NULL)
    {
        sendto(
            socketFileDescriptor, sendline, strlen(sendline), 0,
            (struct sockaddr *)&remote_address, len);

        recvfrom(
            socketFileDescriptor, recline, 999, 0,
            (struct sockaddr *)&remote_address, &len);

        recline[n] = 0; // terminatore stringa, va bene anche al posto di \0

        inet_ntop(AF_INET6, &(remote_addr.sin6_addr), ipv6_addr, INET6_ADDRSTRLEN);

        printf(
            "IP = %s, P = %d, msg = %s",
            ipv6_addr,
            ntohs(remote_address.sin6_port),
            recline);

        if (strcmp(recline, "fine\n") == 0)
            break;
    }

    printf("Fine comunicazione\n");
    close(socketFileDescriptor);

    return 0;
}