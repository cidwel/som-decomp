# Native event-menu palette workspace exchange

`EventPaletteExchange` reconstructs complete C2C7DD..C2C805: 41 instruction bytes, no new data. Real callers C1CB4F and C1CB6B bracket the general public menu with this exchange. If DP2A is zero, the routine returns after setting M8. Otherwise it establishes DB7E, exchanges all 256 words between scene palette0600 and transition paletteBE00, restores Y and DB, and leaves native M8/X16. It retains the literal accumulator clobber and final N/Z from PLB; it does not replace the exchange with a one-direction copy.

## Evidence

Smoke case1 and first full eight-call capture both returned terminal exit0 synchronously. `data/event_menu_palette_exchange_proof.json` and its coverage file contain 9,288 original instructions without hooks. Directed cases include inactive/active gates, all four incoming register-width combinations, incoming DB00/7E/7F/C0, varied direct pages and randomized full memory. Full WRAM/SRAM, CPU/context and hardware state agree outside observed stack frames.

`data/event_menu_palette_exchange_audit.json` verifies all 24 own instruction starts, 35 PC/M/X states and 29 unchanged dependency hashes. Model, checker and captured evidence are frozen after this result. The consumed palette bytes are supplied memory, not new source assets. Independent physical source recovery and joint assembly remain required before credit.

This proves the complete exchange helper. The surrounding general-menu loop and its nonreturning modal transfers remain separate caller obligations.
