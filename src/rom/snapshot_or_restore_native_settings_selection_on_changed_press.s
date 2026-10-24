; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-settings-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

commit_three_native_controller_bindings_to_runtime_and_save_records = $C76FA7
derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
refresh_native_shop_frame_graphics_icons_and_request_sound = $C76256
routine_c01baf = $1BAF
snapshot_native_shop_item_selection_records = $C7626A

.segment "CODE"
.org $2C0F
snapshot_or_restore_native_settings_selection_on_changed_press:
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda $43,X
    cmp a:$A204,X
    beq snapshot_or_restore_native_settings_selection_on_changed_press_c02c3b
    jsl f:snapshot_native_shop_item_selection_records
    .a8
    lda #$80
    bit a:$A212
    beq snapshot_or_restore_native_settings_selection_on_changed_press_c02c32
    jsr routine_c01baf
    jsl f:refresh_native_shop_frame_graphics_icons_and_request_sound
    .a8
    lda #$80
    trb a:$A212
    bra snapshot_or_restore_native_settings_selection_on_changed_press_c02c3b
snapshot_or_restore_native_settings_selection_on_changed_press_c02c32:
    .a8
    lda #$01
    tsb a:$A20A
    jsl f:commit_three_native_controller_bindings_to_runtime_and_save_records
snapshot_or_restore_native_settings_selection_on_changed_press_c02c3b:
    rts
