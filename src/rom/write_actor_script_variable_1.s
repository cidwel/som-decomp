; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


ACTOR_PROGRAM_VARIABLES_01 = $0146

.segment "CODE"
.org $01AE
write_actor_script_variable_1:
    phd
    php
    rep #$30
    sep #$20
    asl
    asl
    asl
    asl
    pha
    lda a:ACTOR_PROGRAM_VARIABLES_01,Y
    .a8
    and #$0F
    ora $01,S
    sta a:ACTOR_PROGRAM_VARIABLES_01,Y
    pla
    plp
    pld
    rts
