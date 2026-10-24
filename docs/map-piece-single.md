# Direct map-piece initialization and deferred replay

`tools/map_piece_single.py:decode` reconstructs C0CC72..C0CD92, 289 instruction bytes already physically covered by the matching C0CBD1/450 source. This is a new readable contract and original proof for its interior entry, with **zero newly recovered bytes**. It selects the original CC/CD/CE/CF bank using the three CD0000 thresholds and indexed pointer table, reads dimensions and subpiece flags, initializes first/second-layer extents when absent, constructs the real FF00 subpiece pointer cache, invokes the existing complete CD93 body decoder, and replays every deferred FF20 placement until its terminator. It preserves the native byte-index truncation, carry arithmetic for pointer additions and packed subpiece dimensions. Existing CD93, conditional-piece loading and supporting data models receive no duplicate source credit.

The first eight-call smoke passed. The first full capture passed 3,176 original calls: all 794 distinct piece IDs referenced by real map lists, crossed with both layers and initialized/uninitialized layer dimensions. Coverage records 506 PC/M/X states, all four source banks, and up to 49 actual deferred subpieces in one call. No instruction hooks or replaced body calls are installed.

Full randomized WRAM agrees outside only the observed native stack writes (lowest address 1EFB), together with A/X/Y/C/N/Z/V/M/X-width/S/D/DB and static video/DMA/peripheral state. The input domain uses D0, DB7F, X8, binary arithmetic, a cleared FF00 work cache, zero deferred count, valid layer destinations at 0000/4000, both accumulator widths, flag variations and ignored upper piece-ID bits. This covers the 794 IDs present in real lists; the remaining arbitrary table indices, corrupted caches, arbitrary direct pages and console timing are not claimed.

Captured tool hash and all 19 dependencies match disk. In-memory source recovery confirms the complete 289-byte body, unambiguous immediate widths at every required instruction, and exact instruction boundaries. The existing containing source already supplies the byte-exact assembly; integration records this interior contract without adding an overlapping source or counting its bytes again. The callable contract intentionally remains `decode(rom, state)` using the existing `map_piece_body.State`, rather than introducing a separate wrapper class.

Stable SHA-256:

- tools/map_piece_single.py: 68d372cd2419836fbfe7f7e5357bf28061543141a701092ee813d5d80af677f7
- data/map_piece_single.json: 233111e1b80a1d0e2d333f6e7c4b77de7d48f6bc027f7710a2aa29269d0ff1c0
- data/map_piece_single.coverage.json: 801374389732592f183ba099da2e374fd4c5a061b0af429409a48c194f2c209b

The next composition is C0CAFF/40 and C0CB27/28: event opcodes 0A and 41 reload conditional pieces or invoke this direct decoder, then execute sixteen real NMI-driven redraw rows through the stable MapTileRefresh model. That composition has a readable implementation and checker prepared but remains unverified until its separate original comparison.
