# Spell-entity initializer near wrappers

C12C06 calls the complete C12C15 twin-family initializer using JSL and returns
with RTS. C14810 similarly calls D3FD3F, the bounded random-fallback initializer.
Each body occupies five physical ROM bytes. Their callees already have matching
sources; this work covers the missing near wrappers and their complete nested
execution with the extra caller stack bytes retained.

The local model extends the existing twin/fallback model. Fixtures cover both
incoming accumulator widths, X16, binary arithmetic, DB7E and D0/300/1234;
valid heaps and sprite pools; one to three targets; four twin header selections
and eight override actors; and real RNG, including the all-zero seed. The
original comparison runs the actual complete resource, IRQ/RTI and audio work
without replacing callees. Full memory outside the observed consumed stack,
native registers/context, peripherals and ordered arithmetic/audio writes are
compared after the outer RTS. These are direct ABI fixtures, with no claim of
a produced gameplay scheduler caller.

The full original comparison passes 128 calls and 9,093,373 instructions, with
2,636 captured PC/M/X states. Both wrapper bodies have all four instruction
starts observed and independently assemble exactly to their ten original bytes.
The evidence is `data/actor_entity_initializer_wrappers.json`, its
`.coverage.json` and `data/actor_entity_initializer_wrappers.source_audit.json`.
The preliminary two-call replay is excluded from source adoption. Frozen
predecessor dependencies remain unchanged; catalogue integration is separate.
