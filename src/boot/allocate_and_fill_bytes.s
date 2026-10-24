; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

boot_b081 = $B081
boot_c37d = $C37D

.segment "CODE"
.org $B0A1
allocate_and_fill_bytes:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0003
    tcd
    tcs
    lda $04,S
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    sta $01
    stx $04
    jsr boot_b081
    stx $02
    lda $01
    ldy $04
    jsr boot_c37d
    ldx $02
    plb
    rep #$20
    tsc
    clc
    .a16
    adc #$0005
    tcs
    plp
    pld
    rts
