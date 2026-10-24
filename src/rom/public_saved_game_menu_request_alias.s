; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

forward_saved_game_menu_request_to_saved_word_entry = $008C

.segment "CODE"
.org $000C
public_saved_game_menu_request_alias:
    jmp forward_saved_game_menu_request_to_saved_word_entry
