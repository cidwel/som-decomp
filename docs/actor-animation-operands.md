# Actor animation operand readers

`tools/actor_animation_operands.py:AnimationOperands` reconstructs four native entries totaling318 instruction bytes. These are callees of the still-open C0F90B animation command reader, which is itself reached from C0F4CB. The complete ordinary actor updater is not claimed.

| Entry | Bytes | Behavior |
| --- | ---: | --- |
| C1D48D | 118 | Read three overlapping operand bytes, advance the low script pointer by4; F8 sets signed/mirrored X/Y and Z velocity, F9 sends the actual nonmusic audio packet and reduces pointer consumption to3. Other commands return after the operand read. |
| C1D503 | 39 | Derive native volume/panning from the actor screen byte. The entry branches on incoming Z, not an independent comparison of A. Its nonzero path loads actorE10C into Y and restores Y. |
| C1D52A | 150 | Read two operands and advance by3; F0 decodes packed XYZ nibbles, F1 saves continuation and replaces the low pointer in the same bank, other commands issue actual PPU color/subscreen writes and set an effect timer. |
| C1D5C0 | 11 | Advance by1 and fall through into the existing273-byte C1D5CB low-command dispatcher. |

F8 horizontal and vertical signed-byte conversion differ literally: horizontal negative values XOR7F, increment and OR80 before mirroring; vertical negative values XORFF, increment and OR80. Mirrored negative zero becomes0. F0 Z has a different signed-nibble encoding from horizontal/vertical velocities. The helper calls preserve high accumulator bytes left by the16-bit pointer operations; saving only the initial low command byte is intentional.

F9 executes C30004 and the original packet sender with input acknowledgements supplied at the APU port boundary. There is no instruction bypass hook. The ordered port writes and preserved caller registers are compared. This is not an SPC instruction, waveform or timing proof.

`data/actor_animation_operands.json` records13,824 complete original calls:10,240 packed reader calls,2,304 velocity/sound reader calls,512 volume calls and768 low-command wrapper calls. F0 covers all4,096 XYZ nibble combinations with both mirror states in writable RAM; F1..F7 and F8..FF each cover all256 first operands. The volume helper covers every screen byte with incoming Z independently varied. All48 low commands have16 contexts with real palette dependencies.

An additional512 boundary cases retain actual operands from banks7E/7F/D1/D2 and low pointers4000/FFFD/FFFE/FFFF. Reads carry through the24-bit long address; advancing the script pointer wraps only its low16 bits. At7F:FFFF the next operand can read the DP pointer itself through80:0000. Boundary fixture injection avoids overwriting those pointer bytes. See `docs/analysis-animation-reader-carry.md` for the initial failed fixture and the distinction between bank carry, self-aliasing and2MiB ROM mirrors. The local reader supports the verified WRAM/ROM domain and rejects peripheral-address operands outside it; arbitrary malformed pointers are not proven.

Full randomized128KiB WRAM outside129 caller-stack bytes, CPU/S/D/DB, static video/peripherals and1,440 ordered audio writes agree. There are1,728 screen-effect calls. Domain: D0/DB7E/M8/X16/binary,12 aligned actors, valid palette cursors. The evidence trace stores addresses and width states without original byte payloads. Matching assembly is independently regenerated for the318 new bytes; a591-byte component joins these entries with the existing low dispatcher without adding credit for its273 bytes again.

Next: compose these readers with the command80..FF paths in C0F90B, preserving its nonlocal PLA/RTS exits, then recover the full animation/frame body and real idle-AI/refill dependencies. Full ordinary scheduling, every AI opcode, full frame publication and live interrupt/audio timing remain open.
