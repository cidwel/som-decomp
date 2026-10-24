; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-header.md.
.setcpu "65816"
.smart
.a8
.i16

move_native58_and_clear_party_hp_at_lower_boundary = $7DE7

.segment "CODE"
.org $7AF4
dispatch_native58_parent_with_complete_motion_guard:
    jsr move_native58_and_clear_party_hp_at_lower_boundary
    ldx $87
    lda a:$0094,X
    asl
    tax
    jmp ($7B01,X)
