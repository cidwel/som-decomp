# Posición controlada desde la orden de grupo

La rama del selector 16 reconstruye trece bytes C1EBE1..C1EBED. Avanza el
cursor D1 sin extender D3, pone M/X a dieciséis bits, carga D4 y llama a
C00072 con retorno real. Los 81 bytes de C00072/C0385A/C03E35 ya existen
en las fuentes y no reciben crédito adicional.

La prueba ejecuta 576 callers originales completos, 33.696 instrucciones,
con seis patrones de controladores: sin controlador, prioridad del primer
valor negativo y enlaces 1..4. Cruza DB00/7E, ambos tamaños M/X, D0/300/1234
y cuatro posiciones del cursor con desbordamiento; varía D4 y el estado
inicial de registros, WRAM y SRAM. Coinciden CPU, WRAM, SRAM, contexto y
hardware fuera de la pila consumida observada, sin hooks. Se observan las
seis instrucciones propias y sus tamaños antes del ensamblado exacto.

Evidencia: `data/event_party_snapshot_command.json`; modelo:
`tools/event_party_snapshot_command.py`; prueba:
`tools/event_party_snapshot_command_proof.py`; fuente:
`src/rom/save_controlled_position_from_party_command.s`. Esto no cierra las
otras ramas del comando ni demuestra alcanzabilidad en una partida.
