; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1CDE
upload_menu_two_row_window:
    lda a:$1D05
    .a8
    cmp #$07
    bne upload_menu_two_row_window_c01d23
    .i16
    ldy #$9400
    ldx a:$1D06
    .a8
    lda #$02
upload_menu_two_row_window_c01ced:
    pha
    phx
    stx a:$2116
    ldx a:$1D08
    stx a:$4375
    .a8
    lda #$01
    sta a:$4370
    .a8
    lda #$18
    sta a:$4371
    sty a:$4372
    .a8
    lda #$7E
    sta a:$4374
    .a8
    lda #$80
    sta a:$420B
    rep #$20
    pla
    clc
    adc a:$1D18
    tax
    tya
    clc
    adc a:$1D08
    tay
    sep #$20
    pla
    dec
    bne upload_menu_two_row_window_c01ced
upload_menu_two_row_window_c01d23:
    rts
