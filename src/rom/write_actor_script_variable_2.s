; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


ACTOR_PROGRAM_VARIABLES_23 = $0147

.segment "CODE"
.org $01C7
write_actor_script_variable_2:
    phd
    php
    rep #$30
    sep #$20
    .a8
    and #$0F
    pha
    lda a:ACTOR_PROGRAM_VARIABLES_23,Y
    .a8
    and #$F0
    ora $01,S
    sta a:ACTOR_PROGRAM_VARIABLES_23,Y
    pla
    plp
    pld
    rts
