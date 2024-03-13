---
Data: 2024-03-13T00:00:00.000+01:00
Docente: "[[Luca Guarnera]]"
Argomenti:
  - C
  - File Binari
  - Gestione File
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
