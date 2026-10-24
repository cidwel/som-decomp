; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-load.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $592E
unpack_saved_menu_word_and_advance_sram_cursor:
    rep #$20
    lda f:$306000,X
    sta a:$A25A
    sep #$20
    inx
    inx
    rts
