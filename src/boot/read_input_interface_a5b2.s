; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A5B2
read_input_interface_a5b2:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0005
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$00
    pha
    plb
    rep #$20
    stz $02
    stz $04
    sep #$20
    .a8
    lda #$BF
    sta f:$004201
    .a8
    lda #$10
    sta $01
read_input_interface_a5b2_a5d6:
    lda a:$4016
    ror
    rep #$20
    rol $02
    ror
    rol $04
    sep #$20
    dec $01
    bne read_input_interface_a5b2_a5d6
    .a8
    lda #$FF
    sta f:$004201
    rep #$20
    lda $04
    sta a:$0094
    lda $02
    plb
    sta $04,S
    tsc
    clc
    .a16
    adc #$0003
    tcs
    pla
    plp
    pld
    rts
