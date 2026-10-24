# Temporary and main spell-entity cleanup

C1284B/33 saves the caller's direct page, status and data bank, forces bank7E,
and releases the three actual heap pointers at8212/8214/8218 in order.
C14190/21 performs the same saved-context protocol for the main heap pointer
at8424. Both bodies require incoming X16; they accept both accumulator widths.
They restore the original bank, processor status, direct page and stack, with
final N/Z from the restored direct page.

The new model composes the unchanged complete release-unit calculation and
retains the actual nested near-return positions for its stack-derived accumulator
residue. The real saved-bank release wrapper is reproduced around that calculation.
Zero and unaligned pointers retain the original no-op behavior; duplicate pointers
are released only once because subsequent calls see the naturally cleared bitmap.
The pointer holders remain unchanged, matching the original cleanup bodies.

Each fixture first executes the original complete heap initializer C13BD3 and
three original unit allocations C13C04, comparing them with their frozen readable
models. These four producer calls are separately counted and receive no new byte
credit. The resulting disjoint allocations drive four length triples and27
zero/aligned/unaligned/duplicate pointer patterns, three main-pointer selections,
both M widths, four saved D/DB contexts and caller stacks01FF/1F00.

The strict cleanup comparison preserves all CPU/context fields, SRAM and hardware,
and every WRAM byte outside the stack interval actually observed during its
nested native calls. Owner-map integrity checks prove that selected allocations
are cleared while the other produced allocations remain owned. Binary native
mode and X16 are explicit. No hooks, fabricated release result, scheduler shortcut
or saved original payload is used.


The frozen full proof passes1,728 complete cleanup calls and206,253 cleanup
instructions. The6,912 genuine producer calls add7,210,944 separately recorded
setup instructions. All32 own starts are observed (18 triple-cleanup and14
main-cleanup), with uniquely observed immediate widths. Independent temporary
ca65/ld65 assembly matches all54 ROM bytes. The audit verifies83 unchanged
recursive dependencies and genuine report/coverage hashes.

`data/actor_spell_entity_cleanup.source_audit.json` records the audit;
`tools/actor_spell_entity_cleanup_source_adoption.py` contains proposed adoption.
The single-case replay is diagnostic and excluded from adoption.
