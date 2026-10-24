; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


ACTOR_POSITION_Y = $0022
ACTOR_JUMP_HEIGHT = $0045

.segment "CODE"
.org $0343
read_actor_y_minus_height_x:
    phd
    php
    rep #$20
    lda a:ACTOR_JUMP_HEIGHT,X
    .a16
    and #$00FF
    .a16
    eor #$FFFF
    inc
    clc
    adc a:ACTOR_POSITION_Y,X
    plp
    pld
    rts
