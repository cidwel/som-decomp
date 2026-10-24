; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-projection.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B453
multiply_signed_ui_coordinate_using_two_native_byte_products:
    bpl multiply_signed_ui_coordinate_using_two_native_byte_products_c2b47f
    txa
    .a8
    eor #$FF
    clc
    .a8
    adc #$01
    sta a:$4203
    phx
    pla
    stz $01
    lda a:$4217
    sta $00
    pla
    .a8
    eor #$FF
    .a8
    adc #$00
    sta a:$4203
    clc
    rep #$20
    lda $00
    adc a:$4216
    .a16
    eor #$FFFF
    inc
    tax
    sep #$20
    rts
multiply_signed_ui_coordinate_using_two_native_byte_products_c2b47f:
    txa
    sta a:$4203
    phx
    pla
    stz $01
    lda a:$4217
    sta $00
    pla
    sta a:$4203
    clc
    rep #$20
    lda $00
    adc a:$4216
    tax
    sep #$20
    rts
