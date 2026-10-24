# Spell entity slot and one-hot indices

C14708/24 saves the direct page and processor status, widens both register
classes, masks A to its low nibble and constructs a one-hot bit by the literal
left-shift loop. It publishes the bit in A and X, then restores the incoming
status and direct page. Restoring X8 narrows X, while A retains the full bit.
Final N/Z come from the restored direct page, with the caller's other flags
restored even when the shifts produce carry.

C14398/30 saves direct page, status and data bank, forces bank7E and reads the
actual spell-entity heap base at8424. It subtracts that base from X with 16-bit
wrap, shifts the result right five times and masks to three bits. The produced
index0..7 remains in A. The original bank, status, direct page, stack and index
registers are restored; final N/Z again reflect the restored direct page.

The independent model reproduces all physical stack writes. Proof compares every
WRAM byte without stack exclusions, SRAM, hardware and complete CPU/context
through the actual near return. Inputs include all16 nibbles in16 upper-byte
contexts, nine heap-position boundaries crossed with seven heap bases, both M/X
widths, direct pages0/1/8000/FFFF, incoming banks0/7E/7F/42 and stacks01FF/1F00.
Binary native mode is explicit. No hooks, substituted returns or persisted
original payloads are used.


The frozen full proof passes5,104 complete original calls and163,488 original
instructions. All37 own starts are observed (15 one-hot and22 heap-index), with
uniquely observed immediate widths. Independent temporary ca65/ld65 assembly
matches all54 ROM bytes. The source audit verifies five unchanged recursive
dependencies and genuine primary report/coverage hashes.

`data/actor_entity_index_bits.source_audit.json` records the audit;
`tools/actor_entity_index_bits_source_adoption.py` contains proposed adoption.
The earlier single-case replay is diagnostic and excluded from adoption.
