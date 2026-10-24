; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c7527b = $527B
select_first_active_native_menu_party_hero = $5DDC

.segment "CODE"
.org $5273
construct_native_save_page_after_selecting_active_hero:
    jsr select_first_active_native_menu_party_hero
    bra routine_c7527b
