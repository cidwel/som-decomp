; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-name-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269

.segment "CODE"
.org $324A
reset_native_name_repeat_timer_on_new_direction:
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda a:$A204,X
    .a8
    and #$0F
    bne reset_native_name_repeat_timer_on_new_direction_c03259
    .a8
    lda #$F2
    sta a:$A201
reset_native_name_repeat_timer_on_new_direction_c03259:
    rts
