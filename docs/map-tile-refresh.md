# Sixteen-row map refresh and public CPU context wrapper

The translated coordinator closes four canonical bodies: C0CB43 (73 bytes), C0CB8C (4), C1803D (21), and C18012 (3), totaling 101 instruction bytes. Public bank-01 mirrors are verified without duplicate source credit. Existing row planning, upload, coordinate advance and complete NMI handler models are reused unchanged.

C0CB43 saves AA/B2/AE/B6, then performs sixteen actual row requests. B9 selects one or two layers. Each request plans rows, sets EC bit 1, waits at CB6D for an explicit external NMI edge, uploads the actual rows, and advances coordinates. The final coordinates are restored. The native comparison executes the real NMI handler and RTI; the readable model applies its independently validated translation. Neither execution clears EC by a hook or bypasses the handler. C0CB8C supplies the long return. C1803D saves P/DB/D, installs D0/DB0 and restores all original status and context after the long call. C18012 is its public JMP alias.

The primary capture passes 192 complete original calls, 32 per canonical/mirror entry, with 954 PC/M/X states and 3,072 real NMI/RTI events. Thirty-two actual map headers are sampled: 31 have two layers (32 row builders and 128 DMA transfers per call), map 407 has one layer (16 builders and 64 transfers). The separate first-layer supplement explicitly sets the native B9 input to zero on four maps, passing another 24 complete calls with 629 states and 384 NMIs. Both captures passed their first full comparison; the primary also passed its initial six-call smoke.

Verification compares all WRAM except the observed native stack writes, all video/DMA/peripheral state, returned registers and flags, D/DB/S, and exact interrupt budget consumption. Fixtures vary real map geometry, scroll boundaries, both CPU versions, all four M/X combinations, sixteen CNZV combinations and public D0/0300/1234 with DB7E/42/7F. The explicit environment uses binary arithmetic, forced blank, menu zero, 10E zero, HDMA zero and exactly sixteen external NMI edges. This proves the routine and composed handler under that environment, not console timing or every NMI branch; the handler's other branches retain their existing separate proofs.

Both dependency closures and captured tool hashes match disk. In-memory source recovery succeeds for all four bodies with unambiguous immediate widths and exact instruction boundaries. Parent integration independently assembles and compares the 101 bytes before crediting them. Existing dependency bodies receive no new source credit.

Stable primary SHA-256:

- tools/map_tile_refresh.py: 5a47d20d98c622c80398702e8b876aef671fdc26f73965a7670b42e25676ba54
- data/map_tile_refresh.json: a651ac482b68fd0f489a85c71c4fab5ade280f7205241166b22acda7e63f97a0
- data/map_tile_refresh.coverage.json: cea60aaa9d2590f00d2a4b499795e66eb2c5d5f66361e348282b52c411fe8e4b

Stable first-layer supplement SHA-256:

- tools/map_tile_refresh_first_layer_guard.py: 078afe1266fb53f564418cba6f03985fea2b6fa93d713f89423e6cdbcf849c8c
- data/map_tile_refresh_first_layer_guard.json: 2762c780c805ffa9e7e8fb63a7aa06618c6d814459bff631b2676ff1b854da8d
- data/map_tile_refresh_first_layer_guard.coverage.json: 873bfda97de32e6c42bf1647f88ab3660535b9a2d64bd4688ba94af27dc31d5d

Integration should retain the primary model and capture as the contract and attach the separate supplement as supporting evidence. No existing delivered model or shared metadata was modified.
