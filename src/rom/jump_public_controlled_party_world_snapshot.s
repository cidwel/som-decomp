; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-world-snapshot.md.
.setcpu "65816"
.smart
.a8
.i16

jump_internal_controlled_party_world_snapshot = $385A

.segment "CODE"
.org $0072
jump_public_controlled_party_world_snapshot:
    jmp jump_internal_controlled_party_world_snapshot
