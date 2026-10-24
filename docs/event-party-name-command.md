# Edición de nombres desde la orden de grupo

Los selectores 0, 1 y 2 abren la pantalla de nombre del personaje elegido.
C1EB71/11 transfiere el selector a X, carga la acción cero y llama a
C0000F→C0008F→C01D97. La acción cero selecciona la página tres, cuyo
constructor C02AA4 llama a C75000. Al salir ejecuta C1FF3A y retorna.
Se reconstruyen los once bytes del caller y los dos aliases de tres bytes;
las fuentes de menú, nombres, héroes y pantalla ya presentes no se cuentan
de nuevo.

La prueba ejecuta 6 callers completos y 1445017
instrucciones originales. Cada personaje tiene dos planes de botones:
B/release/Start para añadir y confirmar un glifo real de ROM, y
Start/release/B/release/Start para rechazar primero un nombre vacío.
No se fuerza ningún retorno ni estado de salida. El modelo compone
HeroInitialize y la restauración de pantalla con llamadas reales originales.

Los tres personajes comparten el mismo contexto ordinario de mapa cero,
producido por la prueba ya verificada de solicitud de guardado: NewGame,
tres héroes y SRAM coherente, cabecera/recursos/puertos de mapa. Sólo cambia
el selector de evento y el plan de botones. No se afirma inicialización
completa del mundo ni un contexto de restauración de jefe. D0/DB7E,
M16/X16 de entrada, byte alto de A cero, modo nativo y binario.
Coinciden CPU, WRAM, SRAM, contexto, gráficos/audio, controladores y NMIs
fuera de la pila consumida observada, sin hooks. Todas las starts/anchuras
propias se observan antes del ensamblado independiente exacto.

El menú general C01D97 sigue sin contrato completo: CFF6 no nulo y
C7D000 requieren el comportamiento real de la vía excepcional, que no
puede sustituirse por un retorno. Tampoco se prueban otros tamaños/DB/D
de entrada ni alcanzabilidad durante una partida con esta prueba.

Modelo: `tools/event_party_name_command.py`; prueba:
`tools/event_party_name_command_proof.py`; evidencia:
`data/event_party_name_command.json`; fuentes:
`src/rom/edit_hero_name_from_party_command.s`,
`src/rom/jump_public_native_name_menu.s` y
`src/rom/jump_internal_native_name_menu.s`.
