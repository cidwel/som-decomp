# Resolved interpreter dispatch tables

`tools/dispatch_tables.py ROM --json data/dispatch.json` records four table bases, their exact legal entry counts, dispatch instruction addresses, targets and entry M/X. The catalogue is partial; it does not resolve every ROM/RAM indirect transfer or inline argument convention.

| Interpreter | Table | Entries | Dispatch instruction | M/X at target |
|---|---|---:|---|---|
| Ordinary monster / hero AI | `$C1:2257` | 256 words | `$C1:252C`, `JSR (abs,X)` | 1/0 |
| Event commands | `$C1:E922` | 81 words, op 00-50 | `$C1:E8FF`, `JMP (abs,X)` | 1/1 |
| Event wait states | `$C1:E902` | 16 words, states 80-8F | `$C1:E8EC`, `JMP (abs,X)` | 1/1 |
| Boss/object state commands | `$C2:37CC` | 22 words, op 00-15 | `$C2:37C9`, `JMP (abs,X)` | 0/0 |

The AI dispatcher loads the script byte, masks to 8 bits, doubles it in 16-bit A/X and switches M to 1 before its indirect JSR. All 40 undefined opcode entries point to `$C1:0100`; A2/A3/C2/C3 now terminate the static walk correctly, rather than falling through the fixed-length table. Original handlers and the VM model agree in 80 generated cases for each of these four ops, with no mismatches.

The event dispatcher explicitly clamps every command byte >= 0x50 to index 0x50. Therefore it has **81** command handlers, not 96. Negative event states are doubled using 8-bit A/X, mapping the documented 80-8F range to the adjacent 16-word wait table. This identifies the defined table extent, not a bounds check for arbitrary corrupted state bytes.

The boss loader compares the selected state with object +0x7A at `$C2:377A`, resolves its pointer through object +0x76, clears the state working fields and walks commands until FF. Dispatch is `$C2:37C7-$37CB`; the first handler is `$C2:37F8`, immediately after the 22-word table. The old `statescript.py` header incorrectly cited `$C2:3799` as its entry; that address lies inside the operand of a zeroing instruction. Executed instruction boundaries from the Dark Lich harness confirm the corrected loader/dispatch addresses and M/X. Operand lengths and command names still come from the existing state-script decoder.

`rom_map.py` adds all documented table targets as candidate seeds. For a dispatch instruction present in actual coverage, its legal table targets also extend static reachability from that observed dispatch. Candidate-only bytes include scan hits and targets of tables whose dispatch has not been observed. These static bytes are not completed decompilation. Audited table bytes block accidental instruction walks through the pointer arrays themselves.
