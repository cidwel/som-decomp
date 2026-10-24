# Native event commands 0A and 41

`EventMapRedraw` reconstructs C1EA99/10 and C1F10E/50, totaling60 instruction bytes with no overlap in catalogued matching-source intervals. Opcode0A increments the native word script cursorD1, sets carry and calls00CAFF to reload conditional map pieces and redraw. Opcode41 takes its first operand from dispatcher scratch05, reads the remaining real long script operands, advances only the wordD1 by five without incrementingD3, transforms its packed coordinates through the exact XBA/ASL/AND/conditionalORA/LSR sequence, clears carry and calls the same complete bank00 coordinator for an individual piece.

The four-call smoke passes after correcting an unavailable model helper name before the first opcode41 original call. The first complete128-call capture passes:64 calls per entry, actual map/piece inputs, both layer cases, geometry/scroll boundaries, all sixteen flag combinations, D1 boundary and word-wrap cases, and long operand reads crossing7EFFFF into7F. The cases record script_start and script_next, proving the deliberate difference between long operand address carry and word cursor advancement. Generated fixture operands are runtime input only; no ROM scripts or assets are persisted.

Every call executes sixteen complete original NMI/RTI edges through the full redraw dependency chain:2,048 real interrupts. Coverage contains1,248 PC/M/X states. All randomized WRAM outside only observed stack writes, video/DMA/peripheral state and complete returned CPU/context state agree; the minimum stack address is1EE1. No instruction hooks, redraw bypass or forced EC completion is installed.

The explicit environment uses D0/DB0, M8/X8, binary arithmetic, valid map/piece data and generated long scripts, forcedblank, menu0,10E0 andHDMA0. This proves these two complete opcode handlers and their real map redraw calls, rather than claiming the entire event VM or console interrupt timing. Other handlers and text rendering remain separate reconstruction frontiers.

All42 dependency hashes and captured tool hash match disk. In-memory source recovery succeeds for both bodies with unambiguous immediate widths and exact boundaries. Parent independently assembles and compares the60 original bytes; existing redraw/piece/NMI dependency sources are reused without new credit.

Stable SHA-256:

- tools/event_map_redraw.py: 008318fe9983720fa78f2bf69bf49f16ee60635271b41d96a4688030bfee85f6
- data/event_map_redraw.json: 6ebaf8cc290d95ec7ef936788d329d3cb3e4d06933d2db4f24418e75a7579a2f
- data/event_map_redraw.coverage.json: 4dc905a7a8e23626e0076920d73eed4309e04bc1f4997d98573a17eb67284ddc

The next coherent family contains event control handlers, the actual three-hero freeze helper, wait-state resume logic and the dispatch coordinator. Its implementation remains separate and unproven until its own original comparison.
