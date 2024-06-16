---
tags:
  - modelli/rete
aliases:
  - TCP/IP
---
# Modello Transmission Control Protocol / Internet Protocol

![[Pasted image 20240617000114.png]]

## Livello di Applicazione

Questo livello è analogo al livello di trasporto del modello OSI. È responsabile della comunicazione end-to-end e della consegna dei dati senza errori. Protegge le applicazioni di livello superiore dalla complessità dei dati.

- HTTP
- SSH
- NTP
- FTP
- SMTP/IMAP4
- Telnet
- DNS
- RIP
- SNMP
- TFTP
- BOOTP
- DHCP
- OSPF

## Livello di Trasporto

I protocolli del livello di trasporto TCP/IP si scambiano i riconoscimenti di ricezione dei dati e ritrasmettono i pacchetti mancanti per garantire che i pacchetti arrivino in ordine e senza errori. La comunicazione end-to-end viene definita come tale. Il protocollo TCP (Transmission Control Protocol) e il protocollo UDP (User Datagram Protocol) sono protocolli a livello di trasporto all'interno di questo livello.

- TCP
- UDP

## Livello di Rete

Questo livello è parallelo alle funzioni del livello di rete di OSI. 
Definisce i protocolli responsabili della trasmissione logica dei dati sull'intera rete. 

- IP
- ICMP 
- ARP
- IGMP

## Data Link Layer

Il tipo di protocollo di rete del pacchetto, in questo caso TCP/IP, è identificato dal livello di collegamento dati. La prevenzione degli errori e il Framing sono forniti anche dal livello di collegamento dati. 

- PPP
- Ethernet IEEE 802.2 Logical Link Control

## Livello Fisico

Si tratta di un gruppo di applicazioni che richiedono comunicazioni di rete. Questo livello è responsabile della generazione dei dati e della richiesta di connessioni. Agisce per conto del mittente e il livello di accesso alla rete per conto del destinatario.

- ISO 802.3 z Gigabit Ethernet
- ISO 802.2 Ethernet