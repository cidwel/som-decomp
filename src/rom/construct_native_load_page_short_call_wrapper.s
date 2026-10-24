; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-menu-trajectory.md.
.setcpu "65816"
.smart
.a8
.i16

construct_native_load_game_page_and_select_remembered_slot = $C75278

.segment "CODE"
.org $2AAE
construct_native_load_page_short_call_wrapper:
    jsl f:construct_native_load_game_page_and_select_remembered_slot
    rts
