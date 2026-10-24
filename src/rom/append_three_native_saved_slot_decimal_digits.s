; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_decimal_pair = $5AFF

.segment "CODE"
.org $5A1E
append_three_native_saved_slot_decimal_digits:
    lda a:$A237
    bne append_three_native_saved_slot_decimal_digits_c75a2a
    .a8
    lda #$80
    sta a:$9C00,X
    bra append_three_native_saved_slot_decimal_digits_c75a2d
append_three_native_saved_slot_decimal_digits_c75a2a:
    sta a:$9C00,X
append_three_native_saved_slot_decimal_digits_c75a2d:
    inx
    jsr append_native_saved_slot_decimal_pair
    rts
