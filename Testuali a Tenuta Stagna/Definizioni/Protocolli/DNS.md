# Domain Name System
decentralizzato

fortemente connesso a [[DHCP]]

## Richiesta e Risposta

### Richiesta

#### Iterativa

(se non trovi nella cache)
parte da local poi va a root
torna a local va a toplevel
torna a local va a authoritative (copy)

#### Ricorsiva

va fino ad authoritative e torna indietro (se non trova cache prima)

### Risposta

```DNS
tupla(nome, valore, tipo, timeToLive)
```

---

## Local

per non fare di nuovo tutte le richieste possono fungere da cache.

Ogni Internet Service Provider ha un server DNS Locale

## Root servers

Ce ne sono tanti (circa 1000)

- perché altrimenti ci sarebbe un punto di vulnerabilità
- ci sono diversi server che devono gestire meno richieste
- se ci fosse una sola root non potrebbe essere vicina fisicamente a tutti gli endpoint del mondo
    - e poi problemi burocratici per capire chi se lo deve tenè sto robo
- manutenzione, un singolo server nun c'ha fa

## Top-Level Domain

.com, .gov, .org

## Authoritative

Sono i server più specifici e gli ultimi a venire interrogati per la risoluzione delle risorse URI

### Authoritative Copy

funziona come cache (simile a proxy?) degli authoritative servers

## Riepilogo

![[Pasted image 20240617154238.png]]
