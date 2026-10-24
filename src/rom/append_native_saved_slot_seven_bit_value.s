; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_text_space_token = $5389
derive_selected_save_slot_primary_or_backup_offset = $5D00
format_and_append_native_saved_slot_decimal_pair = $5AFC

.segment "CODE"
.org $5A8A
append_native_saved_slot_seven_bit_value:
    lda a:$A216
    .a8
    and #$03
    .a8
    cmp #$03
    beq append_native_saved_slot_seven_bit_value_c75aaa
    phx
    rep #$20
    jsr derive_selected_save_slot_primary_or_backup_offset
    lda f:$3062B7,X
    .a16
    and #$007F
    tay
    sep #$20
    plx
    jsr append_native_saved_slot_text_space_token
    jsr format_and_append_native_saved_slot_decimal_pair
append_native_saved_slot_seven_bit_value_c75aaa:
    rts
