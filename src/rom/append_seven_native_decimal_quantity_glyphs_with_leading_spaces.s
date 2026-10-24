; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_text_space_token = $5389

.segment "CODE"
.org $54B0
append_seven_native_decimal_quantity_glyphs_with_leading_spaces:
    .i16
    ldy #$0000
    .a8
    lda #$06
append_seven_native_decimal_quantity_glyphs_with_leading_spaces_c754b5:
    xba
    lda a:$A136,Y
    iny
    .a8
    cmp #$00
    bne append_seven_native_decimal_quantity_glyphs_with_leading_spaces_c754c7
    jsr append_native_saved_slot_text_space_token
    xba
    dec
    bne append_seven_native_decimal_quantity_glyphs_with_leading_spaces_c754b5
    iny
    xba
append_seven_native_decimal_quantity_glyphs_with_leading_spaces_c754c7:
    xba
    dey
    inc
append_seven_native_decimal_quantity_glyphs_with_leading_spaces_c754ca:
    xba
    lda a:$A136,Y
    iny
    clc
    .a8
    adc #$B5
    sta a:$9C00,X
    inx
    xba
    dec
    bne append_seven_native_decimal_quantity_glyphs_with_leading_spaces_c754ca
    rts
