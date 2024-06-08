---
Data: 2024-05-03T00:00:00.000+02:00
Docente: "[[Luca Guarnera]]"
Argomenti:
  - TCP
---

| **Data** | `INPUT[datePicker:Data]` |
| -------- | ------------------------ |

Connessioni TCP

Server

1. socket()
2. bind()
3. listen()
4. accept() <->
5. recv() <-
6. send() ->
7. close()
   Client
8. socket()
9.
10.
11. connect() <->
12. send() ->
13. recv() <-
14. close

## Indirizzamento con server multipli

codice:: [[clientTCP.c]]
codice:: [[serverTCP.c]]
