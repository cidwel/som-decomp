; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

construct_native_save_confirmation_page_from_selected_slot = $C752AF

.segment "CODE"
.org $2AB8
near_call_native_save_confirmation_page_constructor:
    jsl f:construct_native_save_confirmation_page_from_selected_slot
    rts
