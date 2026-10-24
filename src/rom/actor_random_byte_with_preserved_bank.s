; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

public_random_byte_jump = $C00018



.segment "CODE"
.org $26FB
actor_random_byte_with_preserved_bank:
    phd
    php
    rep #$30
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    jsl f:public_random_byte_jump
    plb
    plp
    pld
    rts
