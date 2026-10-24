; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

restart_actor_program_on_script_error = $0100

ACTOR_PROGRAM_PC = $0144
ACTOR_PROGRAM_DEPTH = $014F
ACTOR_PROGRAM_RETURNS = $0150

.segment "CODE"
.org $02F8
actor_script_return:
    phd
    php
    rep #$20
    phx
    tsc
    tcd
    sep #$20
    lda a:ACTOR_PROGRAM_DEPTH,Y
    dec
    .a8
    cmp #$10
    bcs actor_script_return_c10322
    sta a:ACTOR_PROGRAM_DEPTH,Y
    asl
    rep #$20
    .a16
    and #$00FF
    clc
    .a16
    adc #ACTOR_PROGRAM_RETURNS
    sta $01
    lda ($01),Y
    sta a:ACTOR_PROGRAM_PC,Y
    .a16
    lda #$FFFF
    bra actor_script_return_c10325
actor_script_return_c10322:
    jsr restart_actor_program_on_script_error
actor_script_return_c10325:
    sep #$20
    sta $02,S
    pla
    pla
    plp
    pld
    rts
