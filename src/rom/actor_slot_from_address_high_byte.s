; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16




.segment "CODE"
.org $05CF
actor_slot_from_address_high_byte:
    rep #$20
    txa
    sep #$20
    xba
    sec
    .a8
    sbc #$E0
    lsr
    rts
