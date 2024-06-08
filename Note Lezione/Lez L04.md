---
Data: 2024-04-08T00:00:00.000+02:00
Docente: "[[Luca Guarnera]]"
Argomenti:
  - UDP
  - sendto
  - recvfrom
  - bind
  - client - server
---

| **Data** | `INPUT[datePicker:Data]` |
| -------- | ------------------------ |

# Connessioni UDP recap

## Server-Client

server:

1. socket()
2. bind()
3. recvfrom()
4. sendto()
5. close()

client:

1. socket()
2. -
3. sendto()
4. recvfrom()
5. close()

## conversione indirizzi

### funzioni pton() e ntop()

## funzioni host to network e viceversa

# Socket

## domain

## type

## famiglia

---

# Funzioni

```c
int bind(
    int socket,
    struct sockaddr *addr, // bisogna settarla a zero prima con memset()
    int addrlen
);

int sendto(
    int socket,
    void *buffer,
    size_t size,
    int flags,
    struct sockaddr *addr,
    size_t length,
);

int recvfrom(
    int socket,
    void *buffer,
    size_t size,
    int flags,
    struct sockaddr *addr,
    size_t *length
)
```

codice:: [[Sender.c]]

Su teams si trovano già gli esercizi di
