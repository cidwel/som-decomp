; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


ACTOR_PROGRAM_VARIABLES_01 = $0146

.segment "CODE"
.org $015B
read_actor_script_variable_0:
    phd
    php
    rep #$20
    sep #$20
    lda a:ACTOR_PROGRAM_VARIABLES_01,Y
    .a8
    and #$0F
    plp
    pld
    rts
