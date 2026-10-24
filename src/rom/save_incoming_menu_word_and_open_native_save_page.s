; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c01d97 = $C01D97

.segment "CODE"
.org $00BA
save_incoming_menu_word_and_open_native_save_page:
    php
    rep #$20
    sta f:$7EA25A
    .a16
    lda #$0007
    plp
    jml f:routine_c01d97
