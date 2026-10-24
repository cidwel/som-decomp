; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

construct_native_save_page_after_selecting_active_hero = $C75273

.segment "CODE"
.org $2AB3
near_call_native_save_page_constructor:
    jsl f:construct_native_save_page_after_selecting_active_hero
    rts
