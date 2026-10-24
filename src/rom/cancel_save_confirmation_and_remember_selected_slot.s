; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

compare_selected_pad_buttons_against_native_previous_buttons = $325A
routine_c01baf = $1BAF

.segment "CODE"
.org $2EA2
cancel_save_confirmation_and_remember_selected_slot:
    jsr compare_selected_pad_buttons_against_native_previous_buttons
    beq cancel_save_confirmation_and_remember_selected_slot_c02ebb
    .a8
    lda #$01
    sta a:$A210
    lda a:$A211
    sta f:$307FFF
    .a8
    lda #$01
    tsb a:$A20A
    jsr routine_c01baf
cancel_save_confirmation_and_remember_selected_slot_c02ebb:
    rts
