# Native menu icon placement and two-row strip

[V] Six bodies consume215 instruction bytes: C75F13/13 draws two four-tile groups, C75F20/42 selects an original position record and tile/OAM cursors, C76CEB/44 applies the page4 hero-name position override, C76D17/25 draws a four-tile group, C76D30/39 emits one tile, and C76D57/52 fills a29-column strip. C76D5C is the alternate native strip entry inside the last source; its bytes are counted once.

The icon emitter uses A15A then A159 as grid coordinates, multiplies each by8 using byte arithmetic, and writes the two original ROM tile/attribute bytes. Quad/group callers preserve their literal coordinate increments and decrements, including byte overflow. C75F20 reads the real eleven-word position table, chooses one of four tile sequences and positions OAM using the low two selector bits; on page4 C76CEB replaces coordinates from A136 and offsets hero2 by one row/column.

The strip publishes29 top/bottom tile pairs, advances tile values by4 per column and clears the trailing pair. Both20-based and21-based tile sequences follow their real entrypoints and set the tile-publication bit; index/accumulator widths and flags remain native.

Smoke6 and first full76 original comparisons pass without corrections. They cover all11 selectors, page0/4/7, all heroes, byte wrap, four initial flag contexts and both strip entrypoints. Full memories/peripherals/CPU/context agree outside observed stack; no hooks/NMI. Contracts D0/DB7E/M8/X16/binary. Original instructions executed:9068. Runtime tile-table bytes are never saved as ROM payloads. Full interactive page initializers remain open.

Evidence: `data/event_menu_page_sprites_proof.json`, its `.coverage.json` and `data/event_menu_page_sprites_source_audit.json`; report freezes dependency hashes.

La captura primaria de 76 llamadas conserva dos inicios pendientes (C76D10/C76D13). La captura independiente de 120 llamadas de PartyIcons alcanza ambos con hero 2/página 4. `data/event_menu_page_sprites_complete_source_audit.json` verifica la unión completa sin repetir ni modificar la captura primaria.
