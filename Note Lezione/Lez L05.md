---
Data: 2024-04-24T00:00:00.000+02:00
Docente: "[[Luca Guarnera]]"
Argomenti:
  - sendto
  - receive
  - UDP
  - IPv4
  - IPv6
---

| **Data** | `INPUT[datePicker:Data]` |
| -------- | ------------------------ |

cominciamo fast as heck con visual studio

codice:: [[senderUDPfd.c]]
codice:: [[recUDPfd.c]]
codice:: [[sendUDPv6.c]]
codice:: [[recUDPv6.c]]

è possibile fare in modo che la receive from diventi non bloccante

```c
socket(PF_INET, SOCK_DGRAM | SOCK_NONBLOCK, 0)
```

librerie utili per non bloccante:

```c
errno.h
unistd.h
```

---

abbiamo accennato le fork per riuscire a fare più processi di comunicazione contemporaneamente

codice:: [[fork.c]]
codice:: [[chat1.c]]
