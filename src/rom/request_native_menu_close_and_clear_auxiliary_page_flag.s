; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

compare_selected_pad_buttons_against_native_previous_buttons = $325A

.segment "CODE"
.org $305A
request_native_menu_close_and_clear_auxiliary_page_flag:
    jsr compare_selected_pad_buttons_against_native_previous_buttons
    beq request_native_menu_close_and_clear_auxiliary_page_flag_c03069
    .a8
    lda #$01
    tsb a:$A20A
    .a8
    lda #$20
    trb a:$A212
request_native_menu_close_and_clear_auxiliary_page_flag_c03069:
    rts
