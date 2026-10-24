# Reinicio en caliente desde la orden de grupo

Se reconstruye el salto de cuatro bytes C1EBEE a C00075. La prueba ejecuta
la entrada original C1EB63 hasta esa transferencia sin retorno: 9.216 casos
y 184.320 instrucciones originales, con selectores 13, 14, 15, 17, 127 y 255,
ambos tamaños M/X, todos los estados CNZV, D0/300, DB00/7E/42, estado decimal
e interrupciones, y cuatro posiciones del cursor incluyendo desbordamiento.

Coinciden CPU, WRAM completa, SRAM y hardware, incluida la pila abandonada
de la llamada corta. No se sustituyen llamadas ni se excluye memoria.
La prueba se detiene antes de ejecutar C00075: el arranque en caliente y
las restantes ramas de la orden requieren sus propios contratos. No se
atribuye cobertura dinámica a todos los selectores por estos seis ejemplos.

Evidencia: `data/event_party_warm_restart_transfer.json`; modelo y prueba:
`tools/event_party_warm_restart_transfer.py`; fuente:
`src/rom/transfer_party_command_to_warm_reset.s`.
