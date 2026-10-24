; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


ACTOR_PROGRAM_VARIABLES_23 = $0147

.segment "CODE"
.org $0179
read_actor_script_variable_2:
    phd
    php
    rep #$20
    sep #$20
    lda a:ACTOR_PROGRAM_VARIABLES_23,Y
    .a8
    and #$0F
    plp
    pld
    rts
