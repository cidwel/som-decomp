; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

cast_spell_public_jump = $C0001B

.segment "CODE"
.org $1E16
actor_script_call_native_cast_preserving_context:
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
    tyx
    jsl f:cast_spell_public_jump
    ply
    plb
    plp
    pld
    rts
