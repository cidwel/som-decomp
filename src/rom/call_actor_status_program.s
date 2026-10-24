; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

restart_actor_program = $263C

ACTOR_PROGRAM_PC = $0144
ACTOR_PROGRAM_DEPTH = $014F
ACTOR_PROGRAM_RETURNS = $0150
ACTOR_ID = $0180

.segment "CODE"
.org $2698
call_actor_status_program:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0002
    tcd
    tcs
    lda $03,S
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
    lda a:ACTOR_PROGRAM_DEPTH,Y
    asl
    .a16
    and #$00FF
    clc
    .a16
    adc #ACTOR_PROGRAM_RETURNS
    sta $03
    lda a:ACTOR_PROGRAM_PC,Y
    sta ($03),Y
    lda $01
    asl
    .a16
    and #$00FF
    tax
    lda f:$D04ED3,X
    sta a:ACTOR_PROGRAM_PC,Y
    sep #$20
    lda a:ACTOR_PROGRAM_DEPTH,Y
    inc
    .a8
    cmp #$10
    bcs call_actor_status_program_c126ea
    sta a:ACTOR_PROGRAM_DEPTH,Y
    bra call_actor_status_program_c126f1
call_actor_status_program_c126ea:
    lda a:ACTOR_ID,Y
    tyx
    jsr restart_actor_program
call_actor_status_program_c126f1:
    plb
    sta $04,S
    pla
    pla
    pla
    pla
    plp
    pld
    rts
