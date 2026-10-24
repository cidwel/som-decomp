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
.org $02B7
actor_script_call:
    phd
    php
    rep #$20
    phx
    tsc
    tcd
    lda a:ACTOR_PROGRAM_DEPTH,Y
    asl
    .a16
    and #$00FF
    clc
    .a16
    adc #ACTOR_PROGRAM_RETURNS
    sta $01
    lda a:ACTOR_PROGRAM_PC,Y
    tax
    clc
    .a16
    adc #$0003
    sta ($01),Y
    lda f:$D04F16,X
    xba
    sta a:ACTOR_PROGRAM_PC,Y
    sep #$20
    lda a:ACTOR_PROGRAM_DEPTH,Y
    inc
    .a8
    cmp #$10
    bcs actor_script_call_c102ee
    sta a:ACTOR_PROGRAM_DEPTH,Y
    .a8
    lda #$FF
    bra actor_script_call_c102f1
actor_script_call_c102ee:
    jsr restart_actor_program_on_script_error
actor_script_call_c102f1:
    sta $02,S
    pla
    pla
    plp
    pld
    rts
