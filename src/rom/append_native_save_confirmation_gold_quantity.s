; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

append_seven_native_decimal_quantity_glyphs_with_leading_spaces = $54B0
convert_24_bit_dialogue_quantity_to_seven_digit_fields = $C754DB
derive_selected_save_slot_primary_or_backup_offset = $5D00

.segment "CODE"
.org $5473
append_native_save_confirmation_gold_quantity:
    rep #$20
    jsr derive_selected_save_slot_primary_or_backup_offset
    txa
    clc
    .a16
    adc #$006D
    tax
    sep #$20
    .i16
    ldy #$0000
    .a8
    lda #$04
append_native_save_confirmation_gold_quantity_c75485:
    xba
    lda f:$306000,X
    sta a:$A136,Y
    inx
    iny
    xba
    dec
    bne append_native_save_confirmation_gold_quantity_c75485
    jsl f:convert_24_bit_dialogue_quantity_to_seven_digit_fields
    .i16
    ldx #$0000
    .i16
    ldy #$0008
    .a8
    lda #$80
append_native_save_confirmation_gold_quantity_c7549f:
    sta a:$9C00,X
    inx
    dey
    bne append_native_save_confirmation_gold_quantity_c7549f
    jsr append_seven_native_decimal_quantity_glyphs_with_leading_spaces
    .a8
    lda #$A1
    sta a:$9C00,X
    inx
    rts
