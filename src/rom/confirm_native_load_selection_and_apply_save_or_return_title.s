; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-title-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

apply_selected_saved_game_and_restore_live_party = $C7557A
compare_selected_pad_buttons_against_native_previous_buttons = $325A
select_title_load_or_new_game_page_and_initialize_save_records = $C75F4A

.segment "CODE"
.org $2EBC
confirm_native_load_selection_and_apply_save_or_return_title:
    jsr compare_selected_pad_buttons_against_native_previous_buttons
    beq confirm_native_load_selection_and_apply_save_or_return_title_c02eda
    jsl f:apply_selected_saved_game_and_restore_live_party
    lda a:$A212
    .a8
    bit #$04
    beq confirm_native_load_selection_and_apply_save_or_return_title_c02ed5
    stz a:$A211
    jsl f:select_title_load_or_new_game_page_and_initialize_save_records
    bra confirm_native_load_selection_and_apply_save_or_return_title_c02eda
confirm_native_load_selection_and_apply_save_or_return_title_c02ed5:
    .a8
    lda #$01
    tsb a:$A20A
confirm_native_load_selection_and_apply_save_or_return_title_c02eda:
    .a8
    lda #$04
    trb a:$A212
    rts
