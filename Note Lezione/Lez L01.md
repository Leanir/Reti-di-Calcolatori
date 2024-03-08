---
Data: 2024-03-08
Docente: "[[Luca Guarnera]]"
Argomenti:
  - C
---
Data Lezione: `INPUT[datePicker:Data]`
Docente: `VIEW[{Docente}][link]`

---

![[HelloWorld.c]]



# Intro C

```C
// tipi di variabili
// array e matrici

printf("valore di a è %d", a);

scanf("%d", &a); // passa riferimento a variabile per scrivere da input

if () { } else { }

switch() {
	case _:
	...
}

// cicli
while (cond) { }

do { } while (cond);

for (ini; cond; step) { }

break;    -> esce dal ciclo attuale
continue; -> 

---

#include <string.h>

struct nomeStruct 
{
	tipo1 nome1;
	tipo2 nome2;
	...
	tipoN nomeN;
}

malloc() // -> allocazione dinamica da <stdlib.h>
```

---

# Esempio `struct` Persona

```C
#include<stdio.h>
#include<string.h>

typedef struct Persona { char nome[50]; char cognome[50]; int age; } pers;

int main (int argc, char const **argv)
{
	scanf("%s", pers.nome);
	scanf("%s", pers.cognome);
	scanf("%d", &pers.age); 
	// solo questa vuole reference perché gli altri son vettori

	printf("%s", pers.nome);
	printf("%s", pers.cognome);
	printf("%d", pers.age);
}
```

# comandi terminale

man -> manuale/documentazione di C


# Simulazione autenticazione

#esercizio da implementare coi file

- in un file simulare un server
	- servere deve capire se client vuole registrarsi o fare login
- in un altro file simulare il client
	- scrive dati 0 1 ogni riga, seguito da utente e password


| client.c             | server.c                                         |
| -------------------- | ------------------------------------------------ |
| crea file temporaneo |                                                  |
|                      | interpreta file temporaneo                       |
|                      | se registra, verifica che non sia già registrato |
|                      | se accedi verifica che abbia account             |
 
 ---

# Puntatori in C

operator & => indirizzo di memoria
! puoi fare un puntatore a tipo base

ha fatto vedere esempi di blocchi codice, forse li recupero dopo e li scrivo meglio dopo aver fatt esercizio

## Relazione tra puntatori e array

## strutture e puntatori

## Swap() con puntatori

---

# operazioni bit a bit

- AND
- OR
- XOR
- NEGAZIONE

- SHIFT
	- sinistro
	- destro

#esercizio fare un programma in C che applichi le operazioni qui sopra


