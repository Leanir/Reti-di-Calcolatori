---
tags:
  - hardware/router
aliases:
  - LSR
  - Router di Transito
---
# Label Switching Router

**LSR** è un componente delle reti [[Multi Protocol Label Switching]] che garantisce un inoltro rapido, scalabile e affidabile dei dati.

È un router specializzato che inoltra i pacchetti dati basandosi su etichette **MPLS** anziché sugli indirizzi IP tradizionali.

## Funzionamento

1. Ricezione del pacchetto dati da un router client.
2. Estrazione dell'etichetta MPLS dall'header del pacchetto.
3. Consulta la tabella di inoltro MPLS per determinare il prossimo router a cui inoltrare il pacchetto.
4. Inoltro del pacchetto al router successivo, aggiungendo una nuova etichetta MPLS se necessario.

---

#todo
- [ ] 📅 2024-06-17 check for functioning diagram