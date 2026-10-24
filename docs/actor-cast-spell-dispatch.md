# Complete spell hit entry and canonical dispatch

The readable model now composes the original C8E6D4 bookkeeping and C8E7A7 dispatch with the real handlers for all 42 canonical spell IDs. It includes first-hit MP consumption, element grade and progress, level-up notices and sound. Reflection and delivery remain separate pending blocks; C18707 is not closed by this proof.

| Entry | Instruction bytes | Role |
|---|---:|---|
| C8E6D4 | 211 | Prepare and resolve complete spell hit |
| C8E7A7 | 90 | Dispatch spell hit on target |
| D04DCD | 161 | Advance spell element progress after first hit |
| D04E6E | 62 | Read actor element grade and progress |
| C05B75 | 47 | Enqueue spell element level-up notice |

These 571 bytes are candidate source ranges, not automatically new decompilation credit. Integration must subtract existing exact matching sources. Existing handlers, arithmetic, statuses, messages, attribute rebuild and sound contracts are reused without duplicate credit.

C8E6D4 establishes caster/target context, publishes the flash, reads the actual D0 spell row, computes the effective level and performs first-hit bookkeeping once. Its three-entry hit list retains duplicate/full-list and dead-caster/dead-target guards, Revive/objectEA exceptions and the special controller route. C8E7A7 follows the original ROM pointer table, executes the real selected handler and publishes newly changed buff notices. No handler is replaced by a hook.

Progress uses packed hero element grades, the actual grade-dependent gain and cap rules, ED-dependent halving, progress carry, level-up message records and real C03989 sound. C05B75 enters the notice suffix after its grade-increment entry, so its decimal value is the current grade rather than an extra increment. The model preserves native scratch, hardware multiply/divide ports, registers and flags across the complete composition.

## Evidence and domain

The completed native comparison contains 8,832 original calls: 4,032 each for C8E6D4 and C8E7A7, and 256 each for the remaining three entries. Coverage records 2,708 PC/M/X states. Every canonical spell ID 0..41 is actually dispatched through a handler, checked explicitly by the harness. The comparison also matches 420 ordered APU port writes, including bounded acknowledgement delays 0..3. No NMI or instruction bypass hooks are used.

Compared state includes all WRAM except 129 temporary caller-stack bytes, A/X/Y/C/N/Z/V/M/X-width, S/D/DB, peripherals and ordered sound writes. Domain: D0300/DB7E/M8/X16/binary; 12 aligned actors; 42 ROM spell rows; levels 0..8; divisors 0/1/2/3/255; first, duplicate, full, dead and special guards; grades 0..8, progress 0/98/99 and caps 0/1/3/8; bounded valid actor classifications, queue cursors and RNG indices. Fixtures sample combinations rather than exhaust the complete machine state space.

Report dependency hashes and coverage tool hash match the final implementation. Runtime ROM reads contain actual spell tables and message data; no such payload is saved in the source, report or documentation.

## Next dependency

D04C82 must retain the actual Wall candidate selection, charge consumption, distance and eligibility checks and duplicate reflection notice. C18D12 must then compose real hit resolution and target graphics/publication/restoration. The sprite and temporary spell-entity coroutine chain still prevents claiming complete C18707 reconstruction.
