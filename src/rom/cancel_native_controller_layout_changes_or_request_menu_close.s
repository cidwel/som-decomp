; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

decode_native_controller_layout_and_publish_four_button_labels = $C76DFC
publish_native_controller_layout_frame_and_optional_mirror = $C76E17
request_native_menu_close_and_clear_auxiliary_page_flag = $305A
restore_native_controller_bindings_and_copy_mirror_free_runtime_flags = $C76FB7
routine_c01baf = $1BAF
snapshot_native_controller_permutation_to_two_buffers = $C76F29

.segment "CODE"
.org $300C
cancel_native_controller_layout_changes_or_request_menu_close:
    .a8
    lda #$80
    bit a:$A212
    beq request_native_menu_close_and_clear_auxiliary_page_flag
    trb a:$A212
    jsr routine_c01baf
    jsl f:restore_native_controller_bindings_and_copy_mirror_free_runtime_flags
    jsl f:decode_native_controller_layout_and_publish_four_button_labels
    jsl f:publish_native_controller_layout_frame_and_optional_mirror
    jsl f:snapshot_native_controller_permutation_to_two_buffers
    .a8
    lda #$02
    tsb a:$A20A
    rts
