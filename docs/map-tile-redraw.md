# Piece reload, direct decode and complete map redraw

The composed model reconstructs C0CAFF/40 and C0CB27/28, 68 instruction bytes not overlapping any currently catalogued matching-source interval. CAFF saves scratch20..2F to05F0..05FF, invokes the internal coordinator, restores that scratch and returns RTL with DB0. CB27 uses native carry: set reloads the actual map piece list and allocates trigger tiles; clear clears the piece cache and executes the independently proved interior CC72 entry. Both branches continue directly into the complete sixteen-row CB43 refresh. The real event callers use the bank-00 CAFF mirror, also compared here without duplicate byte credit.

The initial six-call smoke and first full 192-call capture pass without model changes. The full comparison covers 64 calls each to C0CAFF, C0CB27 and00CAFF, both carry paths, actual map and referenced piece inputs, one/two-layer cases, geometry/scroll boundaries and all four M/X combinations. Each call consumes exactly sixteen explicit external NMI edges and executes the complete original handler and RTI: 3,072 native interrupts in total. Coverage contains2,330 PC/M/X states. No hooks, replaced piece calls or forced EC completion are installed.

All randomized WRAM outside only observed native stack writes agrees, together with video/DMA/peripheral state and complete returned CPU registers/flags, S/D/DB. The lowest observed stack address is1EE3. The environment is binary,D0/DB0,forcedblank,menu0,10E0,HDMA0; caches and maps are valid. It proves both composed redraw branches in this explicit interrupt environment, without claiming live console timing, arbitrary corrupt maps or every possible NMI branch.

All41 dependency hashes and the captured tool hash match disk. In-memory source recovery succeeds for both full bodies with unambiguous immediate widths and exact boundaries. Parent independently assembles and compares the original bytes before assigning68 new bytes. Dependencies, including interior CC72/289 already covered by CBD1/450, receive no duplicate credit.

Stable SHA-256:

- tools/map_tile_redraw.py: 705b32f132dd4d112de6969bc074078ce9731bceac0171c3f7ae2c467e0e1b9d
- data/map_tile_redraw.json: 15b4ba44986f00b9901310baf31edd2a981fabda2983c4300aaaf87a4d86b95e
- data/map_tile_redraw.coverage.json: 585917ef460a341f5ea527bde2138ed3282a4deb25e92db1b8aeac946fe87f38

The next real consumers are event0A C1EA99/10 and event41 C1F10E/50. Their readable model and checker are prepared separately; neither has been counted or proven by this capture.
