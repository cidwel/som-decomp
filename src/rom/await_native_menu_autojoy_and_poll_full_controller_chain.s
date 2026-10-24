; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-menu-poll.md.
.setcpu "65816"
.smart
.a8
.i16

routine_008000 = $8000

.segment "CODE"
.org $2BD9
await_native_menu_autojoy_and_poll_full_controller_chain:
await_native_menu_autojoy_and_poll_full_controller_chain_c02bd9:
    lda f:$004212
    .a8
    and #$01
    bne await_native_menu_autojoy_and_poll_full_controller_chain_c02bd9
    sep #$10
    jsl f:routine_008000
    rep #$10
    rts
