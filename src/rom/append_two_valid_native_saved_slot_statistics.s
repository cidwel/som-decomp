; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16

append_three_native_saved_slot_decimal_digits = $5A1E
format_five_native_saved_slot_decimal_digits_via_hardware_division = $5D17
read_native_saved_slot_character_first_statistic = $5B48
read_native_saved_slot_character_second_statistic = $5B67

.segment "CODE"
.org $59FC
append_two_valid_native_saved_slot_statistics:
    lda a:$A216
    .a8
    and #$03
    .a8
    cmp #$03
    beq append_two_valid_native_saved_slot_statistics_c75a1d
    jsr read_native_saved_slot_character_first_statistic
    jsr format_five_native_saved_slot_decimal_digits_via_hardware_division
    jsr append_three_native_saved_slot_decimal_digits
    .a8
    lda #$C1
    sta a:$9C00,X
    inx
    jsr read_native_saved_slot_character_second_statistic
    jsr format_five_native_saved_slot_decimal_digits_via_hardware_division
    jsr append_three_native_saved_slot_decimal_digits
append_two_valid_native_saved_slot_statistics_c75a1d:
    rts
