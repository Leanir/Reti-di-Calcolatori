---
aliases:
  - MPLS
tags:
  - modelli/rete
---
# Multi Protocol Label Switching

## Componenti

In una rete MLSP ci sono due tipi di router

- [[Label Edge Router]]
    - ingresso al circuito virtuale della MLSP
    - egresso dal circuito virtuale della MLSP

- [[Label Switching Router]]
    - un numero indefinito

## Vantaggi

- **Inoltro rapido:** 
    - L'instradamento basato su etichette è significativamente più veloce rispetto all'instradamento IP tradizionale, che richiede l'analisi completa dell'intestazione IP per ogni hop.
- **Scalabilità:** 
    - Le reti MPLS possono supportare un gran numero di connessioni VPN e flussi di traffico in modo efficiente grazie all'instradamento basato su etichette.
- **Qualità del servizio (QoS):** 
    - Le etichette MPLS possono essere utilizzate per contrassegnare i pacchetti in base alla priorità o al tipo di traffico.
- **Flessibilità:** 
    - Le reti MPLS possono essere configurate in modo flessibile per supportare una varietà di topologie di rete e servizi.