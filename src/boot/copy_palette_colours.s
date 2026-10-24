; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $BC9A
copy_palette_colours:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0005
    tcd
    tcs
    lda $06,S
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    sta $01
    xba
    sta $05
    xba
    sty $03
    stx $06
    rep #$20
    .a16
    and #$00F0
    lsr
    lsr
    lsr
    clc
    adc $06
    tax
    lda $01
    .a16
    and #$000F
    inc
    sta $01
    .i16
    ldy #$0000
copy_palette_colours_bcd2:
    lda [$03],Y
    sta a:$0000,X
    iny
    iny
    inx
    inx
    dec $01
    bne copy_palette_colours_bcd2
    plb
    tsc
    clc
    .a16
    adc #$0007
    tcs
    plp
    pld
    rts
