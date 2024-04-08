---
Data: 2024-03-20
Docente: "[[Luca Guarnera]]"
Argomenti:
  - schede reti
  - Clonazione macchine
  - scp
  - Socket
  - ssh
  - UDP
codice: "[[HelloWorld.c]]"
---

| **Data** | `INPUT[datePicker:Data]` |
| -------- | ------------------------ |

`ip address` -> fornisce informazioni necessarie sulle schede di rete
la scheda 1 non ci interesserà mai

la numero 2 è la nostra scheda di rete
`<..., UP, LOWER_UP>` significa che la scheda è attiva

inet -> indirizzo IPv4 della scheda
inet6 -> IPv6
molto simile per contenuto al MAC address - [x] molto importante⏫ settare mac address per evitare conflitti tra più macchine

virtual box non consente di fare copia-incolla, a questo problema ovvieremo tra un po'

è possibile freezzare la macchina salvandone lo stato

## Clonazione macchina

modalità esperta

- clone completo -> 100 macchine da 10 GB = 1000 GB di macchine
- clone collegato -> 100 macchine da 10 GB = poco pi+ di 10 GB

criteri indirizzi mac

- includi solo con NAT -> problema del mac ripetuto
- genera nuovi indirizzi per ogni scheda di rete -> this!

impostazioni macchina clonata:

- scheda 1 : rete interna
- scheda 2 : scheda solo host - permette di trasferire script da macchina host a virtuale (prendi IP da questa) - per ora non tocchiamo roba avanzata
  `ip link set dev enp0s8 up`

---

## terminal

pwd comando che restituisce path testuale

scp \[da] \[a] permette di trasferire file da una macchina all'altra
`user@IP:PATH/*.c`

![[Pasted image 20240320114353.png]]

---

# Parte teorica: Socket

astrazione fisica

concetti utili:

- UDP
- TCP
- categoria
  - IPv4
  - IPv6

## Connessioni UDP

| Server     | Client     | Dettagli                                                                                                                                                                                                                                                                               |
| ---------- | ---------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| socket()   | socket()   | entrambi creano la socket                                                                                                                                                                                                                                                              |
| bind()     |            | bind fa, <li>se la porta è disponibile e la associa al processo server se disponibile</li> <li>se non disponibile bind restituisce un valore negativo o errore.</li><br>non lo fa il client perché sa quale servizio deve usare, ha già tutte le informazioni, ma il server deve farlo |
| recvfrom() | sendto()   | client manda pacchetto e server riceve, non hanno una logica specifica, è in base al caso d'uso. è la parte importante per l'esame                                                                                                                                                     |
| sendto()   | recvfrom() | UDP manda una risposta, ma non è obbligato a farlo                                                                                                                                                                                                                                     |
| close()    | close()    | entrambi chiuderanno la socket                                                                                                                                                                                                                                                         |

### versione base connessione UDP

| Receiver   | Sender   |
| ---------- | -------- |
| socket()   | socket() |
| bind()     |          |
| recvfrom() | sendto() |
| close()    | close()  |

## definizione socket address

```C
struct sockaddr{
	u_short sa_family;
	char    sa_data[14];
}
```

questa struct viene usata da altre funzioni
occupa 16 Byte

## struct che useremo per IPv4

```C
typedef struct sockaddr_in{
	short int           sin_family;
	unsigned short int  sin_port;
	struct in_addr      sin_addr;     // contiene campo con indirizzo IP
	unsigned char       sin_zero[8];  // contiene solo caratteri 0 *
	// * per distinguere i campi del pacchetto (evitare confusione ed errore)
} AF_INET;

// progettata per funzionare con ogni protocollo
// per evitare problemi di ogni tipo
struct in_addr{
	u_int32_t s_addr;
};
```

### variante IPv6

```C
typedef struct sockaddr_in6{
	u_int16_t           sin6_family;
	u_int16_t           sin6_port;
	u_int32_t           ...;
	...
	...
} AF_INET6;

struct ...{
	...
};
```

## conversione degli indirizzi

pton presentation to network
ntop network to presentation

```C
inet_ntop(..., ..., ..., ...);
inet_pton(..., ..., ...);
```

- [ ] vedi le slide per concludere tutto

## funzione socket()

parametri :=: (dominio, tipo, protocollo

tipo DGRAM UDP
STREAM TCP

protocollo

- 0 si adatta al secondo parametro
- udp
- tcp
- asdas
- asdasd

## funzione bind()

(socket, puntatore ad address, lunghezza address)

## funzioni sendto recvfrom
