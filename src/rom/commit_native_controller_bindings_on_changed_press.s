; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-settings-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

commit_three_native_controller_bindings_to_runtime_and_save_records = $C76FA7
derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269

.segment "CODE"
.org $2BFB
commit_native_controller_bindings_on_changed_press:
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda $43,X
    cmp a:$A204,X
    beq commit_native_controller_bindings_on_changed_press_c02c0e
    jsl f:commit_three_native_controller_bindings_to_runtime_and_save_records
    .a8
    lda #$01
    tsb a:$A20A
commit_native_controller_bindings_on_changed_press_c02c0e:
    rts
