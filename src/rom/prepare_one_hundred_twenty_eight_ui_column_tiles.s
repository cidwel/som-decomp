; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-columns.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $993C
prepare_one_hundred_twenty_eight_ui_column_tiles:
    rep #$20
    sep #$10
    ldx $2F
    bne prepare_one_hundred_twenty_eight_ui_column_tiles_c09945
prepare_one_hundred_twenty_eight_ui_column_tiles_c09944:
    rts
prepare_one_hundred_twenty_eight_ui_column_tiles_c09945:
    bmi prepare_one_hundred_twenty_eight_ui_column_tiles_c09944
    .i8
    cpx #$01
    bne prepare_one_hundred_twenty_eight_ui_column_tiles_c09956
    lda $FA
    lsr
    lsr
    lsr
    clc
    .a16
    adc #$003F
    bra prepare_one_hundred_twenty_eight_ui_column_tiles_c0995f
prepare_one_hundred_twenty_eight_ui_column_tiles_c09956:
    lda $FA
    lsr
    lsr
    lsr
    sec
    .a16
    sbc #$0040
prepare_one_hundred_twenty_eight_ui_column_tiles_c0995f:
    .a16
    and #$01FF
    sta $00
    .a16
    and #$007F
    sta $78
    sep #$30
    .a8
    lda #$7F
    sta $02
    .i8
    ldx #$00
prepare_one_hundred_twenty_eight_ui_column_tiles_c09971:
    lda [$00]
    sta a:$0B80,X
    lda $01
    clc
    .a8
    adc #$02
    sta $01
    inx
    bpl prepare_one_hundred_twenty_eight_ui_column_tiles_c09971
    .i8
    ldx #$FF
    stx $2F
    rts
