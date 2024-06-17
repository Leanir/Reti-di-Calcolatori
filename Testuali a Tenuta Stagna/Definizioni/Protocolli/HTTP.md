---
tags:
  - protocollo/applicazione
  - protocollo/stateless
  - paradigma/client-server
aliases:
  - HyperText Transfer Protocol
---
# HyperText Transfer Protocol

HTTP è composto da una serie di connessioni [[TCP]] separate che sono collegate da un’unica sessione logica di livello superiore tramite i cookie. Sono i cookie che realizzano lo stato all’interno di HTTP.

## URI

Il client ha un applicativo (browser) che spedisce una richiesta al server web, specificando un **U**niform **R**esource **I**dentifier. 

### URL

Ogni pagina web consiste di una base HTML che include più oggetti referenziati, ognuno indirizzabile con un **U**niform **R**esource **L**ocator.

> [!example]- URL
> 
> `www.unict.it/` Host name        
> `sites/all/themes/id_theme_unict/logo.svg` path name
> 
> ![](https://www.unict.it/sites/all/themes/id_theme_unict/logo.svg)

### Documenti

### Indirizzo posta elettronica

### Codice ISBN di un libro

### Numero telefono con prefisso internazionale

---

## Richiesta HTTP

La richiesta è del seguente formato

```
<METODO> <URI> <HTTP_version>[cr][lf]
<PARAMETRO INTESTAZIONE>[cr][lf]
...
<PARAMETRO INTESTAZIONE>[cr][lf]
[cr][lf]
<BODY>

<METODO>:
    - GET:     Richiesta per leggere una pagina web
    - HEAD:    Richiesta per leggere un header di una pagina web
    - PUT:     Richiesta per conservare una pagina web
    - POST:    Fare un APPEND a una risorsa nominata
    - DELETE:  Rimuovere la pagina web
    - TRACE:   Fare una ECHO alla richiesta in arrivo
    - CONNECT: Conservare per uso futuro
    - OPTIONS: Fare una query per certe opzioni

<PARAMETRI INTESTAZIONE>: lista di parametri nella forma "X: something", ad esempio
"""
    Host: website.com
    User-Agent: Chrome/5.0 (Windows 10)
    Accept-Language: en-US
    Accept-Encoding: gzip, deflate
    Connection: keep-alive</code.
"""
```

## Risposta HTTP

```http
<VERSIONE> <STATUS> <text>[cr][lf]
<PARAMETRO INTESTAZIONE>[cr][lf]
...
<PARAMETRO INTESTAZIONE>[cr][lf]
[cr][lf]
<BODY>

"""
HTTP/1.1 200 OK 
Date:           Mon, 27 Jul 2022 12:28:53 GMT 
Server:         Apache/2.2.14 (Win32) 
Last-Modified:  Wed, 22 Jul 2022 19:15:56 GMT 
Content-Length: 88 
Content-Type:   text/html 
Connection:     Closed

<!DOCTYPE HTML PUBLIC “-//IETF//DTD HTML 2.0//EN”></code.
"""
```

### Codici di stato HTTP

#### 1xx Codici di informazione

#### 2xx Codici di Successo

#### 3xx Codici di Reindirizzamento

#### 4xx Codici di Errore Client

#### 5xx Codici di Errore Server



---

## Versioni HTTP

### v1.0

prevedeva una chiusura della connessione diretta ogni volta che veniva mandato un singolo file; nel caso quindi della richiesta di più file, veniva utilizzata una connessione per ogni file.

### v1.1

permette di specificare da parte del client, di tenere aperta la connessione finché il client capisce di aver caricato interamente la pagina web, e solo allora la connessione viene chiusa

### v2.0

uses header compression, permits "push" dispatch and parallel download (RFC 7540 - 96 pagine)

### v3.0

Vietas connessioni TCP multiple verso lo stesso server
