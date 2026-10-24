# Event waits and saturating flag decrement

`EventWaitFlagDecrement` reconstructs the complete C1EC1A wait handler (44 bytes) and C1EC7F decrement handler, including its shared writeback and dispatch tail (33 bytes).

Opcode28 with a nonzero operand stores the tick count in4F and selects native wait state82. A zero operand selects state83, resolves the controlled actor's controller binding, decrements the binding byte, maps binding4 to index2 and clears the corresponding indexed latch. It then advances the word script cursor twice and returns with M16. The zero-operand native dispatcher supplies an accumulator high byte of zero; the direct proof preserves that caller contract rather than inventing behavior for a different incoming high byte. Raw binding0 consequently indexes FF, and all other byte values retain their actual indexed writes, including any direct-page aliases.

Opcode2A decrements only the low nibble of CF00+operand, saturates zero and preserves the upper nibble. The real shared tail advances D1 twice and resumes the native dispatcher. Its END continuation executes rather than returning through a substituted callback. The increment handler29 has a separate radial-window/particle dependency and remains open; no bytes from it are credited here.

The first16-call smoke and first9,532-call capture passed unchanged. The capture contains1,024 waits covering every operand with four controller bindings,252 additional zero waits covering all remaining binding bytes,8,192 decrements crossing all256 flag IDs,16 low nibbles and upper nibbles0/F, plus64 actual dispatcher calls. Script cursors4000,7FFC and7FFE exercise ordinary addition and signed-word boundaries. Inputs cover16 CNZV patterns and three controlled actors with D0/DB7E, M8/X8 and binary arithmetic.

All WRAM matches outside only instruction-observed stack writes. Full returned CPU state, S/D/DB, video/DMA peripherals and interrupt counters match, with no instruction hooks or NMI. The capture records81 PC/M/X states and78 dependency hashes. The existing wait-state callbacks remain separate recovered dependencies; this proof covers setup and direct decrement resumption, not every subsequent game frame.

Reproduce with `python3 tools/coverage_run.py ROM data/event_vm_wait_flag_decrement.coverage.json tools/event_vm_wait_flag_decrement.py --json data/event_vm_wait_flag_decrement.json`.

Stable tool SHA256: `42e7a6fc3f7b61ffe8d82aacca42a8277a33c1dbbfbe30071ea7d9a694420ff7`. Stable report SHA256: `1688619c11ce186a05fdaec92d122ef49aca94caf47ce93b01ccb446ca60d1ba`. Capture session51692 ended exit0. Both sources independently assemble to their exact77 original bytes and are included in the matching-source counter.
