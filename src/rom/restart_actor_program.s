; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


ACTOR_PROGRAM_PC = $0144
ACTOR_PROGRAM_VARIABLES = $0146
ACTOR_PROGRAM_CONTROL_FLAGS = $014C
ACTOR_PROGRAM_AUX_FLAGS = $014E
ACTOR_PROGRAM_DEPTH = $014F
ACTOR_TARGETS = $01AC

.segment "CODE"
.org $263C
restart_actor_program:
    phd
    php
    rep #$30
    pha
    tsc
    tcd
    pla
    phx
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    rep #$20
    sta $01
    txa
    .a16
    and #$1FFF
    .a16
    ora #$E000
    tay
    .a16
    lda #$FFFF
    sta a:ACTOR_TARGETS,Y
    lda $01
    sep #$20
    xba
    .a8
    lda #$10
    rep #$20
    sta f:$004202
    pha
    pla
    lda f:$004216
    tax
    lda f:$D00009,X
    clc
    .a16
    adc #$0003
    sta a:ACTOR_PROGRAM_PC,Y
    .a16
    lda #$0000
    sta a:ACTOR_PROGRAM_VARIABLES,Y
    sta a:ACTOR_PROGRAM_CONTROL_FLAGS,Y
    sep #$20
    sta a:ACTOR_PROGRAM_AUX_FLAGS,Y
    sta a:ACTOR_PROGRAM_DEPTH,Y
    plb
    sta $02,S
    pla
    pla
    plp
    pld
    rts
