; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
routine_c030ca = $30CA
routine_c030fe = $30FE

.segment "CODE"
.org $30A2
select_native_controller_button_one_from_exclusive_current_mask:
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda $42,X
    .a8
    and #$C0
    .a8
    cmp #$40
    bne routine_c030fe
    lda $43,X
    .a8
    and #$C0
    bne routine_c030fe
    .a8
    lda #$01
    bra routine_c030ca
