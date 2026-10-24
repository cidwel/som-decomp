# Punteros mutables de los descriptores de jefes

Las pruebas conservan los valores escritos por el asignador original C23438.
No sustituyen los callbacks por destinos elegidos durante el recorrido.
El contexto inicial es una entrada ABI declarada, no una partida completa:
D0200/DB7E/M16/X16, variante y fase cero, HP100/100, tres personajes activos,
ocho ranuras de jefes ocupadas y una libre. Se prueban las nueve ranuras.

`data/boss_mutable_descriptor_dispatch_proof.json` registra 135 asignaciones
originales y 540 llamadas completas a los cuatro consumidores de descriptor.
Los 15 registros producen 468 saltos y 52 destinos distintos; los campos nulos
regresan sin saltar. Cada ruta parte de una copia del resultado real de la
asignación. Los sitios C235C8/C23613/C2361E/C23629 mantienen PB, S y el marco
de retorno en el JMP. La comparación incluye WRAM fuera del stack realmente
consumido, CPU/contexto/periféricos/audio. Crédito de fuente adicional: cero.

`data/boss_mutable_definition_start_proof.json` sigue otras 135 asignaciones
hasta la definición, inicialización y primer estado completos, y después el
consumidor de movimiento C211F4. Ejecuta 114422 instrucciones originales.
El campo8E=34D8 viene del asignador; B4/B6/B8/BA del descriptor;90/48/4A del
primer script real. C20F8E/C21222/C236B5 quedan observados en estos dominios,
además de C235C8. WRAM fuera del stack consumido, SRAM, CPU/contexto,
periféricos y audio coinciden. No hay hooks que eviten instrucciones.

Esta composición reveló un hueco real: el primer estado del descriptor1
instala C24413 como callback de finalización. El modelo
`tools/boss_descriptor_one_completion.py:OneCompletion` reconstruye sus36
bytes completos. Variante0 termina inmediatamente con carry1. Otras variantes
devuelven carry0 antes del tick24, carry1 desde60; entre24 y59 seleccionan
el objetivo y terminan si la distancia Manhattan en unidades de16 píxeles
es menor que5. Se preservan los valores y flags literales del original.

`data/boss_descriptor_one_completion.json` y su cobertura contienen324
llamadas originales sin hooks: variantes0/1/FFFF, tiempos0/23/24/59/60/FFFF,
distancias a ambos lados de80 píxeles, ambos carry iniciales y nueve actores.
La auditoría independiente comprueba cada comienzo de instrucción y el
ensamblado exacto antes de conceder36 bytes de fuente nuevos.

No se extienden estas pruebas a todas las variantes, scripts posteriores,
combates, creación de hijos con ranuras libres, punteros de muerte o loader.
La frontera estática de11 sitios mutables permanece como inventario de ABI:
estas pruebas añaden dominios producidos, no convierten cada puntero en una
tabla constante ni demuestran el100% global.
