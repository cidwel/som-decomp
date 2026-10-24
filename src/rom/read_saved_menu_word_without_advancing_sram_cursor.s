; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-load.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $593C
read_saved_menu_word_without_advancing_sram_cursor:
    rep #$20
    lda f:$306000,X
    sta a:$A23C
    sep #$20
    rts
