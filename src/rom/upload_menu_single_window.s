; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1D24
upload_menu_single_window:
    lda a:$1D05
    .a8
    cmp #$07
    beq upload_menu_single_window_c01d51
    ldx a:$1D06
    stx a:$2116
    ldx a:$1D08
    stx a:$4375
    .a8
    lda #$01
    sta a:$4370
    .a8
    lda #$18
    sta a:$4371
    .i16
    ldx #$9400
    stx a:$4372
    .a8
    lda #$7E
    sta a:$4374
    .a8
    lda #$80
    sta a:$420B
upload_menu_single_window_c01d51:
    rts
