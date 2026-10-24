# Summon initialization and produced object callbacks

C12BE8, C12BED and C12BF2 are five-byte near wrappers around the complete
D3EE5C initializer, D3F159 sprite-object update and D3EE14 release. The actual
initializer writes C12BED and C12BF2 into the entity's update/release callback
fields alongside each allocated sprite-object pointer.

This proof retains one complete state for each seven-call sequence: initialize,
update each of the three created objects once, then release each object once.
The model and original each read their own produced pointers and callback fields.
Memory, pools and resources are not reseeded between calls. The test supplies
call timing and an outer RTS ABI; it does not claim to execute the complete
entity scheduler or the objects' full natural lifetime.

The calling domain is native X16, both accumulator widths, binary arithmetic,
DB7E and D0/300/1234, valid resource/heap/sprite pools, one to three input targets
and all eight owner identifiers. Complete callees, their actual IRQ/RTI work and
audio acknowledgement run without hooks. Every call compares full WRAM outside
its observed consumed stack, SRAM, CPU/context, peripherals and ordered
arithmetic/audio effects.

The 32 sequences pass all 224 complete original calls and 1,350,542 original
instructions. The capture contains 3,266 PC/M/X states; all six wrapper starts
are observed and all three sources independently assemble exactly to their
15 original bytes. Per-call semantic audio traces are accumulated across each
sequence before comparison to the retained native trace; no native log or
device is reset between the seven calls.

Evidence: `data/actor_entity_summon_wrappers.json`, its `.coverage.json`, and
`data/actor_entity_summon_wrappers.source_audit.json`. The preliminary seven-call
replay is excluded from source adoption. Frozen predecessor dependencies remain
unchanged; the coordinator owns catalogue integration.
