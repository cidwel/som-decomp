; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

save_incoming_menu_word_and_open_native_save_page = $00BA

.segment "CODE"
.org $008C
forward_saved_game_menu_request_to_saved_word_entry:
    jmp save_incoming_menu_word_and_open_native_save_page
