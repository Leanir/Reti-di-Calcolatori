---
Data: 2024-03-13T00:00:00.000+01:00
Docente: "[[Luca Guarnera]]"
Argomenti:
  - C
  - File Binari
  - Gestione File
  - Virtualizzazione
---

| **Docente** | `VIEW[{Docente}]`        |
| ----------- | ------------------------ |
| **Data**    | `INPUT[datePicker:Data]` |

robe viste da approfondire:

- `fprintf()`
- `fseek()

# C

## File Binari

### output binario

```C
fwrite(address, int dim, int n, FILE *f)
```

### input binario

```C
fread(address, int dim, int n, FILE *f)
```

## files

### apertura

Per aprire un file si usa la funzione `fopen(char fname[], char mode[])`

```C
fopen(char fname[], char mode[])
---
FILE *fp;
fp = fopen("esempio.txt", ?)
```

### scrittura

```C
fprintf(FILE* f, "", %);
```

### Lettura

```C
fseek() //permette di spostare testina nel file
```

### Controlli

end of file check

```C
feof()
```

## Lettura stringhe

```C
char *fgets(...)  //useremo di più queste per interazioni client-server

int fputs(char *s, FILE *fp)
```

---

# Esercizi

1. boh cercalo nella slide
2. sostituire tutte le maiuscole in minuscole in un file di testo fornito come unico dato di ingresso
3. salvare su un file binario binary.dat contenuto di un array di dieci interi

# Setup per Virtualizzazione

una volta settata una macchina virtuale, si useranno dei cloni per evitare tutti i casini ogni volta! comfy!

## virtualbox

### overview

va a tradurre istruzione che vogliamo eseguire rispetto all'hardware che si possiede, la manda alla scheda di rete, verrà eseguita e poi ancora ritornerà

i danni rimangono dentro virtualbox e non intaccano macchina ospitante

conserva in un file xml tutti i dettagli su numero di schede di rete, funziona! non ci interessa sapere come (abbiamo una sola scheda fisica)

### setup vero

1. scarica ultima version eper sistema operativo host
2. apri virtualbox
   1. nuova
      1. inserisci nome (Debian AL)
      2. cartella tiene tutti i file di configurazione della macchina
      3. ISO -> inserire path della distribuzione [[Lez L02#debian|debian]]
      4. tipo ->linux
      5. salta installazione non supervisionata
         1. guest additions (per ora non li usiamo, a fine corso)
      6. hardware
         1. default
      7. disco fisso
         1. creane uno ora (2 GB sembra andare bene)
         2. tipo -> tieni VDI
      8. fine
   2. impostazioni
      1. rete
         1. abilita schede di rete (per ora solo la prima)
            1. in futuro possiamo maneggiare file XML per aggiungere più di 4
         2. connessa a -> lascia NAT
            1. in futuro useremo rete interna (per routing) e scheda solo host (connessione con host)
               1. rete interna -> nome = LAN
               2. se due reti interne hanno stesso nome sono forzate a stare nella stessa LAN
   3. Avvia macchina
      1. ~~Graphical~~ install
      2. Lingua -> duh
      3. termina installazione

## debian

una volta dentro la schermata di installazione e avendo settato install e lingua, procedi a premere invio un paio di volte, e setta una password per root [password::root]

password per user :: user

partizionamento -> guidato - usa intero disco

prosegui confermando tutto

scrivere modifiche -> Sì!

mettere no alle cose più scomode

selezione del software -> server ssh e utilità sistema standard

GRUB? -> Sì!

dev/sda/

### GCC

`apt install gcc`

![[Pasted image 20240313124831.png]]

### verifica install ssh

`ps ax | grep sshd`

## vscode
