; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_selected_effect_public_jump = $C00024

.segment "CODE"
.org $1FB3
actor_script_call_selected_effect_preserving_context:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    phy
    jsl f:actor_selected_effect_public_jump
    ply
    plb
    plp
    pld
    rts
