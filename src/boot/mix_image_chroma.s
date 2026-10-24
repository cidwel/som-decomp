; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9DF5
mix_image_chroma:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    .i16
    ldy #$0000
    tyx
    .a16
    lda #$0040
    sta $01
mix_image_chroma_9e09:
    lda a:$1B00,X
    lsr
    sta a:$1C00,Y
    lsr
    sta $03
    lda a:$1A00,X
    lsr
    lsr
    lsr
    clc
    adc $03
    .a16
    eor #$FFFF
    inc
    sta a:$1C01,Y
    lda a:$1A00,X
    lsr
    sta a:$1C02,Y
    inx
    inx
    iny
    iny
    iny
    iny
    dec $01
    bne mix_image_chroma_9e09
    sep #$20
    pla
    pla
    pla
    pla
    plp
    pld
    rts
