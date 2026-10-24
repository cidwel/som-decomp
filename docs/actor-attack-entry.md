# Complete actor attack entries

Six native C0 entries now compose attack gating, target/animation selection,
palette restoration and the party attack gauge. They total 213 new code
bytes: `C0B24A/61`, `C0B287/14`, `C0B295/10`, `C0B29F/8`, `C0B2A7/108` and
`C0B313/12`. The target-selection and attack-palette models remain frozen and
receive no duplicate source credit.

The ordinary entry refuses an actor with movement, attack or animation busy
fields, then marks attack state, clears movement fields and passes carry from
the direct-page selector shift to the real target lookup. The public direct
target wrapper produces the selector byte `$FF`. The variant entry has its
own busy gate, preserves the native alternate-frame animation path, and
either starts the attack timer or clears and publishes the party gauge.
The controller entry derives the actor offset from the literal mask `$06`.

Both public long-call wrappers save and restore the caller bank; the internal
short-call entries use DB0. The palette bridge temporarily selects DB7E and
returns through the real restoration routine. The final bank-restoration
flags and width changes are retained in the readable composition.

All 412 complete original calls pass: six actor records, the distinct busy
fields, direct/free selection, the alternation bit and frame parity, both
gauge states, controller masks 0/2/4/6 and both palette-bit states. All 93 own
instruction starts are observed. Full WRAM outside the observed native
stack, returned processor state and peripherals match without hooks.
Entry context is M8/X16, D0 and binary arithmetic; public wrappers accept
DB7E and internal entries DB0.

Evidence is recorded in `data/actor_attack_entry_proof.json`, its coverage
report and `data/actor_attack_entry_audit.json`. All 213 source bytes are
integrated and independently assemble to the original ROM. The joint
checkpoint is `data/source_checkpoint_20261010_attack_entries_skill_shop_inventory.json`.
The enclosing `C1D942` dispatcher
and its actor-program step remain open.
