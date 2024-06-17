---
aliases:
  - port
  - porta
---
# Socket

Una socket è una porta di **accesso**/*uscita* attraverso la quale i [[Processo|processi]] **ricevono**/*inviano* i messaggi

Ad ogni scambio sono coinvolte sempre due porte, una per host di comunicazione.

## Well-known 

`[ 0 .. 1023 ]` porte riservate ai servizi di sistema

> [!example]- Esempi di porte note
> 
> |         |                                  |
> | ------- | -------------------------------- |
> | 20/tcp  | FTP - data                       |
> | 21/tcp  | FTP - control                    |
> | 22/tcp  | SSH - Secure login               |
> | 23/tcp  | Telnet                           |
> | 25/tcp  | SMTP                             |
> | 53/tcp  | DNS                              |
> | 53/udp  | DNS                              |
> | 67/udp  | BOOTP (Server) and DHCP (Server) |
> | 68/udp  | BOOTP (Client) and DHCP (Client) |
> | 69/udp  | TFTP                             |
> | 70/tcp  | Gopher                           |
> | 80/tcp  | HTTP                             |
> | 88/tcp  | Kerberos Authenticating Agent    |
> | 110/tcp | POP3                             |
> | 123/udp | NTP                              |
> | 143/tcp | IMAP4                            |
> | 161/udp | SNMP (Agent)                     |
> | 162/udp | SNMP (Manager)                   |
> | 443/tcp | HTTPS                            |
> | 465/tcp | SMTP over SSL                    |
> | 993/tcp | IMAP4 over SSL                   |
> | 995/tcp | POP3 over SSL                    |

## Registered

`[ 1024 .. 49_151 ]` porte assegnate dalla Internet Corporation for Assigned Names and Numbers (ICANN) per uso specifico

## Dinamiche e/o Private

`[ 49_152 .. 65_535 ]`