---
Data: 2024-05-06T00:00:00.000+02:00
Docente: "[[Luca Guarnera]]"
Argomenti:
  - Rete interna
  - Smistamento IP
---

| **Data**    | `INPUT[datePicker:Data]` |
| ----------- | ------------------------ |

![[Pasted image 20240506103611.png]]

catyella dei config
![[Pasted image 20240506103718.png]]
entriamo nella cartella network
![[Pasted image 20240506103754.png]]


fai 
nano interfaces

![[Pasted image 20240506104332.png]]
nelle schede rete interna abbiamo assegnato un indirizzo IPv4 statico

nella scheda solo address invece abbiamo usato il dhcp perché siamo belli

dopo il reboot della macchina:
![[Pasted image 20240506104551.png]]

con ip route verifichiamo _
![[Pasted image 20240506105147.png]]

---

creiamo una maccina B con solo una scheda rete interna abilitata (nel mio caso alla LAN_04, ma basta che abbia una lan qualsiasi compatibile con la macchina A)

![[Pasted image 20240506105746.png]]

qui abbiamo creato una scheda di rete temporanea

## Smistamento IP

Abbiamo una subnet  145.67.0.0/16

in binario:
    10010001.01000011.00000000.00000000
    11111111.11111111.00000000.00000000

dobbiamo spartire questi 2^16 indirizzi in 4 subnet interne
    LAN 1 -> 100 IP
    LAN 2 -> 140 IP
    LAN 4 -> 1000 IP
    LAN 3 -> 11000 IP
garantendo la massima espandibilità (ulteriori subnet)

### Metodo dell'albero binario
più si va in fondo nell'albero più aumentiamo la maschera

LAN 1 -> arriviamo a maschera 25 (128 indirizzi IP)
LAN 2 -> 
LAN 3 -> 
LAN 4 -> maschera 18 (16k indirizzi IP)
    da 145.67.


---

ho perso ufficialmente l'attenzione alle 12:28

---

nano sysctl.conf
scommentare riga in base ad esercizio
net.ipv?.conf.all.forward=1