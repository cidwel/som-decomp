; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9AA4
scale_image_coefficients:
    phd
    tdc
    sec
    .a16
    sbc #$2100
    tax
    .i16
    ldy #$1D00
    .a16
    lda #$2100
    tcd
    sep #$20
scale_image_coefficients_9ab4:
    lda a:$0000,Y
    beq scale_image_coefficients_9ad2
    iny
    sta $1B
    .a8
    lda #$00
    sta $1B
    lda $00,X
    sta $1C
    sta $1C
    lda $34
    sta $00,X
    inx
    lda $35
    sta $00,X
    inx
    bra scale_image_coefficients_9ab4
scale_image_coefficients_9ad2:
    pld
    rts
