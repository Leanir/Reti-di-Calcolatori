---
aliases:
  - FTP
tags:
  - protocollo/applicazione
  - protocollo/stateful
---
# File Transfer Protocol

FTP (File Transfer Protocol) è uno dei protocolli più vecchi progettati per Internet, con lo scopo principale di trasferire copie di un file tra due macchine. Questo protocollo è bidirezionale, permettendo all’utente di caricare file sul server e di scaricare file dal server al filesystem locale. Inoltre è stateful con sessione di lavoro unica. 

*Fun fact: il supporto a FTP è stato dismesso da Google Chrome e Firefox nel 2021*

## Porte

Utilizza due connessioni separate: 
- Porta 20 per il trasferimento dei dati
- Porta 21 per la connessione di controllo. 

## Apertura

La prima operazione che viene eseguita con il protocollo FTP è l’operazione di login su un server remoto tramite l’interfaccia utente. FTP invia le **credenziali in chiaro** e non dispone di meccanismi di autenticazione del server presso il client.

## Chiusura

- Timeout, il server chiude la connessione per inattività dell’utente
- Attivamente dall’utente con i comandi di uscita.
