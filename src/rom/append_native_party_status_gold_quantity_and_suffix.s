; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

append_seven_native_decimal_quantity_glyphs_with_leading_spaces = $54B0
convert_24_bit_dialogue_quantity_to_seven_digit_fields = $C754DB
select_bank_C7_and_copy_native_terminated_tokens = $6ABE

.segment "CODE"
.org $6997
append_native_party_status_gold_quantity_and_suffix:
    .i16
    ldy #$7B61
    jsr select_bank_C7_and_copy_native_terminated_tokens
    phx
    .i16
    ldy #$0000
    .a8
    lda #$04
    .i16
    ldx #$0000
append_native_party_status_gold_quantity_and_suffix_c769a6:
    xba
    lda a:$CC6A,X
    sta a:$A136,Y
    inx
    iny
    xba
    dec
    bne append_native_party_status_gold_quantity_and_suffix_c769a6
    jsl f:convert_24_bit_dialogue_quantity_to_seven_digit_fields
    plx
    jsr append_seven_native_decimal_quantity_glyphs_with_leading_spaces
    .i16
    ldy #$7B6A
    jsr select_bank_C7_and_copy_native_terminated_tokens
    rts
