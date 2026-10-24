# Cofres desde la orden de grupo

La rama del selector 12, C1EBD4..C1EBE0, tiene trece bytes reconstruidos.
Avanza el cursor, carga el actor destino de D4 y el cofre de 3A, y ejecuta
la llamada pública C00066 con retorno real. Los cuerpos ya recuperados de
recompensas, inventario, oro y avisos no reciben crédito adicional.

La prueba compara 1024 llamadas originales completas y
410694 instrucciones: las 256 identidades de cofre, cuatro
contextos de inventario, orbes, oro y estado, D0/300/1234/1800, ambos tamaños
M/X de entrada, DB7E, aritmética binaria, interrupciones y cursor con
desbordamiento. CPU, WRAM, SRAM y periféricos coinciden fuera de la pila
consumida observada; no hay hooks. Las seis instrucciones propias y sus
tamaños de operandos se observan antes de ensamblar la fuente.

Son contextos de prueba del consumidor; no prueban que cada combinación
sea alcanzable durante una partida. Las otras variantes de la orden y
la ejecución completa de eventos siguen abiertas.

Modelo: `tools/event_party_chest_command.py`; prueba:
`tools/event_party_chest_command_proof.py`; evidencia:
`data/event_party_chest_command.json`; fuente:
`src/rom/open_chest_from_party_command.s`.
