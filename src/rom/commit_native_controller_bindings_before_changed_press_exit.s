; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

commit_three_native_controller_bindings_to_runtime_and_save_records = $C76FA7
compare_selected_pad_buttons_against_native_previous_buttons = $325A

.segment "CODE"
.org $302F
commit_native_controller_bindings_before_changed_press_exit:
    jsl f:commit_three_native_controller_bindings_to_runtime_and_save_records
    jsr compare_selected_pad_buttons_against_native_previous_buttons
    beq commit_native_controller_bindings_before_changed_press_exit_c03042
    .a8
    lda #$01
    tsb a:$A20A
    .a8
    lda #$20
    trb a:$A212
commit_native_controller_bindings_before_changed_press_exit_c03042:
    rts
