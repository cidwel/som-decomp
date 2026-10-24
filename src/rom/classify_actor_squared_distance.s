; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

read_actor_y_minus_height_x = $0343
read_actor_y_minus_height_y = $032E

ACTOR_POSITION_X = $0020

.segment "CODE"
.org $0358
classify_actor_squared_distance:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    lda a:ACTOR_POSITION_X,X
    sec
    sbc a:ACTOR_POSITION_X,Y
    beq classify_actor_squared_distance_c1036e
    bcs classify_actor_squared_distance_c10372
classify_actor_squared_distance_c1036e:
    .a16
    eor #$FFFF
    inc
classify_actor_squared_distance_c10372:
    .a16
    bit #$FF00
    bne classify_actor_squared_distance_c103ec
    sta $01
    sep #$20
    xba
    lda $01
    rep #$20
    sta f:$004202
    pha
    pla
    lda f:$004216
    sta $03
    jsr read_actor_y_minus_height_y
    sta $01
    jsr read_actor_y_minus_height_x
    sec
    sbc $01
    beq classify_actor_squared_distance_c1039b
    bcs classify_actor_squared_distance_c1039f
classify_actor_squared_distance_c1039b:
    .a16
    eor #$FFFF
    inc
classify_actor_squared_distance_c1039f:
    .a16
    bit #$FF00
    bne classify_actor_squared_distance_c103ec
    sta $01
    sep #$20
    xba
    lda $01
    rep #$20
    sta f:$004202
    pha
    pla
    lda f:$004216
    clc
    adc $03
    .a16
    cmp #$2400
    beq classify_actor_squared_distance_c103c1
    bcs classify_actor_squared_distance_c103f6
classify_actor_squared_distance_c103c1:
    .a16
    cmp #$1000
    beq classify_actor_squared_distance_c103c8
    bcs classify_actor_squared_distance_c103f1
classify_actor_squared_distance_c103c8:
    .a16
    cmp #$0900
    beq classify_actor_squared_distance_c103cf
    bcs classify_actor_squared_distance_c103ec
classify_actor_squared_distance_c103cf:
    .a16
    cmp #$0400
    beq classify_actor_squared_distance_c103d6
    bcs classify_actor_squared_distance_c103e7
classify_actor_squared_distance_c103d6:
    .a16
    cmp #$0100
    beq classify_actor_squared_distance_c103dd
    bcs classify_actor_squared_distance_c103e2
classify_actor_squared_distance_c103dd:
    .a16
    lda #$0001
    bra classify_actor_squared_distance_c103f9
classify_actor_squared_distance_c103e2:
    .a16
    lda #$0002
    bra classify_actor_squared_distance_c103f9
classify_actor_squared_distance_c103e7:
    .a16
    lda #$0004
    bra classify_actor_squared_distance_c103f9
classify_actor_squared_distance_c103ec:
    .a16
    lda #$0008
    bra classify_actor_squared_distance_c103f9
classify_actor_squared_distance_c103f1:
    .a16
    lda #$0010
    bra classify_actor_squared_distance_c103f9
classify_actor_squared_distance_c103f6:
    .a16
    lda #$0030
classify_actor_squared_distance_c103f9:
    sep #$20
    sta $04,S
    pla
    pla
    pla
    pla
    plp
    pld
    rts
