; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

refresh_actor_appearance_public_jump = $C0003C

.segment "CODE"
.org $1660
actor_script_refresh_appearance_preserving_context:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    jsl f:refresh_actor_appearance_public_jump
    plb
    plp
    pld
    rts
