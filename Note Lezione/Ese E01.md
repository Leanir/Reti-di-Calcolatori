---
Data: 2024-05-24T00:00:00.000+02:00
Docente: "[[Luca Guarnera]]"
Argomenti:
  - Esercitazione
  - Esame
---

# Esercitazione in aula del `VIEW[{Data}]`

## 28 Luglio 2023

### Esercizio 1

Configurare la rete secondo lo schema riportato in figura.
Gli indirizzi IP da utilizzare sono nel range 163.91.0.0/16

![[Ese E01 20240524094054.excalidraw]]

Famo roba con la cosa ad albero, but first:

![[Ese E01 20240524094826.excalidraw]]

163.91.x.x = 10100011.01011011.xxxxxxxx.xxxxxxxx

con maschera 16 abbiamo 65k indirizzi

| Maschera | numIndirizzi |
| -------- | ------------ |
| 17       | 32k          |
| 18       | 16384        |
| 19       | 8k           |
| 20       | 4k           |
| 21       | 2k           |
| 22       | 1k           |
| 23       | 512          |
| 24       | 256          |
| 25       | 128          |

![[Ese E01 20240524095757.excalidraw]]

LAN 3:
10100011.01011011.00xxxxxx.xxxxxxxx/18

- da 10100011.01011011.00000000.00000000 -> 163.91.0.0
- a 10100011.01011011.00111111.11111111 -> 163.91.63.255

LAN 1:
10100011.01011011.01000000.0xxxxxxx

- da 10100011.01011011.01000000.00000000 -> 163.91.64.0
- a 10100011.01011011.01000000.01111111 -> 163.91.64.127

### Esercizio 2

#### Router

/etc/network/interfaces
![[Pasted image 20240524104512.png]]

/etc/sysctl.conf
![[Pasted image 20240524104640.png]]

![[Pasted image 20240524115551.png]]
