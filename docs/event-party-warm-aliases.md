# Enlaces de reinicio caliente

Se reconstruyen C00075/3 (JMP C0009B) y C0009B/4 (JML C10018). La prueba
ejecuta la entrada de evento C1EB63 y ambos saltos reales en 9.216 casos,
202.752 instrucciones originales, hasta el cuerpo ya recuperado C10018.
Coinciden todos los registros, flags, WRAM, SRAM, hardware y la pila
abandonada, sin hooks ni exclusiones. Cruza D0/300, DB00/7E/42, ambos
M/X, todos los estados CNZV, decimal/interrupciones y cursor con wrap.

Los selectores probados son 13, 14, 15, 17, 127 y 255. No se atribuye
cobertura a los restantes por extrapolación. C10018 y la descompresión
ROM ya tienen fuentes; no se cuentan de nuevo. El estado de entrada a
ese cuerpo se conserva, pero esta prueba no ejecuta el arranque posterior.

Modelo/prueba: `tools/event_party_warm_restart_aliases.py`; evidencia:
`data/event_party_warm_restart_aliases.json`; ensamblado:
`data/event_party_warm_restart_aliases.source_audit.json`.
